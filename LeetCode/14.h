#pragma once
#include "leetcode.h"

namespace _14 {
	class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			if (strs.size() == 0)
				return "";
			string prefix = strs[0];
			for (int i = 1; i < strs.size(); i++) {
				for (int j = 0; j < prefix.size(); j++) {
					if (j == strs[i].size() || strs[i][j] != prefix[j]) {
						prefix = prefix.substr(0, j);
						break;
					}
				}
			}
			return prefix;
		}
	};
}