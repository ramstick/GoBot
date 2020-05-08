#include <iostream>
#include <queue>
using namespace std;

#define NUM_MATCHES 50
#define NUM_GENERATIONS 50
#define BOARD_SIZE 19

struct Coord{
    short x,y;
    Coord(short x, short y){
        this->x = x;
        this->y = y;
    }
};

struct GoBoard {
    short board [BOARD_SIZE][BOARD_SIZE];
    queue<Coord> board_cache;
    bool visited [BOARD_SIZE][BOARD_SIZE];
    void setUpBoard(){
        for (int i = 0; i < BOARD_SIZE; i ++){
            for (int j = 0; j < BOARD_SIZE; j ++){
                board[j][i] = 0;
                visited[j][i] = false;
            }    
        }
    }

    bool playMove(short player, short x, short y){
        board[y][x] = player;
        if(checkLiberties(x,y) == 0){
            board[y][x] = 0;
            return false;
        }
        if(checkLiberties(x+1,y) == 0){
            while(!board_cache.empty()){
                Coord a = board_cache.front();
                board[a.y][a.x] = 0;
                board_cache.pop();
            }
        }
        if(checkLiberties(x-1,y) == 0){
            while(!board_cache.empty()){
                Coord a = board_cache.front();
                board[a.y][a.x] = 0;
                board_cache.pop();
            }
        }
        if(checkLiberties(x,y+1) == 0){
            while(!board_cache.empty()){
                Coord a = board_cache.front();
                board[a.y][a.x] = 0;
                board_cache.pop();
            }
        }
        if(checkLiberties(x,y-1) == 0){
            while(!board_cache.empty()){
                Coord a = board_cache.front();
                board[a.y][a.x] = 0;
                board_cache.pop();
            }
        }
    }
    int checkLiberties(short x, short y) {
        if(y < 0 || y >= BOARD_SIZE || x < 0 || x >= BOARD_SIZE) {return 0;}
        if(board[y][x]==0) {return 1;}
        if(visited[y][x]) {return 0;}
        visited[y][x] = true;
        cout << x << " " << y << endl;
        short a = board[y][x];
        short out = 0;
        board_cache.push(Coord(x,y));
        if(0 == board[y][x-1]){
            out ++;
        }
        if(0 == board[y][x+1]){
            out ++;
        }
        if(0 == board[y-1][x]){
            out ++;
        }
        if(0 == board[y+1][x]){
            out ++;
        }
        if(a == board[y][x-1]){
            out += checkLiberties(x-1,y);
        }
        if(a == board[y][x+1]){
            out += checkLiberties(x+1,y);
        }
        if(a == board[y-1][x]){
            out += checkLiberties(x,y-1);
        }
        if(a == board[y+1][x]){
            out += checkLiberties(x,y+1);
        }
        return out;
    } 

    void print(){
        for (int i = 0; i < BOARD_SIZE; i ++){
            for (int j = 0; j < BOARD_SIZE; j ++){
                cout << "    " << board[i][j];
            }    
            cout << endl;
        }
    }

    void printDead(){
        
    }
};

int main() {
    GoBoard board;
    board.setUpBoard();
    board.playMove(1,1,0);
    board.print();
}
