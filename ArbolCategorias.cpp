#include "ArbolCategorias.h"

ArbolCategorias::ArbolCategorias(const Categoria& c) : categorias() {
	estr_cat *nuevaCategoria = new estr_cat(1, c);
	categorias.Definir(c, (*nuevaCategoria));
}

ArbolCategorias::~ArbolCategorias() {

}

void ArbolCategorias::agregarCategoria(const Categoria& c, const Categoria& h) {
	estr_cat catPadre = categorias.Obtener(c);
	estr_cat *nuevaCategoria = new estr_cat(categorias.CantidadClaves()+1, h);
	categorias.Definir(h, *(nuevaCategoria));
	catPadre.hijos.AgregarRapido(nuevaCategoria);
}

Categoria& ArbolCategorias::raiz() {
	return this->root.nombre;
}

int ArbolCategorias::id(const Categoria& c) {
	return categorias.Obtener(c).id;
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
