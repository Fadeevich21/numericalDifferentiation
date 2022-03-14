#pragma once

#include "..\MethodCauchyProblem\MethodCauchyProblem.hpp"

namespace cauchyProblem
{

	class MethodEulerSecondOrder : public MethodCauchyProblem
	{
	public:
		MethodEulerSecondOrder(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0, const BaseType &alpha)
			: MethodCauchyProblem(maxOrderDerivative, limitLeft, limitRight, function, y0), _alpha(alpha)
		{
			this->_p = p;
		}

		BaseType getResult();

	private:
		BaseType _alpha;

		static constexpr size_t p = 2;
	};

}
