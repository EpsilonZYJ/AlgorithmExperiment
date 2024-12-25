// DONE
#include <iostream>
#include <string>

using namespace std;
string strs[20];
int visited[20];
int length = 0, n;

int isValid(const string& str1, const string& str2) {
    for(int i = 1; i < min(str1.length(), str2.length()); i++) {
        int flag = 1;
        for(int j = 0; j < i; j++)
            if(str1[str1.length() - i + j] != str2[j])
                flag = 0;
        if(flag)
            return i;
    }
    return 0;
}
void dfs(const string& str, int len) {
    length = max(len, length);
    for(int i = 0; i < n; i++) {
        if(visited[i] >= 2)
            continue;
        int validLength = isValid(str, strs[i]);
        if(validLength > 0) {
            visited[i]++;
            dfs(strs[i], len + strs[i].length() - validLength);
            visited[i]--;
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i <= n; i++)
        cin >> strs[i];
    dfs(' '+strs[n], 1);
    cout << length << endl;
}