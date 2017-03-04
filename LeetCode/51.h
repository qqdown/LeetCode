#pragma once
#include "leetcode.h"

namespace _51 {
	class Solution {
	public:
		vector<vector<string>> solveNQueens(int n) {
			vector<vector<char>> board(n);
			for (int i = 0; i < n; i++) {
				board[i] = vector<char>(n);
				for (int j = 0; j < n; j++) {
					board[i][j] = '.';
				}
			}
			result.clear();
			int *rowarr = new int[n], *colarr = new int[n], *dialarr = new int[2 * n], *diararr = new int[2 * n];
			memset(rowarr, 0, n*sizeof(int));
			memset(colarr, 0, n*sizeof(int));
			memset(dialarr, 0, 2*n*sizeof(int));
			memset(diararr, 0, 2*n*sizeof(int));
			for (int i = 0; i < n; i++) {
				solveNQueens(0, i, board, rowarr, colarr, dialarr, diararr, n);
			}
			delete[] rowarr;
			delete[] colarr;
			delete[] dialarr;
			delete[] diararr;
			return result;
		}

	private:
		vector<vector<string>> result;

		void solveNQueens(int row, int col, vector<vector<char>>&board, int rowarr[], int colarr[], int dialarr[], int diararr[], int n) {
			int dial = getDiaL(row, col, n), diar = getDiaR(row, col, n);
			if (rowarr[row] != 0 || colarr[col] != 0 || dialarr[dial] != 0 || diararr[diar] != 0)
				return;
			if (row == n - 1) {
				board[row][col] = 'Q';
				vector<string> res(n);
				for (int i = 0; i < board.size(); i++) {
					string str(board[i].begin(), board[i].end());
					res[i] = str;
				}
				result.push_back(res);
				board[row][col] = '.';
			}
			else {
				rowarr[row] = 1;
				colarr[col] = 1;
				dialarr[dial] = 1;
				diararr[diar] = 1;
				board[row][col] = 'Q';
				for (int i = 0; i < n; i++) {
					solveNQueens(row + 1, i, board, rowarr, colarr, dialarr, diararr, n);
				}
				rowarr[row] = 0;
				colarr[col] = 0;
				dialarr[dial] = 0;
				diararr[diar] = 0;
				board[row][col] = '.';
			}
		}

		int getDiaL(int row, int col, int n) {
			return row + col;
		}

		int getDiaR(int row, int col, int n) {
			return row + (n - col - 1);
		}

	};
}