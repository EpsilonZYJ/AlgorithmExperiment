// DONE
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;
int n, m, num, answer;

int fa[MAX_N];
struct node{
    int x, y, t;
    bool operator<(const node &a) const{
        return t < a.t;
    }
}e[MAX_N];

int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++){
        cin >> e[i].x >> e[i].y >> e[i].t;
    }
    sort(e + 1, e + m + 1);
    for(int i = 1; i <= m; i ++){
        int x = find(e[i].x);
        int y = find(e[i].y);
        if(x == y) continue;
        fa[x] = y;
        num++;
        answer = max(answer, e[i].t);
    }
    if(num != n-1)
        cout << "-1" << endl;
    else
        cout << answer << endl;
    return 0;
}