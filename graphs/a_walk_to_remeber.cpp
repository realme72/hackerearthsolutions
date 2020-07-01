#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define endl "\n"
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mapii map<int,int> 
#define mapll map<ll,ll>
#define all(a) a.begin(),a.end()
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x*y)/gcd(x,y)
#define test ll t; cin>>t; while(t--)
#define prec(n) fixed<<setprecision(n)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int N = int(1e5)+1;
const int M = int(2e5)+1;
vii g[N],rg[N],comp,order;
int vis[N],ans[N];

void dfs1(int u){
    vis[u]=1;
    for(int i=0;i<(int)g[u].size();i++)
        if(!vis[g[u][i]])
            dfs1(g[u][i]);
    order.PB(u);
}

void dfs2(int u){
    vis[u]=1;comp.PB(u);
    for(int i=0;i<(int)rg[u].size();i++)
        if(!vis[rg[u][i]])
            dfs2(rg[u][i]);
}

int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[u].PB(v);
        rg[v].PB(u);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs1(i);
            
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        int v = order[n-i];
        if(!vis[v])
        {
            dfs2(v);
            if(comp.size()>1)
                for(auto &it:comp)
                    ans[it]=1;
            comp.clear();
        }
    }
    
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
	return 0;
}
