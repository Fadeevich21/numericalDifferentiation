#include "MethodCauchyProblem.hpp"

namespace cauchyProblem
{

	MethodCauchyProblem::MethodCauchyProblem(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0) : _maxOrderDerivative(maxOrderDerivative), _limitLeft(limitLeft), _limitRight(limitRight), _function(function), _table(Matrix<BaseType>(maxOrderDerivative + 1, 2))
	{
		this->_table[0][1] = y0;
	}

	MethodCauchyProblem::~MethodCauchyProblem()
	{
	};

	void MethodCauchyProblem::setMaxOrderDerivative(const size_t &maxOrderDerivative)
	{
		this->_maxOrderDerivative = maxOrderDerivative;
	}

	void MethodCauchyProblem::setLimitLeft(const BaseType &limitLeft)
	{
		this->_limitLeft = limitLeft;
	}

	void MethodCauchyProblem::setLimitRight(const BaseType &limitRight)
	{
		this->_limitRight = limitRight;
	}

	void MethodCauchyProblem::setFunction(const Function &function)
	{
		this->_function = function;
	}

	void MethodCauchyProblem::writeTableResult() const
	{
		WriteMatrix(this->_table);
	}
}