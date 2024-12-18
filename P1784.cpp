// DONE
#include <iostream>

using namespace std;

int Sudoku[10][10];
bool row[10][10], column[10][10], grid[10][10];

void printTable(){
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cout << Sudoku[i][j] << " ";
        }
        cout << endl;
    }
    exit(0);
}

void DFS(const pair<int, int> &position){
    if(Sudoku[position.first][position.second] != 0){
        // 如果有数字
        if(position.first == 9 && position.second == 9){
            printTable();
        }
        else if(position.second == 9){
            DFS(make_pair(position.first+1, 1));
        }
        else{
            DFS(make_pair(position.first, position.second+1));
        }
    }
    else{
        for(int i = 1; i <= 9; i ++){
            if( row[position.first][i] == true ||
                column[position.second][i] == true ||
                grid[(position.first-1)/3*3+(position.second-1)/3+1][i] == true)
                continue;
            row[position.first][i] = true;
            column[position.second][i] = true;
            grid[(position.first-1)/3*3+(position.second-1)/3+1][i] = true;
            Sudoku[position.first][position.second] = i;
            if(position.first == 9 && position.second == 9){
                printTable();
            }
            else if(position.second == 9){
                DFS(make_pair(position.first+1, 1));
            }
            else{
                DFS(make_pair(position.first, position.second+1));
            }
            row[position.first][i] = false;
            column[position.second][i] = false;
            grid[(position.first-1)/3*3+(position.second-1)/3+1][i] = false;
            Sudoku[position.first][position.second] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cin >> Sudoku[i][j];
            if(Sudoku[i][j] > 0){
                row[i][Sudoku[i][j]] = true; // 第i行的数字Sudoku[i][j]已经被使用
                column[j][Sudoku[i][j]] = true;
                grid[(i-1)/3*3+(j-1)/3+1][Sudoku[i][j]] = true;
            }
        }
    }
    DFS(make_pair(1, 1));
    return 0;
}