#pragma once
#include "leetcode.h"

/*
165. Compare Version Numbers
*/

namespace _165
{
	class Solution {
	public:
		int compareVersion(string version1, string version2) {
			vector<int> v1 = getVersions(version1);
			vector<int> v2 = getVersions(version2);
			int i = 0;
			while (i < v1.size() && i < v2.size())
			{
				if (v1[i] > v2[i])
					return 1;
				else if (v1[i] < v2[i])
					return -1;
				else
					i++;
			}
			if (v1.size() == v2.size())
				return 0;
			else
				return (v1.size() > v2.size() ? 1 : -1);

		}

		vector<int> getVersions(string version)
		{
			vector<int> versions;
			int i = 0, j = 0;
			for (; i < version.size(); i++) {
				if (version[i] == '.') {
					versions.push_back(atoi(version.substr(j, i - j).c_str()));
					j = i + 1;
				}
			}
			versions.push_back(atoi(version.substr(j, i - j).c_str()));
			while (!versions.empty() && versions.back() == 0)
			{
				versions.pop_back();
			}
			return versions;
		}
	};
}