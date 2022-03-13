#include "MethodRungeKutta.hpp"
#include <vector>

using namespace std;

namespace cauchyProblem
{

	BaseType MethodRungeKutta::getResult()
	{
		BaseType result = BaseType();
		if (this->_maxOrderDerivative > 0)
		{
			BaseType x = this->_limitLeft;
			this->_table[0][0] = x;

			BaseType y = this->_table[0][1];
			this->_table[0][1] = y;

			BaseType h = (this->_limitRight - this->_limitLeft) / static_cast<BaseType>(this->_maxOrderDerivative);
			for (size_t i = 1; i <= this->_maxOrderDerivative; i++)
			{
				BaseType arr[4];
				arr[0] = this->_function(x, y);
				arr[1] = this->_function(x + h / 2.0L, y + h / 2.0L * arr[0]);
				arr[2] = this->_function(x + h / 2.0L, y + h / 2.0L * arr[1]);
				arr[3] = this->_function(x + h, y + h * arr[2]);
				
				y += h / 6.0L * (arr[0] + 2 * arr[1] + 2 * arr[2] + arr[3]);
				this->_table[i][1] = y;

				x += h;
				this->_table[i][0] = x;
			}

			result = this->_table[this->_maxOrderDerivative][1];
		}

		return result;
	}

}