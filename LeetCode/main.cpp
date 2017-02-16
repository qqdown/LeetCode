#pragma warning(disable:4018)
#include "problems.h"

int main()
{
	_502::Solution sol;
	int arr[] = {1,2,3};
	int arr2[] = {0,1,1};
	string arrstr[] = { "Hello", "Alaska", "Dad", "Peace" };
	vector<int> vec(arr,arr+ sizeof(arr)/sizeof(int));
	vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(int));
	vector<string> vecstr(arrstr, arrstr + 4);
	ListNode* head = createList(vec);
	TreeNode* tree = createTree(vec);
	auto result = sol.findMaximizedCapital(2,0,vec, vec2);
	printResult( result);
	
	getchar();
	return 0;
}


