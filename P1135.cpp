// DONE
#include <iostream>
#include <queue>

using namespace std;

const int N_MAX = 205;

int floorMove[N_MAX];
int visited[N_MAX];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i ++){
        cin >> floorMove[i];
    }
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int cur = q.front();
        int nxt = cur+floorMove[cur];
        if(nxt <= n){
            if(nxt == b && nxt != a){
                visited[nxt] = visited[cur] + 1;
                break;
            }
            else if(visited[nxt] == 0 && nxt != a){
                visited[nxt] = visited[cur] + 1;
                q.push(nxt);
            }
        }
        nxt = cur-floorMove[cur];
        if(nxt > 0){
            if(nxt == b && nxt != a){
                visited[nxt] = visited[cur] + 1;
                break;
            }
            else if(visited[nxt] == 0 && nxt != a){
                visited[nxt] = visited[cur] + 1;
                q.push(nxt);
            }

        }
        q.pop();
    }
    cout << (visited[b] == 0 ? (b == a ? 0 : -1) : visited[b]) << endl;

    return 0;
}