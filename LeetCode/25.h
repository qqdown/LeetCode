#pragma once
#include "leetcode.h"

namespace _25 {
	class Solution {
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			if (k == 1)
				return head;
			int len = 0;
			ListNode* tryNode = head;
			while (tryNode) {
				tryNode = tryNode->next;
				len++;
			}
			if (len < k)
				return head;
			int i = 0;
			ListNode *cur = head;
			ListNode newHead(-1);
			ListNode *thead = NULL, *ttail = &newHead, *next, *newTail = cur;
			while (true) {
				if (i == k) {
					ttail->next = thead;
					ttail = newTail;
					i = 0;
					thead = NULL;
					newTail = cur;
					len -= k;
					if (len < k) {
						ttail->next = cur;
						break;
					}
				}
				else {
					if (!cur)
						break;
					i++;
					next = cur->next;
					cur->next = thead;
					thead = cur;
					cur = next;
				}
			}

			return newHead.next;
		}
	};
}