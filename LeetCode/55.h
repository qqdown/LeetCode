#pragma once
#include "leetcode.h"

namespace _55 {
	class Solution {
	public:
		bool canJump(vector<int>& nums) {
			int max = 0;
			for (int i = 0; i < nums.size() - 1; i++) {
				if (max >= i) {
					int sp = i + nums[i];
					if (sp > max)
						max = sp;
					if (max >= nums.size()-1)
						return true;
				}
				else
					break;
			}
			return max >= nums.size()-1;
		}
	
	};
}