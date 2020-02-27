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
#define INF 1000000000
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

/////////////////////////////////////////////////////////////////////////////////////////////////
//                     https://www.spoj.com/problems/RMQSQ/
/////////////////////////////////////////////////////////////////////////////////////////////////

////////////////// SEGMENT TREES ->   RANGE- MINIMUM- QUERY. ////////////////////////////////////

// si-> segment index , ss-> segment start , se-> segment end
// qs-> query start , qe-> query end 
// SegTree-> Segment Tree array ,  arr-> Input array

int SegTree[400001] , arr[100001];
//This is because :
//4*N space have to be allocated for a Segment-Tree, where N is the size of the original array.

void build(int si, int ss, int se) 
{

    if(ss == se) 
    {
        SegTree[si] = arr[ss];  // ( or) SegTree[si]=arr[se] , as both ss==se.
        return;
    }
    int mid= (ss+se)/2;
    build(2*si, ss, mid);
    build(2*si+1, mid+1, se);
    SegTree[si]=min(SegTree[2*si], SegTree[2*si+1]); //as Range-Minimum-Query
}

int query( int si, int ss, int se, int qs, int qe )
{
     //Completely Outside
     if(qs > se  ||  qe < ss)   //Either of them must be false.
     return INF;   // INF= 10^10;

    // Completely Inside
    if( ss >= qs  &&  se<=qe )    //Both condition must satisy.
    return SegTree[si];
    
    int mid= (ss + se)/2;
    int l= query(2*si, ss, mid, qs, qe);
    int r= query(2*si+1, mid+1, se, qs, qe);

    return min(l,r);
}

/*
for n=3 :

      1 3
     /   \
    /     \
  1 2      2 3
  /  \      \
 /    \      \
1 1   2 2    3 3 

*/

int main()
{ __
 
#ifndef ONLINE_JUDGE
freopen_cpp
#endif 

int n, l, r; 

cin>>n;

for(int i=1; i<=n; i++) cin>>arr[i];   //as taking 1-based indexing.

int q; cin>>q;

build(1, 1, n);  //calling build function.

while ( q-- )
{
    cin >> l >> r;
    cout << query(1 , 1 , n , l+1 , r+1) << endl;
    // because we have start with 1-based indexing.
    //Usually, as query ranges are specified using 0-based indexing.

}

return 0;
}
