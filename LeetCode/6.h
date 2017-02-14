#pragma once
#include "leetcode.h"

namespace _6
{
	class Solution {
	public:
		string convert(string s, int numRows) {
			if (numRows == 1)
				return s;
			int col = (s.size() / (2 * numRows - 2) + 1) * 2;
			char* arr = new char[numRows*col];
			memset(arr, 0, numRows*col*sizeof(char));
			int m = 0, n = 0, i=0;//m为行，n为列
			while (i < s.size()) {
				if (n % 2 == 0) {//偶数列，可放numRows个
					if (m >= numRows){
						m = numRows-2; n++;//从下标1开始
						
					}
				}
				if (n % 2 == 1) {//另开一个if，用于处理奇数列不能放的情况
					if (m <= 0) {
						m = 0; n++;
					}
				}
				arr[m*col + n] = s[i];
				i++;
				if (n % 2 == 0) m++;
				else m--;
			}
			string result = "";
			for (size_t i = 0; i < numRows; i++) {
				for (size_t j = 0; j < col; j++) {
					if (arr[i*col + j] != 0) {
						result += arr[i*col + j];
					}
				}
			}
			delete[] arr;
			return result;
		}
	};
}