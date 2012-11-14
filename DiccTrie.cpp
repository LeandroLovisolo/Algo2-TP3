
template<class T>
DiccTrie<T>::DiccTrie() : raiz() {
	this->cantidadClaves = 0;
}

//template<class T>
//DiccTrie<T>::~DiccTrie() {
//	raiz.hijos.~Arreglo();
//}

template<class T>
void DiccTrie<T>::Definir(const Arreglo<char> &c, const T& s) {
	estr_nodo *actual = &this->raiz;
	for(Nat i=0;i<c.Tamanho();i++) {
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
T DiccTrie<T>::Obtener(const Arreglo<char> &c) {
	estr_nodo *actual = &this->raiz;
	for(Nat i=0;i<c.Tamanho();i++) {
		actual = actual->hijos[c[i]];
	}
	T * tempSig = actual->significado;
	return *tempSig;
}

template<class T>
const int DiccTrie<T>::CantidadClaves() {
	return this->cantidadClaves;
}
