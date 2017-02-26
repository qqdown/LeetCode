#pragma once
#include "leetcode.h"

namespace _530 {
	class Solution {
	public:
		int getMinimumDifference(TreeNode* root) {
			vector<int> vec;
			getVector(vec, root);
			int m = INT_MAX;
			for (int i = 1; i < vec.size(); i++) {
				m = min(m, abs(vec[i] - vec[i - 1]));
			}
			return m;
		}

		void getVector(vector<int>& vec, TreeNode* root) {
			if (root == NULL) {
				return;
			}
			getVector(vec, root->left);
			vec.push_back(root->val);
			getVector(vec, root->right);
		}
	};
}