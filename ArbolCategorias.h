#ifndef ARBOLCATEGORIAS_H_
#define ARBOLCATEGORIAS_H_

#include "driver/Tipos.h"
#include "modulos/aed2.h"
#include "DiccTrie.h"

class ArbolCategorias {
public:

	class IteradorCategoriasHijas {
		IteradorCategoriasHijas();
		friend class ArbolCategorias;

	public:
		bool HaySiguiente();
		const Categoria& Siguiente();
		void Avanzar();
		virtual ~IteradorCategoriasHijas();
	};

	ArbolCategorias(); // No se deberia crear sin raiz
	ArbolCategorias(const Categoria&);
	void agregarCategoria(const Categoria& c, const Categoria& h);
	Categoria& raiz();
	int id(const Categoria&);
	IteradorCategoriasHijas categoriasHijas(const Categoria& c);
	virtual ~ArbolCategorias();

private:

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
};

#endif /* ARBOLCATEGORIAS_H_ */
