#include "Iterator.h"
#include "LO.h"

#include <iostream>
using namespace std;

// complexitate teta de 1
Iterator::Iterator(const LO& lo) : lo(lo){
	/* de adaugat */
	prim();
}

// complexitate teta de 1
void Iterator::prim(){
	/* de adaugat */
	this->de_parcurs = lo.start;
}

// complexitate teta de 1
void Iterator::urmator(){
	/* de adaugat */
	if (this->valid())
		this->de_parcurs = this->de_parcurs->urmator;
	else
		throw exception();
}

// complexitate O(n)
void Iterator::anterior()
{
	Iterator aux = this->lo.prim();
	if (this->de_parcurs!=aux.de_parcurs)
		while (aux.de_parcurs!=nullptr)
		{
			if (aux.de_parcurs->urmator == this->de_parcurs)
			{
				this->de_parcurs = aux.de_parcurs;
				break;
			}
			aux.de_parcurs = aux.de_parcurs->urmator;
		}
	else
		throw exception();
}


// complexitate teta de 1
bool Iterator::valid() const{
	/* de adaugat */
	if (this->de_parcurs != nullptr)
		return true;
	else 
		return false;
}

// complexitate teta de 1
TElement Iterator::element() const{
	/* de adaugat */
	if (valid())
		return this->de_parcurs->componenta;
}


