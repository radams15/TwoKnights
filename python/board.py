gen_board = lambda: [[0 for _ in range(8)] for _ in range(8)]

def print_board(board):
	for x in board:
		for y in x:
			print("#" if y is 1 else "_", end="")
		print()

def get_point(board, x,y):
        return board[x][y]

def set_point(board, x,y,v):
        board[x][y] = v
