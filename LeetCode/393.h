#pragma once
#include "leetcode.h"

namespace _393 {
	class Solution {
	public:
		bool validUtf8(vector<int>& data) {
			int state = 0;//start
			int i = 0, count=0;
			while (i < data.size())
			{
				char b = (char)(data[i]);
				switch (state)
				{
				case 0:
					if ((b & 128) == 0)//0xxxxxxx
						state = 0;//1byte,and start
					else if ((b & 0xe0) == 0xc0)//b&11100000=11000000
						state = 1;//2byte
					else if ((b & 0xf0) == 0xe0)//b&11110000=11100000
						state = 2;//3byte
					else if ((b & 0xf8) == 0xf0)//b&11111000=11110000
						state = 3;//4byte
					else
						state = -1;
					count = 0;	
					break;
				case 1:
				case 2:
				case 3:
					if ((b & 0xc0) == 0x80)//b&11000000=10000000
					{
						count++;
						if (count == state)
							state = 0;
					}
					else {
						state = -1;
					}
					break;
				default:
					return false;
				}
				i++;
			}
			return state == 0;
		}
	};
}