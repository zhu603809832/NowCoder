#pragma once

class Solution {
public:
	double Power(double base, int exponent) {
		double dRetValue = 1.0;
		if (0 == exponent)
			return dRetValue;

		int nReciprocal = exponent < 0 ? 1 : 0;
		exponent = exponent < 0 ? -exponent : exponent;
		for (int i = 0; i < exponent; ++i)
		{
			dRetValue *= base;
		}
		if (nReciprocal)
			dRetValue = 1 / dRetValue;
		return dRetValue;
	}
	bool TestSolution() {
		bool bResult = false;
		double d = Power(2, 1);
		double d1 = Power(5, 3);
		double d2 = Power(2, -3);
		bResult = true;
		return bResult;
	}
};