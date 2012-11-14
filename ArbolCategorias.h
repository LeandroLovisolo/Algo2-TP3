#ifndef ARBOLCATEGORIAS_H_
#define ARBOLCATEGORIAS_H_

#include "driver/Tipos.h"

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

	ArbolCategorias();
	ArbolCategorias(const Categoria&);
	void agregarCategoria(const Categoria& c, const Categoria& h);
	Categoria& raiz();
	int id(const Categoria&);
	IteradorCategoriasHijas categoriasHijas(const Categoria& c);
	virtual ~ArbolCategorias();
};

#endif /* ARBOLCATEGORIAS_H_ */
