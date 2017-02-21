#pragma once
#include "leetcode.h"

namespace _23 {
	class Solution {
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			if (lists.size() == 0)
				return NULL;
			else if (lists.size() == 1)
				return lists[0];
			else if (lists.size() == 2)
				return mergeList(lists[0], lists[1]);
			else {
				int size = lists.size();
				int m = size / 2;
				vector<ListNode*> leftList(lists.begin(), lists.begin() + m);
				vector<ListNode*> rightList(lists.begin() + m, lists.end());
				ListNode* l = mergeKLists(leftList);
				ListNode* r = mergeKLists(rightList);
				return mergeList(l, r);
			}
		}
	private:
		
		ListNode* mergeList(ListNode* ln, ListNode*rn) {
			ListNode head (-1);
			ListNode* n = &head;
			while (ln && rn) {
				if (ln->val < rn->val) {
					n->next = ln;
					ln = ln->next;
				}
				else {
					n->next = rn;
					rn = rn->next;
				}
				n = n->next;
			}
			if (ln) n->next = ln;
			if (rn) n->next = rn;
			return head.next;
		}
	};
}