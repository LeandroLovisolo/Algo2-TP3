#include "ArbolCategorias.h"

ArbolCategorias::ArbolCategorias(const Categoria& c) {
}

ArbolCategorias::~ArbolCategorias() {
}

void ArbolCategorias::agregarCategoria(const Categoria& c, const Categoria& h) {
}

Categoria& ArbolCategorias::raiz() {
	Categoria c("");
	return c;
}

int ArbolCategorias::id(const Categoria& c) {
	return 0;
}

ArbolCategorias::IteradorCategoriasHijas ArbolCategorias::categoriasHijas(const Categoria& c) {
	return ArbolCategorias::IteradorCategoriasHijas();
}

ArbolCategorias::IteradorCategoriasHijas::IteradorCategoriasHijas() {
}

bool ArbolCategorias::IteradorCategoriasHijas::HaySiguiente() {
	return false;
}

const Categoria& ArbolCategorias::IteradorCategoriasHijas::Siguiente() {
	return "";
}

void ArbolCategorias::IteradorCategoriasHijas::Avanzar() {
}

ArbolCategorias::IteradorCategoriasHijas::~IteradorCategoriasHijas() {
}
