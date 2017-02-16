#pragma once
#include "leetcode.h"

namespace _24
{
	class Solution {
	public:
		ListNode* swapPairs(ListNode* head) {
			if (head==NULL || head->next == NULL)
				return head;
			ListNode* temp = head->next->next;
			ListNode* newHead = head->next;
			newHead->next = head;
			head->next = temp;
			ListNode  *cur=temp, *prev=newHead->next;
			while (cur != NULL && cur->next != NULL) {
				temp = cur->next->next;
				prev->next = cur->next;
				cur->next->next = cur;
				cur->next = temp;
				prev = cur;
				cur = cur->next;
			}
			return newHead;
		}
	};
}
