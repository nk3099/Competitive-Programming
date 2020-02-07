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
 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/teachers-dilemma-3/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int parent[100001];

/* for input :
5 4
1 2
2 3
1 3
4 5
*/

/*
Output :
6
*/
 
int find(int a)
{
    ///////// EARLIER METHOD -> TLE ///////////////////////////////////////////////
    /*
	while(parent[a] > 0) 
	a = parent[a];
		
	return a;
	*/
   ////////////////////////////////////////////////////////////////////////////////
	
	
	////// USING DISJOINT COMPRESSION METHOD (RECURSIVE) ///////////////////////////
	
	/* if(parent[a] < 0) return a;
      
      return parent[a]=find(parent[a]);
    
    */
   //////////////////////////////////////////////////////////////////////////////////
   
    
   ///////// USING DISJOINT COMPRESSION METHOD (ITERATIVE) //////////////////////////
   vector<int>v;
   while(parent[a] > 0)
   { 
     v.push_back(a);   //4,3,2.. made function calls for parent
     a=parent[a];
   } //fails on a=1; so now value of a=1 ,upon failing
   
   for(int i=0; i<v.size();i++)
   {
       parent[ v[i] ] =a; //i.e = 1; // as a=1 was made;
       // making all nodes referenced to parent node -> updated with parent node.
   }
   
   return a;

  ///////////////////////////////////////////////////////////////////////////////////
   
    
}
 
void Union(int a , int b)
{
	parent[a] += parent[b];		//adding size of set b to set a
	parent[b] = a;				//making a , parent of new set
}
 
 
int main()
{ __
 
 #ifndef ONLINE_JUDGE
 freopen_cpp
 #endif
 
	int n , m , a , b;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		parent[i] = -1;		//initializing
		
	while(m--)
	{
		cin>>a>>b;
		a = find(a) , b = find(b);
		
		if(a != b) Union(a , b);
	}
	
	long long int res = 1;
	
	for(int i=1;i<=n;i++)
	if(parent[i] < 0)
	res = (res * abs(parent[i])) % 1000000007;
	
	cout<<res;
	
	return 0;
}