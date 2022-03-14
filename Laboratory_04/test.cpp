#include "test.hpp"

//-V:using:3549
//-V:using:2575

using namespace cauchyProblem;

namespace test
{

	void test_MethodEulerFirstOrder(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0, const string &fname)
	{
		cout << "Test name: test_MethodEulerFirstOrder" << endl << endl;

		SolveCauchyProblem solver(new MethodEulerFirstOrder(maxOrderDerivative, limitLeft, limitRight, function, y0));
		cout << "result = " << solver.getResult() << endl << endl;

		cout << "delta = " << abs(solver.getResult() + 1.86466L) << endl;
		cout << "Delta = " << abs(solver.getResult() + 1.86466L) / 1.86466L * 100 << endl;

		cout << "Write Table:" << endl;
		solver.writeTableResult();
		solver.writeTableResultInFile("MethodEulerFirstOrder_" + fname);
		cout << endl;
	}

	void test_MethodEulerSecondOrder(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0, const BaseType &alpha, const string &fname)
	{
		cout << "Test name: test_MethodEulerSecondOrder" << endl << endl;

		SolveCauchyProblem solver(new MethodEulerSecondOrder(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha));

		cout << "alpha = " << alpha << endl;
		cout << "result = " << solver.getResult() << endl << endl;

		cout << "delta = " << abs(solver.getResult() + 1.86466L) << endl;
		cout << "Delta = " << abs(solver.getResult() + 1.86466L) / 1.86466L * 100 << endl;

		cout << "Write Table:" << endl;
		solver.writeTableResult();
		solver.writeTableResultInFile("MethodEulerSecondOrder_" + fname);
		cout << endl;
	}

	void test_MethodEulerCauchy(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0, const string &fname)
	{
		cout << "Test name: test_MethodEulerCauchy" << endl << endl;

		SolveCauchyProblem solver(new MethodEulerCauchy(maxOrderDerivative, limitLeft, limitRight, function, y0));

		cout << "alpha = " << 1.0L << endl;
		cout << "result = " << solver.getResult() << endl << endl;

		cout << "delta = " << abs(solver.getResult() + 1.86466L) << endl;
		cout << "Delta = " << abs(solver.getResult() + 1.86466L) / 1.86466L * 100 << endl;

		cout << "Write Table:" << endl;
		solver.writeTableResult();
		solver.writeTableResultInFile("MethodEulerCauchy_" + fname);
		cout << endl;
	}

	void test_MethodEulerModified(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0, const string &fname)
	{
		cout << "Test name: test_MethodEulerModified" << endl << endl;

		SolveCauchyProblem solver(new MethodEulerModified(maxOrderDerivative, limitLeft, limitRight, function, y0));

		cout << "alpha = " << 0.5L << endl;
		cout << "result = " << solver.getResult() << endl << endl;

		cout << "delta = " << abs(solver.getResult() + 1.86466L) << endl;
		cout << "Delta = " << abs(solver.getResult() + 1.86466L) / 1.86466L * 100 << endl;

		cout << "Write Table:" << endl;
		solver.writeTableResult();
		solver.writeTableResultInFile("MethodEulerModified_" + fname);
		cout << endl;
	}

	void test_MethodRungeKutta(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0, const string &fname)
	{
		cout << "Test name: test_MethodRungeKutta" << endl << endl;

		SolveCauchyProblem solver(new MethodRungeKutta(maxOrderDerivative, limitLeft, limitRight, function, y0));

		cout << "result = " << solver.getResult() << endl << endl;

		cout << "delta = " << abs(solver.getResult() + 1.86466L) << endl;
		cout << "Delta = " << abs(solver.getResult() + 1.86466L) / 1.86466L * 100 << endl;

		cout << "Write Table:" << endl;
		solver.writeTableResult();
		solver.writeTableResultInFile("MethodRungeKutta_" + fname);
		cout << endl;
	}

	void test_variant(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0, const BaseType &alpha, const string &fname)
	{
		cout << "####################################" << endl;
		test_MethodEulerFirstOrder(maxOrderDerivative, limitLeft, limitRight, function, y0, fname);

		cout << "####################################" << endl;
		test_MethodEulerSecondOrder(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha, fname);

		cout << "####################################" << endl;
		test_MethodEulerCauchy(maxOrderDerivative, limitLeft, limitRight, function, y0, fname);

		cout << "####################################" << endl;
		test_MethodEulerModified(maxOrderDerivative, limitLeft, limitRight, function, y0, fname);

		cout << "####################################" << endl;
		test_MethodRungeKutta(maxOrderDerivative, limitLeft, limitRight, function, y0, fname);

		cout << "####################################" << endl;
		cout << endl;
	}

	void test_variantExampleMethodolicalManual_step02()
	{
		cout << "Test name: test_variantExampleMethodolicalManual_step02" << endl << endl;

		string fname = "test_variantExampleMethodolicalManual_step02.csv";
		size_t maxOrderDerivative = 5;
		BaseType limitLeft = 1;
		BaseType limitRight = 2;
		Function function = [](const BaseType &x, const BaseType &y) -> BaseType
		{
			return 3.0L * x * x;
		};
		BaseType y0 = 3;
		BaseType alpha = 0.667L;

		test_variant(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha, fname);
	}

	void test_variant10_step02()
	{
		cout << "Test name: test_variant10_step02" << endl << endl;

		string fname = "test_variant10_step02.csv";
		size_t maxOrderDerivative = 5;
		BaseType limitLeft = 0;
		BaseType limitRight = 1;
		Function function = [](const BaseType &x, const BaseType &y) -> BaseType
		{
			return (2 * x * (x - y)) / (1 + x * x);
		};
		BaseType y0 = 2.0L / 3.0L;
		BaseType alpha = 0.667L;

		test_variant(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha, fname);
	}

	void test_variantExampleMethodolicalManual_step01()
	{
		cout << "Test name: test_variantExampleMethodolicalManual_step01" << endl << endl;

		string fname = "test_variantExampleMethodolicalManual_step01.csv";
		size_t maxOrderDerivative = 10;
		BaseType limitLeft = 1;
		BaseType limitRight = 2;
		Function function = [](const BaseType &x, const BaseType &y) -> BaseType
		{
			return 3.0L * x * x;
		};
		BaseType y0 = 3;
		BaseType alpha = 0.667L;

		test_variant(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha, fname);
	}

	void test_variant10_step01()
	{
		cout << "Test name: test_variant10_step01" << endl << endl;

		string fname = "test_variant10_step01.csv";
		size_t maxOrderDerivative = 10;
		BaseType limitLeft = 0;
		BaseType limitRight = 1;
		Function function = [](const BaseType &x, const BaseType &y) -> BaseType
		{
			return (2 * x * (x - y)) / (1 + x * x);
		};
		BaseType y0 = 2.0L / 3.0L;
		BaseType alpha = 0.667L;

		test_variant(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha, fname);
	}

	void test_variant22_step02()
	{
		cout << "Test name: test_variant22_step02" << endl << endl;

		string fname = "test_variant22_step02.csv";
		size_t maxOrderDerivative = 10;
		BaseType limitLeft = 0;
		BaseType limitRight = 2;
		Function function = [](const BaseType &x, const BaseType &y) -> BaseType
		{
			return (-x * x * x - x * y);
		};
		BaseType y0 = 3;
		BaseType alpha = 0.667L;

		test_variant(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha, fname);
	}

	void test_variant22_step01()
	{
		cout << "Test name: test_variant22_step01" << endl << endl;

		string fname = "test_variant22_step01.csv";
		size_t maxOrderDerivative = 20;
		BaseType limitLeft = 0;
		BaseType limitRight = 2;
		Function function = [](const BaseType &x, const BaseType &y) -> BaseType
		{
			return (-x * x * x - x * y);
		};
		BaseType y0 = 3;
		BaseType alpha = 0.667L;

		test_variant(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha, fname);
	}

	void test_variant18_step02()
	{
		cout << "Test name: test_variant18_step02" << endl << endl;

		string fname = "test_variant18_step02.csv";
		size_t maxOrderDerivative = 5;
		BaseType limitLeft = 1;
		BaseType limitRight = 2;
		Function function = [](const BaseType &x, const BaseType &y) -> BaseType
		{
			return 1 - y * (1 - 2 * x) / (x * x);
		};
		BaseType y0 = 1;
		BaseType alpha = 0.667L;

		test_variant(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha, fname);
	}

	void test_variant18_step01()
	{
		cout << "Test name: test_variant18_step01" << endl << endl;

		string fname = "test_variant18_step01.csv";
		size_t maxOrderDerivative = 10;
		BaseType limitLeft = 1;
		BaseType limitRight = 2;
		Function function = [](const BaseType &x, const BaseType &y) -> BaseType
		{
			return 1 - y * (1 - 2 * x) / (x * x);
		};
		BaseType y0 = 1;
		BaseType alpha = 0.667L;

		test_variant(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha, fname);
	}


	void test_getExactResult_MethodEulerFirstOrder(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0, const BaseType &epsilon, const string &fname)
	{
		cout << "Test name: test_getExactResult_MethodEulerFirstOrder" << endl << endl;

		SolveCauchyProblem solver(new MethodEulerFirstOrder(maxOrderDerivative, limitLeft, limitRight, function, y0));

		cout << "result = " << solver.getExactResult(epsilon) << endl << endl;

		cout << "Write Table:" << endl;
		solver.writeTableResult();
		solver.writeTableResultInFile("getExactResult_MethodEulerFirstOrder_" + fname);
		cout << endl;
	}

	void test_getExactResult_MethodEulerSecondOrder(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0, const BaseType &alpha, const BaseType &epsilon, const string &fname)
	{
		cout << "Test name: test_getExactResult_MethodEulerSecondOrder" << endl << endl;

		SolveCauchyProblem solver(new MethodEulerSecondOrder(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha));

		cout << "alpha = " << alpha << endl;
		cout << "result = " << solver.getExactResult(epsilon) << endl << endl;

		cout << "Write Table:" << endl;
		solver.writeTableResult();
		solver.writeTableResultInFile("getExactResult_MethodEulerSecondOrder_" + fname);
		cout << endl;
	}

	void test_getExactResult_MethodEulerCauchy(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0, const BaseType &epsilon, const string &fname)
	{
		cout << "Test name: test_getExactResult_MethodEulerCauchy" << endl << endl;

		SolveCauchyProblem solver(new MethodEulerCauchy(maxOrderDerivative, limitLeft, limitRight, function, y0));

		cout << "alpha = " << 1.0L << endl;
		cout << "result = " << solver.getExactResult(epsilon) << endl << endl;

		cout << "Write Table:" << endl;
		solver.writeTableResult();
		solver.writeTableResultInFile("getExactResult_MethodEulerCauchy_" + fname);
		cout << endl;
	}

	void test_getExactResult_MethodEulerModified(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0, const BaseType &epsilon, const string &fname)
	{
		cout << "Test name: test_getExactResult_MethodEulerModified" << endl << endl;

		SolveCauchyProblem solver(new MethodEulerModified(maxOrderDerivative, limitLeft, limitRight, function, y0));

		cout << "alpha = " << 0.5L << endl;
		cout << "result = " << solver.getExactResult(epsilon) << endl << endl;

		cout << "Write Table:" << endl;
		solver.writeTableResult();
		solver.writeTableResultInFile("getExactResult_MethodEulerModified_" + fname);
		cout << endl;
	}

	void test_getExactResult_MethodRungeKutta(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0, const BaseType &epsilon, const string &fname)
	{
		cout << "Test name: test_getExactResult_MethodRungeKutta" << endl << endl;

		SolveCauchyProblem solver(new MethodRungeKutta(maxOrderDerivative, limitLeft, limitRight, function, y0));

		cout << "result = " << solver.getExactResult(epsilon) << endl << endl;

		cout << "Write Table:" << endl;
		solver.writeTableResult();
		solver.writeTableResultInFile("getExactResult_MethodRungeKutta_" + fname);
		cout << endl;
	}

	void test_getExactResult_variant(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0, const BaseType &alpha, const BaseType &epsilon, const string &fname)
	{
		cout << "####################################" << endl;
		test_getExactResult_MethodEulerFirstOrder(maxOrderDerivative, limitLeft, limitRight, function, y0, epsilon, fname);

		cout << "####################################" << endl;
		test_getExactResult_MethodEulerSecondOrder(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha, epsilon, fname);

		cout << "####################################" << endl;
		test_getExactResult_MethodEulerCauchy(maxOrderDerivative, limitLeft, limitRight, function, y0, epsilon, fname);

		cout << "####################################" << endl;
		test_getExactResult_MethodEulerModified(maxOrderDerivative, limitLeft, limitRight, function, y0, epsilon, fname);

		cout << "####################################" << endl;
		test_getExactResult_MethodRungeKutta(maxOrderDerivative, limitLeft, limitRight, function, y0, epsilon, fname);

		cout << "####################################" << endl;
		cout << endl;
	}

	void test_getExactResult_variant22()
	{
		cout << "Test name: test_getExactResult_variant22" << endl << endl;

		string fname = "test_getExactResult_variant22.csv";
		size_t maxOrderDerivative = 10;
		BaseType limitLeft = 0;
		BaseType limitRight = 2;
		Function function = [](const BaseType &x, const BaseType &y) -> BaseType
		{
			return (-x * x * x - x * y);
		};
		BaseType y0 = 3;
		BaseType alpha = 0.667L;
		BaseType epsilon = 0.001L;

		test_getExactResult_variant(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha, epsilon, fname);
	}

	void test_getExactResult_variant10()
	{
		cout << "Test name: test_getExactResult_variant10" << endl << endl;

		string fname = "Test name: test_getExactResult_variant10.csv";
		size_t maxOrderDerivative = 10;
		BaseType limitLeft = 0;
		BaseType limitRight = 1;
		Function function = [](const BaseType &x, const BaseType &y) -> BaseType
		{
			return (2 * x * (x - y)) / (1 + x * x);
		};
		BaseType y0 = 2.0L / 3.0L;
		BaseType alpha = 0.667L;
		BaseType epsilon = 0.001L;

		test_getExactResult_variant(maxOrderDerivative, limitLeft, limitRight, function, y0, alpha, epsilon, fname);
	}

}