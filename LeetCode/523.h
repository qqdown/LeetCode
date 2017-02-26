#pragma once
#include "leetcode.h"

namespace _523 {
	class Solution {
	public:
		bool checkSubarraySum(vector<int>& nums, int k) {
			int* tree = new int[nums.size() * 4+10];
			createTree(1, tree, nums, 0, nums.size() - 1);
			for (int i = 0; i < nums.size() - 1; i++) {
				for (int j = i + 1; j < nums.size(); j++) {
					int s = sum(tree, 1, 0, nums.size() - 1, i, j);
					if (k == 0) {
						if (s == 0) {
							delete[] tree;
							return true;
						}
							
					}
					else {
						if (s%k == 0)
						{
							delete[] tree;
							return true;
						}
					}
				}
			}
			delete[] tree;
			return false;
		}

	private:
		int sum(int tree[], int n, int ln, int rn, int targetl, int targetr) {
			if (targetl == ln && targetr == rn)
				return tree[n];
			int m = (ln + rn) / 2;
			int l = n * 2;
			int r = n * 2 + 1;
			if (targetr <= m) {
				return sum(tree, l, ln, m, targetl, targetr);
			}
			if (targetl > m) {
				return sum(tree, r, m + 1, rn, targetl, targetr);
			}
			return sum(tree, l, ln, m, targetl, m) + sum(tree, r, m + 1, rn, m+1, targetr);
		}

		void createTree(int n, int tree[], vector<int>& nums, int ln, int rn) {
			if (ln == rn) {
				tree[n] = nums[ln];
				return;
			}
			int l = n * 2;
			int r = n * 2 + 1;
			int m = (ln + rn) / 2;
			createTree(l, tree, nums, ln, m);
			createTree(r, tree, nums, m + 1, rn);
			tree[n] = tree[l] + tree[r];
		}
	};
}