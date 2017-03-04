#pragma once
#include "leetcode.h"

namespace _160 {
	class Solution {
	public:
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			ListNode* p1, *p2;
			p1 = headA;
			p2 = headB;
			if (p1 == NULL || p2 == NULL)
				return NULL;
			while (p1 != p2) {
				p1 = (p1 == NULL) ? headB : p1->next;
				p2 = (p2 == NULL) ? headA : p2->next;
			}
			return p1;
		}
	};
}