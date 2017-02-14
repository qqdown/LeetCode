#pragma once
#include "leetcode.h"

namespace _515
{
	class Solution {
	public:
		vector<int> largestValues(TreeNode* root) {
			vector<TreeNode*> depthNodes;
			vector<int> result;
			if (root == NULL)
				return result;
			depthNodes.push_back(root);
			while (!depthNodes.empty()) {
				int size = depthNodes.size();
				int m = depthNodes[0]->val;
				for (int i = 0; i < size; i++) {
					m = max(depthNodes[i]->val, m);
					if (depthNodes[i]->left != NULL)
						depthNodes.push_back(depthNodes[i]->left);
					if (depthNodes[i]->right != NULL)
						depthNodes.push_back(depthNodes[i]->right);
				}
				result.push_back(m);
				depthNodes = vector<TreeNode*>(depthNodes.begin() + size, depthNodes.end());
			}
			return result;
		}
	};
}