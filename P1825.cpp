#include <iostream>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

struct Node{
    pair<int, int> position;
    int length;
    Node() = delete;
    Node(int x, int y, int length): length(length){
        position.first = x;
        position.second = y;
    }
    Node(pair<int, int> p, int length): position(p), length(length){}
};

const pair<int, int> direction[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
enum mode{FORBIDDEN, PASS, START, EXIT, TRANSMIT};
int N, M;
const int MAX = 350;
char maze[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> bindNode[30];

inline pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) noexcept{
    return make_pair(a.first + b.first, a.second + b.second);
}

constexpr bool operator==(const pair<int, int>& a, const pair<int, int>& b) noexcept{
    return a.first == b.first && a.second == b.second;
}

constexpr bool operator!=(const pair<int, int>& a, const pair<int, int>& b) noexcept{
    return a.first != b.first || a.second != b.second;
}

pair<int, int> findAnotherEnd(const pair<int, int> &position, const char c){
    if(bindNode[c-'A'][0] != position){
        return bindNode[c-'A'][0];
    }
    return bindNode[c-'A'][1];
}

mode getMode(const pair<int, int>& position){
    if(maze[position.first][position.second] == '#')
        return FORBIDDEN;
    else if(maze[position.first][position.second] == '.')
        return PASS;
    else if(maze[position.first][position.second] == '@')
        return START;
    else if(maze[position.first][position.second] == '=')
        return EXIT;
    else if(maze[position.first][position.second] >= 'A' && maze[position.first][position.second] <= 'Z')
        return TRANSMIT;
    else
        exit(-1);
}

bool isValid(const pair<int, int>& position){
    if (position.first < 1 && position.first > N && position.second < 1 && position.second > M)
        return false;
    else if(getMode(position) == FORBIDDEN)
        return false;
    else if(getMode(position) == PASS && visited[position.first][position.second] == false)
        return true;
    else if((getMode(position) == PASS || getMode(position) == START)&& visited[position.first][position.second] == true)
        return false;
    else if (getMode(position) == EXIT || getMode(position) == TRANSMIT)
        return true;
}

int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    getline(cin, s);
    istringstream iss(s);
    iss >> N >> M;
    pair<int, int> start, end;
    for(int i = 1; i <= N; i ++){
        string line;
        getline(cin, line);
        istringstream iss(line);
        char c;
        for(int j = 1; j <= M; j ++){
            iss >> c;
            maze[i][j] = c;
            if(c == '@')
                start = make_pair(i, j);
            else if(c == '=')
                end = make_pair(i, j);
            else if(c >= 'A' && c <= 'Z')
                bindNode[c-'A'].emplace_back(i, j);
        }
    }
    queue<Node> q;
    q.push(Node(start, 0));
    visited[start.first][start.second] = true;
    while(!q.empty()){
        Node temp = q.front();
        q.pop();
        if (maze[temp.position.first][temp.position.second] == '=') {
            cout << temp.length+1 << endl;
            return 0;
        }
        for(const auto & i : direction){
            pair<int, int> nextPosition = temp.position + i;
            if(getMode(nextPosition) == EXIT){
                cout << temp.length+1 << endl;
                return 0;
            }
            else if(!isValid(nextPosition))
                continue;
            else if(getMode(nextPosition) == TRANSMIT){
                visited[nextPosition.first][nextPosition.second] = true;
                nextPosition = findAnotherEnd(nextPosition, maze[nextPosition.first][nextPosition.second]);
                q.emplace(nextPosition, temp.length+1);
            }
            else{
                q.push(Node(nextPosition, temp.length+1));
                visited[nextPosition.first][nextPosition.second] = true;
            }
        }
    }
    return 0;
}