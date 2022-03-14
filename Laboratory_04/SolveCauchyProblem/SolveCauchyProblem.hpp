#pragma once

#include "..\MethodCauchyProblem\MethodCauchyProblem.hpp"

namespace cauchyProblem
{

	class SolveCauchyProblem
	{
	public:
		SolveCauchyProblem(MethodCauchyProblem *const method = nullptr);
		~SolveCauchyProblem();

		void setMethod(MethodCauchyProblem *const &method);

		BaseType getResult();
		BaseType getExactResult(const BaseType &epsilon);

		void writeTableResult() const;
		void writeTableResultInFile(const string &fname) const;

	private:
		MethodCauchyProblem *_method;
	};

}
