#include "MethodEulerCauchy.hpp"

namespace cauchyProblem
{

	BaseType MethodEulerCauchy::getResult()
	{
		BaseType result = MethodEulerSecondOrder::getResult();

		return result;
	}

}