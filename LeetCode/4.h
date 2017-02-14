#pragma once
#include "leetcode.h"

namespace _4
{
	class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int size = nums1.size() + nums2.size();
			if (size == 0)
				return 0;
			if (size <= 2) {
				int sum = 0;
				for (size_t i = 0; i < nums1.size(); i++) {
					sum += nums1[i];
				}
				for (size_t i = 0; i < nums2.size(); i++) {
					sum += nums2[i];
				}
				return sum*1.0 / size;
			}

			if (nums1.size() > 0 && nums2.size()>0)
			{
				if (nums1[0] < nums2[0])
					nums1.erase(nums1.begin());
				else
					nums2.erase(nums2.begin());

				if (nums1.back() > nums2.back())
					nums1.pop_back();
				else
					nums2.pop_back();
			}
			else if (nums1.size() == 0) {
				nums2.erase(nums2.begin());
				nums2.pop_back();
			}
			else
			{
				nums1.erase(nums1.begin());
				nums1.pop_back();
			}
			return findMedianSortedArrays(nums1, nums2);
		}
	};
}