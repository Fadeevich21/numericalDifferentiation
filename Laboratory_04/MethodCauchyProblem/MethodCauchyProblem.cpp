#include "MethodCauchyProblem.hpp"
#include <sstream>

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
		this->_table = Matrix<BaseType>(this->_maxOrderDerivative + 1, 2, _table[0][1]);
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

	BaseType MethodCauchyProblem::getExactResult(const BaseType &epsilon)
	{
		BaseType res1 = this->getResult();
		BaseType res2 = res1;
		while (this->_maxOrderDerivative * 2 <= this->_maxPossibleOrderDerivative)
		{
			this->setMaxOrderDerivative(this->_maxOrderDerivative * 2);
			res2 = this->getResult();

			if (abs((res2 - res1) / ((1 << (this->_p - 1)) - 1)) <= epsilon)
			{
				break;
			}

			res1 = res2;
		}

		return res2;
	}

	void MethodCauchyProblem::writeTableResult() const
	{
		WriteMatrix(this->_table);
	}

	void MethodCauchyProblem::writeTableResultInFile(const string &fname) const
	{
		fstream fout(fname, ios::out);
		
		Matrix<BaseType> &matr = const_cast<Matrix<BaseType> &>(this->_table);
		for (auto &row : matr)
		{
			for (auto &el : row)
			{

				ostringstream strs;
				strs << el;
				string s = strs.str();
				replace(begin(s), end(s), '.', ',');

				fout << s << "; ";
			}

			fout << "\n";
		}

		fout << "\n";
	}

}