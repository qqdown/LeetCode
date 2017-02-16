#pragma once
#include "leetcode.h"

namespace _17
{
	class Solution {
	public:
		vector<string> letterCombinations(string digits) {
			vector<string> result;
			if (digits.size() == 0)
				return result;
			result.push_back("");
			letterCombinations(result, digits);
			return result;
		}

	private:
		void letterCombinations(vector<string>& prevComb, string digits) {
			vector<string> result;
			if (digits.size() == 0)
				return;
			int digit = digits[0] - '0';
			if (digit == 1)
				return;
			int from=0, to=0;
			if (digit == 2) { from = 0; to = 2; }
			else if (digit == 3) { from = 3; to = 5; }
			else if (digit == 4) { from = 6; to = 8; }
			else if (digit == 5) { from = 9; to = 11; }
			else if (digit == 6) { from = 12; to = 14; }
			else if (digit == 7) { from = 15; to = 18; }
			else if (digit == 8) { from = 19; to = 21; }
			else if (digit == 9) { from = 22; to = 25; }
			else if (digit == 0) { from = ' '-'a'; to = ' ' - 'a'; }
			for (int i =0; i < prevComb.size(); i++) {
				for (int j = from; j <= to; j++) {
					result.push_back(prevComb[i] + (char)('a' + j));
				}
			}
			prevComb.clear();
			prevComb.assign(result.begin(), result.end());
			letterCombinations(prevComb, digits.substr(1));
		}
	};
}