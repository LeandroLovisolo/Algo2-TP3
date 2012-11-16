#include "ArbolCategorias.h"

ArbolCategorias::estr_cat::estr_cat(Nat id, const Categoria &nombre) : id(id), nombre(nombre), hijos() {
}

ArbolCategorias::estr_cat::estr_cat(const estr_cat &e) : id(e.id), nombre(e.nombre), hijos(e.hijos) {
}

ArbolCategorias::ArbolCategorias(const Categoria& c) : raiz(1, c), categorias() {
	categorias.Definir(c, raiz);
}

ArbolCategorias::~ArbolCategorias() {
}

void ArbolCategorias::AgregarCategoria(const Categoria& c, const Categoria& h) {
	estr_cat &catPadre = categorias.Obtener(c);
	estr_cat *nuevaCategoria = new estr_cat(categorias.CantidadDeClaves() + 1, h);
	categorias.Definir(h, *(nuevaCategoria));
	catPadre.hijos.AgregarRapido(nuevaCategoria);
	estr_cat catPadre2 = categorias.Obtener(c);
}

Categoria& ArbolCategorias::NombreCategoriaRaiz() {
	return this->raiz.nombre;
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

bool ArbolCategorias::IteradorCategoriasHijas::HayMas() const {
	return it.HaySiguiente();
}

const Categoria& ArbolCategorias::IteradorCategoriasHijas::CategoriaActual() const {
	return it.Siguiente()->nombre;
}

Nat ArbolCategorias::IteradorCategoriasHijas::IdCategoriaActual() const {
	return it.Siguiente()->id;
}

void ArbolCategorias::IteradorCategoriasHijas::Avanzar() {
	it.Avanzar();
}

ArbolCategorias::IteradorCategoriasHijas::~IteradorCategoriasHijas() {
}
