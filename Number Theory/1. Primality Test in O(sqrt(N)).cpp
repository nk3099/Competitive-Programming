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
 
 
 /////////////////////////////////////////////////////////////////
//        https://www.codechef.com/problems/PRB01
///////////////////////////////////////////////////////////////// 
 

// ----- NAIVE APPROACH : -----------
/*

  bool isPrime ( int n )
  {
    if( n == 1 )
       return false;

    for(int i=2; i<=n; i++)
    {
      if( n % i == 0)
        return false;
    }

    return true;

  }

*/


//NOTE: As all divisors of a  number 'N' occurs in pairs of (a,b) such that a*b = N
/*

 For example : 12 has following divisors-
 d = 1, 2, 3, 4, 6, 12.
 pairs are: (1,12), (2,6), (3,4)

*/

// Therefore, for a divisor pair (a,b) one of them lies below sqrt(N) and other lies above sqrt(N)

bool isPrime(int n)
{

  if(n == 1) return false;

  for(int i=2; i*i<=n; i++)
  {
    if(n % i == 0)
      return false;
  }

  return true;

}
 

int main()
{ __
 
#ifndef ONLINE_JUDGE    
freopen_cpp
#endif
 

// same as :
/* 
 
 int t, n; cin >> t;
 while( t-- )
 {
  cin >> n;
  ...

 }

*/


testcases(t)    //using a Macro, for testcases !! ;)
{

   int n; cin >> n;

   if( isPrime(n))
   {
      cout << "yes" << endl;
    
   }
   else
   {
      cout << "no" << endl;

   }

}  

    return 0;
}


