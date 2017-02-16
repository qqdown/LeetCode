#pragma once
#include "leetcode.h"

namespace _496 {
	class Solution {
	public:
		vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
			unordered_map<int, int> placeMap;
			for (int i = 0; i < nums.size(); i++) {
				placeMap[nums[i]] = i;
			}
			vector<int> result;
			for (int i = 0; i < findNums.size(); i++) {
				int find = -1;
				for (int j = placeMap[findNums[i]]+1; j < nums.size(); j++) {
					if (nums[j] > findNums[i])
					{
						find = nums[j];
						break;
					}
				}
				result.push_back(find);
			}
			return result;
		}
	};
}