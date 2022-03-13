#pragma once

#include "..\MethodCauchyProblem\MethodCauchyProblem.hpp"

namespace cauchyProblem
{

	class SolveCauchyProblem
	{
	public:
		SolveCauchyProblem(MethodCauchyProblem *const method = nullptr);
		~SolveCauchyProblem();

		void setMethod(MethodCauchyProblem *const method);

		BaseType getResult();

		void writeTableResult() const;

	private:
		MethodCauchyProblem *_method;
	};

}
