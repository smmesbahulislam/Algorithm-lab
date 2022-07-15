#include<bits/stdc++.h>
using namespace std;

#define mx 1005
#define INF INT_MAX

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

vector< vector<int> > g;
int DY,DX;
queue<pair<int,int> > q;
bool color[mx][mx];
int dis[mx][mx];

int nodes,edges;
int destx,desty;

bool isOngrid(pair<int,int> p)
{
    if(p.first < 0 || p.first >= DY || p.second >= DX || g[p.first][p.second] == false)
        return false;
    else return true;
}

void bfs(int srcY,int srcX)
{
    pair<int , int > u,v;

    for(int i = 0;i < DY;i++)
        for(int j = 0;j < DX;j++){
            dis[i][j] = INF;
            color[i][j] = false;
        }
    
    color[srcY][srcX] = true;
    dis[srcY][srcX] = 0;
    q.push(make_pair(srcY,srcX));

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i = 0;i < 4;i++)
        {
            v.first = u.first + dy[i];
            v.second = u.second + dx[i];

            if(color[v.first][v.second] == false && isOngrid(v))
            {
                color[v.first][v.second] = true;
                dis[v.first][v.second] = dis[u.first][u.second] + 1;

                q.push(v);

            }
        }
    }
    return;
}


int main()
{
    int row,col,boomb,col_with_boomb,row_with_boomb;
    int srcX,srcY;
    while(scanf("%d %d",&DY,&DX) == 2 && DX != 0 && DY != 0)
    {
        g = vector< vector<int > > (DY, vector<int>(DX,true));
        cin >> row;
        for(int i = 0; i < row;i++)
        {
            cin >> row_with_boomb >> boomb;
            for(int j = 0;j < boomb;j++)
            {
                cin >> col_with_boomb;
                g[row_with_boomb][col_with_boomb] = false;
            }
        }

        cin >> srcY >> srcX >> desty >> destx;
        bfs(srcY,srcX);
        cout << dis[desty][destx] << endl;

    }
    return 0;
}
