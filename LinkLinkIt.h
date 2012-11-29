#ifndef LINKLINKIT_H_
#define LINKLINKIT_H_

#include "modulos/aed2.h"
#include "Tipos.h"
#include "ArbolCategorias.h"
#include "DiccTrie.h"

class LinkLinkIt {
	struct estr_link {
		Link l;
		Nat cid;
		Fecha ultimoAcceso;
		Nat as[3];

		estr_link(const Link& l, const Categoria& c, LinkLinkIt* lli);
	};

	struct estr_linksPorCatId {
		Categoria cat;
		Nat idPadre;
		Lista<estr_link*> links;
		Fecha ultimoAcceso;
		bool ordenado;

		estr_linksPorCatId(const Categoria& cat, Nat idPadre);
	};

	const ArbolCategorias& acat;
	DiccTrie<estr_link> links;
	Arreglo<estr_linksPorCatId> linksPorCatId;
	Fecha fechaActual;

public:

	class Iterador {
		LinkLinkIt* lli;
		Nat cid;
		Lista<estr_link*>::Iterador itLista;

		Iterador(LinkLinkIt* lli, Nat cid, const Lista<estr_link*>::Iterador& itLista);
		friend class LinkLinkIt;

	public:
		bool HayMas() const;
		const Link& LinkActual() const;
		const Categoria& CategoriaLinkActual() const;
		Nat AccesosRecientesLinkActual() const;
		void Avanzar();
	};

	LinkLinkIt(const ArbolCategorias&);
	void AgregarLink(const Link&, const Categoria&);
	void AccederLink(const Link&, Fecha);
	Nat CantidadDeLinks(const Categoria&) const;
	Iterador CrearIt(const Categoria&);

private:
	void AgregarALinksPorCatId(ArbolCategorias::Iterador& it, Nat idPadre);
	void OrdenarLinks(estr_linksPorCatId& estr_c) const;
	Nat AccesosRecientes(const estr_link& estr_l, const estr_linksPorCatId& estr_c) const;
	void Intercambiar(Lista<estr_link*>::Iterador& it, Lista<estr_link*>::Iterador& it2) const;
};

#endif /* LINKLINKIT_H_ */
