"""You are given a 9 x 9 Sudoku board board.

A Sudoku board is valid if the following rules are followed:

Each row must contain the digits 1-9 without duplicates.
Each column must contain the digits 1-9 without duplicates.
Each of the nine 3 x 3 sub-boxes of the grid must contain the
digits 1-9 without duplicates.
Return true if the Sudoku board is valid, otherwise return false

Note: A board does not need to be full or be solvable to be valid.
"""

from typing import List
from collections import defaultdict


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        cols = defaultdict(set)
        rows = defaultdict(set)
        squares = defaultdict(set)  # key (r/3, c/3)

        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    continue
                if (
                    board[r][c] in rows[r]
                    or board[r][c] in cols[c]
                    or board[r][c] in squares[(r // 3, c // 3)]
                ):
                    return False
                cols[c].add(board[r][c])
                rows[r].add(board[r][c])
                squares[((r // 3, c // 3))].add(board[r][c])
        return True


if __name__ == "__main__":
    # Integer division
    print(8 // 3)

    sol = Solution()
    print(
        sol.isValidSudoku(
            [
                ["1", "2", ".", ".", "3", ".", ".", ".", "."],
                ["4", ".", ".", "5", ".", ".", ".", ".", "."],
                [".", "9", "8", ".", ".", ".", ".", ".", "3"],
                ["5", ".", ".", ".", "6", ".", ".", ".", "4"],
                [".", ".", ".", "8", ".", "3", ".", ".", "5"],
                ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
                [".", ".", ".", ".", ".", ".", "2", ".", "."],
                [".", ".", ".", "4", "1", "9", ".", ".", "8"],
                [".", ".", ".", ".", "8", ".", ".", "7", "9"],
            ]
        )
    )  # True

    print(
        sol.isValidSudoku(
            [
                ["1", "2", ".", ".", "3", ".", ".", ".", "."],
                ["4", ".", ".", "5", ".", ".", ".", ".", "."],
                [".", "9", "1", ".", ".", ".", ".", ".", "3"],
                ["5", ".", ".", ".", "6", ".", ".", ".", "4"],
                [".", ".", ".", "8", ".", "3", ".", ".", "5"],
                ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
                [".", ".", ".", ".", ".", ".", "2", ".", "."],
                [".", ".", ".", "4", "1", "9", ".", ".", "8"],
                [".", ".", ".", ".", "8", ".", ".", "7", "9"],
            ]
        )
    )  # False
