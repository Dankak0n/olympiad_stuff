//Lil_Dankakon

#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <stack>
#include <cstdio>
#include <vector>
#include <bitset>
#include <random>
#include <string>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <numeric>
#include <cassert>
#include <utility>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define              V vector
#define             fi first
#define             se second
#define             re return
#define             pb push_back
#define             eb emplace_back
#define             mp make_pair
#define          sq(x) ((ll)(x) * (ll)(x))
#define          sz(a) ((long long)(a).size())
#define         all(a) a.begin(), a.end()
#define         unq(x) (x.resize(unique(all(x)) - x.begin()))
#define       popcount __builtin_popcountll
#define      maxbit(x) (63 - __builtin_clzll(x))
#define    getbit(x,i) ((((ll)x)>>(i))&1LL)
#define        IN(a,n) for(int _i_=0;_i_<(n);++_i_){cin>>a[_i_];}
#define     IN2(a,n,m) for(int _i_=0;_i_<(n);++_i_){for(int _j_=0;_j_<(m);++_j_){cin>>a[_i_][_j_];}}
#define       OUT(a,n) for(int _i_=0;_i_<(n);++_i_){cout<<a[_i_]<<' ';}
#define    OUT2(a,n,m) for(int _i_=0;_i_<(n);++_i_){for(int _j_=0;_j_<(m);++_j_){cout<<a[_i_][_j_]<<' ';}cout<<'\n';}
#define      ROUT(a,n) for(int _i_=(n)-1;_i_>=0;--_i_){cout<<a[_i_]<<' ';}
#define    FILL(a,n,x) for(int _i_=0;_i_<(n);++_i_){a[_i_]=(x);}
#define FILL2(a,n,m,x) for(int _i_=0;_i_<(n);++_i_){for(int _j_=0;_j_<(m);++_j_){a[_i_][_j_]=(x);}}
#define     rep(l,r,i) for(ll i=(l);i!=(r);i+=((l)<(r)?1LL:-1LL))

#define   y0 y_9910
#define   y1 y_9911
#define next next_239
#define prev prev_239

using namespace std;

template<class T1, class T2> ostream& operator << (ostream &o, pair<T1, T2> x) {re o << x.fi << ' ' << x.se;}
template<class T1, class T2> istream& operator >> (istream &o, pair<T1, T2> &x) {re o >> x.fi >> x.se;}
template<class T> ostream& operator << (ostream &o, vector<T> &x) {for (auto &el : x) o << el << ' '; re o;}
template<class T> istream& operator >> (istream &o, vector<T> &x) {for (auto &el : x) o >> el; re o;}
template<class T1, class T2> pair<T1, T2> operator + (pair<T1, T2> a, pair<T1, T2> b) {a.fi += b.fi; a.se += b.se; re a;}
template<class T1, class T2> pair<T1, T2> operator - (pair<T1, T2> a, pair<T1, T2> b) {a.fi -= b.fi; a.se -= b.se; re a;}
template<class T1, class T2> void operator += (pair<T1, T2> &a, pair<T1, T2> b) {a.fi += b.fi; a.se += b.se;}
template<class T1, class T2> void operator -= (pair<T1, T2> &a, pair<T1, T2> b) {a.fi -= b.fi; a.se -= b.se;}

using   ll = long long;
using   ld = long double;
using  ull = unsigned long long;
using  str = string;
using  pll = pair <ll, ll>;
using  pii = pair <int, int>;
using  pld = pair <ld, ld>;
using  vll = vector <ll>;
using   vi = vector <int>;

double getTime(){re clock() / (double) CLOCKS_PER_SEC;};

mt19937 rnd(0);

str  nstr() {str x; cin >> x; re x;}
char nchr() {char x; cin >> x; re x;}
ll    nll() {ll x; cin >> x; re x;}
ll rand(ll n) { re rnd() % n; }
ll rand(ll l, ll r) { re rnd() % (r - l + 1) + l; }


#ifdef LOCAL
bool is_local = 1;
#define deb(x) cout << #x << " = " << (x) << endl
#define debn(x, n) { cout << #x << "(" << n << ") = " << \
	"{"; int _f_ = 1; rep(0, n, _i_) {if (!_f_) cout << "|"; cout << x[_i_]; _f_= 0;} cout << "}" << endl;}
#define deba(x) { cout << #x << " (size: " << sz(x) << ") = " << \
	"{"; int _f_ = 1; for (auto o : x) {if (!_f_) cout << "|"; cout << o; _f_ = 0;} cout << "}" << endl;}
#else
bool is_local = 0;
#define deb(x) ;
#define debn(x, n) ;
#define deba(x) ;
#endif
void init_() {
    if (is_local) {
        freopen ("input.txt", "r", stdin);
//        freopen ("output.txt", "w", stdout);
		srand((int)time(0));
		rnd.seed((int)time(0));
    }
    else {
//        freopen ("input.txt", "r", stdin);
//        freopen ("output.txt", "w", stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void solve_();
void precalculation_();
void cin_(int & i);

int main() {
    init_();
    precalculation_();
    int tests = 1;
    cin_(tests);
    for(int i = 0; i < tests; ++i) {
//        cout << "Case #" << i + 1 << ": ";
        solve_();
    }
    if (is_local)
        cout << endl << endl << "time = " << getTime() << endl;
}
//GOOSE!!! was here :(
//And I loved him
//)':

//#include <ext/pb_ds/assoc_container.hpp>
//#define    unknown_t int
//#define   lower_than order_of_key
//#define get_ith(s,i) *s.find_by_order(i)
//using namespace __gnu_pbds;
//typedef tree <unknown_t, null_type, less <unknown_t>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//#include <bits/stdc++.h>

//#define point pld
//#define X fi
//#define Y se

//const pll to4[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//const pll to8[8] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
const ld    PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
const ll     D = 510;
const ll    D2 = 1010;
const ll     N = 101000;
const ll    N2 = 201000;
const ll    N3 = 301000;
const ll    N4 = 401000;
const ll    N5 = 501000;
const ll   INF = 2000000000000000007;
const int iINF = 2000000007;
//1000000007
//998244353
const ll   MOD = 998244353;

void precalculation_() {
}

void solve_() {
}

//--------------------------------------------------------------------------------------------------------------------
void cin_(int & i) {
//    cin >> i;
}





//
