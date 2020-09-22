#include <stdio.h>

#include "board.c"

struct Moves{
    int** moves;
    int length;
};


int move_adds[8][2]= {
    {1,2},
    {2,1},
    {-1,2},
    {2,-1},
    {-2,1},
    {1,-2},
    {-1,-2},
    {-2,-1}
};

void free_moves(struct Moves moves){
    for(int i=0 ; i<moves.length ; i++){
        free(moves.moves[i]);
    }
    free(moves.moves);
}


void print_moves(struct Moves moves){
    for(int i=0 ; i<moves.length ; i++){
        printf("\t%d, %d, ", moves.moves[i][0], moves.moves[i][1]);
    }
    printf("\n");
}

struct Moves get_moves(int** board, int x, int y){
    struct Moves moves;
    moves.length = 0;
    moves.moves = malloc(0);
    
    for(int i=0 ; i<8 ; i++){
        int nx = x+move_adds[i][0];
        int ny = y+move_adds[i][1];
        
        if(nx>0 && nx<8 && ny>0 && ny<8 && get_board(board,nx,ny) != 1){
            moves.moves = realloc(moves.moves, moves.length*sizeof(int*));
            moves.moves[moves.length] = malloc(2*sizeof(int));
            
            moves.moves[moves.length][0] = nx;
            moves.moves[moves.length][1] = ny;
            moves.length++;
        }
    }
    return moves;
}

struct Moves run(){
    struct Moves history;
    
    int** board = gen_board();
    int point[2];
    
    history.moves = malloc(0);
    
    while(1){
        struct Moves moves = get_moves(board,0,0);
            printf("OGKDN\n");
        
        if(moves.length == 0){
            break;
        }
        
        int id_to_get = 0;
        int* point = moves.moves[id_to_get];
        history.length++;
        
        
        history.moves = realloc(history.moves, history.length*sizeof(int*));
        history.moves[moves.length] = malloc(2*sizeof(int));
        
        history.moves[moves.length][0] = point[0];
        history.moves[moves.length][1] = point[1];
        
        free_moves(moves);
    }

    free_board(board);
    return history;
}

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}


int main(){
    
    int largest = 0;
    
    while(1){
        struct Moves result = run();
        
        largest = max(result.length, largest);
        
        if(result.length == 64){
            print_moves(result);
            break;
        }
        
        free_moves(result);
    }

    return 0;
}
