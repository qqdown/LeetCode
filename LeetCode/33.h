#pragma once
#include "leetcode.h"

namespace _33 {
	class Solution {
	public:
		int search(vector<int>& nums, int target) {
			if (nums.size() == 0)
				return -1;
			return searchRotatedBinary(nums, 0, nums.size() - 1, target);
		}

	private:
		int searchRotatedBinary(vector<int>& nums, int start, int end, int target) {
			if (nums[start] == target)
				return start;
			if (nums[end] == target)
				return end;
			if (start == end)
				return -1;
			int m = (start + end) / 2;
			if (target > nums[start]) {
				
				if (nums[m] < nums[start])
					return searchRotatedBinary(nums, start, m, target);
				else {
					if (nums[m] == target)
						return m;
					if (nums[m] > target)
						return searchRotatedBinary(nums, start, m, target);
					else
						return searchRotatedBinary(nums, m + 1, end, target);
				}
				
			}
			else if (target < nums[end]) {
				if (nums[m] >nums[end])
					return searchRotatedBinary(nums, m+1, end, target);
				else {
					if (nums[m] == target)
						return m;
					if (nums[m] > target)
						return searchRotatedBinary(nums, start, m, target);
					else
						return searchRotatedBinary(nums, m + 1, end, target);
				}
			}

			return -1;
		}

		
	};
}