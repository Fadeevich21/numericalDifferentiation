#include <iostream>
#include <windows.h>
#include "test.hpp"

//-V:using:3549
//-V:using:2575

//-V:test_:3549
//-V:test_:2575

using namespace std;
using namespace test;

void test_();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Привет, Мир!" << endl << endl;

	test_();

	return 0;
}

void test_()
{
	test_variantExampleMethodolicalManual_step02();
	test_variantExampleMethodolicalManual_step01();

	test_variant10_step02();
	test_variant10_step01();

	test_variant22_step02();
	test_variant22_step01();

	test_getExactResult_variant22();
	test_getExactResult_variant10();
}
