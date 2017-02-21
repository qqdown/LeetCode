#pragma warning(disable:4018)
#include "problems.h"

int main()
{
	_27::Solution sol;
	int arr[] = { 3,2,2,3};
	int arr2[] = {2,4,6,8,10};
	int arr3[] = { 12,14,16,18,110 };
	int arr4[] = { 3,4,6,7,8 };
	string arrstr[] = { "Hello", "Alaska", "Dad", "Peace" };
	vector<int> vec(arr,arr+ sizeof(arr)/sizeof(int));
	vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(int));
	vector<int> vec3(arr3, arr3 + sizeof(arr3) / sizeof(int));
	vector<int> vec4(arr4, arr4 + sizeof(arr4) / sizeof(int));
	vector<string> vecstr(arrstr, arrstr + 4);
	ListNode* n1 = createList(vec);
	ListNode* n2 = createList(vec2);
	ListNode* n3 = createList(vec3);
	ListNode* n4 = createList(vec4);
	TreeNode* tree = createTree(vec);

	vector<ListNode*> vl;
	vl.push_back(n1);
	vl.push_back(n2);
	vl.push_back(n3);
	vl.push_back(n4);

	auto result = sol.removeElement(vec, 3);

	printResult( result);

	getchar();
	return 0;
}


