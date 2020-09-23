

def get_board(start=0):
    board = []
    for x in range(8):
        temp = []
        for y in range(8):
            temp.append(start)
        board.append(temp)
    return board

def is_won():
    for x in range(8):
        for y in range(8):
            if board[x][y] == 0:
                return False
    return True

def print_board():
    for x in range(8):
        print(board[x])

def get_moves(x1, y1):
    out = []
    for x, y in [[1, 2],[2, 1],[2, -1],[-1, 2],[-2, 1],[1, -2],[-1, -2],[-2, -1]]:
        possible = [x1+x, y1+y]
        if possible[0] < 0 or possible[1] < 0 or possible[0] > 7 or possible[1] > 7:
            continue

        if board[possible[0]][possible[1]] == 1:
            continue
        out.append(tuple(possible))

    return out

board = get_board(0)

move_history = []
history = {}
point = (0,0) # starting point

def move(moves=None):
    global point

    if not moves:
        moves = get_moves(*point)

    print("{} Moves!".format(len(moves)))

    choice_num = -1

    if not moves:
        board[point[0]][point[1]] = 0 # remove last move evidence
        try:
            point = move_history.pop() # get last point
            moves = get_moves(*point) # get moves from that point
            del moves[choice_num]
        except:
            return False

    history[point] = moves

    move_history.append(point)

    point = moves[choice_num]

    board[point[0]][point[1]] = 1

    print("Gone To [{},{}]".format(*point))

    return True

i=0
while move():
    i+=1

print_board()