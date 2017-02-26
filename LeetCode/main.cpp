#pragma warning(disable:4018)
#include "problems.h"

int main()
{
	_524::Solution sol;
	int arr[] = {23,2,6,4,7};
	int arr2[] = {2,4,6,8,10};
	int arr3[] = { 12,14,16,18,110 };
	int arr4[] = { 3,4,6,7,8 };
	string arrstr[] = { "a","b","c" };
	vector<int> vec(arr,arr+ sizeof(arr)/sizeof(int));
	vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(int));
	vector<int> vec3(arr3, arr3 + sizeof(arr3) / sizeof(int));
	vector<int> vec4(arr4, arr4 + sizeof(arr4) / sizeof(int));
	vector<string> vecstr(arrstr, arrstr + 3);
	ListNode* n1 = createList(vec);
	ListNode* n2 = createList(vec2);
	ListNode* n3 = createList(vec3);
	ListNode* n4 = createList(vec4);
	TreeNode* tree = createTree(vec);
	char *arrsd[9] = { "53..7....", "6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5" ,"....8..79"};
	vector<vector<char>> board;
	for (int i = 0; i < 9; i++) {
		char* sd = arrsd[i];
		vector<char> vc(sd, sd + 9);
		board.push_back(vc);
	}

	
	auto result = sol.findLongestWord("abpcplea", vecstr);
	printResult(result);
	
	getchar();
	return 0;
}


