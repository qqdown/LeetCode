#pragma warning(disable:4018)
#include "problems.h"

int main()
{
	_15::Solution sol;
	int arr[] = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	vector<int> vec(arr,arr+ sizeof(arr)/sizeof(int));
	auto result = sol.threeSum(vec);
	printVector(result);
	
	getchar();
	return 0;
}


