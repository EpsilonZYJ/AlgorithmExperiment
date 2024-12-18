// DONE
#include <iostream>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::max;
using std::min;

#define ABS(x) (((x) < 0) ? -(x) : (x))

using ll = long long;
const int MAX_N = 200005;
int weight[MAX_N];
int value[MAX_N];
ll num_prefix[MAX_N];
ll value_prefix[MAX_N];
pair<int, int> range[MAX_N];
int n, m;
int max_weight = -1;
int min_weight = INT_MAX;
enum Mode{ADD, MINUS};
ll answer;
int left, right, mid;
ll object;
ll s;
ll y = 0;

Mode check(int checkWeight){
    y = 0;
    object = 0;
    num_prefix[0] = 0;
    value_prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        if(weight[i] >= checkWeight){
            num_prefix[i] = num_prefix[i-1] + 1;
            value_prefix[i] = value_prefix[i-1] + value[i];
        }
        else{
            num_prefix[i] = num_prefix[i-1];
            value_prefix[i] = value_prefix[i-1];
        }
    }
    for(int i = 1; i <= m; i ++){
        y += (num_prefix[range[i].second] - num_prefix[range[i].first - 1])
                *(value_prefix[range[i].second] - value_prefix[range[i].first - 1]);
    }
    object = ABS(y-s);

    if(y > s)
        return ADD;
    else
        return MINUS;
}

int main(){
    std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 0; i < n; i ++){
        cin >> weight[i+1] >> value[i+1];
        max_weight = max(max_weight, weight[i+1]);
        min_weight = min(min_weight, weight[i+1]);
    }
    for(int i = 1; i <= m; i ++)
        cin >> range[i].first >> range[i].second;
    answer = 0x3f3f3f3f3f3f3f3f;
    left = min_weight - 1;
    right = max_weight + 2;    //包含Y==0点情况
    while(left <= right){
        mid = (left + right) / 2;
        if(check(mid) == ADD) left = mid + 1;
        else if(check(mid) == MINUS) right = mid - 1;
        answer = min(answer, object);
    }
    cout << answer << endl;
    return 0;
}
