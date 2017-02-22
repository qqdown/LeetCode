#pragma once
#include "leetcode.h"

namespace _35 {
	class Solution {
	public:
		int searchInsert(vector<int>& nums, int target) {
			return searchInsert(nums, 0, nums.size() - 1, target);
		}

	private:
		int searchInsert(vector<int>& nums, int start, int end, int target) {
			if (target < nums[start])
				return start;
			if (target > nums[end])
				return end+1;
			int m = (start + end) / 2;
			if (nums[m] == target)
				return m;
			else if (nums[m] > target)
				return searchInsert(nums, start, m-1, target);
			else
				return searchInsert(nums, m+1, end, target);
		}
	};
}