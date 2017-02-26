#pragma once
#include "leetcode.h"

namespace _524 {
	class Solution {
	public:
		string findLongestWord(string s, vector<string>& d) {
			int max = 0;
			string str = "";
			for (int i = 0; i < d.size(); i++) {
				if (exist(s, d[i])) {
					int len = d[i].size();
					if (len == max) {
						if (d[i] < str)
							str = d[i];
					}
					else if (len > max) {
						max = len;
						str = d[i];
					}
				}
			}
			return str;
		}

	private:
		bool exist(string s, string t) {
			int i = 0, j = 0;
			while (i < s.size() && j < t.size()) {
				if (s[i] == t[j]) {
					i++; j++;
				}
				else {
					i++;
				}
			}
			return j == t.size();
		}
	};
}