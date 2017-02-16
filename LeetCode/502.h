#pragma once
#include "leetcode.h"
namespace _502 {
	class Solution {
	public:
		int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
			for (int i = 0; i < k; i++) {
				int maxPro = -1, maxIndx = -1;
				for (int j = 0; j < Capital.size(); j++) {
					if (Capital[j] <= W) {//can afford
						if (maxPro < Profits[j]) {
							maxPro = Profits[j];
							maxIndx = j;
						}
					}
				}
				if (maxIndx < 0)
					break;
				W += maxPro;
				Capital.erase(Capital.begin() + maxIndx);
				Profits.erase(Profits.begin() + maxIndx);
			}
			return W;
		}
	};
}
