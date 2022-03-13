#pragma once

#include "..\..\..\..\Libraries\MethodCauchyProblem\MethodCauchyProblem.hpp"
#include "..\..\..\..\Libraries\SolveCauchyProblem\SolveCauchyProblem.hpp"
#include "..\..\..\..\Libraries\MethodEulerFirstOrder\MethodEulerFirstOrder.hpp"
#include "..\..\..\..\Libraries\MethodEulerSecondOrder\MethodEulerSecondOrder.hpp"
#include "..\..\..\..\Libraries\MethodEulerCauchy\MethodEulerCauchy.hpp"
#include "..\..\..\..\Libraries\MethodEulerModified\MethodEulerModified.hpp"
#include "..\..\..\..\Libraries\MethodRungeKutta\MethodRungeKutta.hpp"

namespace test
{

	void test_variantExampleMethodolicalManual_step02();
	void test_variantExampleMethodolicalManual_step01();

	void test_variant10_step02();
	void test_variant10_step01();

	void test_variant22_step02();
	void test_variant22_step01();

	void test_getExactResult_variant22();
	void test_getExactResult_variant10();
}