// DONE
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int answer[100002];
int pathLength[1002][1002];
char maze[1002][1002];
const pair<int, int> direction[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

pair<int, int> operator+(pair<int, int> p1, pair<int, int> p2){
    return make_pair(p1.first + p2.first, p1.second + p2.second);
}

void dfs(const pair<int, int> &current,int flag,int tag){
    if (current.first<0 || current.first>=n || current.second<0 || current.second>=n
        || pathLength[current.first][current.second]!=-1 || maze[current.first][current.second]-'0'!=flag)
        return;
    pathLength[current.first][current.second]=tag;
    answer[tag]++;
    for (int i=0;i<4;i++) {
        pair<int, int> p1 = direction[i]+current;
        dfs(p1,!flag,tag);
    }
}
int main()
{
    cin >> n >> m;
    for (int i=0;i<n;i++)
        scanf("%s",maze[i]);
    memset(pathLength,-1,sizeof(pathLength));
    for (int i=0;i<m;i++)
    {
        pair<int, int> query;
        cin >> query.first >> query.second;
        query.first--;
        query.second--;
        if (pathLength[query.first][query.second]==-1)
            dfs(query, maze[query.first][query.second]-'0', i);
        else
            answer[i] = answer[pathLength[query.first][query.second]];
    }
    for (int i=0;i<m;i++)
        cout << answer[i] << "\n";
    return 0;
}