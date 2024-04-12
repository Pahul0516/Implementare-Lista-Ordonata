#include "Iterator.h"
#include "LO.h"

#include <iostream>
using namespace std;

#include <exception>

// complexitate teta de 1
LO::LO(Relatie r) {
	/* de adaugat */
	this->relatie = r;
}

// complexitate teta de n
// returnare dimensiune
int LO::dim() const {
	/* de adaugat */
	int lungime = 0;
	nod* cop;
	cop = this->start;
	while (cop != NULL)
	{
		lungime++;
		cop = cop->urmator;
	}
	return lungime;
}

// complexitate teta de 1
// verifica daca LO e vida
bool LO::vida() const {
	/* de adaugat */
	if (this->dim() == 0)
		return true;
	else
		return false;
}

// complexitate teta de 1
// prima pozitie din LO
Iterator LO::prim() const {
	/* de adaugat */
	return Iterator(*this);
}

// complexitate teta de 1
// returnare element de pe pozitia curenta
// arunca exceptie daca poz nu e valid
TElement LO::element(Iterator poz) const {
	/* de adaugat */
	if (poz.valid() == true)
		return poz.de_parcurs->componenta;
	else
		throw exception();

}

// complexitate O(n)
//sterge element de pe o pozitie poz si returneaza elementul sters
//dupa stergere poz e pozitionat pe elementul de dupa cel sters
//arunca exceptie daca poz nu e valid
TElement LO::sterge(Iterator& poz) {
	/* de adaugat */
	TElement de_returnat = -1;
	if (poz.valid())
		de_returnat = poz.de_parcurs->componenta;
	else
		throw exception();
	nod* cop = this->start;


	// daca e primul element
	if (cop->componenta == poz.de_parcurs->componenta)
	{
		poz.de_parcurs = poz.de_parcurs->urmator;
		this->start = this->start->urmator;
		return de_returnat;
	}


	while (cop != NULL)
	{
		if (cop->urmator->componenta == poz.de_parcurs->componenta)
		{
			cop->urmator = poz.de_parcurs->urmator;
			poz.de_parcurs = poz.de_parcurs->urmator;
			break;
		}
		cop = cop->urmator;
	}
	return de_returnat;
}

// complexitate O(n)
// cauta element si returneaza prima pozitie pe care apare (sau iterator invalid)
Iterator LO::cauta(TElement e) const{
	/* de adaugat */
	Iterator it = this->prim();
	while (it.valid())
	{
		if (it.de_parcurs->componenta == e)
		{
			return it;
		}
		it.urmator();
	}
	return it;
}


// complexitate O(n)
// adaugare element in LO
void LO::adauga(TElement e) {
	/* de adaugat */
	nod* p = new nod;
	p->componenta = e;
	p->urmator = NULL;
	if (dim() == 0 || dim() == 1)
	{
		if (dim()==0)
			this->start = p;
		else 
			if (relatie(this->start->componenta, e) == true)
			{
				this->start->urmator = p;
			}
			else
			{
				nod* cop = this->start;
				p->urmator = cop;
				this->start = p;
			}
	}
	else
	{
		bool ok = true;
		nod* cop;
		cop = this->start;

		while (cop != nullptr) // daca e vorba sa adaugam pe prima pozitie
		{
			if (relatie(e, cop->componenta) == false)
				ok = false;
			cop = cop->urmator;
		}
		if (ok == true)
		{
			nod* cop2;
			cop2 = this->start;
			p->urmator = cop2;
			this->start = p;
			return;
		}

		cop = this->start;
		while (cop != nullptr)
		{
			TElement actual = cop->componenta;
			TElement urmator = cop->urmator->componenta;
			if (relatie(actual, e) == true && relatie(urmator, e) == false) // daca e vorba sa adaugam undeva in mijlocul listei
			{
				p->urmator = cop->urmator;
				cop->urmator = p;
				break;
			}
			cop = cop->urmator;
			if (cop->urmator == NULL) /// daca e vorba sa adaugam pe ultima pozitie
			{
				cop->urmator = p;
				break;
			}
		}
	}

	
}


// complexitate teta de n
//destructor
LO::~LO() {
	/* de adaugat */
	nod* cop = this->start;
	while (cop != nullptr)
	{
		nod* cop2 = cop;
		cop = cop->urmator;
		delete cop2;
	}
}
