//             _..._
//           .'      '.      _
//          /     .-""-\   _/ \
//        .-|    /:.   |  |   |
//        |  \   |:.   /.-'-./
//        | .-' -;:__.'    =/                     
//       .'=    *=|IND  _.='                                                                                                                                                                                                        
//       /   _.   |    ;
//       ;-.-'|   \    |                      
//     /   |  \   _\  _\
//     \__/'._;.  ==' ==\
//              \    \   |
//              /    /   /  
//              /-._/-._/
//              \   `\  \
//               `-._/._/ Built by Neeraj Kumar(nk_3099)
//                           "Let Work itself be the Ambition."
//
 
#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long
#define ll long long
#define INF 1e18
#define MOD 1000000007
ll power(ll a,ll b, ll m=MOD)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
            res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res%m;
}
 
ll inverse(ll a,ll m=MOD)
{
    return power(a,m-2,m);
}
 
#define F first
#define S second
#define endl "\n"
#define MP make_pair
#define PB push_back
 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define for0(i,n)  for(int i=0;i<n;i++)
#define for1(i,n)  for(int i=1;i<=n;i++)
#define rfor0(i,n) for(int i=n-1;i>=0;i--)
#define rfor1(i,n) for(int i=n;i>=1;i--)
  
#define PI acos(-1)
#define gcd(a,b) __gcd(a,b)
#define bnc(x) __builtin_popcountll(x)
#define sz(x) (int)(x).size()
#define all(a) a.begin(),a.end()
#define sortall(x) sort(all(x))
#define clr(x) memset(x,0,sizeof(x))
 
#define print2(a,b) cout<<a<<' '<<b;endl;
#define print3(a,b,c) cout<<a<<' '<<b<<' '<<c;endl;
#define print4(a,b,c,d) cout<<a<<' '<<b<<' '<<c<<' '<<d;endl;
#define lower(a) transform(a.begin(),a.end(),a.begin(),::tolower);
#define upper(a) transform(a.begin(),a.end(),a.begin(),::toupper);
 
#define testcases(t) ll t; cin>>t; while(t--)
#define tri(x) for(auto it=x.begin();it!=x.end();it++)cout<<*it<<' ';cout<<endl;
#define trii(x)for(auto it=x.begin();it!=x.end();it++)cout<<it->F<<' '<<it->S<<endl;  
#define __ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define freopen_cpp freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 

 
///////////////////////////////////////////////////////////////////////////////////////
//  https://www.spoj.com/problems/PT07Y/
//////////////////////////////////////////////////////////////////////////////////////

/*

TREE: a GRAPH with 'N' nodes, then 'N-1' edges.


PROPERTIES OF TREE:
-------------------

1> It is connected, i.e. from every node we can reach every any other node.
Therefore, in the given graph -> if we have >=2 connected components, it is NOT A TREE.

2> A Tree doesn't contain any Cycle.
// a Cycle can by checked by looking at the edges.


*/


vector<int>adj[100001]; //adjacency-list.
int vis[100001];

void dfs(int node)
{
    vis[node]=1;
    for(int child : adj[node])  //traversing adjacency list of current node
    if(vis[child]==0) dfs(child);
}


int main()
{ __
 
#ifndef ONLINE_JUDGE    
freopen_cpp
#endif

int n,m,u,v; cin>>n>>m;
// n -> no. of nodes, m -> no. of edges

for(int i=1;i<=m;i++)
{
    cin>>u>>v;
    //Each line contains a pair (u, v) means there is an edge between node u and node v 
    adj[u].push_back(v);   
    adj[v].PB(u);
}

//cc -> connected_component;
int cc_count=0;
for(int i=1;i<=n;i++)
{
    if(vis[i]==0) dfs(i), cc_count++;  
    // if ( !vis[i] ) dfs(i), cc++; 
    //i.e. if the ith node is not visited.
}


//It is a Tree, if no. of connected components=1 [i.e., cc=1 ] AND  
//total no. of edges = n-1.  [i.e., m == n-1]
if(cc_count == 1 && m == n-1 ) cout<<"YES"<<endl; 

else cout<<"NO"<<endl;

return 0;
}
