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
		Fecha ac[3];
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
		bool HaySiguiente();
		const Link& SiguienteLink();
		const Categoria& SiguienteCategoria();
		int SiguienteAccesosRecientes();
		void Avanzar();
		virtual ~IteradorLinksOrdenadosPorAcceso();
	};

	LinkLinkIt(ArbolCategorias*);
	void nuevoLink(const Link&, const Categoria&);
	void acceso(const Link&, Fecha);
	int cantLinks(const Categoria&);
	IteradorLinksOrdenadosPorAcceso linksOrdenadosPorAccesos(const Categoria&);
	virtual ~LinkLinkIt();

private:
	void AgregarALinksPorCatId(ArbolCategorias::IteradorCategoriasHijas* it, Nat idPadre);
};

#endif /* LINKLINKIT_H_ */
