#pragma once
#include "leetcode.h"

namespace _18 {
	class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			
			sort(nums.begin(), nums.end());
			vector<vector<int>> result;
			if (nums.size() < 4)
				return result;
			int i = 0;
			while(i<nums.size()-3) {
				int j = i + 1;
				while(j<nums.size()-2){
					int l = j + 1, r = nums.size() - 1;
					while (l < r) {
						int sum = nums[i] + nums[j] + nums[l] + nums[r];
						if (target == sum) {
							int res[] = {nums[i], nums[j], nums[l], nums[r]};
							result.push_back(vector<int>(res, res + 4));
							do { l++; } while (l < r && nums[l - 1] == nums[l]);
							do { r--; } while (l < r && nums[r + 1] == nums[r]);
						}
						else if(sum<target)
						{
							do { l++; } while (l < r && nums[l - 1] == nums[l]);
						}
						else
						{
							do { r--; } while (l < r && nums[r + 1] == nums[r]);
						}
					}
					do { j++; } while (j < nums.size()-2 && nums[j - 1] == nums[j]);
				}
				do { i++; } while (i < nums.size() - 3 && nums[i - 1] == nums[i]);
			}
			return result;
		}
	};
}