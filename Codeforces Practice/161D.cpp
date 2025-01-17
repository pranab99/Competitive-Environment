#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define ar array
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
#define db2d(arr) for(auto x : arr){ for(auto y : x) cout << y << " "; cout << "\n";}
#define read(arr) for(auto &x : arr) cin >> x;
#define nl "\n"
#define sz(x) (int)x.size()
#define MOD 1000000007
#define MOD2 998244353
using namespace std;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key (k) : Number of items strictly smaller than k 
// find_by_order(k) : K-th element in a set (counting from zero)

const ll inf = (ll)1e18;
const int mod = (ll)1e9 + 7;
const ld eps = (ld)1e-9;
const ld pi = acos(-1.0);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int d8x[8]={-1, -1, 0, 1, 1, 1, 0, -1};
const int d8y[8]={0, 1, 1, 1, 0, -1, -1, -1};

ll power(ll n,ll m){
	if(m==0) return 1;
	ll val=power(n,m/2);
	if(m%2==0) return (val*val); else return ((val*val)*n);
}

ll powermod(ll n,ll m,ll _MOD){
	if(m==0) return 1;
	ll val=powermod(n,m/2,_MOD);
	val %= _MOD;
	if(m%2==0) return (val*val) % _MOD; else return (((val*val) % _MOD) * n) % _MOD;
}

int mult(ll a,ll b){ return (a*b)%MOD; }

int pot(int n,int k){
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}
 
int divide(int a,int b){ return mult(a,pot(b,MOD-2)); }
int sub(int a,int b){ if (a-b>=0) return a-b; return a-b+MOD; }
int add(int a,int b){ if (a+b>=MOD) return a+b-MOD;	return a+b; }

const int mxN = 5e4 + 50;
vector < int > g[mxN];
bool vis[mxN];
int n, k;
ll ans;

void dfs(int v, int d[501]){
	vis[v] = true;
	int d2[501];
	for(int i = 0; i <= k; i++) d[i] = 0;
	d[0] = 1;
	for(auto x : g[v]){
		if(!vis[x]){
			dfs(x, d2);
			for(int j = k; j > 0; j--){ d2[j] = d2[j - 1]; ans += (ll)(d2[j] * d[k - j]);}
			for(int j = 1; j <= k; j++) d[j] += d2[j];
		}
	}
}

void solve(){
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int l, r;
		cin >> l >> r;
		g[l].pb(r);
		g[r].pb(l);
	}
	int d[501];
	dfs(1, d);
	cout << ans << nl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	#endif

	int t = 1;
	// cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}