#ifndef LINKLINKIT_H_
#define LINKLINKIT_H_

#include "driver/Tipos.h"
#include "ArbolCategorias.h"

class LinkLinkIt {
public:

	class IteradorLinksOrdenadosPorAcceso {
		IteradorLinksOrdenadosPorAcceso();
		friend class LinkLinkIt;

	public:
		bool HaySiguiente();
		const Link& SiguienteLink();
		const Categoria& SiguienteCategoria();
		int SiguienteAccesosRecientes();
		void Avanzar();
		virtual ~IteradorLinksOrdenadosPorAcceso();
	};

	LinkLinkIt(ArbolCategorias*);
	void nuevoLink(const Link&, const Categoria&);
	void acceso(const Link&, Fecha);
	int cantLinks(const Categoria&);
	IteradorLinksOrdenadosPorAcceso linksOrdenadosPorAccesos(const Categoria&);
	virtual ~LinkLinkIt();
};

#endif /* LINKLINKIT_H_ */
