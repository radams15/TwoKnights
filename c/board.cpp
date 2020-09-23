#include <cstdlib>

#define OCCUPIED 1
#define NONE 0

int** gen_board(){
    int** out = (int**) malloc(8 * sizeof(int*));
    for(int x=0 ; x<8 ; x++){
        out[x] = (int*) malloc(8*sizeof(int));
        for(int i=0 ; i<8 ; i++){
            out[x][i] = NONE;
        }
    }
    return out;
}

void set_board(int** board, int x, int y, int v){
    board[x][y] = v;
}

int get_board(int** board, int x, int y){
    return board[x][y];
}

void free_board(int** board){
    for(int x=0 ; x<8 ; x++){
        free(board[x]);
    }
    free(board);
}

void print_board(int** board){
    for(int x=0 ; x<8 ; x++){
        for(int y=0 ; y<8 ; y++){
            printf("%d ", board[x][y]);
        }
        printf("\n");
    }
}
