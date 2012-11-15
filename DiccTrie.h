#ifndef DICCTRIE_INCLUDED
#define DICCTRIE_INCLUDED

#include "modulos/aed2.h"

template<class T> class DiccTrie{
private:
	class estr_nodo{
	public:
		T *significado;
		Arreglo<estr_nodo*> hijos;
		estr_nodo() : significado(0), hijos(256) {
			for(Nat i=0;i<hijos.Tamanho();i++) {
				hijos.Definir(i, 0);
			}
		}
		~estr_nodo() {
			if(significado != 0) {
				delete significado;
			}
			for(Nat i=0;i<hijos.Tamanho();i++) {
				if(hijos[i] != 0) {
					delete hijos[i];
				}
			}
		}
	};
	int cantidadClaves;
	estr_nodo raiz;
public:
	DiccTrie();
	void Definir(const Categoria &c, const T& s);
	T Obtener(const Categoria &c);
	const int CantidadClaves();
};

#include "DiccTrie.cpp"

#endif
