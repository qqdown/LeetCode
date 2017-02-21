#pragma once
#include "leetcode.h"

namespace _27 {
	class Solution {
	public:
		int removeElement(vector<int>& nums, int val) {
			for (int j = nums.size() - 1; j >= 0; j--) {
				if (nums[j] == val) {
					nums.erase(nums.begin() + j);
				}
			}
			return nums.size();
		}
	};
}