#pragma once
#include "leetcode.h"

namespace _3
{
	class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			vector<int> charPlace(256, -1);
			int maxLen = 0, start = -1;
			for (int i = 0; i < s.size(); i++) {
				start = max(start, charPlace[s[i]]);
				charPlace[s[i]] = i;
				maxLen = max(maxLen, i - start);
			}
			return maxLen;
		}
	};
}