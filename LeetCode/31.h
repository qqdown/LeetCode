#pragma once
#include "leetcode.h"

namespace _31 {
	class Solution {
	public:
		void nextPermutation(vector<int>& nums) {
			int i = nums.size() - 2;
			for (; i >= 0; i--) {
				if (nums[i] < nums[nums.size() - 1])
				{
					int temp = nums[i];
					nums[i] = nums[nums.size() - 1];
					nums[nums.size() - 1] = temp;
					break;
				}
			}
			if (i < 0)
				sort(nums.begin(), nums.end());
		}
	};
}