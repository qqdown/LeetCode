#pragma once
#include "34.h"

namespace _34 {
	class Solution {
	public:
		vector<int> searchRange(vector<int>& nums, int target) {

		}
	private:
		vector<int> searchRange(vector<int>&nums, int start, int end, int target) {
			vector<int> res;
			if (nums[start] == target && nums[end] == target) {
				res.push_back(start);
				res.push_back(end);
				return res;
			}
			else if (nums[start] <= target && nums[end] >= target) {
				int m = (start + end) / 2;
				vector<int> l = searchRange(nums, start, m, target);
				vector<int> r = searchRange(nums, m + 1, end, target);
			}

			
		}
	};
}