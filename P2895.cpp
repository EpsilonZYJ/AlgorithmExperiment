#include <iostream>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

const int N = 305;

const pair<int, int> direction[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b){
    return make_pair(a.first+b.first, a.second+b.second);
}

bool positionValid(const pair<int, int> &position){
    return position.first >= 0 && position.second >= 0;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int regionMap[N][N];
    int memory[N][N];
    for(auto & i : regionMap)
        for(int & j : i)
            j = INT_MAX;
    for(auto & i : memory)
        for(int & j : i)
            j = 0;
    int M, X_i, Y_i, T_i;
    cin >> M;
    for(int i = 0; i < M; i ++){
        cin >> X_i >> Y_i >> T_i;
        regionMap[X_i][Y_i] = min(regionMap[X_i][Y_i], T_i);
        if(X_i-1 >= 0)
            regionMap[X_i-1][Y_i] = min(regionMap[X_i-1][Y_i], T_i);
        if(Y_i-1 >= 0)
            regionMap[X_i][Y_i-1] = min(regionMap[X_i][Y_i-1], T_i);
//        if(X_i+1 <= 300)
            regionMap[X_i+1][Y_i] = min(regionMap[X_i+1][Y_i], T_i);
//        if(Y_i+1 <= 300)
            regionMap[X_i][Y_i+1] = min(regionMap[X_i][Y_i+1], T_i);
    }
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 0));
    memory[0][0] = 1;
    while(!q.empty()){
        pair<pair<int, int>, int> cur_pos_time = q.front();
        pair<int, int> cur_pos = cur_pos_time.first;
        q.pop();
//        for(int i = 0; i < 4; i ++){
//            pair<int, int> next_pos = cur_pos+direction[i];
//            if(!positionValid(next_pos))
//                continue;
//            if(regionMap[next_pos.first][next_pos.second] == INT_MAX){
//                cout << cur_pos_time.second+1;
//                return 0;
//            }
//            else if(regionMap[next_pos.first][next_pos.second] <= cur_pos_time.second+1)
//                continue;
//            else if(memory[next_pos.first][next_pos.second] == INT_MAX){
//                q.push(make_pair(next_pos, cur_pos_time.second+1));
//            }
//        }
        for(int i = 0; i < 4; i ++){
            pair<int, int> next_pos = cur_pos+direction[i];
            if(positionValid(next_pos) && memory[next_pos.first][next_pos.second]==0 && regionMap[next_pos.first][next_pos.second] > cur_pos_time.second+1){
                memory[next_pos.first][next_pos.second] = 1;
                q.push(make_pair(next_pos, cur_pos_time.second+1));
                if(regionMap[next_pos.first][next_pos.second] == INT_MAX){
                    cout << cur_pos_time.second + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << -1 << "\n";

    return 0;
}