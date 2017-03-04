#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* createList(vector<int>& list) {
	if (list.size() == 0)
		return NULL;
	ListNode* head = new ListNode(list[0]);
	ListNode* prev = head;
	for (int i = 1; i < list.size(); i++) {
		prev->next = new ListNode(list[i]);
		prev = prev->next;
	}
	return head;
}

TreeNode* createTree(vector<int>& treeArr) {
	if (treeArr.size() == 0)
		return NULL;
	//first element can't be NAN
	TreeNode* head = new TreeNode(treeArr[0]);
	queue<TreeNode*> Q;
	Q.push(head);
	int i = 1;
	while (!Q.empty() && i < treeArr.size()) {
		TreeNode* cur = Q.front();
		Q.pop();
		if (treeArr[i] != NAN) {
			TreeNode* left = new TreeNode(treeArr[i]);
			cur->left = left;
			Q.push(left);
		}
		if (i + 1 < treeArr.size() && treeArr[i + 1] != NAN) {
			TreeNode* right = new TreeNode(treeArr[i + 1]);
			cur->right = right;
			Q.push(right);
		}
		i += 2;
	}

	return head;
}

void printResult(int res) {
	cout << res << endl;
}

void printResult(int n1, int n2) {
	cout << n1 << " " << n2 << endl;
}

void printResult(int n1, int n2, int n3) {
	cout << n1 << " " << n2 <<" "<<n3<<  endl;
}

void printResult(string& res) {
	cout << res << endl;
}

void printResult(vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

void printResult(vector<vector<int>>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		printResult(vec[i]);
	}
}

void printResult(vector<char>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "";
	}
	cout << endl;
}

void printResult(vector<vector<char>>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		printResult(vec[i]);
	}
}

void printResult(vector<string>& vec, bool multiLine = false) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
		if (multiLine)
			cout << endl;
	}
	cout << endl;
}

void printResult(vector<vector<string>>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		printResult(vec[i], true);
	}
}

void printResult(ListNode* head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void printResult(TreeNode* node) {
	if (node == NULL)
		return;
	queue<TreeNode*> Q;
	Q.push(node);
	while (!Q.empty()) {
		TreeNode* n = Q.front();
		Q.pop();
		if (n == NULL) {
			cout << "NULL ";
		}
		else {
			cout << n->val << " ";
			Q.push(n->left);
			Q.push(n->right);
		}
		
	}
	cout << endl;
}