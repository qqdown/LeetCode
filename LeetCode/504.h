#pragma once
#include "leetcode.h"

namespace _504 {
	class Solution {
	public:
		string convertToBase7(int num) {
			int remain = num<0?-num:num;
			string result;
			while (remain >= 7) {
				result += '0' + remain % 7;
				remain = remain / 7;
			}
			result += '0' + remain;
			reverse(result.begin(), result.end());
			if (num < 0)
				result = '-' + result;
			return result;
		}
	};
}