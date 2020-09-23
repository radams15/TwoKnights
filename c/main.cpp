#include <cstdio>

#include <vector>
#include <ctime>
#include <unistd.h>
#include <string>
#include <fstream>

#include "board.cpp"

#define NUM_THREADS 2

using namespace std;

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


void print_moves(vector<vector<int>> moves){
    for(int i=0 ; i<moves.size() ; i++){
        printf("\t%d, %d, ", moves[i][0], moves[i][1]);
    }
    printf("\n");
}

struct vector<vector<int>> get_moves(int** board, int x, int y){
    vector<vector<int>> moves;

    for(int i=0 ; i<8 ; i++){
        int nx = x+move_adds[i][0];
        int ny = y+move_adds[i][1];
        
        if(nx>0 && nx<8 && ny>0 && ny<8){
            if(get_board(board,nx,ny) != OCCUPIED) {
                vector<int> move = {nx, ny};

                moves.push_back(move);
            }
        }
    }
    return moves;
}

struct vector<vector<int>> run(){
    vector<vector<int>> history;
    
    int** board = gen_board();
    int point[2] = {0,0};

    while(true){
        vector<vector<int>> moves = get_moves(board,point[0],point[1]);
        
        if(moves.empty()){
            break;
        }

        srand(time(nullptr));
        
        int id_to_get = rand()%moves.size();
        vector<int> temp_pnt = moves.at(id_to_get);
        point[0] = temp_pnt[0];
        point[1] = temp_pnt[1];

        set_board(board, point[0], point[1], OCCUPIED);

        history.push_back(temp_pnt);
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

void save_data(int pid, vector<vector<int>> data){
    string name = "../out/data_"+to_string(pid)+".txt";

    ofstream out;
    out.open(name);

    for(int i=0 ; i<data.size() ; i++){
        out << data[i][0] << "," << data[i][1] << "\n";
    }
    out.close();
}


int main(){
    int largest = 0;

    for(int i = 0; i <= NUM_THREADS ; i++) {
        int pid = fork();
        if(pid < 0 || pid == 0) {
            break;
        } else  {
            usleep(1000*100);
        }
    }

    while(true){
        vector<vector<int>> result = run();
        
        largest = max(result.size(), largest);

        printf("Largest: %d\n", largest);
        
        if(result.size() > 64){
            print_moves(result);
            save_data(getpid(), result);
            break;
        }
    }

    return 0;
}
