

gen_board = lambda: [[0 for _ in range(8)] for _ in range(8)]
print_board = lambda: [print(x) for x in board]

def get_point(board, x,y):
        return board[x][y]

def set_point(board, x,y,v):
        board[x][y] = v
