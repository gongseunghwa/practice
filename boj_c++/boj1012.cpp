#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int tc,x,y,ex,xx,yy;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(void) {

    cin >> tc;

    for(int t=0; t<tc; t++) {
        int x,y,ex;
        cin >> x >> y >> ex;

        int farmland[51][51] = {0};
        int vis[51][51] ={0};
        

        for(int i=0; i<ex; i++) {
            cin >> xx >> yy;
            farmland[xx][yy] = 1;
        }

        
        // for(int i=0; i<x;i++) {
        //     for(int j=0;j<y;j++) {
        //         cout << farmland[i][j];
        //     }

        //     cout <<endl;
        // }

        // BFS
        int cnt=0;
        for(int i=0; i<x; i++) {
            for(int j=0; j<y; j++) {
                if(farmland[i][j] == 0 || vis[i][j]) continue;
                cout << farmland[i][j] << " " << vis[i][j] << endl;
                cnt++;
                vis[i][j] =1;
                queue<pair<int,int>> Q;
                Q.push({i,j});

                while (!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0; dir<4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx<0 || nx>=x || ny<0 || ny>=y) continue;
                        if(vis[nx][ny] || farmland[nx][ny] != 1) continue;

                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
                
            }
        }

        cout << cnt << endl;
    }
}