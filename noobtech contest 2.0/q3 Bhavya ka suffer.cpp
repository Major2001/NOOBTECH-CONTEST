//  ||  || |____|  //
//  ||  ||   ||   // 
//  \\__//   ||  // 
#include<bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#include <bitset>
#define mp make_pair
#define F first
#define S second
#define I insert
#define vll vector <ll>
#define mll map <ll,ll>
#define pb push_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
#define popf pop_front
#define popb pop_back
#define M 1000000007
#define M1 998244353
#define pi 3.14159265
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test ll t;cin>>(t);while(t--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
ll power(ll x,ll n) {ll result=1; while(n) {if(n%2==1) result=result*x; n=n/2; x=x*x;} return result;}
ll gcd(ll a, ll b) {if(!b)return a;return gcd(b, a % b);} 
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
ll BS(ll a[],ll s,ll n,ll val) {ll mid,beg=s,end=n-1; while(beg<=end)
{mid=(beg+end)/2; if(val==a[mid]){break;} else if(val>a[mid]){beg=mid+1;}else{end=mid-1;}} return mid;}
inline ll mul(ll x,ll y,ll m){ll z=1LL*x*y;if (z>=m){z%=m;} return z;}
ll powmod(ll x,ll y,ll m){ll r=1;while(y){if(y&1){r=mul(r,x,m);}y>>=1;x=mul(x,x,m);}return r;}
using namespace std;
void start()
{
    fast;
    
}
/***********************************************************************************************************/

int main()
{
    start();
    ll n,k; cin>>n>>k;
    ll a[n];
    f(0,n) cin>>a[i];
    multiset<ll> s;
    mll m;
    f(0,k)
    {
        s.insert(a[i]);
        m[a[i]]++;
    }
    auto it1 = s.begin();
    auto it2 = s.end();
    it2--;
    ll ans = *it2-*it1;
    f(k,n)
    {
        s.insert(a[i]);
        m[a[i]]++;
        if(m[a[i-k]]==1)
            s.erase(a[i-k]);
        m[a[i-k]]--;
        it1 = s.begin();
        it2 = s.end();
        it2--;
        ll x = *it2-*it1;
        if(x<ans)
            ans=x;
    }
    cout<<ans;
    return 0;
}