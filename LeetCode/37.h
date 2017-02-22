#pragma once
#include "leetcode.h"

namespace _37 {
	class Solution {
	public:
		void solveSudoku(vector<vector<char>>& board) {
			//输入的必须是合法的
			map_row.clear();
			map_col.clear();
			map_grid.clear();
			int count = 0;
			for (int i = 0; i < 9; i++) {
				unordered_set<char> row;
				unordered_set<char> col;
				unordered_set<char> grid;
				map_row[i] = row;
				map_col[i] = col;
				map_grid[i] = grid;
			}
			for (int i = 0; i < 9; i++) {
				unordered_set<char> set;
				for (int m = 3 * (i / 3); m < 3 * (i / 3) + 3; m++) {
					for (int n = 3 * (i % 3); n < 3 * (i % 3) + 3; n++) {
						if (board[m][n] == '.')
						{
							count++;
							continue;
						}
						map_row[m].insert(board[m][n]);
						map_col[n].insert(board[m][n]);
						map_grid[i].insert(board[m][n]);
					}
				}
			}
			solveSudoku(board, count);
		}

	private:
		unordered_map<int, unordered_set<char>> map_row, map_col, map_grid;
		vector<char> getChoices(vector<vector<char>>& board, int row, int col) {
			vector<char> choices;
			int grid = 3*(row / 3) + col / 3;
			for (int i = 0; i < 9; i++) {
				char ch = '1' + i;
				if (map_row[row].find(ch) == map_row[row].end() &&
					map_col[col].find(ch) == map_col[col].end() &&
					map_grid[grid].find(ch) == map_grid[grid].end())
					choices.push_back(ch);
			}
			return choices;
		}

		bool solveSudoku(vector<vector<char>>& board, int remaining) {
			if (remaining == 0)
				return true;
			for (int row = 0; row < 9; row++) {
				for (int col = 0; col < 9; col++) {
					if (board[row][col] == '.') {
						int grid = 3 * (row / 3) + col / 3;
						vector<char> choices = getChoices(board, row, col);
						if (choices.size() == 0)
							return false;
						for (int i = 0; i < choices.size(); i++) {
							board[row][col] = choices[i];
							map_row[row].insert(choices[i]);
							map_col[col].insert(choices[i]);
							map_grid[grid].insert(choices[i]);
							if (solveSudoku(board, remaining - 1))
								return true;
							map_row[row].erase(choices[i]);
							map_col[col].erase(choices[i]);
							map_grid[grid].erase(choices[i]);
							board[row][col] = '.';
						}
						return false;
					}
				}
			}
			return true;
		}
	};
}