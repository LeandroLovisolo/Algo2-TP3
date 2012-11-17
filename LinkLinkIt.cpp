#include "LinkLinkIt.h"

LinkLinkIt::estr_link::estr_link(const Link& l, const Categoria& c, LinkLinkIt* lli)
		: l(l), cid(lli->acat->IdCategoriaPorNombre(c)), ultimoAcceso(lli->fechaActual), as({0, 0, 0}) {
}

LinkLinkIt::estr_linksPorCatId::estr_linksPorCatId(const Categoria& cat, Nat idPadre)
		: cat(cat), idPadre(idPadre), links(), ultimoAcceso(0), ordenado(false) {
}

LinkLinkIt::LinkLinkIt(ArbolCategorias* a)
		: acat(a), links(), linksPorCatId(a->CantidadDeCategorias()), fechaActual(0) {
	linksPorCatId.Definir(0, estr_linksPorCatId(acat->NombreCategoriaRaiz(), 0));
	ArbolCategorias::IteradorCategoriasHijas it = acat->CrearItRaiz();
	AgregarALinksPorCatId(&it, 1);
}

void LinkLinkIt::AgregarALinksPorCatId(ArbolCategorias::IteradorCategoriasHijas* it, Nat idPadre) {
	while(it->HayMas()) {
		linksPorCatId.Definir(it->IdCategoriaActual() - 1, estr_linksPorCatId(it->CategoriaActual(), idPadre));
		ArbolCategorias::IteradorCategoriasHijas itHijos = acat->CrearItHijos(*it);
		ArbolCategorias::IteradorCategoriasHijas *ptr = &itHijos;
		Nat idCatActual = it->IdCategoriaActual();
		AgregarALinksPorCatId(ptr, idCatActual);
		it->Avanzar();
	}
}

LinkLinkIt::~LinkLinkIt() {
}

void LinkLinkIt::AgregarLink(const Link& l, const Categoria& c) {
	links.Definir(l, estr_link(l, c, this));
	estr_link& estr_l = links.Obtener(l);

	Nat cid = estr_l.cid;
	while(cid != 0) {
		linksPorCatId[cid - 1].links.AgregarAtras(&estr_l);
		linksPorCatId[cid - 1].ultimoAcceso = fechaActual;
		linksPorCatId[cid - 1].ordenado = false;
		cid = linksPorCatId[cid - 1].idPadre;
	}
}

void LinkLinkIt::AccederLink(const Link& l, Fecha f) {
	estr_link& estr_l = links.Obtener(l);
	if(f == estr_l.ultimoAcceso) {
		estr_l.as[0] = estr_l.as[0] + 1;
	} else if(f == estr_l.ultimoAcceso + 1) {
		estr_l.as[2] = estr_l.as[1];
		estr_l.as[1] = estr_l.as[0];
		estr_l.as[0] = 1;
	} else if(f == estr_l.ultimoAcceso + 2) {
		estr_l.as[2] = estr_l.as[0];
		estr_l.as[1] = 0;
		estr_l.as[0] = 1;
	} else {
		estr_l.as[2] = 0;
		estr_l.as[1] = 0;
		estr_l.as[0] = 1;
	}

	fechaActual = f;

	Nat cid = estr_l.cid;
	while(cid != 0) {
		linksPorCatId[cid - 1].ultimoAcceso = fechaActual;
		linksPorCatId[cid - 1].ordenado = false;
		cid = linksPorCatId[cid - 1].idPadre;
	}
}

int LinkLinkIt::CantidadDeLinks(const Categoria& c) {
	return linksPorCatId[acat->IdCategoriaPorNombre(c) - 1].links.Longitud();
}

LinkLinkIt::IteradorLinksOrdenadosPorAcceso LinkLinkIt::CrearIt(const Categoria& c) {
	estr_linksPorCatId& estr_c = linksPorCatId[acat->IdCategoriaPorNombre(c) - 1];
	if(!estr_c.ordenado) OrdenarLinks(estr_c);
	return IteradorLinksOrdenadosPorAcceso(this, acat->IdCategoriaPorNombre(c), estr_c.links.CrearIt());
}

LinkLinkIt::IteradorLinksOrdenadosPorAcceso::IteradorLinksOrdenadosPorAcceso(
		LinkLinkIt* lli, Nat cid, Lista<estr_link*>::Iterador itLista)
		: lli(lli), cid(cid), itLista(itLista) {
}

void LinkLinkIt::OrdenarLinks(estr_linksPorCatId& estr_c) {
	// TODO: Implementar sorting
}

Nat LinkLinkIt::AccesosRecientes(estr_link& estr_l, estr_linksPorCatId& estr_c) {
	return 0;
}

LinkLinkIt::IteradorLinksOrdenadosPorAcceso::~IteradorLinksOrdenadosPorAcceso() {
}

bool LinkLinkIt::IteradorLinksOrdenadosPorAcceso::HayMas() {
	return itLista.HaySiguiente();
}

const Link& LinkLinkIt::IteradorLinksOrdenadosPorAcceso::LinkActual() {
	return itLista.Siguiente()->l;
}

const Categoria& LinkLinkIt::IteradorLinksOrdenadosPorAcceso::CategoriaLinkActual() {
	return lli->linksPorCatId[itLista.Siguiente()->cid - 1].cat;
}

int LinkLinkIt::IteradorLinksOrdenadosPorAcceso::AccesosRecientesLinkActual() {
	return lli->AccesosRecientes(*itLista.Siguiente(), lli->linksPorCatId[cid - 1]);
}

void LinkLinkIt::IteradorLinksOrdenadosPorAcceso::Avanzar() {
	itLista.Avanzar();
}
