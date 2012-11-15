template<class T>
DiccTrie<T>::DiccTrie() : raiz() {
	this->cantidadClaves = 0;
}

template<class T>
void DiccTrie<T>::Definir(const Categoria &c, const T& s) {
	estr_nodo *actual = &this->raiz;
	for(Nat i=0;i<c.size();i++) {
		if(actual->hijos[Nat(c[i])] == 0){
			estr_nodo *nuevoNodo = new estr_nodo();
			actual->hijos[Nat(c[i])] = nuevoNodo;
		}
		actual = actual->hijos[Nat(c[i])];
	}
	actual->significado = new T(s);

	this->cantidadClaves++;
}

template<class T>
T& DiccTrie<T>::Obtener(const Categoria &c) {
	estr_nodo *actual = &this->raiz;
	for(Nat i=0;i<c.size();i++) {
		actual = actual->hijos[c[i]];
	}
	T * tempSig = actual->significado;
	return *tempSig;
}

template<class T>
const int DiccTrie<T>::CantidadClaves() {
	return this->cantidadClaves;
}
