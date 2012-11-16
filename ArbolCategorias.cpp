#include "ArbolCategorias.h"

ArbolCategorias::estr_cat::estr_cat(Nat id, const Categoria &nombre) : id(id), nombre(nombre), hijos() {
}

ArbolCategorias::ArbolCategorias(const Categoria& c) : categorias() {
	categorias.Definir(c, estr_cat(1, c));
	raiz = &categorias.Obtener(c);
}

ArbolCategorias::~ArbolCategorias() {
}

void ArbolCategorias::AgregarCategoria(const Categoria& c, const Categoria& h) {
	estr_cat& estr_padre = categorias.Obtener(c);
	categorias.Definir(h, estr_cat(categorias.CantidadDeClaves() + 1, h));
	estr_cat& estr_hija = categorias.Obtener(h);
	estr_padre.hijos.AgregarRapido(&estr_hija);
}

Categoria& ArbolCategorias::NombreCategoriaRaiz() {
	return this->raiz->nombre;
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
