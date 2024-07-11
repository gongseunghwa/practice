#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define MAX 100
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[MAX][MAX];
int vis[MAX][MAX];
int n,m;

class Point {
public:
  pair<int,int> arr;
  pair<int,int> dest;

  bool amIArrive(pair<int,int> p) {
    if(p.X == arr.X && p.Y == arr.Y) return true;

    return false;
  }
};

int a,b,c,d;

list<Point> dictionary;



void switchOn(pair<int,int> p) {
  for(Point au : dictionary) {
    if(au.amIArrive(p)) {
      board[au.dest.X][au.dest.Y]=1;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  n++;
  for(int i=0;i<m; i++) {
    cin >> a >> b >> c >> d;
    Point p1;

    p1.arr={a,b};
    p1.dest={c,d};
    dictionary.push_back(p1);
  }

  board[1][1]=1;
  int result=0;
  queue<pair<int,int>> Q;
  Q.push({1,1});
  switchOn({1,1});
  vis[1][1]=1;
  while(!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    
    cout << "{" << cur.X << ", " << cur.Y << "} 에 도착 했을 때" << endl;
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        cout << board[i][j];
      }
      cout << endl;
    }
    bool switchss = 1;

    while(switchss){
      switchss=0;
      for(int dir=0; dir<4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        if(nx <1 || ny <1 || nx >= n+1 || ny >= n+1) continue;
        if(vis[nx][ny] || board[nx][ny] == 0) continue;

        vis[nx][ny] = 1;
        Q.push({nx,ny});
        switchOn({nx,ny});
        switchss=1;

      }
    }

  }

  fill(vis[n], vis[n] + n, 0);
  queue<pair<int,int>> Q2;

  Q2.push({1,1});
  vis[1][1]=1;
  while(!Q2.empty()) {
    result++;
    auto cur= Q2.front(); Q2.pop();
    for(int dir=0; dir<4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(nx <1 || ny <1 || nx >= n+1 || ny >= n+1) continue;
      if(vis[nx][ny] || board[nx][ny] == 0) continue;
      vis[nx][ny] = 1;
      Q2.push({nx,ny});
    }
  }

  cout << "result : " << result;
} 

  // 1. 방에 도착한다 (Q에 1,1 이 들어있는상태)
  // 2. 내 방에서 킬 수 있는 불을 모두 킨다. => Q에 집어넣는 행위
  // 3. BFS를 통해 내가 주변에 갈 수 있는 방을 Q에 넣는다.
  // 4. 이동할 수 있는 방에 이동하며 위 BFS를 반복한다.
  // 5. 생각해야 될 점으로는 이미 못지나간다고 판단했던 곳에 불이 켜질 수 도 있다. => 원점을 방무하여 해결한다?
  
