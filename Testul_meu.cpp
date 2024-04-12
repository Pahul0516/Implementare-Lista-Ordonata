#include <assert.h>

#include "LO.h"
#include "Iterator.h"

#include <exception>
using namespace std;

bool r(TElement cheie1, TElement cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

void testAll_Testul_meu() {
    LO lo = LO(r);
    lo.adauga(1);
    lo.adauga(2);
    lo.adauga(3);
    lo.adauga(4);
    Iterator it = lo.prim();

    it.urmator();
    it.anterior();
    assert(it.element() == 1);

    it.urmator();
    it.urmator();
    it.anterior();
    assert(it.element() == 2);
    it.anterior();
    assert(it.element() == 1);
    try {
        it.anterior();
        assert(false);
    }
    catch (exception&)
    {
        assert(true);
    }
    it.urmator();
    it.urmator();
    it.urmator();
    it.urmator();
    it.anterior();
    assert(it.element() == 4);
}

