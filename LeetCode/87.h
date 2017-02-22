#pragma once

#include "leetcode.h"

namespace _87 {
	class Solution {
	public:
		bool isScramble(string s1, string s2) {
			resultMap.clear();
			return isScramble(s1, s2, false);
		}
	private:
		unordered_map<string, bool> resultMap;
		bool isScramble(string s1, string s2, bool isReverse) {
			if (s1 == s2)
				return true;
			if (s1.size() != s2.size() || s1.size() == 1)
				return false;
			string key = s1 + " " + s2;
			if (resultMap.find(key) != resultMap.end())
				return resultMap[key];
			bool res = false;
			for (int m = 1; m < s1.size(); m++)
			{
				//int m = s1.size() / 2;
				
				if (isScramble(s1.substr(0, m), s2.substr(0, m), false) && isScramble(s1.substr(m), s2.substr(m), false))
					res = true;
				else if (isScramble(s1.substr(0, m), s2.substr(s2.size() - m, m), false) && isScramble(s1.substr(m), s2.substr(0, s2.size() - m), false))
					res = true;
				if (res)
					break;
			}
			
			resultMap[key] = res;
			return res;
		}
	};
}
