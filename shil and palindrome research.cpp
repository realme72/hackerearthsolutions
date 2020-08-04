/*
		@Author :- Gaurav Bharti
		National Institute of Technology, Jamshedpur.
*/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define empb emplace_back
#define mp make_pair
#define F first
#define S second
#define endl "\n"
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define mapii map<int,int> 
#define mapll map<ll,ll>
#define all(a) a.begin(),a.end()
#define test ll t; cin>>t; while(t--)
#define prec(n) fixed<<setprecision(n)
#define jaldibazi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
const int N=1e5+10;
int B[N][26];
int n , q;

void update(int id, int val, int pos) {
	while ( id <= n) {
		B[id][pos] += val;
		id += (id &- id);
	}
}

int query(int id, int pos) {
	int ans=0;
	while(id>0) {
		ans += B[id][pos];
		id -= (id &- id);
	}
	return ans;
}

int main(){
	jaldibazi;

    cin >> n >> q;
    string s; cin >> s;

    for(int i=0;i < n ; ++i) {
    	update( i+1, 1, s[i]-'a');
    }

    int t,l,r;
    while (q-- ){
    	cin >> t;
    	if(t==1){
    		char x;
    		cin >> l >> x;
    		update(l,1,x-'a');
    		update(l,-1,s[l-1]-'a');
    		s[l-1]=x;
    	}
    	else {
    		cin >> l >> r;
    		int od=0;
    		int cur=0;
    		for (int i = 0 ; i < 26 ; ++i) {
    			cur = query(r,i) - query(l-1,i);
    			if(cur%2) ++od;

    		}

    		if(od <= 1) cout << "yes\n";
    		else cout << "no\n";
    	}
    }

    return 0;
}
