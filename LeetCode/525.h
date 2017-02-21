#pragma once
#include "leetcode.h"

namespace _525 {
	class Solution {
	public:
		int findMaxLength(vector<int>& nums) {
			
			return findMaxLength(nums, 0, nums.size()-1);
		}

	private:
		int findMaxLength(vector<int>& nums, int start, int end) {
			if (start > end)
				return 0;
			int c0 = 0, c1 = 0;
			for (int i = start; i <= end; i++) {
				if (nums[i] == 0)
					c0++;
				else
					c1++;
			}

			int i = start, j = end;
			while (i<j && c1 != c0) {
				if (c1 < c0) {
					if (nums[i] == 0) {
						i++;
						c0--;
					}
					else
					{
						if (nums[j] == 0)
							c0--;
						else
							return max(findMaxLength(nums, start + 1, end), findMaxLength(nums, start, end - 1));
						j--;
					}
				}
				else {
					if (nums[i] == 1) {
						i++;
						c1--;
					}
					else {
						if (nums[j] == 0)
							return max(findMaxLength(nums, start + 1, end), findMaxLength(nums, start, end - 1));
						else
							c1--;
						j--;
					}
				}
			}
			return j - i + 1;
		}
	
	};
}