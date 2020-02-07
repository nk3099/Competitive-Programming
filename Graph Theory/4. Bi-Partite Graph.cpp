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
//  https://www.spoj.com/problems/BUGLIFE/
//////////////////////////////////////////////////////////////////////////////////////


//XOR TABLE:
//  Input : Output 
//   X  Y     Z
//   0  0     0
//   1  1     0
//   0  1     1
//   1  0     1

//NOTE: THIS PROBLEM IS BASED ON CHECKING WHETHER IT IS A "BI-PARTITE" OR NOT FOR EACH CONNECTED COMPONENTS.

vector<int>adj[2001]; //adjacency-list.
int vis[2001],color[2001]; //another array required to save the color.

bool dfs(int node, int  c)
{
    vis[node]=1;
    color[node]=c;
    for(int child : adj[node])  //traversing adjacency list of current node
    {

        if(vis[child]==0) //if child not visited
        {
            bool res= dfs(child, c^1);  //make a call to dfs, passing the color just-opposite the current node color.
            //and if that node founds that the graph is not Bi-Partite, result returns false.
            if(res==false) return false; // we return false from here, indicating that the graph is not Bi-Partite.
        }

        else // if child is visited, we would compare the color.
        {

               if(color[node] == color[child]) //if same color, indicating not Bi-Partite.
               return false;
        }
    } //end of for-loop

    //i.e if whole part executed successfully, we return true.
    return true; //Means, graph is Bi-Partite.

} //end of dfs() fucntion


int main()
{ __
 
#ifndef ONLINE_JUDGE    
freopen_cpp
#endif

int t,n,m,u,v; cin>>t;
// t->no. of testcases
//NOTE: We can't use while(t--) , as we also have to print the testcase no. as well ( in #scenario)
for(int tc=1;tc<=t;tc++)  
{
    cin>>n>>m;
    //since there 't' testcases, we have to clear the adjacency-list of each node.
    //Because the adjacency-list may contain element from the previous testcases.
    //Also, reset the visited array value as well.
    for(int i=1;i<=n;i++) adj[i].clear() , vis[i]=0;

    for(int i=1;i<=m;i++)
    cin>>u>>v , adj[u].push_back(v) , adj[v].PB(u);

    bool flag = true;

    for(int i=1;i<=n;i++)
    if( !vis[i] )   //Means, this connected component has not been tested for Bi-Partite test, 
    {
          bool res= dfs(i,0); //so make a dfs call to this node, passing the color.

          if(res==false) flag=false;  //Means, not a Bi-partite graph, ie.
         //the Theory of the professor is false.
    }

    cout<<"Scenario #"<<tc<<":"<<endl;
    if(flag==false)
    cout<<"Suspicious bugs found!"<<endl;
    else
    cout<<"No suspicious bugs found!"<<endl;   

}

return 0;
}
