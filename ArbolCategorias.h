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
		Conj<estr_cat*>::const_Iterador it;

		Iterador(const Conj<estr_cat*> &conjHijos);
		friend class ArbolCategorias;

	public:
		bool HayMas() const;
		const Categoria& CategoriaActual() const;
		Nat IdCategoriaActual() const;
		void Avanzar();
	};

	ArbolCategorias(const Categoria&);
	const Categoria& NombreCategoriaRaiz() const;
	void AgregarCategoria(const Categoria& padre, const Categoria& hija);
	Nat IdCategoriaPorNombre(const Categoria&) const;
	Nat CantidadDeCategorias() const;
	Iterador CrearIt(const Categoria& c) const;
	Iterador CrearItRaiz() const;
	Iterador CrearItHijos(const Iterador& it) const;

};

#endif /* ARBOLCATEGORIAS_H_ */
