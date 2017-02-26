#pragma once
#include "leetcode.h"

namespace _529 {
	class Solution {
	public:
		vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
			updateBoard(board, click[0], click[1]);
			return board;
		}

		void updateBoard(vector<vector<char>>& board, int i, int j) {
			if (board[i][j] == 'M') {
				board[i][j] = 'X';
			}
			if (board[i][j] == 'E') {
				int findMine = getMineNum(board, i, j);
				if (findMine > 0) {
					board[i][j] = '0'+findMine;
				}
				else {
					board[i][j] = 'B';
					if (i - 1 >= 0 && board[i - 1][j] == 'E')
						updateBoard(board, i - 1, j);
					if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 'E')
						updateBoard(board, i - 1, j-1);
					if (i - 1 >= 0 && j + 1 < board[0].size() && board[i - 1][j + 1] == 'E')
						updateBoard(board, i - 1, j+1);
					if (i + 1 < board.size() && board[i + 1][j] == 'E')
						updateBoard(board, i +1, j);
					if (i + 1 < board.size() && j - 1 >= 0 && board[i + 1][j - 1] == 'E')
						updateBoard(board, i+1 , j-1);
					if (i + 1 < board.size() && j + 1 < board[0].size() && board[i + 1][j + 1] == 'E')
						updateBoard(board, i + 1, j+1);
					if (j - 1 >= 0 && board[i][j - 1] == 'E')
						updateBoard(board, i , j-1);
					if (j + 1 < board[0].size() && board[i][j + 1] == 'E')
						updateBoard(board, i , j+1);
				}
				
			}
		}
	private:
		int getMineNum(vector<vector<char>>& board, int i, int j) {
			int n = 0;
			if (i - 1 >= 0 && board[i - 1][j] == 'M')
				n++;
			if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 'M')
				n++;
			if (i - 1 >= 0 && j + 1 < board[0].size() && board[i - 1][j + 1] == 'M')
				n++;
			if (i + 1 < board.size() && board[i + 1][j] == 'M')
				n++;
			if (i + 1 < board.size() && j - 1 >= 0 && board[i + 1][j - 1] == 'M')
				n++;
			if (i + 1 < board.size() && j + 1 < board[0].size() && board[i + 1][j + 1] == 'M')
				n++;
			if (j - 1 >= 0 && board[i][j - 1] == 'M')
				n++;
			if (j + 1 < board[0].size() && board[i][j + 1] == 'M')
				n++;
			return n;
		}
	};
}