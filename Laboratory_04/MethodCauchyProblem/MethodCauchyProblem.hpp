#pragma once

#include "..\Matrix\Matrix.hpp"
#include <vector>

namespace cauchyProblem
{

	using namespace computationalMathematics;
	using BaseType = long double;
	using Function = BaseType(*)(const BaseType &x, const BaseType &y);

	class MethodCauchyProblem
	{

	public:
		MethodCauchyProblem(const size_t &maxOrderDerivative, const BaseType &limitLeft, const BaseType &limitRight, const Function &function, const BaseType &y0);
		virtual ~MethodCauchyProblem();
	
		virtual BaseType getResult() = 0;
		BaseType getExactResult(const BaseType &epsilon);

		void setMaxOrderDerivative(const size_t &maxOrderDerivative);
		void setLimitLeft(const BaseType &limitLeft);
		void setLimitRight(const BaseType &limitRight);
		void setFunction(const Function &function);

		void writeTableResult() const;
		void writeTableResultInFile(const string &fname) const;

	protected:
		Matrix<BaseType> _table;
		size_t _maxOrderDerivative;
		BaseType _limitLeft;
		BaseType _limitRight;
		Function _function;
		size_t _p;

		static constexpr size_t _maxPossibleOrderDerivative = 1000;
	};

}
