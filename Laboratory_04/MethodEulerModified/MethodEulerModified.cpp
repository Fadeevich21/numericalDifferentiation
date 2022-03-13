#include "MethodEulerModified.hpp"

namespace cauchyProblem
{

	BaseType MethodEulerModified::getResult()
	{
		BaseType result = MethodEulerSecondOrder::getResult();

		return result;
	}

}