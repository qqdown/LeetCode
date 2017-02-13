#pragma once
#include "leetcode.h"

namespace _1
{
	class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int, int> map;
			vector<int> result;
			for (size_t i = 0; i < nums.size(); i++) {
				map[nums[i]] = i;
			}

			for (size_t i = 0; i < nums.size(); i++) {
				int find = target - nums[i];
				auto it = map.find(find);
				if (it != map.end() && it->second != i)
				{
					result.push_back(i);
					result.push_back(it->second);
					return result;
				}

			}
			return result;
		}
	};
}