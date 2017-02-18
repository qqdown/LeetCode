#pragma warning(disable:4018)
#include "problems.h"

int main()
{
	_394::Solution sol;
	int arr[] = { 0,9,5,7,3 };
	int arr2[] = {0,1,1};
	string arrstr[] = { "Hello", "Alaska", "Dad", "Peace" };
	vector<int> vec(arr,arr+ sizeof(arr)/sizeof(int));
	vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(int));
	vector<string> vecstr(arrstr, arrstr + 4);
	ListNode* head = createList(vec);
	TreeNode* tree = createTree(vec);
	//auto result = sol.decodeString("");
	//printResult( result);
	_307::NumArray obj(vec);
	printResult(obj.sumRange(1, 2));
	obj.update(4, 5);
	obj.update(0,8);
	obj.update(1,7);
	printResult(obj.sumRange(1,2));
	getchar();
	return 0;
}


