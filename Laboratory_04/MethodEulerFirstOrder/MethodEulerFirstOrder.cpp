#include "MethodEulerFirstOrder.hpp"

namespace cauchyProblem
{

	BaseType MethodEulerFirstOrder::getResult()
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
				y += h * this->_function(x, y);
				this->_table[i][1] = y;
				
				x += h;
				this->_table[i][0] = x;
			}

			result = this->_table[this->_maxOrderDerivative][1];
		}
		
		return result;
	}

}