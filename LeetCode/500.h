#pragma once
#include "leetcode.h"

namespace _500 {
	class Solution {
	public:
		vector<string> findWords(vector<string>& words) {
			vector<string> res;
			for (int i = 0; i < words.size(); i++) {
				if (isInRow(words[i]))
					res.push_back(words[i]);
			}
			return res;
		}

	private:
		bool isInRow(string words) {
			
			if (words.size() == 0)
				return true;
			char ch = tolower(words[0]);
			int row = placeMap[ch];
			for (int i = 1; i < words.size(); i++) {
				ch = tolower(words[i]);
				if (row != placeMap[ch])
					return false;
			}
			return true;
		}

		unordered_map<char, int> placeMap = {
			{'q',1},{'w',1},{'e',1},{'r',1},{'t',1},{'y',1},{'u',1},{'i',1},{'o',1},{'p',1},
			{'a', 2},{'s',2 },{'d',2},{'f',2},{'g',2},{'h',2},{'j',2},{'k',2},{'l',2},
			{'z',3},{'x',3}, {'c',3},{'v',3},{'b',3},{'n',3},{'m',3} };
	};
}