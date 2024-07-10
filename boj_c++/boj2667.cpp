#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

#define X first
#define Y second

string board[26];
int vis[26][26];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    for(int i=0; i<size; i++) {
        cin >>board[i];
    }

    int count=0;
    list<int> l;
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(board[i][j] == '0' || vis[i][j]) continue;
            queue<pair<int,int>> Q;
            Q.push({i,j});
            vis[i][j] =1;
            count++;
            int area=0;
            while (!Q.empty())
            {
                area++;
                auto cur = Q.front(); Q.pop();
                for(int dir=0; dir<4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx<0 || nx>=size || ny<0 || ny>=size) continue;
                    if(vis[nx][ny] || board[nx][ny] != '1') continue;
                    vis[nx][ny] =1;
                    Q.push({nx,ny});
                }
            }
            l.push_front(area);
        }
    }
    cout << count << endl;
    l.sort();
    for(auto a: l) {
        cout << a << endl;
    }
}