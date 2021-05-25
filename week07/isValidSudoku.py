class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        if not board:
            return False

        row = [set() for _ in range(9)]
        col = [set() for _ in range(9)]
        square = [set() for _ in range(9)]

        for i in range(9):
            for j in range(9):
                if board[i][j] != '.' and board[i][j] not in row[i] and board[i][j] not in col[j] \
                        and board[i][j] not in square[i//3 * 3 + j // 3]:
                    row[i].add(board[i][j])
                    col[j].add(board[i][j])
                    square[i // 3 * 3 + j // 3].add(board[i][j])
                else:
                    if board[i][j] == '.':
                        continue
                    else:
                        return False
        return True