
template<class T>
DiccTrie<T>::DiccTrie() : raiz() {
	this->cantidadClaves = 0;
}

//template<class T>
//DiccTrie<T>::~DiccTrie() {
//	raiz.hijos.~Arreglo();
//}

template<class T>
void DiccTrie<T>::Definir(const Categoria &c, const T& s) {
	estr_nodo *actual = &this->raiz;
	for(Nat i=0;i<c.size();i++) {
		if(actual->hijos[c[i]] == 0){
			estr_nodo *nuevoNodo = new estr_nodo();
			actual->hijos[c[i]] = nuevoNodo;
		}
		actual = actual->hijos[c[i]];
	}
	actual->significado = new T(s);
	T * tempSig = actual->significado;
	this->cantidadClaves++;
}

template<class T>
T DiccTrie<T>::Obtener(const Categoria &c) {
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
