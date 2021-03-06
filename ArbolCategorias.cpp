#include "ArbolCategorias.h"

ArbolCategorias::estr_cat::estr_cat(Nat id, const Categoria &nombre)
		: id(id), nombre(nombre), hijos() {
}

ArbolCategorias::ArbolCategorias(const Categoria& raiz) : categorias() {
	categorias.Definir(raiz, estr_cat(1, raiz));
	this->raiz = &categorias.Obtener(raiz);
}

const Categoria& ArbolCategorias::NombreCategoriaRaiz() const {
	return this->raiz->nombre;
}

void ArbolCategorias::AgregarCategoria(const Categoria& padre, const Categoria& hija) {
	estr_cat& estr_padre = categorias.Obtener(padre);
	categorias.Definir(hija, estr_cat(categorias.CantidadDeClaves() + 1, hija));
	estr_cat& estr_hija = categorias.Obtener(hija);
	estr_padre.hijos.AgregarRapido(&estr_hija);
}

Nat ArbolCategorias::IdCategoriaPorNombre(const Categoria& c) const {
	return categorias.Obtener(c).id;
}

Nat ArbolCategorias::CantidadDeCategorias() const {
	return categorias.CantidadDeClaves();
}

ArbolCategorias::Iterador ArbolCategorias::CrearIt(const Categoria& c) const{
	return Iterador(categorias.Obtener(c).hijos);
}

ArbolCategorias::Iterador ArbolCategorias::CrearItRaiz() const {
	return Iterador(categorias.Obtener(NombreCategoriaRaiz()).hijos);
}

ArbolCategorias::Iterador ArbolCategorias::CrearItHijos(const Iterador& it) const {
	return Iterador(it.it.Siguiente()->hijos);
}

ArbolCategorias::Iterador::Iterador(const Conj<estr_cat*> &conjHijos) {
	this->it = conjHijos.CrearIt();
}

bool ArbolCategorias::Iterador::HayMas() const {
	return it.HaySiguiente();
}

const Categoria& ArbolCategorias::Iterador::CategoriaActual() const {
	return it.Siguiente()->nombre;
}

Nat ArbolCategorias::Iterador::IdCategoriaActual() const {
	return it.Siguiente()->id;
}

void ArbolCategorias::Iterador::Avanzar() {
	it.Avanzar();
}
