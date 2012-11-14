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
			for(int i=0;i<256;i++) {
				hijos.Definir(i, 0);
			}
		}
		//~estr_nodo() {
		//	cout << "Borrando significado " << *significado << endl;
		//	delete significado;
		//	hijos.~Arreglo();
		//}
	};
	int cantidadClaves;
	estr_nodo raiz;
public:
	DiccTrie();
	void Definir(const Categoria &c, const T& s);
	T Obtener(const Categoria &c);
	const int CantidadClaves();
	//~DiccTrie();
};

#include "DiccTrie.cpp"

#endif
