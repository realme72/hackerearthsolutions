#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
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
int n,m,t=0;
vector<int> adj[11];
bool vis[11],ap[11];
int disc[11],low[11],parent[11]={-1};
stack<pii> s;
int even=0,odd=0,cnt=0;

void dfs(int u){
    vis[u]=true;
    disc[u]=low[u]=t++;
    for(int i=0;i<adj[u].size();i++){
        int p=adj[u][i];
        if(!vis[p]){
            parent[p]=u;
            s.push(mp(u,p));
            dfs(p);
            low[u]=min(low[u],low[p]);
            if(low[p]>=disc[u]){
                cnt=0;
                while(s.top().first!=u && s.top().second!=p){
                    s.pop();
                    cnt++;
                }
                s.pop();
                cnt++;
                if(cnt==1) even++;
                else{
                    if(cnt%2==0) even++;
                    else odd++;
                }
            }
        }
        else if(p!=parent[u] && disc[p]<low[u]){
            low[u]=disc[p];
            s.push(mp(u,p));
        }
    }
}

int main(){
    cin>>n>>m;
    int x,y;
    while(m--){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i);
    }

    cnt=0;
    while(!s.empty()){
        cnt++;
        s.pop();
    }
    if(cnt>0){  
        if(cnt==1) even++;
        else{
            if(cnt%2==0) even++;
            else odd++;
        }
    }
    cout<<odd<<" "<<even<<endl;
    return 0;
}
