#include <iostream>
using namespace std;

struct node {
    int data;
    int last_x;
    int last_y;
};

const int MAX = 8;
int Value[MAX][MAX];
int Answer[MAX];
node dp[MAX][MAX];
// dp[i][j]: 第i束花放在第j个花瓶中的最大值
// dp[i][j] = max(dp[i-1][j-1]+Value[i][j], dp[i][j-1])

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int F, V;
    cin >> F >> V;
    for(int i = 1; i <= F; i ++)
        for(int j = 1; j <= V; j ++)
            cin >> Value[i][j];

    memset(dp, INT_MIN, sizeof(dp));
    dp[1][1].data = Value[1][1];
    for(int i = 0; i <= F; i ++)
        dp[0][i].data = 0;
    for(int i = 1; i <= F; i ++){
        for(int j = 1; j <= V; j ++){
            if(dp[i-1][j-1].data+Value[i][j] > dp[i][j-1].data){
                dp[i][j].data = dp[i-1][j-1].data+Value[i][j];
                dp[i][j].last_x = i-1;
                dp[i][j].last_y = j-1;
            }
            else{
                dp[i][j] = dp[i][j-1];
                dp[i][j].last_x = i;
                dp[i][j].last_y = j-1;
            }
        }
    }
    cout << dp[F][V].data << endl;
    int i = F;
    pair<int, int> last;
    last.first = dp[F][V].last_x;
    last.second = dp[F][V].last_y;
    while (i > 0) {
        if (last.first == i) {
            last.second --;
            last.first = dp[i][last.second].last_x;
            last.second = dp[i][last.second].last_y;
        }else {
            // Answer[i] = dp[last.first][last.second].data;
            Answer[i] = last.second+1;
            int x_tmp = last.first;
            int y_tmp = last.second;
            last.first = dp[x_tmp][y_tmp].last_x;
            last.second = dp[x_tmp][y_tmp].last_y;
            i --;
        }

    }
    for (int i = 1; i <= F; i ++)
        cout << Answer[i] << " ";
    cout << endl;

    return 0;
}