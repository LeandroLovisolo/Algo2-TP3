#ifndef ARBOLCATEGORIAS_H_
#define ARBOLCATEGORIAS_H_

#include "modulos/aed2.h"
#include "Tipos.h"
#include "DiccTrie.h"

class ArbolCategorias {
	struct estr_cat {
		Nat id;
		Categoria nombre;
		Conj<estr_cat*> hijos;

		estr_cat(Nat id, const Categoria& nombre);
	};

	estr_cat* raiz;
	DiccTrie<estr_cat> categorias;

public:
	class Iterador {
		Conj<estr_cat*>::Iterador it;

		Iterador(Conj<estr_cat*> &conjHijos);
		friend class ArbolCategorias;

	public:
		bool HayMas() const;
		const Categoria& CategoriaActual() const;
		Nat IdCategoriaActual() const;
		void Avanzar();
	};

	ArbolCategorias(); // No se deberia crear sin raiz
	ArbolCategorias(const Categoria&);
	Categoria& NombreCategoriaRaiz();
	void AgregarCategoria(const Categoria& padre, const Categoria& hija);
	Nat IdCategoriaPorNombre(const Categoria&);
	Nat CantidadDeCategorias();
	Iterador CrearIt(const Categoria& c);
	Iterador CrearItRaiz();
	Iterador CrearItHijos(const Iterador& it);

};

#endif /* ARBOLCATEGORIAS_H_ */
