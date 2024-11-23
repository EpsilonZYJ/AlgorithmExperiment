#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

const int MAXN = 1e5+50;

using namespace std;


vector<int> add(vector<int> &a, vector<int> &b) {
    vector<int> ans;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += a[i--];
        if (j >= 0) sum += b[j--];

        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int cmp(vector<int> A, vector<int> B){
    if(A.size()>B.size())	return 1;
    else if(A.size()<B.size())	return -1;
    else{
        if(A>B)	return 1;
        else if(A<B)	return -1;
        else	return 0;
    }
}


vector<int> mul(vector<int>& a, vector<int>& b) {
    vector<int> ans(a.size() + b.size(), 0);

    for (int i = a.size() - 1; i >= 0; i--) {
        for (int j = b.size() - 1; j >= 0; j--) {
            int mul = a[i] * b[j];
            int sum = mul + ans[i + j + 1];

            ans[i + j + 1] = sum % 10;
            ans[i + j] += sum / 10;
        }
    }
    ans.erase(ans.begin(), find_if(ans.begin(), ans.end(), [](int num) { return num != 0; }));
    return ans.empty() ? vector<int>{0} : ans;
}

vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = 0; i < A.size(); i ++ )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    C.erase(C.begin(), find_if(C.begin(), C.end(), [](int num) { return num != 0; }));
    return C;
}

int main(){
    int n;  // 大臣人数
    cin >> n;
    vector<pair<int, int>> line;
    for(int i = 0; i < n+1; i ++){
        int left, right;
        cin >> left >> right;
        line.push_back(make_pair(left, right));
    }

    sort(line.begin()+1, line.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        return (a.first*a.second) < (b.first*b.second);
    });

    vector<int> left, right;
    vector<int> max_num;
    vector<int> cur_num;
    left.push_back(1);
    for(int i = 1; i < line.size(); i ++){
        vector<int> left_add;
        int r;
        left = mul(left, left_add);
        cur_num = div(left, line[i].second, r);
        if(cmp(max_num, cur_num) < 0)
            max_num = cur_num;
    }
    for(const auto &i: max_num)
        cout << i;
    return 0;
}