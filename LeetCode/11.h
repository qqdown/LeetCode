#pragma once
#include "leetcode.h"

namespace _11
{
	class Solution {
	public:
		int maxArea(vector<int>& height) {
			int m = 0;
			int left = 0, right = height.size() - 1;
			while (left < right) {
				m = max(m, min(height[left], height[right])*(right - left));
				if (height[left] < height[right])
					left++;
				else
					right--;
			}
			return m;
		}
	};
}