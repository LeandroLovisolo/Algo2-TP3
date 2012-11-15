#include "ArbolCategorias.h"

ArbolCategorias::ArbolCategorias(const Categoria& c) : categorias() {
	estr_cat nuevaCategoria = estr_cat(1, c);
	categorias.Definir(c, nuevaCategoria);
}

ArbolCategorias::~ArbolCategorias() {

}

void ArbolCategorias::agregarCategoria(const Categoria& c, const Categoria& h) {
	estr_cat &catPadre = categorias.Obtener(c);
	estr_cat *nuevaCategoria = new estr_cat(categorias.CantidadClaves()+1, h);
	categorias.Definir(h, *(nuevaCategoria));
	catPadre.hijos.AgregarRapido(nuevaCategoria);
	estr_cat catPadre2 = categorias.Obtener(c);
}

Categoria& ArbolCategorias::raiz() {
	return this->root.nombre;
}

int ArbolCategorias::id(const Categoria& c) {
	return categorias.Obtener(c).id;
}

ArbolCategorias::IteradorCategoriasHijas ArbolCategorias::categoriasHijas(const Categoria& c) {
	return IteradorCategoriasHijas(categorias.Obtener(c).hijos); //Se puede devolver asi?
}

ArbolCategorias::IteradorCategoriasHijas::IteradorCategoriasHijas(Conj<estr_cat*> &conjHijos) {
	this->it = conjHijos.CrearIt();
}

bool ArbolCategorias::IteradorCategoriasHijas::HaySiguiente() {
	return it.HaySiguiente();
}

const Categoria& ArbolCategorias::IteradorCategoriasHijas::Siguiente() {
	return it.Siguiente()->nombre;
}

void ArbolCategorias::IteradorCategoriasHijas::Avanzar() {
	it.Avanzar();
}

ArbolCategorias::IteradorCategoriasHijas::~IteradorCategoriasHijas() {
}
