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
//  https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int parent[100001];

/* for input :
7 3
1 2
3 4
1 7
4
1 2
5 6
3 7
1 5
*/

/*
Output :
TIE
6
7
1
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
	
	  if(parent[a] < 0) return a;
      
      return parent[a]=find(parent[a]);
    
    
   //////////////////////////////////////////////////////////////////////////////////
   
    
   ///////// USING DISJOINT COMPRESSION METHOD (ITERATIVE) //////////////////////////
   /* 
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
  */
  ///////////////////////////////////////////////////////////////////////////////////
   
    
}

//EARLIER, THE PARENT NODE REPRESENTED THE MAGNITUDE OF NO. OF ELEMENTS IN THAT SET,
// BUT SINCE, WE NOW HAVE TO FIND MAXIMUM HITTING-POWER OF A SET,
// WE STORE THE PARENT NODE WITH THE MAXIMUM HITTING-POWER OF A SET.
void Union(int a , int b)
{
    ///////////// EARLIER METHOD //////////////////////////////////////////////////////////
    /*
    parent[a]+=parent[b];
    parent[b]=a;
    */
    ////////////////////////////////////////////////////////////////////////////////////////
    
    ////////////////////////////////////////////////////////////////////////////////////////
     //NOW,
    
	 parent[a] = min(parent[a],parent[b]);	  // since negative values, doing min() for largest-HittingPower 
	 //( as -5 < -4) but absolute of (-5) > abs(-4).
 	 parent[b] = a;				//making a , parent of new set
	
	 ////////////////////////////////////////////////////////////////////////////////////////
}
 
 
int main()
{ __
 
 #ifndef ONLINE_JUDGE
 freopen_cpp
 #endif
 
	int n , m , a , b, q;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		parent[i] = -i;		// earlier-> parent[i]= -1;
		// Now,initializing with their own values : As to determin max. hitting power of each set.
		//therefore, parent[i]= -i;
		
	while(m--)
	{
		cin>>a>>b;
		a = find(a) , b = find(b);
		
		if(a != b) Union(a , b);
	}
	
	 //////////// USING EARLIER METHOD /////////////////////////////////////////////////////
	 /*
	 // for(int i=1;i<=n;i++) cout<<parent[i]<<" "; 
	 
	 Now, parent[i]'s are : -3 1 -2 3 -1 -1 1
	 Therefore, 1,2 and 7 are friends. 3 and 4 are friends. 5 and 6 have no friends
	 */
	 ////////////////////////////////////////////////////////////////////////////////////////
	 
	 
	 ////////////////////////////////////////////////////////////////////////////////////////
	 /*
	 //NOW,
	 // for(int i=1;i<=n;i++) cout<<parent[i]<<" ";
	 	 
	  Now, parent[i]'s are : -7 1 -4 3 -5 -6 1  
	  
	  Indicating the negative ones as PARENT, with the Max. hitting power of that set.
	  Therefore, 
	  
	   __SET__   -->   __MAX._Power(of SET)__
	   
	    [1,2,7]  -->         7   [PARENT OF SET IS : 1] // parent->represented by -ve values.
	  
	     [3,4]   -->         4   [PARENT OF SET IS : 3]
	     
	     [5]     -->         5   [PARENT OF SET IS : 5]
	     
	     [6]     -->         6   [PARENT OF SET IS : 6]
	   
	   */
	  ////////////////////////////////////////////////////////////////////////////////////////
	 
	cin>>q;
	int x,y;
	while( q--)
	{
	    cin>>a>>b;
	    x=a, y=b;     //storing original values to be printed on wining set
	    a=find(a), b=find(b);      // same as a=find(a); b=find(b);
	    if(a==b) cout<<"TIE"<<endl;   
	    else 
	    {
	        if( parent[a] < parent[b])      //because of negative values, lesser value wins. ( as abs(less -ve value ) is greater ).
	        cout<<x<<endl;
	        else 
	        cout<<y<<endl;
	    }
	}
	
	return 0;
}
