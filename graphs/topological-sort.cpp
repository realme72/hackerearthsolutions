#include"bits/stdc++.h"
using namespace std;
#define pb push_back
#define ll long long
#define sorted(x) sort(x.begin(),x.end())
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(v) v.begin(), v.end()
const int N = 11;
vector<int> ans;
vector<int> v[N];
int vis[N],n,m;

void dfs(int u){
    vis[u]=1;
    for(auto i: v[u]){
        if(!vis[i]) dfs(i);
    }
    ans.pb(u);
}

int main(){
    fastio;
    cin>>n>>m;
    for (int i=0;i<m;++i){
        int u,w;cin>>u>>w;
        v[u].pb(w);
    }

    for(int i=1;i<=n;++i)
    sort(all(v[i]),greater<int>());

    for (int i=n;i>=1;--i)
        if(!vis[i]) dfs(i);

    reverse(all(ans));
    for(auto i: ans) cout<<i<<' ';

return 0;
}
