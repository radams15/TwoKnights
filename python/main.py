import random

from board import *

def get_moves(board,x, y):
    out=[]
    for x1,y1 in [[1,2],[2,1],[-1,2],[2,-1],[-2,1],[1,-2],[-1,-2],[-2,-1]]:
        nx,ny = x+x1, y+y1
        if 0<nx<8 and 0<ny<8:
            if get_board(board, nx, ny) != 1:
                out.append((nx,ny))
    return out

def get_all_moves(board):
    out = {}
    for x in range(8):
        for y in range(8):
            moves = get_moves(board, x, y)
            if moves:
                out[(x,y)] = moves
    return out

def print_plots(plots):
    board = gen_board()
    for plot in plots:
        set_board(board, *plot, 1)
    print_board(board)


def run(i, board):
    point = (0, 0)

    out = []

    moves = get_moves(board, *point)

    if not moves:
        return out

    try:
        point = moves[i]
    except:
        return out

    out.append(point)

    set_board(board, *point, 1)

    for move in out:
        set_board(board, *move, 0)

    return out

def main():
    board = gen_board()

    point = (0, 0)

    out = []

    set_board(board, *point, 1)
    while True:
        moves = get_moves(board, *point)
        print(moves)

        if not moves:
            break

        tried = []
        for i in range(len(moves)):
            tried.append([i, run(i, board)])

        id_to_get = sorted(tried, key=lambda move: len(move[1])) # sort by length of try
        point = moves[id_to_get[0][0]]

        out.append(point)

        set_board(board, *point, 1)

    print_board(board)

    return out

main()