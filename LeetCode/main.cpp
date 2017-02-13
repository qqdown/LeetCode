#include "problems.h"
int main()
{
	_1::Solution sol;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	auto result = sol.twoSum(nums, 6);
	cout << result[0] << " " << result[1];
	getchar();
	return 0;
}