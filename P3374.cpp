#include <iostream>

using namespace std;

const int MAX_N = 500050;

int tree[MAX_N];
int n, m;

inline int lowbit(int x){
    return x&(-x);
}

void add(int pos, int val){
    while(pos <= n){
        tree[pos] += val;
        pos += lowbit(pos);
    }
}

int query(int pos){
    int sum = 0;
    while(pos){
        sum += tree[pos];
        pos -= lowbit(pos);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        int t;
        cin >> t;
        add(i, t);
    }
    for(int i = 1; i <= m; i ++){
        int option, x, y;
        cin >> option >> x >> y;
        if(option == 1){
            add(x, y);
        }
        else{
            cout << query(y) - query(x - 1) << endl;
        }
    }
    return 0;
}