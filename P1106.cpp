// DONE
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void deleteNum(vector<char>& num){
    for(int i = 0; i < num.size()-1; i ++){
        if(num[i] > num[i+1]){
            num.erase(num.begin()+i);
            return;
        }
    }
    num.pop_back();
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // 读数据
    vector<char> num;
    string line;
    cin >> line;
    istringstream iss(line);
    char c;
    while((iss >> c) && c != '\n'){
        num.push_back(c);
    }

    // 删除数字
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        deleteNum(num);
    }
    line = "";
    for(const auto &i: num) {
        line += i;
    }
    if(num.empty())
        cout << 0;
    else{
        int i = 0;
        while(num[i] == '0' && i < num.size()) i ++;
        if(i == num.size())
            cout << 0;
        else
            for(; i < num.size(); i ++)
                cout << num[i];
    }
    return 0;
}