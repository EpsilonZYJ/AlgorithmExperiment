// DONE
// 中位数
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> candy;
    for(ll i = 0; i < n; i ++){
        ll x;
        cin >> x;
        candy.push_back(x);
    }
    ll mean = 0;
    for (const auto& x : candy) {
        mean += x;
    }
    mean /= n;

    vector<ll> tmp_const(candy.size());
    ll a_sum = 0;
    for (ll i = 0; i < candy.size(); ++i) {
        a_sum += candy[i];
        tmp_const[i] = a_sum - i*mean;
    }
    sort(tmp_const.begin(), tmp_const.end());
    ll middle = tmp_const[candy.size()/2];
    ll ans = 0;
    for(const auto &i : tmp_const) {
        ans += abs(i-middle);
    }
    cout << ans << '\n';
    return 0;
}
