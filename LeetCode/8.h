#pragma once
#include "leetcode.h"

namespace _8 {
	class Solution {
	public:
		int myAtoi(string str) {
			int pos = 0;
			//skip blank
			while (str[pos] == ' ') pos++;
			int sign = 1;
			if (str[pos] == '-') { sign = -1; pos++; }
			else if (str[pos] == '+') { sign = 1; pos++; }
			long res = 0;
			while (pos < str.size()) {
				int digit = str[pos++] - '0';
				if (digit < 0 || digit>9)
					break;
				res = res * 10 + sign*digit;
				if (res > INT32_MAX) return INT32_MAX;
				if (res < INT32_MIN) return INT32_MIN;
			}
			return res;
		}
	};
}