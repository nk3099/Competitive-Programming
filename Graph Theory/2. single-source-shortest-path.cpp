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
 
 
vector<int>adj[1001]; //for creating adjacency list for 1000 cities
int vis[1001], dist[1001]; //distance array to store the distance of each city.
//NOTE: when globally declared an integer array in C++ , automatically assigned value zero.
 
void dfs(int nodeT, int d)  
{
    vis[nodeT]=1;  // make node as visited
    dist[nodeT]=d; //set distance of current node=d.
   
    //visiting thro' all the nodes in the adjacency list of current 'nodeT', i.e.
    //traversing adjacency list of current node.
     for(int child : adj[nodeT])   
    {
       if(vis[child]==0) dfs(child, dist[nodeT]+1); 
       //if current child not visited, then we would make a dfs call to this child,
       //passing the distance as  ( dist[current-node] + 1 ).
       //dist[nodeT]+1 HERE, dist[nodeT] is the adjacency-Node , which connects to other child nodes.
    }
 
}
 
 
int main()
{ __
 
#ifndef ONLINE_JUDGE    
freopen_cpp
#endif
 
int n; cin>>n; //no. of countries
int u,v,q;
 
for(int i=1;i<=n-1; i++)  // n-1 edges
cin>>u>>v, adj[u].push_back(v), adj[v].PB(u);
 
dfs(1,0); //calculate the SINGLE SOURCE SHORTEST PATH (SSSP using DFS) , we make a dfs call to node 1(source node).
 
// SSSP -> to find shortest distance to every other node, starting from given sources vertex.
//starting from node 1 (source node), and since it's distance is zero.
 
cin>>q;  // no. of girls
 
int ans= -1, min_dist=INF; //10^9
while(q--) 
{
    int girl_city; cin>>girl_city;
    
    if(dist[girl_city] < min_dist) min_dist=dist[girl_city], ans=girl_city;
    
    //if multiple girls having same minimum distance,
    //then we have to check for the minimum city-id (ie. girl_city is the city-id ).
    else
    if(dist[girl_city] == min_dist && girl_city < ans)
    ans=girl_city;
    
}
 
//ANSWER:
 cout<<ans<<endl;
 
return 0;
}