#pragma once
#include "leetcode.h"

namespace _15 {
	class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			vector<vector<int>> result;
			if (nums.size() <3)
				return result;
			int lastLeft = nums[0];
			for (int left = 0; left < nums.size() - 2; left++) {
				if (left != 0 && lastLeft == nums[left])
					continue;
				lastLeft = nums[left];
				int mid = left + 1, right = nums.size() - 1;
				int lastMid = nums[mid], lastRight = nums[right];
				while (mid < right) {
					int sum = nums[left] + nums[mid] + nums[right];
					if (sum == 0) {
						if (mid == left + 1 && right == nums.size() - 1 || !(nums[mid] == lastMid&&nums[right] == lastRight))
						{
							int find[3] = { nums[left], nums[mid], nums[right] };
							result.push_back(vector<int>(find, find + 3));
							lastMid = nums[mid];
							lastRight = nums[right];
						}
						mid++; right--;
					}
					else if (sum < 0)
						mid++;
					else
						right--;
					
				}
			}
			return result;
		}
	};
}