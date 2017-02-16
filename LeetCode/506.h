#pragma once
#include "leetcode.h"

namespace _506
{
	struct athlete {
		int score;
		int index;
		athlete(int s, int i) : score(s), index(i) {}
	};

	class Solution {
	public:
		vector<string> findRelativeRanks(vector<int>& nums) {
			vector<athlete> athletes;
			for (int i = 0; i < nums.size(); i++) {
				athletes.push_back(athlete(nums[i], i));
			}
			sort(athletes.begin(), athletes.end(), cmp);
			string* result = new string[athletes.size()];
			for (int i = 0; i < athletes.size(); i++) {
				string score = "";
				if (i == 0)
					score = "Gold Medal";
				else if (i == 1)
					score = "Silver Medal";
				else if (i == 2)
					score = "Bronze Medal";
				else
				{
					stringstream ss;
					ss << (i + 1);
					score = ss.str();
				}
				result[athletes[i].index] = score;
			}
			vector<string> r = vector<string>(result, result + athletes.size());
			delete[] result;
			return r;
		}

	private:
		static bool cmp(const athlete& a1, const athlete& a2){
			return a1.score > a2.score;
		}
	};
}