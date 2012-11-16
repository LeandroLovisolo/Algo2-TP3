#include "LinkLinkIt.h"

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
		AgregarALinksPorCatId(&itHijos, it->IdCategoriaActual());
		it->Avanzar();
	}
}

LinkLinkIt::~LinkLinkIt() {
}

void LinkLinkIt::AgregarLink(const Link& l, const Categoria& c) {
}

void LinkLinkIt::AccederLink(const Link& l, Fecha f) {
}

int LinkLinkIt::CantidadDeLinks(const Categoria& c) {
	return -1;
}

LinkLinkIt::IteradorLinksOrdenadosPorAcceso LinkLinkIt::CrearIt(const Categoria& c) {
	return IteradorLinksOrdenadosPorAcceso();
}

LinkLinkIt::IteradorLinksOrdenadosPorAcceso::IteradorLinksOrdenadosPorAcceso() {
}

LinkLinkIt::IteradorLinksOrdenadosPorAcceso::~IteradorLinksOrdenadosPorAcceso() {
}

bool LinkLinkIt::IteradorLinksOrdenadosPorAcceso::HayMas() {
	return false;
}

const Link& LinkLinkIt::IteradorLinksOrdenadosPorAcceso::LinkActual() {
	return "";
}

const Categoria& LinkLinkIt::IteradorLinksOrdenadosPorAcceso::CategoriaLinkActual() {
	return "";
}

int LinkLinkIt::IteradorLinksOrdenadosPorAcceso::AccesosRecientesLinkActual() {
	return 0;
}

void LinkLinkIt::IteradorLinksOrdenadosPorAcceso::Avanzar() {
}
