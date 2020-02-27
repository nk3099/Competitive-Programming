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
 //        https://www.spoj.com/problems/TDKPRIME/
///////////////////////////////////////////////////////////////////////////////////////////////////////////
 
/* using Macro's :

#define vi vector<int>
vi primes;

*/

// OR 

vector<int>primes;
bool arr[87000008];   //sieve precomputation, declared array global with MAX=87000008

//boolean array declared globally with MAX size, all elements initalized to 'false'.
//NOTE: 1 is neither a prime no. nor a composite no. 

// Sieve of Eratosthenes :
// TIME COMPLEXITY - O(Nlog(logN))

void sieve()
{
   int maxN = 87000009;  //array size upto which we have to generate prime nos.

   arr[0] =  true;   //since, 0 and 1 are not prime no., we mark them as not prime
   arr[1] =  true;

   for(int i=2; i*i<=maxN; i++)
   {

       if(!arr[i])
       {

            for(int j=i*i; j<=maxN; j+=i) 
             arr[j] = true;  
            //Marking all multiples of 2,3, etc. as not prime
            //-> As multiple of a Prime no. , cannot be a prime no.

           //if 'i'th no. is a prime no. 
           //then we start from it's square till maxN, we mark every multiple of 'i' as not Prime no.
           //i.e. each time 'j' increamented by i
           //eg:  if i=7, j=49, then each time increament/add 7 to get next multiple
       }

   }


   for(int i=2; i<=maxN; i++)
   if(!arr[i])
   primes.push_back(i);       //OR primes.PB(i);

}
 
 
int main()
{ __
 
#ifndef ONLINE_JUDGE    
freopen_cpp
#endif
 
int q,n; cin >> q;

sieve();   //calling the sieve() function

while( q-- )
{

   cin >> n, cout << primes[n-1] << endl;  

}

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* OR -> using int array :

int is_prime[87000008]; 
//NOTE: when globally declared an integer array in C++ , automatically assigned value zero.

void sieve()
{
   int maxN = 87000009;  //array size upto which we have to generate prime nos.


   for(int i=1; i<=maxN; i++) is_prime[i]=1;

   is_prime[0] = is_prime[1] = 0;   //since, 0 and 1 are not prime no., we mark them as not prime
   

   for(int i=2; i*i<=maxN; i++)
   {

       if(is_prime[i])
       {

            for(int j=i*i; j<=maxN; j+=i) 
            is_prime[j]=0;          
       }

   }


   for(int i=2; i<=maxN; i++)
   if(is_prime[i])
   primes.push_back(i);       //OR primes.PB(i);

}

*/