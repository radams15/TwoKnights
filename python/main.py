import random

from board import *

def get_moves(board,x, y):
        out=[]
        for x1,y1 in [[1,2],[2,1],[-1,2],[2,-1],[-2,1],[1,-2],[-1,-2],[-2,-1]]:
                nx,ny = x+x1, y+y1
                if 0<nx<8 and 0<ny<8:
                        if get_point(board,nx,ny) is not 1:
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

def run():
        board = gen_board()
        history = []
        i=0
        point=(0,0)
        while True:
                moves = get_moves(board,*point)

                if not moves:
                        #print_board()
                        break

                id_to_get = random.randint(0,len(moves)-1)
                point = moves[id_to_get]
                history.append(point)

                set_point(board,*point, 1)
                i+=1
        
        return history

largest=0
while True:
        result = run()
        length = len(result)
        largest = max(largest,length)
        print(largest)
        if len(result) == 64:
                print(result)
                break
        

