// DONE
#include <iostream>

using namespace std;

const int MAX_N = 500050;

int tree[MAX_N];
int input[MAX_N];
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
    // 前缀和
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
        cin >> input[i];
    }
    for(int i = 1; i <= m; i ++){
        int option;
        cin >> option;
        if(option == 1){
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k);
            add(y+1, -k);
        }
        else{
            int x;
            cin >> x;
            cout << input[x]+query(x) << endl;
        }
    }
    return 0;
}