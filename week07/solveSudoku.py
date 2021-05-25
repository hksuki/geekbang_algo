class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def check(i, j):
            if int(board[i][j]) in row[i] or int(board[i][j]) in col[j] or int(board[i][j]) in square[i//3*3+j//3]:
                return False
            return True

        def solve():
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        for k in range(9):
                            board[i][j] = chr(ord('1')+k)
                            if check(i, j):
                                row[i].add(1+k)
                                col[j].add(1+k)
                                square[i//3*3+j//3].add(1+k)
                                if solve():
                                    return True
                                else:
                                    board[i][j] = '.'
                                    row[i].remove(1+k)
                                    col[j].remove(1+k)
                                    square[i//3*3+j//3].remove(1+k)
                            else:
                                board[i][j] = '.'
                        return False
            return True


        row = [set() for _ in range(9)]
        col = [set() for _ in range(9)]
        square = [set() for _ in range(9)]

        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                row[i].add(int(board[i][j]))
                col[j].add(int(board[i][j]))
                square[i//3*3+j//3].add(int(board[i][j]))
        solve()
        return
