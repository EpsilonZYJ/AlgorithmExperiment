// DONE
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <memory>

using namespace std;

struct searchMap{
public:
    int xMax, yMax;
    int *base = nullptr;

    searchMap() = delete;
    ~searchMap(){
        if(base != nullptr){
            delete[] base;
            base = nullptr;
        }
        xMax = 0;
        yMax = 0;
    }
    searchMap(int yMax, int xMax){
        searchMap::xMax = xMax;
        searchMap::yMax = yMax;
        base = new int[(xMax+1)*(yMax+1)];
        memset(base, -1, sizeof(int)*(xMax+1)*(yMax+1));
    }
    int* operator[](int i){
        return base+i*(xMax+1);
    }
    void printMap(){
        for(int i = 1; i <= yMax; i ++)
            for(int j = 1; j <= xMax; j ++)
                cout << *(base+i*(xMax+1)+j) << " \n"[j == xMax];
    }
};

pair<int, int> direction[] = {
                                {1, 2}, {2, 1}, 
                                {1, -2}, {2, -1},
                                {-1, 2}, {-2, 1},
                                {-1, -2}, {-2, -1}
                                };

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n;
    pair<int, int> start;
    cin >> n >> m >> start.first >> start.second;
    searchMap solution(n, m);
    solution[start.first][start.second] = 0;
    queue<pair<int, int>> q;
    q.push(start);
    while(!q.empty()){
        pair<int, int> cur_position = q.front();
        for(int i = 0; i < 8; i ++){
            int nxt_y = cur_position.first+direction[i].first;
            int nxt_x = cur_position.second+direction[i].second;
            if(nxt_y > n || nxt_y < 1 || nxt_x > m || nxt_x < 1)
                continue;
            if(solution[nxt_y][nxt_x] == -1){
                solution[nxt_y][nxt_x] = solution[cur_position.first][cur_position.second]+1;
                q.push(make_pair(nxt_y, nxt_x));
            }
        }
        q.pop();
    }
    solution.printMap();
    return 0;
}