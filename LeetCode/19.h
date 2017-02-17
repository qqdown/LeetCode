#pragma once
#include "leetcode.h"

namespace _19 {
	class Solution {
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			int len = 0;
			vector<ListNode*> nodes;
			while (head != NULL) {
				nodes.push_back(head);
				head = head->next;
				len++;
			}

			if (n == len)
				return nodes.size()<=1?NULL:nodes[1];
			else
			{
				nodes[len - n - 1]->next = nodes[len - n]->next;
				return nodes[0];
			}

		}
	};
}