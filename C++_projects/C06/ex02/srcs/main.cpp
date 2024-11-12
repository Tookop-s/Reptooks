#include "Base.hpp"

void testIdentify()
{
	std::cout << std::endl << _EMMERALD << "Testing identify" << _END << std::endl;
	Base *a = new A();
	Base *b = new B();
	Base *c = new C();

	identify(a);
	identify(b);
	identify(c);

	identify(*a);
	identify(*b);
	identify(*c);

	delete a;
	delete b;
	delete c;
}

void testNull()
{
	std::cout << std::endl << _EMMERALD << "Testing null pointers" << _END << std::endl;
	Base *a = NULL;
	Base *b = NULL;
	Base *c = NULL;

	identify(a);
	identify(b);
	identify(c);

	identify(*a);
	identify(*b);
	identify(*c);
}

void testGenerateIdentify()
{
	std::cout << std::endl << _EMMERALD << "Testing generate and identify" << _END << std::endl;
	for (int i = 0; i < 12; i++)
	{
		Base *ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
}

int main() 
{
	srand(time(0));

	testIdentify();
	testNull();
	testGenerateIdentify();
	return 0;
}