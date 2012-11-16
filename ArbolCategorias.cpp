#include "ArbolCategorias.h"

ArbolCategorias::ArbolCategorias(const Categoria& c) : categorias() {
	estr_cat nuevaCategoria = estr_cat(1, c);
	categorias.Definir(c, nuevaCategoria);
}

ArbolCategorias::~ArbolCategorias() {

}

void ArbolCategorias::AgregarCategoria(const Categoria& c, const Categoria& h) {
	estr_cat &catPadre = categorias.Obtener(c);
	estr_cat *nuevaCategoria = new estr_cat(categorias.CantidadDeClaves()+1, h);
	categorias.Definir(h, *(nuevaCategoria));
	catPadre.hijos.AgregarRapido(nuevaCategoria);
	estr_cat catPadre2 = categorias.Obtener(c);
}

Categoria& ArbolCategorias::NombreCategoriaRaiz() {
	return this->root.nombre;
}

Nat ArbolCategorias::IdCategoriaPorNombre(const Categoria& c) {
	return categorias.Obtener(c).id;
}

Nat ArbolCategorias::CantidadDeCategorias() {
	return categorias.CantidadDeClaves();
}

ArbolCategorias::IteradorCategoriasHijas ArbolCategorias::CrearIt(const Categoria& c) {
	return IteradorCategoriasHijas(categorias.Obtener(c).hijos);
}

ArbolCategorias::IteradorCategoriasHijas ArbolCategorias::CrearItRaiz() {
	return IteradorCategoriasHijas(categorias.Obtener(NombreCategoriaRaiz()).hijos);
}

ArbolCategorias::IteradorCategoriasHijas ArbolCategorias::CrearItHijos(const IteradorCategoriasHijas& it) {
	return IteradorCategoriasHijas(it.it.Siguiente()->hijos);
}

ArbolCategorias::IteradorCategoriasHijas::IteradorCategoriasHijas(Conj<estr_cat*> &conjHijos) {
	this->it = conjHijos.CrearIt();
}

bool ArbolCategorias::IteradorCategoriasHijas::HayMas() {
	return it.HaySiguiente();
}

const Categoria& ArbolCategorias::IteradorCategoriasHijas::CategoriaActual() {
	return it.Siguiente()->nombre;
}

Nat ArbolCategorias::IteradorCategoriasHijas::IdCategoriaActual() {
	return it.Siguiente()->id;
}

void ArbolCategorias::IteradorCategoriasHijas::Avanzar() {
	it.Avanzar();
}

ArbolCategorias::IteradorCategoriasHijas::~IteradorCategoriasHijas() {
}
