#pragma once
#include "leetcode.h"

namespace _520 {
	class Solution {
	public:
		bool detectCapitalUse(string word) {
			int upper = 0, lower = 0;
			for (int i = 0; i < word.size(); i++) {
				if (word[i] >= 'a' && word[i] <= 'z')
					lower++;
				else
					upper++;
				if (upper > 1 && lower > 0)
					return false;
			}
			if (upper == 1)
				return word[0] >= 'A'&&word[0] <= 'Z';
			return upper == 0 || lower == 0;
		}
	};
}