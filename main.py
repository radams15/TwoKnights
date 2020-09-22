from board import *

def get_moves(x, y):
        out=[]
        for x1,y1 in [[1,2],[2,1],[-1,2],[2,-1],[-2,1],[1,-2],[-1,-2],[-2,-1]]:
                nx,ny = x+x1, y+y1
                if 0<nx<8 and 0<ny<8:
                        if get_point(nx,ny) is not 1:
                                out.append((nx,ny))
        return out

def get_all_moves():
        out = {}
        for x in range(8):
                for y in range(8):
                        moves = get_moves(x,y)
                        if moves:
                                out[(x,y)] = moves
        return out

all_moves = get_all_moves()

history = []
i=0
point=(0,0)

while True:
        moves = get_moves(*point)
        print(moves)

        if not moves:
                print_board()
                break

        point = moves[0]

        set_point(*point, 1)
