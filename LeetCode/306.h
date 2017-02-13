#pragma once
#include "leetcode.h"
/*
306. Additive Number
*/
namespace _306
{
	class Solution {
	public:
		bool isAdditiveNumber(string num) {
			for (size_t i = 1; i <= num.size() / 2; i++)
			{
				for (size_t j = 1; j <= num.size() / 2; j++)
				{
					if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
						return true;
				}
			}
			return false;
		}

	private:

		bool check(string first, string second, string remaining)
		{
			if ((first.size() > 1 && first[0] == '0') || (second.size() > 1 && second[0] == '0'))
				return false;
			string sum = add(first, second);
			if (sum == remaining)
				return true;
			if (sum.size() > remaining.size())
				return false;
			if (strncmp(remaining.c_str(), sum.c_str(), sum.size()) == 0)
				return check(second, sum, remaining.substr(sum.size()));
			else
				return false;
		}

		string add(string num1, string num2)
		{
			int carry = 0;
			int i = num1.size() - 1;
			int j = num2.size() - 1;
			string result = "";
			while (i >= 0 || j >= 0)
			{
				int n1 = (i < 0 ? 0 : num1[i] - '0');
				int n2 = (j < 0 ? 0 : num2[j] - '0');
				int r = n1 + n2 + carry;
				result += (char)('0' + r % 10);
				carry = r / 10;
				i--; j--;
			}
			if (carry != 0)
				result += (char)('0' + carry);
			reverse(result.begin(), result.end());
			return result;
		}
	};
}