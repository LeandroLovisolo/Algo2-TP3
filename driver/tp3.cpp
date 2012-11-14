#include "Driver.h"
#include "aed2_tests.h"
#include "../DiccTrie.h"

void trieDefineCorrectamente() {
	DiccTrie<String> lala;
	lala.Definir("lapala", "esto!");
	ASSERT_EQ(lala.Obtener("lapala"), "esto!");
}

void driverCtor() {
	Driver d;
}

void driverPuedeAgregarCategorias() {
	Driver d;
    /**
     * cat1
     *  |- cat2
     *  \- cat3
     *      \- cat4
     */
    d.nuevoArbol("cat1");
    d.agregarCategoria("cat1","cat2");
    d.agregarCategoria("cat1","cat3");
    d.agregarCategoria("cat3","cat4");

    ASSERT_EQ(d.cantCategoriasHijas("cat1"), 2);
    ASSERT_EQ(d.cantCategoriasHijas("cat2"), 0);
    ASSERT_EQ(d.cantCategoriasHijas("cat3"), 1);
}


int main(void) {
    RUN_TEST(driverCtor);
    RUN_TEST(driverPuedeAgregarCategorias);
    RUN_TEST(trieDefineCorrectamente);
	return 0;
}
