#ifndef DICCTRIE_H_
#define DICCTRIE_H_

#include "modulos/aed2.h"

template<class T>
class DiccTrie {
	struct estr_nodo {
		T *significado;
		Arreglo<estr_nodo*> hijos;

		estr_nodo();
		~estr_nodo();
	};

	Nat cantidadDeClaves;
	estr_nodo raiz;

public:
	DiccTrie();
	void Definir(const string &c, const T& s);
	T& Obtener(const string &c);
	const Nat CantidadDeClaves();
};

#include "DiccTrie.cpp"

#endif /* DICCTRIE_H_ */
