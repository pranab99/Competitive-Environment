/*
	Author : _reyna_
	Created On : 10/03/2021 18:03:12
*/

#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define MP make_pair
#define mt make_tuple
#define eb emplace_back
#define ar array
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
#define db2d(arr) for(auto x : arr){ for(auto y : x) cout << y << " "; cout << "\n";}
#define read(arr) for(auto &x : arr) cin >> x;
#define sz(x) (int)x.size()
#define MOD 1000000007
#define MOD2 998244353
#define nl '\n'
using namespace std;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k 
// find_by_order(k) : K-th element in a set (counting from zero)

string to_string(char c) {
	return string(1, c);
}

string to_string(bool b) {
	return b ? "true" : "false";
}

string to_string(const char* s) {
	return string(s);
}

string to_string(string s) {
	return s;
}

string to_string(vector < bool > v) {
	string res;
	for(int i = 0; i < sz(v); i++)
		res += char('0'+v[i]);
	return res;
}
 
template < size_t S > string to_string(bitset < S > b) {
	string res;
	for(int i = 0; i < S; i++)
		res += char('0' + b[i]);
	return res;
}

template < class T > string to_string(T v) {
    bool f = 1;
    string res;
    for(auto x : v) {
		if(!f)
			res+=' ';
		f=0;
		res += to_string(x);
	}
    return res;
}
 
void dbvar() { cerr << "]" << endl; }
template<class H, class... T> void dbvar(H h, T... t){
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	dbvar(t...);
}

template<class A> void write(A x) {
	cout << to_string(x);
}

template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}

void print() {
	write("\n");
}

template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}

template <typename T1, typename T2>
constexpr typename std::common_type<T1, T2>::type floor_div(T1 x, T2 y) {
	assert(y != 0);
	if (y < 0) x = -x, y = -y;
	return x < 0 ? (x - y + 1) / y : x / y;
}

const ll INFL = (ll)1e18;
const int INF = (int)1e9;
const ld eps = (ld)1e-9;
const ld pi = acos(-1.0);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

ll power(ll n, ll m){
	if(m == 0) return 1;
	ll val = power(n, m/2);
	if(m % 2 == 0) return (val * val); else return ((val * val) * n);
}

ll powermod(ll n, ll m, ll _MOD){
	if(m == 0) return 1;
	ll val = powermod(n,m/2,_MOD);
	val %= _MOD;
	if(m % 2 == 0) return (val * val) % _MOD; else return (((val * val) % _MOD) * n) % _MOD;
}

void solve(){
	int n; cin >> n;
	double ans = 0.0;
	auto calc = [](int x, int y){
		ll x_ = (ll)x;
		ll y_ = (ll)y;
		return sqrtl(x_ * x_ + y_ * y_);
	};
	vector < int > miner, diamond;
	for(int i = 0; i < 2*n; i++){
		int x, y; cin >> x >> y;
		if(x == 0) miner.pb(abs(y)); else diamond.pb(abs(x));
	}
	sort(all(miner)); sort(all(diamond));
	for(int i = 0; i < n; i++){
		ans += calc(miner[i], diamond[i]);
		// cout << ans << ' ';
	}
	double temp = 0.0;
	for(int i = 0; i < n; i++){
		temp += calc(miner[i], diamond[n - 1 - i]);
		// cout << temp << ' ';
	}
	ans = min(ans, temp);
	// print(ans);
	cout << ans << '\n';
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	cout << setprecision(15) << fixed;
	
	int t = 1;
	cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}