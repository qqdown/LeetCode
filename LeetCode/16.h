#pragma once
#include "leetcode.h"

namespace _16 {
	class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());
			int cloest = INT_MAX;
			int result = 0;
			for (int left = 0; left < nums.size() - 2; left++) {
				int mid = left + 1, right = nums.size() - 1;
				while (mid < right) {		
					int sum = nums[left] + nums[mid] + nums[right];
					int delta = abs(target - sum);
					if (delta < cloest) {
						cloest = delta;
						result = sum;

					}
					
					if (sum == target)
						break;
					else if (sum < target)
					{
						do { mid++; } while (mid < right && nums[mid] == nums[mid-1]);
					}
					else
					{
						do { right--; } while (mid < right && nums[right] == nums[right+1]);
					}
				}
			}
			return result;
		}
	};
}
