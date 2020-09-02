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
#define ItsFUN ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007

struct Node {
    int count;
    struct Node* words[26];
    int end;
};
 
struct Node *create() {
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    for(int i = 0; i<26; ++i) {
        temp->words[i] = NULL;
    }
    temp ->count = 0;
    temp -> end = 0;
    return temp;
}
 
void insert(struct Node * root, string s) {
    struct Node * temp = root;
    for(int i = 0; i<s.length(); ++i) {
        if(temp -> words[s[i]-'a'] == NULL) {
            temp -> words[s[i]-'a'] = create();
        }
 
        temp = temp -> words[s[i]-'a'];
        (temp -> count) += 1;
    }
    temp -> end = 1;
}
 
int countpref(struct Node * root, string s) {
    int i = 0;
    struct Node * temp = root;
    while (i < s.length()) {
        if(temp -> words[s[i]-'a'] == NULL) {
            return 0;
        }
        temp = temp->words[s[i]-'a'];
        ++i;
    }
    return temp -> count;
}
 
int main() {
    struct Node * root = create();
    int i ,n; cin >> n;
    string a, b;
    for(int i = 1; i<=n; ++i) {
        cin >> a >> b;
        if(a=="add") {
            insert(root,b);
        }
        else {
            cout << countpref(root,b) << "\n";
        }
    }
    return 0;
}
