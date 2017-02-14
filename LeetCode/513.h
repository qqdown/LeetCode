#pragma once

#include "leetcode.h"

namespace _503 {
	class Solution {
	public:
		int findBottomLeftValue(TreeNode* root) {
			maxDepth = -1;
			result = 0;
			findBottomLeftValue(root, 0);
			return result;
		}

	private:
		int maxDepth = 0;
		int result = 0;
		void findBottomLeftValue(TreeNode* node, int depth) {
			if (node->left == NULL && node->right == NULL) {
				if (depth > maxDepth) {
					maxDepth = depth;
					result = node->val;
				}
			}
			if (node->left != NULL)
				findBottomLeftValue(node->left, depth + 1);
			if (node->right != NULL)
				findBottomLeftValue(node->right, depth + 1);
		}
	};
}