// DONE
#include <iostream>
#include <algorithm>

using namespace std;

int n, x, answer, money[5000];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> x >> n;
    for(int i = 1; i <= n; i ++)
        cin >> money[i];
    sort(money+1, money+n+1);
    if (money[1] != 1) {
        cout << -1 << endl;
        return 0;
    }
    int sum = 0;
    while(sum < x){
        int index;
        for(index = n; index > 0; index --)
            if(money[index] <= sum + 1)
                break;
        answer ++;
        sum += money[index];
    }
    cout << answer << endl;
    return 0;
}