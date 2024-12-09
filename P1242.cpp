#include <iostream>
#include <vector>

const char plateArray[] = {'\0', 'A', 'B', 'C'};

using namespace std;

inline void movePlate(int plate, char from, char to){
    cout << "move " << plate << " from " << from << " to " << to << endl;
}

void dfs(vector<int> &plateInitState, vector<int> &plateFinalState, const int plate, const int to, int &num) {
    if (plateInitState[plate] == to)
        return;
    for (int i = plate - 1; i >= 1; i --) {
        // 先把小盘子给拿走
        dfs(plateInitState, plateFinalState, i, 6-(plateInitState[plate]+to), num);
    }
    movePlate(plate, plateArray[plateInitState[plate]], plateArray[to]);
    plateInitState[plate] = to;
    num ++;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> plateInitState(50, 0);
    vector<int> plateFinalState(50, 0);
    int x;
    for(int i = 1; i <= 3; i ++){
        cin >> x;
        for (int j = 0; j < x; i ++) {
            int plate;
            cin >> plate;
            plateInitState[plate] = i;
        }
    }
    for(int i = 0; i < 3; i ++){
        cin >> x;
        for (int j = 0; j < x; j ++) {
            int plate;
            cin >> plate;
            plateFinalState[plate] = i+1;
        }
    }
    int num = 0;
    // 保证每一个都移动过了
    for (int i = n; i > 0; i --) {
        dfs(plateInitState, plateFinalState, i, plateFinalState[i], num);
    }
    cout << num << endl;

    return 0;
}