#include <iostream>

using namespace std;

const int MAX = 1050;
const pair<int, int> direction[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int maze[MAX][MAX];
int pathLength[MAX][MAX];

pair<int, int> operator+(pair<int, int> p1, pair<int, int> p2){
    return make_pair(p1.first + p2.first, p1.second + p2.second);
}

inline bool isValid(const pair<int, int> &cur, const pair<int, int> &pos, int limit){
    return pos.first > 0 && pos.second > 0 && pos.first <= limit && pos.second <= limit && maze[cur.first][cur.second] != maze[pos.first][pos.second];
}

int searchPath(const pair<int, int> &current, int limit){
    int path = 1;
    for(int i = 0; i < 4; i ++){
        pair<int, int> nextPos = current+direction[i];
        if(isValid(current, nextPos, limit))
            path =
    }
    return path;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c;
            while ((cin >> c) && c == '\n');
            maze[i][j] = c-'0';
        }
    }
    memset(pathLength, -1, sizeof(pathLength));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            searchPath(make_pair(i, j), n);
        }
    }

    for(int i = 0; i < m; i ++){
        pair<int, int> query;
        cin >> query.first >> query.second;
        cout << maze[query.first][query.second] << endl;
    }

    return 0;
}