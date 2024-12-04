// DONE
#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int sum = 0;
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        pq.push(x);
    }
    while(pq.size() > 1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        sum += x+y;
        pq.push(x+y);
    }
    cout << sum;
    return 0;
}