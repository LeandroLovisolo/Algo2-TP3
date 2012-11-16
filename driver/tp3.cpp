#include "Driver.h"
#include "aed2_tests.h"
#include "../DiccTrie.h"

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

void trieDefineYObtieneCorrectamente() {
	DiccTrie<String> d;
	/**
	 * raíz
	 *  |- f
	 *  |  \- o
	 *  |     \- o => bar
	 *  \- c
	 *     \- a
	 *        |- s
	 *        |  \- a => house
	 *        \- c
	 *           \- a => crap
	 */

	ASSERT_EQ(d.CantidadDeClaves(), 0);

	d.Definir("foo", "bar");
	ASSERT_EQ(d.CantidadDeClaves(), 1);

	d.Definir("casa", "house");
	ASSERT_EQ(d.CantidadDeClaves(), 2);

	d.Definir("caca", "crap");
	ASSERT_EQ(d.CantidadDeClaves(), 3);

	ASSERT_EQ(d.Obtener("foo"), "bar");
	ASSERT_EQ(d.Obtener("casa"), "house");
	ASSERT_EQ(d.Obtener("caca"), "crap");
}

int main(void) {
    RUN_TEST(driverCtor);
    RUN_TEST(driverPuedeAgregarCategorias);
    RUN_TEST(trieDefineYObtieneCorrectamente);
	return 0;
}
