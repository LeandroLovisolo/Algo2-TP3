#ifndef ARBOLCATEGORIAS_H_
#define ARBOLCATEGORIAS_H_

#include "driver/Tipos.h"
#include "modulos/aed2.h"
#include "DiccTrie.h"

class ArbolCategorias {
	class estr_cat {
	public:
		Nat id;
		Categoria nombre;
		Conj<estr_cat*> hijos;

		estr_cat() {} //como hago que no se inicializen las cosas?
		estr_cat(Nat id, const Categoria &nombre) : id(id), nombre(nombre), hijos() {}
		estr_cat(const estr_cat &aCopiar) : id(aCopiar.id), nombre(aCopiar.nombre), hijos(aCopiar.hijos) {}
	};

	estr_cat root;
	DiccTrie<estr_cat> categorias;

public:
	class IteradorCategoriasHijas {
		Conj<estr_cat*>::Iterador it;

		IteradorCategoriasHijas(Conj<estr_cat*> &conjHijos);
		friend class ArbolCategorias;

	public:
		bool HayMas();
		const Categoria& CategoriaActual();
		Nat IdCategoriaActual();
		void Avanzar();
		virtual ~IteradorCategoriasHijas();
	};

	ArbolCategorias(); // No se deberia crear sin raiz
	ArbolCategorias(const Categoria&);
	void AgregarCategoria(const Categoria& c, const Categoria& h);
	Categoria& NombreCategoriaRaiz();
	Nat IdCategoriaPorNombre(const Categoria&);
	Nat CantidadDeCategorias();
	IteradorCategoriasHijas CrearIt(const Categoria& c);
	IteradorCategoriasHijas CrearItRaiz();
	IteradorCategoriasHijas CrearItHijos(const IteradorCategoriasHijas& it);
	virtual ~ArbolCategorias();

};

#endif /* ARBOLCATEGORIAS_H_ */
