#pragma once
#include "leetcode.h"
namespace _307 {
	class NumArray {
	public:
		NumArray(vector<int> nums) {
			size = nums.size();
			int initsize = nums.size() * 4 + 10;
			this->segTree = new int[initsize];
			memset(segTree, 0, initsize*sizeof(int));
			
			buildTree(1, 0, nums.size() - 1, nums);
		}

		void update(int i, int val) {
			updateTree(1, 0, size - 1, i, val);

		}

		int sumRange(int i, int j) {
			return sumTree(1, 0, size - 1, i, j);
		}

	private:
		int* segTree;//Ïß¶ÎÊ÷
		int size;
		void buildTree(int node, int begin, int end, vector<int>& nums) {
			if (begin > end)
				return;
			if (begin == end)
				segTree[node] = nums[begin];
			else {
				int m = (begin + end) / 2;
				buildTree(2 * node, begin, m, nums);
				buildTree(2 * node + 1, m + 1, end, nums);
				segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
			}
		}

		void updateTree(int node, int begin, int end, int target, int newValue) {
			if (begin > end)
				return;
			if (begin == end) {
				segTree[node] = newValue;
				return;
			}
			int m = (begin + end) / 2;
			if (target <= m)
				updateTree(node * 2, begin, m, target, newValue);
			else
				updateTree(node * 2 + 1, m + 1, end, target, newValue);
			segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
		}

		int sumTree(int node, int begin, int end, int from, int to) {
			if (begin > end)
				return 0;
			if (from == begin && end == to)
				return segTree[node];
			if (begin == end)
				return segTree[node];
			int m = (begin + end) / 2;
			if (to <= m)
				return sumTree(node * 2, begin, m, from, to);
			if (from > m)
				return sumTree(node * 2 + 1, m + 1, end, from, to);
			return sumTree(node * 2, begin, m, from, m) + sumTree(node * 2 + 1, m+1, end, m+1, to);
		}
	};
}