//PROJECT SUDOKU_SOLVER
// VAIBHAV KUMAR
//2021MCB1219



#include<bits/stdc++.h>
using namespace std;


pair<int,int> find_empty(vector<vector<int>> board){
    /* find_empty function return the position of block that is row & column in the form of pair*/
    for(int j=0;j<9;j++){
        for(int k=0;k<9;k++){
            if(board[j][k]==0){
                return {j,k};
            }
        }
    }
    return {-1,-1};
}

bool is_valid(int row,int col,int num,vector<vector<int>>board){
    /* is_valid function takes argument num,row,col & board and checks if the num is valid at position (row,col) in the given board */
    /*Checking the row if the num is not already present*/
    for(int j=0;j<9;j++){
        if(board[row][j]==num){
            return false;
        }
    }
    /*Checking the col if the num is not already present*/
    for(int j=0;j<9;j++){
        if(board[j][col]==num){
            return false;
        }
    }

    /*Checking the 3x3 box for the respective (row,col) if the num is not already present*/
    int start_row=(row/3)*3;
    int start_col=(col/3)*3;
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            if(board[start_row+j][start_col+k]==num){
                return false;
            }
        }
    }

    return true;
}

bool Sudoku_Solver(vector<vector<int>>&board){
    /*Sudoku_Solver Function backtracks every possible ways and return the valid solution */
    /*Finding the empty cell in the board*/
    pair<int,int>position=find_empty(board);
    int row=position.first;
    int col=position.second;
    if(row==-1 && col==-1){
        return true;
    }
    else{

        for(int j=1;j<=9;j++){
            /*Checking the validity of cell with num from range 1 to 9*/
            if(is_valid(row,col,j,board)==true){
                board[row][col]=j;
                /*If cell is valid with num we recursively call Sudoku_Solver if it results to a valid solution,
                    If the solution is not valid with the given num we revert the cell value back to 0 */
                if(Sudoku_Solver(board)==true){
                    return true;
                }
                else{
                    board[row][col]=0;
                }
            }
        }
        return false;
    }
}



int main(){
//GIVEN SUDOKU BOARD TO BE SOLVED
vector<vector<int>>
board = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

//CALLING OF Sudoku-Solver function if it can result into a valid solution
if(Sudoku_Solver(board)==true)
{

for(int j=0;j<9;j++){
    for(int k=0;k<9;k++){
        cout<<board[j][k]<<" ";
    }
    cout<<"\n";
}
}
else{
    cout<<"NO VALID SOLUTION FOR THE GIVEN INITIAL VALUES ON THE SUDOKU BOARD\n";
}

    return 0;
}