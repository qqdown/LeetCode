#pragma once
#include "leetcode.h"

namespace _36 {
	class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			unordered_map<int, unordered_set<char>> map_row, map_col;
			for (int i = 0; i < 9; i++) {
				unordered_set<char> row;
				unordered_set<char> col;
				map_row[i] = row;
				map_col[i] = col;
			}
			for (int i = 0; i < 9; i++) {
				unordered_set<char> set;
				for (int m = 3*(i / 3); m < 3*(i / 3) + 3; m++) {
					for (int n = 3*(i % 3); n < 3*(i % 3) + 3; n++) {
						if (board[m][n] == '.')
							continue;
						if (set.find(board[m][n]) != set.end())
							return false;
						set.insert(board[m][n]);
						if (map_row[m].find(board[m][n]) != map_row[m].end())
							return false;
						if (map_col[n].find(board[m][n]) != map_col[n].end())
							return false;
						map_row[m].insert(board[m][n]);
						map_col[n].insert(board[m][n]);
					}
				}
			}

			return true;
		}
	};
}