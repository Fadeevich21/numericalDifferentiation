#include "SolveCauchyProblem.hpp"

namespace cauchyProblem
{

	SolveCauchyProblem::SolveCauchyProblem(MethodCauchyProblem * const method) : _method(method)
	{
	}

	SolveCauchyProblem::~SolveCauchyProblem()
	{
		delete this->_method;
	}

	void SolveCauchyProblem::setMethod(MethodCauchyProblem *const &method)
	{
		delete this->_method;
		this->_method = method;
	}

	BaseType SolveCauchyProblem::getResult()
	{
		return this->_method->getResult();
	}

	BaseType SolveCauchyProblem::getExactResult(const BaseType &epsilon)
	{
		return this->_method->getExactResult(epsilon);
	}

	void SolveCauchyProblem::writeTableResult() const
	{
		this->_method->writeTableResult();
	}

	void SolveCauchyProblem::writeTableResultInFile(const string &fname) const
	{
		this->_method->writeTableResultInFile(fname);
	}

}