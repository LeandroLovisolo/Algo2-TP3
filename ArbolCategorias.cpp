#include "ArbolCategorias.h"

ArbolCategorias::estr_cat::estr_cat(Nat id, const Categoria &nombre)
		: id(id), nombre(nombre), hijos() {
}

ArbolCategorias::ArbolCategorias(const Categoria& raiz) : categorias() {
	categorias.Definir(raiz, estr_cat(1, raiz));
	this->raiz = &categorias.Obtener(raiz);
}

Categoria& ArbolCategorias::NombreCategoriaRaiz() {
	return this->raiz->nombre;
}

void ArbolCategorias::AgregarCategoria(const Categoria& padre, const Categoria& hija) {
	estr_cat& estr_padre = categorias.Obtener(padre);
	categorias.Definir(hija, estr_cat(categorias.CantidadDeClaves() + 1, hija));
	estr_cat& estr_hija = categorias.Obtener(hija);
	estr_padre.hijos.AgregarRapido(&estr_hija);
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
