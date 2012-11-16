#ifndef LINKLINKIT_H_
#define LINKLINKIT_H_

#include "modulos/aed2.h"
#include "driver/Tipos.h"
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

	ArbolCategorias* acat;
	DiccTrie<estr_link> links;
	Arreglo<estr_linksPorCatId> linksPorCatId;
	Fecha fechaActual;

public:

	class IteradorLinksOrdenadosPorAcceso {
		IteradorLinksOrdenadosPorAcceso();
		friend class LinkLinkIt;

	public:
		bool HayMas();
		const Link& LinkActual();
		const Categoria& CategoriaLinkActual();
		int AccesosRecientesLinkActual();
		void Avanzar();
		virtual ~IteradorLinksOrdenadosPorAcceso();
	};

	LinkLinkIt(ArbolCategorias*);
	void AgregarLink(const Link&, const Categoria&);
	void AccederLink(const Link&, Fecha);
	int CantidadDeLinks(const Categoria&);
	IteradorLinksOrdenadosPorAcceso CrearIt(const Categoria&);
	virtual ~LinkLinkIt();

private:
	void AgregarALinksPorCatId(ArbolCategorias::IteradorCategoriasHijas* it, Nat idPadre);
};

#endif /* LINKLINKIT_H_ */
