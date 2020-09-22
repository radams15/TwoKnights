board = [[0 for _ in range(8)] for _ in range(8)]
print_board = lambda: [print(x) for x in board]

def get_point(x,y):
	return board[x][y]

def set_point(x,y,v):
	board[x][y] = v
