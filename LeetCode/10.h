#pragma once
#include "leetcode.h"

namespace _10
{
	class Solution {
	public:
		bool isMatch(string s, string p) {
			if (s.size() == 0 && p.size() == 0)
				return true;
			if (p.size() == 0)
				return false;
			bool isMatched = false;

			if (s.size() == 0) {
				if (p.size() > 1 && p[1] == '*') {
					isMatched = isMatch(s, p.substr(2));//match zeros
					if (isMatched)
						return true;
				}
				return false;
			}
			
			if (p[0] == s[0] || p[0] == '.')
			{
				if ( p.size() > 1 && p[1] == '*') {
					isMatched = isMatch(s, p.substr(2));//match zeros
					if (isMatched)
						return true;
					for (int si = 0; si < s.size(); si++) {//match more
						if (s[si] == s[0] || p[0] == '.') {
							isMatched = isMatch(s.substr(si + 1), p.substr(2));
							if (isMatched)
								return true;
						}
						else {
							break;
						}
					}
				}
				else
				{
					isMatched = isMatch(s.substr(1), p.substr(1));
					if (isMatched)
						return true;
				}

			}
			else {
				if (p.size() > 1 && p[1] == '*') {
					isMatched = isMatch(s, p.substr(2));//match zeros
					if (isMatched)
						return true;
				}
			}

			return false;
		}
	};
}