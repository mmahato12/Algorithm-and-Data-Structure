#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int V,E;
int v[15][15];
int Copy[15];
int visited[15];
bool isBridge[15];
vector <int> ans1;
vector < pair<int, int> > Edge, ans2;

bool comp(pair <int , int> a, pair <int , int> b)
{
    if(a.first < b.first)
        return true;
    else if(a.first == b.first && a.second < b.second)
        return true;
    return false;
}

void dfs(int u)
{
    visited[u] = 1;
    for(int j=0; j<V; j++)
    {
        if(v[u][j] && visited[j] == 0)
            dfs(j);
    }
}

void ArticulationPoint()
{
    int count = 0;
    for(int i=0; i<V; i++)
        visited[i] = false;

    int initial_val = 0;
    for(int i=0; i<V; i++)
    {
        if(visited[i] == false)
        {
            dfs(i);
            initial_val += 1;
        }
    }
    
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            visited[j] = false;
            Copy[j] = v[i][j];
            v[i][j] = v[j][i] = 0;
        }

        int nval = 0;
        for(int j=0; j<V; j++)
        {
            if(visited[j] == false && (j!=i))
            {
                nval = nval + 1;
                dfs(j);
            }
        }

        if(nval > initial_val)
        {
            count += 1;
            ans1.push_back(i);
        }
        for(int j=0; j<V; j++)
            v[j][i] = v[i][j] = Copy[j];
    }
}

void find_bridges()
{
    int x;
    queue <int> Queue;
    for(int i=0; i<E; i++)
    {
        bool check = false;
        v[Edge[i].first][Edge[i].second] = v[Edge[i].second][Edge[i].first] = 0;
        for(int j=0; j<V; j++)
            visited[j] = false;

        Queue.push(Edge[i].first);
        visited[Edge[i].first];
        check = false;
        while(Queue.size())
        {
            x = Queue.front();
            if(x == Edge[i].second)
            {
                check = true;
                break;
            }
            Queue.pop();
            for(int j=0; j<V; j++)
            {
                if(v[x][j] == true && visited[j] == false)
                {
                    Queue.push(j);
                    visited[j] = true;
                }
            }
        }

        v[Edge[i].first][Edge[i].second] = v[Edge[i].second][Edge[i].first] = 1;
        if(check == false)
            isBridge[i] = true;
    }

    int ans=0;
    for(int i=0; i<E; i++)
    {
        int x = Edge[i].first;
        int y = Edge[i].second;
        if(x > y) swap(x, y);
        if(isBridge[i])
            ans2.push_back({x, y});
    }
}

signed main()
{
    int x,y;
    cin>>V>>E;
    for(int i=0; i<E; i++)
    {
        cin>>x>>y;
        v[x][y] = v[y][x] = 1;
        Edge.push_back({x, y});
    }

    
    ArticulationPoint();
    find_bridges();

    cout<<ans1.size()<<"\n";
    for(auto &x: ans1)
        cout<<x<<" ";
    cout<<"\n";
    
    sort(ans2.begin(), ans2.end(), comp);
    cout<<ans2.size()<<"\n";
    for(auto &x: ans2)
        cout<<x.first<<" "<<x.second<<"\n";
}