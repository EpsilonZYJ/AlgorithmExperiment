// DONE
#include <iostream>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

const int MAX_N = 105;

int n, m, s, t;
int graph[MAX_N][MAX_N];
int pre[MAX_N];
bool visited[MAX_N];

int BFS(){
    memset(pre, -1, sizeof(pre));
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i <= n+1; i++){
            if(visited[i] == false && graph[u][i] > 0){
                visited[i] = true;
                pre[i] = u;
                q.push(i);
                if(i == t)
                    return true;
            }
        }
    }
    return false;
}

int EK(){
    int u, v;
    int maxflow = 0;
    while(BFS()){
        // 使用BFS寻找增广路径
        maxflow ++;
        v = t;
        while(v != s){
            u = pre[v]; // 寻找走过的路径
            graph[u][v] --; // 正向边的流量减少
            graph[v][u] ++; // 反向边的流量增加
            v = u; // 端点前移
        }
    }
    return maxflow;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    s = 0;
    t = n + 1;
    for (int i = 1; i <= m; i ++)
        graph[s][i] ++;
    for (int i = m + 1; i <= n; i ++)
        graph[i][t] ++;
    int u, v;
    cin >> u >> v;
    while(u != -1 && v != -1){
        graph[u][v] = 1;
        cin >> u >> v;
    }
    int maxflow = EK();
    cout << maxflow << endl;
    // 反向边即为匹配
    for(int i = 1; i <= m; i ++)
        for(int j = m+1; j <= n; j ++)
            if(graph[j][i] > 0)
                cout << i << " " << j << endl;
    return 0;
}