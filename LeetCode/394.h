#pragma once
#include "leetcode.h"
namespace _394 {
	class Solution {
	public:
		string decodeString(string s) {
			if (s.size() == 0)
				return "";
			string str = "";
			int k = 0;
			int i = 0;
			while (s[i] >= '0' && s[i] <= '9')
			{
				k = k * 10 + (s[i] - '0');
				i++;
			}
			if (s[i] == '[') {
				int j = i + 1;
				int bracket = 1;
				for (; j < s.size(); j++) {
					if (s[j] == '[')
						bracket++;
					else if (s[j] == ']')
					{
						bracket--;
						if (bracket == 0)
							break;
					}
				}
				string substr = s.substr(i + 1, j - i-1);
				string decStr = decodeString(substr);
				for (int n = 0; n < k; n++) {
					str += decStr;
				}
				str += decodeString(s.substr(j + 1));
			}
			else {//start with string
				while (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
					str += s[i];
					i++;
				}
				string substr = s.substr(i);
				str  += decodeString(substr);
			}
			return str;
		}
	};
}