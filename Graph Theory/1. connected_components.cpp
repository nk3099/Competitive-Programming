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
 
 
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////
 //        https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
///////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 
vector<int>adj[100001]; //for creating adjacency list for nodes, [as no. of nodes not given, :. adj[100001]; ]
int vis[100001]; 
//NOTE: when globally declared an integer array in C++ , automatically assigned value zero.
 
void dfs(int nodeT)
{
    vis[nodeT]=1;  // make node as visited
    
    //cout<<nodeT<<"->";
    //for(int i=0;i<adj[nodeT].size();i++)
    //{
      //  int child=adj[nodeT][i];
        //if(vis[child]==0) dfs(child);
    //}
    
    for(int child : adj[nodeT])   //visiting thro' all the nodes in the adjacency list of current 'nodeT'
    {
       if(vis[child]==0) dfs(child);
    }
    
}
 
 
int main()
{ __
 
#ifndef ONLINE_JUDGE    
freopen_cpp
#endif
 
int n,e; cin>>n>>e;
 
// no. of nodes -> n
// no. of edges -> m
 
while(e--)
{
    ll u,v; cin>> u >>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    
}
 
int connected_components=0;
for(int i=1; i<=n; i++)  // n -> no. of nodes
{
   if(vis[i]==0)
     dfs(i), connected_components++;
}
 
cout<<connected_components<<endl;
 
    
    
    return 0;
}