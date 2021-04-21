#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};

int arr[251][251];
int visit[251][251];
int n, m;

void dfs(int y, int x)
{
    visit[y][x] = 1;
    for(int i = 0 ; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >=n || ny < 0 || ny >=m)
            continue;

        if (visit[ny][nx] == 0 && arr[ny][nx] == 1)
        {
            visit[ny][nx] = 1;
            dfs(ny, nx);
        }
        
           
        

    }
}

int main()
{
    cin >> m >>n;

    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1 && visit[i][j] == 0)
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;

}