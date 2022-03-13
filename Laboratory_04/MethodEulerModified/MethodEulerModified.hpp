#pragma once

#include "..\MethodEulerSecondOrder\MethodEulerSecondOrder.hpp"

namespace cauchyProblem
{

	class MethodEulerModified : public MethodEulerSecondOrder
	{
	public:
		MethodEulerModified(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0) : MethodEulerSecondOrder(maxOrderDerivative, limitLeft, limitRight, function, y0, _alpha)
		{
		}

		BaseType getResult();

	private:
		static constexpr BaseType _alpha = 0.5L;
	};

}
