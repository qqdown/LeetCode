#pragma once
#include "leetcode.h"

namespace _508 {
	class Solution {
	public:
		vector<int> findFrequentTreeSum(TreeNode* root) {
			vector<int> result;
			if (root == NULL)
				return result;
			sumCountMap.clear();
			nodeSumMap.clear();
			sumTree(root);
			vector<pair<int, int>> mapvec(sumCountMap.begin(), sumCountMap.end());
			sort(mapvec.begin(), mapvec.end(), cmpByValue);
			int m = mapvec[0].second;
			
			for (int i = 0; i < mapvec.size(); i++) {
				if (mapvec[i].second == m)
					result.push_back(mapvec[i].first);
				else
					break;
			}
			return result;
		}

	private:
		unordered_map<int, int> sumCountMap;
		unordered_map<TreeNode*, int> nodeSumMap;
		void sumTree(TreeNode* root) {
			int sum = root->val;
			if (root->left != NULL) {
				sumTree(root->left);
				sum += nodeSumMap[root->left];
			}
			if (root->right != NULL) {
				sumTree(root->right);
				sum += nodeSumMap[root->right];
			}
			nodeSumMap[root] = sum;
			if (sumCountMap.find(sum) == sumCountMap.end()) {
				sumCountMap[sum] = 0;
			}
			sumCountMap[sum]++;
		}
		
		static bool cmpByValue(const pair<int, int>& p1, const pair<int, int>& p2) {
			return p1.second > p2.second;
		}
	};
}