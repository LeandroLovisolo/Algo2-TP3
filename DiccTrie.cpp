template<class T>
DiccTrie<T>::DiccTrie() : raiz() {
	this->cantidadDeClaves = 0;
}

template<class T>
void DiccTrie<T>::Definir(const string &c, const T& s) {
	estr_nodo *actual = &this->raiz;
	for(Nat i=0;i<c.size();i++) {
		if(actual->hijos[Nat(c[i])] == 0){
			estr_nodo *nuevoNodo = new estr_nodo();
			actual->hijos[Nat(c[i])] = nuevoNodo;
		}
		actual = actual->hijos[Nat(c[i])];
	}
	actual->significado = new T(s);

	this->cantidadDeClaves++;
}

template<class T>
T& DiccTrie<T>::Obtener(const string &c) {
	estr_nodo *actual = &this->raiz;
	for(Nat i=0;i<c.size();i++) {
		actual = actual->hijos[c[i]];
	}
	T * tempSig = actual->significado;
	return *tempSig;
}

template<class T>
const Nat DiccTrie<T>::CantidadDeClaves() {
	return this->cantidadDeClaves;
}

template<class T>
DiccTrie<T>::estr_nodo::estr_nodo() : significado(0), hijos(256) {
	for(Nat i=0;i<hijos.Tamanho();i++) {
		hijos.Definir(i, 0);
	}
}

template<class T>
DiccTrie<T>::estr_nodo::~estr_nodo() {
	if(significado != 0) {
		delete significado;
	}
	for(Nat i=0;i<hijos.Tamanho();i++) {
		if(hijos[i] != 0) {
			delete hijos[i];
		}
	}
}
