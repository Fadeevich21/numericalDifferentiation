#pragma once

#include "..\MethodEulerSecondOrder\MethodEulerSecondOrder.hpp"

namespace cauchyProblem
{

	class MethodEulerCauchy : public MethodEulerSecondOrder
	{
	public:
		MethodEulerCauchy(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0) : MethodEulerSecondOrder(maxOrderDerivative, limitLeft, limitRight, function, y0, _alpha)
		{
		}

		BaseType getResult();

	private:
		static constexpr BaseType _alpha = 1.0L;
	};

}
