#include <iostream>
#include <climits>

using namespace std;

const int MAX_SIZE = 60;
int f[MAX_SIZE][MAX_SIZE];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) {
            f[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < s.length(); i++) {
        f[i][i] = 1;
    }
    for(int l = 1; l < s.length(); l++) {
        for(int j = 0; j+l < s.length(); j ++){
            // 左右两端相等，则看是否能为中间的格子向外延伸伊格
            if(s[j+l] == s[j])
                f[j][j+l] = f[j][j+l-1];
            // 对于所有的涂色，都可以分为左右单独涂色的情况
            else {
                f[j][j+l] = f[j][j] + f[j+1][j+l];
                for(int k = j+1; k < j+l; k ++) {
                    f[j][j+l] = min(f[j][j+l], f[j][k] + f[k+1][j+l]);
                }
            }
        }
    }
    cout << f[0][s.length()-1] << endl;;
    return 0;
}