#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

char board[101][101];
bool vis[101][101];
bool vis2[101][101];
char r_g_b[3] = {'R', 'G', 'B'};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int size;
    cin >> size;
//  board 채우기
    for(int i=0; i< size; i++) {
        for(int j=0; j< size;j++) {
            cin >> board[i][j];
        }
    }
    int rg_b_count=0;
    int r_g_b_count=0;
    // 적록색약의 경우 >> RG, B 에 대해 2번 BFS
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if(board[i][j] != 'B' || vis2[i][j]) continue;
                rg_b_count++;
                queue<pair<int,int>> Q;

                vis2[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
                        if(vis2[nx][ny] || board[nx][ny] != 'B') continue;

                        vis2[nx][ny]=1;
                        Q.push({nx,ny});
                    }
                }
        }
    }

        for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if(board[i][j] == 'B' || vis2[i][j]) continue;
                rg_b_count++;
                queue<pair<int,int>> Q;

                vis2[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
                        if(vis2[nx][ny] || board[nx][ny] == 'B') continue;

                        vis2[nx][ny]=1;
                        Q.push({nx,ny});
                    }
                }
        }
    }

    // 적록색약이 아닌 경우 >> R, G, B에 대해 3번 BFS
    for(char c : r_g_b){
        for(int i=0;i<size;i++) {
            for(int j=0;j<size;j++) {
                if(board[i][j] != c || vis[i][j]) continue;
                r_g_b_count++;
                queue<pair<int,int>> Q;

                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
                        if(vis[nx][ny] || board[nx][ny] != c) continue;

                        vis[nx][ny]=1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }

        cout << r_g_b_count << ' ' << rg_b_count;
}