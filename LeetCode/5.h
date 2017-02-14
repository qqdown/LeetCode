#pragma once
#include "leetcode.h"

namespace _5
{
	class Solution {
	public:
		string longestPalindrome(string s) {
			int maxEnd = 0, maxStart = 0;
			bool* isPalindrome = new bool[s.size()*s.size()];
			for (size_t i = 0; i < s.size(); i++) {
				for (size_t j = 0; j < s.size(); j++) {
					if (i >= j)
						isPalindrome[i*s.size() + j] = true;
					else
						isPalindrome[i*s.size() + j] = false;
				}
				
			}
			for (size_t i = 0; i < s.size(); i++) {
				for (size_t j = 0; j+i < s.size(); j++) {
					int k = (int)(j + i);
					if (s[j] == s[k]) {
						isPalindrome[j*s.size() + k] = isPalindrome[(j + 1)*s.size() + k - 1];
						if (isPalindrome[j*s.size() + k] && k - j>maxEnd - maxStart) {
							maxStart = j;
							maxEnd = k;
						}
					}
					else {
						isPalindrome[j*s.size() + k] = false;
					}
					
				}
			}
			return s.substr(maxStart, maxEnd-maxStart+1);
		}
	};
}