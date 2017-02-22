#pragma once
#include "leetcode.h"

namespace _68 {
	class Solution {
	public:
		vector<string> fullJustify(vector<string>& words, int maxWidth) {
			vector<string> lines;
			int i = 0;
			while (i < words.size()) {
				int len = words[i].size();
				int wordLen = words[i].size();
				vector<string> lineWords;
				lineWords.push_back(words[i]);
				i++;
				while (i < words.size()) {
					len = len + 1 + words[i].size();
					if (len <= maxWidth) {
						lineWords.push_back(words[i]);					
						wordLen += words[i].size();
						i++;
					}
					else {
						break;
					}
				}
				if (lineWords.size() == 1) {
					lines.push_back(lineWords[0] + space(maxWidth-lineWords[0].size()));
				}
				else {
					int width = maxWidth - wordLen;
					if (i == words.size()) {
						width = lineWords.size() - 1;
					}
					vector<string> spaces = spaceDiv(lineWords.size() - 1, width);
					string line = lineWords[0];
					for (int i = 1; i < lineWords.size(); i++) {
						line += spaces[i - 1];
						line += lineWords[i];
					}
					if (i == words.size()) {
						line += space(maxWidth - line.size());
					}
					lines.push_back(line);
				}
			}
			return lines;
		}
	private:
		string space(int n) {
			string str = "";
			for (int i = 0; i < n; i++)
				str += " ";
			return str;
		}

		vector<string> spaceDiv(int n, int width) {
			int d = width / n;
			int c = width%n;
			vector<string> r;
			for (int i = 0; i < n; i++) {
				r.push_back(space(d + (c > 0 ? 1 : 0)));
				c--;
			}
			return r;
		}
	};
}