// DONE
#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;

bool satisfy(vector<ull>& rock_pos, ull now_step, ull limited_rocks, ull last){
    ull cnt = 0;
    ull now_pos = 0;
    ull next_pos = 1;
    while(next_pos < rock_pos.size()){
        if(rock_pos[next_pos] - rock_pos[now_pos] < now_step){
            cnt ++;
            next_pos ++;
        }else{
            now_pos = next_pos;
            next_pos ++;
        }
    }

    if(cnt > limited_rocks)
        return false;
    else
        return true;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ull L, M, N;
    cin >> L >> M >> N;
    vector<ull> distance(M+2, 0);
    distance[0] = 0;
    distance[M+1] = L;
    for(ull i = 1; i <= M; i ++){
        cin >> distance[i];
    }

    ull left, right, mid;
    left = 0;
    right = L;
    ull answer;

    // 将跳跃的步数的范围进行二分试错
    while(left <= right){
        mid = (left+right)/2;
        if(satisfy(distance, mid, N, L)) {
            answer = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}
