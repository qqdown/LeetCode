#pragma once
#include "leetcode.h"

namespace _526 {
	class Solution {
	public:
		int countArrangement(int N) {
			unordered_map<int, vector<int>> beautifulMap;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (i%j == 0 || j%i == 0) {
						if (beautifulMap.find(i) == beautifulMap.end()) {
							vector<int> v;
							beautifulMap[i] = v;
						}
						beautifulMap[i].push_back(j);
					}
				}
			}

			count = 0;
			unordered_set<int> set;
			countArrangement(beautifulMap, set, 1, N);
			return count;
		}
	private:
		int count = 0;
		bool countArrangement(unordered_map<int, vector<int>>& beautifulMap, unordered_set<int>& set, int index, int N) {
			bool canArrange = false;
			for (int i = 0; i < beautifulMap[index].size(); i++) {
				int n = beautifulMap[index][i];
				if (set.find(n) == set.end()) {
					set.insert(n);
					if (index == N)
					{
						canArrange = true;
						count++;
					}
					else
					{
						bool res = countArrangement(beautifulMap, set, index + 1, N);
						if (res)
							canArrange = true;
					}
					set.erase(n);
				}
			}
			return canArrange;
		}
	};
}