#pragma once

#include "..\MethodCauchyProblem\MethodCauchyProblem.hpp"

namespace cauchyProblem
{

	class MethodEulerFirstOrder : public MethodCauchyProblem
	{
	public:
		MethodEulerFirstOrder(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0) : MethodCauchyProblem(maxOrderDerivative, limitLeft, limitRight, function, y0)
		{
			this->_p = p;
		}

		BaseType getResult();

	private:
		static constexpr size_t p = 1;
	};

}
