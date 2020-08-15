#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> // Policy_based_Data_Structure
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

/*#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;*/

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define ll long long int
#define ld long double
#define bigint int64_t
#define fst first
#define scd second
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test ll t;read(t);while(t--)
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define INF (ll)(3e18)
#define vvll vector<vector<ll>>
#define R_0 return 0

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))

template <typename T>
void read(T &x) {
    cin >> x;
}
template <typename T , typename T0>
void read(T &x, T0 &y) {
    cin >> x >> y;
}

template <typename T , typename T0 , typename T1>
void read(T &x, T0 &y, T1 &z) {
    cin >> x >> y >> z;
}

template <typename T , typename T0 , typename T1 , typename T2>
void read(T &x, T0 &y, T1 &z, T2 &w) {
    cin >> x >> y >> z >> w;
}

template <typename T , typename T0>
void read(pair< T , T0 > &p) {
    cin >> p.fst >> p.scd;
}

template <typename T>
void read(vector< T > &oneD, ll n) {
    forn(i, n)
    {
        ll x;
        read(x);
        oneD.push_back(x);
    }
}

template <typename T>
void read(T oneD[] , ll n) {
    for (ll i = 0; i < n; i++) {
        read(oneD[i]);
    }
}

template <typename T>
void write(T &x) {

    cout << x << " ";
}

template <typename T , typename T0>
void write(T &x, T0 &y) {
    cout << x << " " << y << "\n";
}

template <typename T , typename T0 , typename T1>
void write(T &x, T0 &y, T1 &z) {
    cout << x << " " << y << " " << z << "\n";
}

template <typename T , typename T0 , typename T1 , typename T2>
void write(T &x, T0 &y, T1 &z, T2 &w) {
    cout << x << " " << y << " " << z << " " << w << "\n";
}

template <typename T , typename T0>
void write(pair< T , T0 > &p) {
    write(p.fst);
    write(p.scd);
    cout << endl;
}

template <typename T>
void write(vector< T > &oneD, ll n) {
    for (ll i = 0; i < n; i++) {
        cout << oneD[i] << " ";
    }
    cout << endl;
}

template <typename T>
void write(T oneD[] , int n) {
    for (ll i = 0; i < n; i++) {
        write(oneD[i]);
    }
    cout << endl;
}

template <typename T , typename T0>
void write(map< T , T0 > &mpp) {
    for (auto it : mpp) {
        write(it.fst);
        cout << ": ";
        write(it.scd);
        cout << "\n";
    }
    cout << endl;
}

vll seive;
void Seive() {
    const ll maxn = 1e6 + 5;
    seive.resize(maxn);
    forn(i, maxn) seive[i] = i;
    forab(i, 2, maxn, 2)
    seive[i] = 2;
    seive[1] = -1;
    seive[0] = -1;
    for (ll i = 3; i <= maxn; i += 2) if (i == seive[i]) for (ll j = i * i ; j < maxn ; j += i) if (seive[j] == j) seive[j] = i;
}

ll extended_GCD(ll a , ll b , ll &x , ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b % a , a , x1 , y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

ll modinv(ll a , ll mod = MOD) {
    ll x , y;
    extended_GCD(a , mod , x , y);
    if (x < 0) x += mod;
    return x;
}

//Chinese Remainder Theoram
ll find_x_CRT(ll num[], ll rem[], ll n)
{
    ll pro = 1;
    forn(i, n)
    pro *= num[i];
    ll res = 0;
    forn(i, n)
    {
        ll pp = pro / num[i];
        res += (rem[i] * modinv(pp, num[i]) * pp);
    }
    res %= pro;
    return res;
}

ll power(ll a, ll b, ll m = MOD) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll powe(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

string getString(char x)
{
    string s(1, x);
    return s;
}

// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> index_set;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

void precompute_NCR(vll &fact)
{
    const ll N = 1e6 + 5;
    fact[0] = 1;
    forab(i, 1, (N - 1), 1)
    {
        ll y = (i % MOD * fact[i - 1] % MOD) % MOD;
        fact[i] = y;
    }
}

ll NCR(vll &fact, ll N, ll R, ll mod = MOD)
{
    ll n = fact[N];
    ll r = fact[R];
    ll n_r = fact[N - R];
    ll y = (r % mod * n_r % mod) % mod;
    ll z = modinv(y, mod);
    ll ans = (n % mod * z % mod) % mod;
    return ans;
}

void shuru_karte_hai_bina_kise_bakchodi_ke()
{
    flash;
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
}

int main()
{
    shuru_karte_hai_bina_kise_bakchodi_ke();
    ll n;
    read(n);
    ll a[n];
    read(a, n);
    ll x = 0;
    forn(i, n)
    x = x ^ a[i];
    forn(i, n)
    {
        cout << (x ^ a[i]) << " ";
    }
    return 0;
}