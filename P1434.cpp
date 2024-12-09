// DONE
// 深度优先搜索
#include <iostream>

using namespace std;

const int MAX = 150;
pair<int, int> direction[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int snowMap[MAX][MAX];
int snowPathLength[MAX][MAX];

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

inline bool isValid(const pair<int, int> cur, const pair<int, int>& pos, const int R, const int C) {
    return pos.first > 0 && pos.second > 0 && pos.first <= R && pos.second <= C && snowMap[cur.first][cur.second] > snowMap[pos.first][pos.second];
}

int searchPath(const pair<int, int> &current, const int R, const int C){
    int pathLength = 1;
    if(snowPathLength[current.first][current.second]){
        return snowPathLength[current.first][current.second];
    }
    else{
        for(int i = 0; i < 4; i ++){
            pair<int, int> next = current+direction[i];
            if(!isValid(current,next, R, C)) {
                continue;
            }
            pathLength = max(pathLength, searchPath(next, R, C)+1);
        }
    }
    snowPathLength[current.first][current.second] = pathLength;
    return pathLength;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int R, C;
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> snowMap[i][j];
        }
    }
    int maxLength = 0;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            maxLength = max(maxLength, searchPath({i, j}, R, C));
        }
    }
    cout << maxLength << endl;
    return 0;
}