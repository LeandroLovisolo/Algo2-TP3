#include "LinkLinkIt.h"

LinkLinkIt::LinkLinkIt(ArbolCategorias* a) {
}

LinkLinkIt::~LinkLinkIt() {
}

void LinkLinkIt::nuevoLink(const Link& l, const Categoria& c) {
}

void LinkLinkIt::acceso(const Link& l, Fecha f) {
}

int LinkLinkIt::cantLinks(const Categoria& c) {
	return 0;
}

LinkLinkIt::IteradorLinksOrdenadosPorAcceso LinkLinkIt::linksOrdenadosPorAccesos(const Categoria& c) {
	return IteradorLinksOrdenadosPorAcceso();
}

LinkLinkIt::IteradorLinksOrdenadosPorAcceso::IteradorLinksOrdenadosPorAcceso() {
}

LinkLinkIt::IteradorLinksOrdenadosPorAcceso::~IteradorLinksOrdenadosPorAcceso() {
}

bool LinkLinkIt::IteradorLinksOrdenadosPorAcceso::HaySiguiente() {
	return false;
}

const Link& LinkLinkIt::IteradorLinksOrdenadosPorAcceso::SiguienteLink() {
	return "";
}

const Categoria& LinkLinkIt::IteradorLinksOrdenadosPorAcceso::SiguienteCategoria() {
	return "";
}

int LinkLinkIt::IteradorLinksOrdenadosPorAcceso::SiguienteAccesosRecientes() {
	return 0;
}

void LinkLinkIt::IteradorLinksOrdenadosPorAcceso::Avanzar() {
}
