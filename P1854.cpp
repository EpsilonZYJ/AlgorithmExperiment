// DONE
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

struct node {
    int data;
    int last_x;
    int last_y;
};

const int MAX = 105;
int Value[MAX][MAX];
int Answer[MAX];
node dp[MAX][MAX];
// dp[i][j]: 前i束花在前j个花瓶中的最大值
// dp[i][j] = max(dp[i-1][j-1]+Value[i][j], dp[i][j-1])

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int F, V;
    cin >> F >> V;
    for(int i = 1; i <= F; i ++)
        for(int j = 1; j <= V; j ++)
            cin >> Value[i][j];

    node* start = &dp[0][0];
    for (int i = 0; i < sizeof(dp)/sizeof(dp[0][0]); i++)
        (start+i)->data = INT_MIN;
    for(int i = 0; i <= V; i ++)
        dp[0][i].data = 0;
    for(int i = 1; i <= F; i ++){
        for(int j = i; j <= V; j ++){
            if(dp[i-1][j-1].data+Value[i][j] > dp[i][j-1].data){
                dp[i][j].data = dp[i-1][j-1].data+Value[i][j];
                dp[i][j].last_x = i-1;
                dp[i][j].last_y = j-1;
            }
            else{
                dp[i][j].data = dp[i][j-1].data;
                dp[i][j].last_x = i;
                dp[i][j].last_y = j-1;
            }
        }
    }
    cout << dp[F][V].data << endl;
    int i = F;
    pair<int, int> last;
    last.first = F;
    last.second = V;
    while (i > 0) {
        while (dp[last.first][last.second].last_x == i) {
            // last.second --;
            last.first = dp[i][last.second].last_x;
            last.second = dp[i][last.second].last_y;
        }
        Answer[last.first] = last.second;
        int x_tmp = last.first;
        int y_tmp = last.second;
        last.first = dp[x_tmp][y_tmp].last_x;
        last.second = dp[x_tmp][y_tmp].last_y;
        i --;

    }
    for (int i = 1; i <= F; i ++)
        cout << Answer[i] << " ";
    cout << endl;

    return 0;
}