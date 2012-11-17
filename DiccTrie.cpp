template<class T>
DiccTrie<T>::DiccTrie() : raiz(), cantidadDeClaves(0) {
}

template<class T>
void DiccTrie<T>::Definir(const string& c, const T& s) {
	estr_nodo* actual = &this->raiz;
	for(Nat i = 0; i < c.size(); i++) {
		if(actual->hijos[c[i]] == NULL) {
			actual->hijos[c[i]] = new estr_nodo();
		}
		actual = actual->hijos[c[i]];
	}
	actual->significado = new T(s);
	this->cantidadDeClaves++;
}

template<class T>
T& DiccTrie<T>::Obtener(const string &c) {
	estr_nodo* actual = &this->raiz;
	for(Nat i = 0; i < c.size(); i++) {
		actual = actual->hijos[c[i]];
	}
	return *actual->significado;
}

template<class T>
const Nat DiccTrie<T>::CantidadDeClaves() {
	return this->cantidadDeClaves;
}

template<class T>
DiccTrie<T>::estr_nodo::estr_nodo() : significado(NULL), hijos(256) {
	for(Nat i = 0; i < hijos.Tamanho(); i++) {
		hijos.Definir(i, NULL);
	}
}

template<class T>
DiccTrie<T>::estr_nodo::~estr_nodo() {
	if(significado != NULL) delete significado;
	for(Nat i = 0; i < hijos.Tamanho(); i++) {
		if(hijos[i] != NULL) delete hijos[i];
	}
}
