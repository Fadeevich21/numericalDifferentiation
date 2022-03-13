#pragma once

#include "..\MethodCauchyProblem\MethodCauchyProblem.hpp"

namespace cauchyProblem
{

	class MethodRungeKutta : public MethodCauchyProblem
	{
	public:
		MethodRungeKutta(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0) : MethodCauchyProblem(maxOrderDerivative, limitLeft, limitRight, function, y0)
		{
		}

		BaseType getResult();

	private:
	};

}
