#include "LinkLinkIt.h"

LinkLinkIt::estr_link::estr_link(const Link& l, const Categoria& c, LinkLinkIt* lli)
		: l(l), cid(lli->acat->IdCategoriaPorNombre(c)), ultimoAcceso(lli->fechaActual) {
	as[0] = as[1] = as[2] = 0;
}

LinkLinkIt::estr_linksPorCatId::estr_linksPorCatId(const Categoria& cat, Nat idPadre)
		: cat(cat), idPadre(idPadre), links(), ultimoAcceso(0), ordenado(false) {
}

LinkLinkIt::LinkLinkIt(ArbolCategorias* a)
		: acat(a), links(), linksPorCatId(a->CantidadDeCategorias()), fechaActual(0) {
	linksPorCatId.Definir(0, estr_linksPorCatId(acat->NombreCategoriaRaiz(), 0));
	ArbolCategorias::Iterador it = acat->CrearItRaiz();
	AgregarALinksPorCatId(it, 1);
}

void LinkLinkIt::AgregarALinksPorCatId(ArbolCategorias::Iterador& it, Nat idPadre) {
	while(it.HayMas()) {
		linksPorCatId.Definir(it.IdCategoriaActual() - 1, estr_linksPorCatId(it.CategoriaActual(), idPadre));
		ArbolCategorias::Iterador itHijos = acat->CrearItHijos(it);
		AgregarALinksPorCatId(itHijos, it.IdCategoriaActual());
		it.Avanzar();
	}
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

	estr_l.ultimoAcceso = f; // Bug en TP 2: Nos olvidamos de actualizar estr_link#ultimoAcceso.
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

LinkLinkIt::Iterador LinkLinkIt::CrearIt(const Categoria& c) {
	estr_linksPorCatId& estr_c = linksPorCatId[acat->IdCategoriaPorNombre(c) - 1];
	if(!estr_c.ordenado) OrdenarLinks(estr_c);
	return Iterador(this, acat->IdCategoriaPorNombre(c), estr_c.links.CrearIt());
}

LinkLinkIt::Iterador::Iterador(
		LinkLinkIt* lli, Nat cid, const Lista<estr_link*>::Iterador& itLista)
		: lli(lli), cid(cid), itLista(itLista) {
}

void LinkLinkIt::OrdenarLinks(estr_linksPorCatId& estr_c) {
	Lista<estr_link*>::Iterador it = estr_c.links.CrearIt();
	while(it.HaySiguiente()) {
		Lista<estr_link*>::Iterador it2 = Lista<estr_link*>::Iterador(it);
		Lista<estr_link*>::Iterador itMax = Lista<estr_link*>::Iterador(it2);
		while(it2.HaySiguiente()) {
			Nat arActual = AccesosRecientes(*it2.Siguiente(), estr_c);
			Nat arMax = AccesosRecientes(*itMax.Siguiente(), estr_c);
			if(arActual > arMax) itMax = Lista<estr_link*>::Iterador(it2);
			it2.Avanzar();
		}
		Intercambiar(it, itMax);
		it.Avanzar();
	}
	estr_c.ordenado = true;
}

Nat LinkLinkIt::AccesosRecientes(estr_link& estr_l, estr_linksPorCatId& estr_c) {
	if(estr_c.ultimoAcceso == estr_l.ultimoAcceso) {
		return estr_l.as[0] + estr_l.as[1] + estr_l.as[2];
	} else if(estr_c.ultimoAcceso == estr_l.ultimoAcceso + 1) {
		return estr_l.as[0] + estr_l.as[1];
	} else if(estr_c.ultimoAcceso == estr_l.ultimoAcceso + 2) {
		return estr_l.as[0];
	} else {
		return 0;
	}
}

void LinkLinkIt::Intercambiar(Lista<estr_link*>::Iterador& it, Lista<estr_link*>::Iterador& it2) {
	if(it == it2) {
		// Esto evita memory leaks al intentar intercambiar una posición en la lista consigo misma.
		return;
	}
	estr_link* ptr = it2.Siguiente();
	it2.EliminarSiguiente();
	it2.AgregarComoSiguiente(it.Siguiente());
	it.EliminarSiguiente();
	it.AgregarComoSiguiente(ptr);
}

bool LinkLinkIt::Iterador::HayMas() {
	return itLista.HaySiguiente();
}

const Link& LinkLinkIt::Iterador::LinkActual() {
	return itLista.Siguiente()->l;
}

const Categoria& LinkLinkIt::Iterador::CategoriaLinkActual() {
	return lli->linksPorCatId[itLista.Siguiente()->cid - 1].cat;
}

int LinkLinkIt::Iterador::AccesosRecientesLinkActual() {
	return lli->AccesosRecientes(*itLista.Siguiente(), lli->linksPorCatId[cid - 1]);
}

void LinkLinkIt::Iterador::Avanzar() {
	itLista.Avanzar();
}
