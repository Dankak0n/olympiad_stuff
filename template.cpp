#define Lil_Dankakon

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
#include <iterator>
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
#define          sq(x) ((x)*(x))
#define          sz(a) ((long long)(a).size())
#define         all(a) a.begin(),a.end()
#define         unq(x) (x.resize(unique(x.begin(),x.end())-x.begin()))
#define       popcount __builtin_popcountll
#define      maxbit(x) (63-__builtin_clzll(x))
#define    getbit(x,i) ((((ll)x)>>(i))&1LL)
#define      vali(a,i) ((i)>=0?(a)[i]:0)
#define        IN(a,n) for(int _i_=0;_i_<(n);++_i_){cin>>a[_i_];}
#define     IN2(a,n,m) for(int _i_=0;_i_<(n);++_i_){for(int _j_=0;_j_<(m);++_j_){cin>>a[_i_][_j_];}}
#define       OUT(a,n) for(int _i_=0;_i_<(n);++_i_){cout<<a[_i_]<<' ';}
#define    OUT2(a,n,m) for(int _i_=0;_i_<(n);++_i_){for(int _j_=0;_j_<(m);++_j_){cout<<a[_i_][_j_]<<' ';}cout<<'\n';}
#define      ROUT(a,n) for(int _i_=(n)-1;_i_>=0;--_i_){cout<<a[_i_]<<' ';}
#define    FILL(a,n,x) for(int _i_=0;_i_<(n);++_i_){a[_i_]=(x);}
#define FILL2(a,n,m,x) for(int _i_=0;_i_<(n);++_i_){for(int _j_=0;_j_<(m);++_j_){a[_i_][_j_]=(x);}}
#define     rep(f,s,i) for(ll i=(f);i!=(s);i+=((f)<(s)?1LL:-1LL))
#define    repR(l,r,i) for(ll i=(l);i<(r);i++)
#define    repL(r,l,i) for(ll i=(r);i>(l);i--)
#define         rip(x) for(int __i=0;__i<x;__i++)

#define   y0 y_9910
#define   y1 y_9911

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

void freopen_();
void freopen_local_();
void solve_();
void precalculation_();
void cin_(int & i);

void init_() {
    if (is_local) {
        freopen_local_();
        srand((int)time(0));
        rnd.seed((int)time(0));
    }
    else {
        freopen_();
    }
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    init_();
    int tests = 1;
    cin_(tests);
    precalculation_();
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

const ld    PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
const int    D = 510;
const int   D2 = 1010;
const int    N = 101000;
const int   N2 = 201000;
const int   N3 = 301000;
const int   N4 = 401000;
const int   N5 = 501000;
const int   N6 = 601000;
const ll   INF = 2000000000000000007;
const int iINF = 2000000007;

//--------------------------------------------------------------------------------------------------------------------



//#include <ext/pb_ds/assoc_container.hpp>
//#define    unknown_t int
//#define   lower_than order_of_key
//#define get_ith(s,i) *s.find_by_order(i)
//using namespace __gnu_pbds;
//typedef tree <unknown_t, null_type, less <unknown_t>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//#include <bits/stdc++.h>

//#define point pld
//#define point pii
//#define X fi
//#define Y se

//const V<pll> to4 = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//const V<pll> to8 = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
//1000000007
//998244353
const ll   MOD = 1000000007;



void precalculation_() {
}

void solve_() {
}




//--------------------------------------------------------------------------------------------------------------------
void cin_(int & i) {
//    cin >> i;
}

void freopen_() {
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);
}

void freopen_local_() {
    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);
}


//
