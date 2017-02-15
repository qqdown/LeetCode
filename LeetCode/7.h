#pragma once
#include "7.h"

namespace _7 {
	class Solution {
	public:
		int reverse(int x) {
			long long res = 0;
			while (x) {
				res = res * 10 + x % 10;
				x /= 10;
			}
			return (res<INT_MIN || res>INT_MAX) ? 0 : (int)res;
		}
	};
}