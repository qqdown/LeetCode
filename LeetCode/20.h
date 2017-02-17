#pragma once
#include "leetcode.h"

namespace _20 {
	class Solution {
	public:
		bool isValid(string s) {
			stack<char> st;
			int i = 0;
			while (i < s.size()) {
				char ch = s[i];
				if (s[i] == '(' || s[i] == '[' || s[i] == '{')
					st.push(s[i]);
				else {
					if (st.empty())
						return false;
					if (s[i] == ')') {
						if (st.top() == '(')
							st.pop();
						else
							return false;
					}
					else if (s[i] == ']') {
						if (st.top() == '[')
							st.pop();
						else
							return false;
					}
					else if (s[i] == '}') {
						if (st.top() == '{')
							st.pop();
						else
							return false;
					}

				}
				i++;
			}
			return st.empty();
		}
	};
}