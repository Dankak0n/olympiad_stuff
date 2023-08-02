//#0.1.1
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

#define              P pair
#define              V vector
#define             fi first
#define             se second
#define             re return
#define             pb push_back
#define             eb emplace_back
#define             mp make_pair
#define          sq(x) ((x)*(x))
#define          sz(a) ((a).size())
#define         all(a) a.begin(),a.end()
#define         abs(x) ((x)<0?-(x):(x))
#define         unq(x) (x.resize(unique(x.begin(),x.end())-x.begin()))
#define       popcount __builtin_popcountll
#define      maxbit(x) ((x)>0?63-__builtin_clzll(x):-1)
#define    getbit(x,i) (((x)>>(i))&1)
#define        IN(a,n) for(int _i_=0;_i_<(n);++_i_){cin>>a[_i_];}
#define     IN2(a,n,m) for(int _i_=0;_i_<(n);++_i_){for(int _j_=0;_j_<(m);++_j_){cin>>a[_i_][_j_];}}
#define       OUT(a,n) for(int _i_=0;_i_<(n);++_i_){cout<<a[_i_]<<' ';}
#define    OUT2(a,n,m) for(int _i_=0;_i_<(n);++_i_){for(int _j_=0;_j_<(m);++_j_){cout<<a[_i_][_j_]<<' ';}cout<<'\n';}
#define      ROUT(a,n) for(int _i_=(n)-1;_i_>=0;--_i_){cout<<a[_i_]<<' ';}
#define    FILL(a,n,x) for(int _i_=0;_i_<(n);++_i_){a[_i_]=(x);}
#define FILL2(a,n,m,x) for(int _i_=0;_i_<(n);++_i_){for(int _j_=0;_j_<(m);++_j_){a[_i_][_j_]=(x);}}
#define     rep(f,s,i) for(int i=(f);i!=(s);(f)<(s)?++i:--i)
#define    repR(l,r,i) for(int i=(l);i<(r);++i)
#define    repL(r,l,i) for(int i=(r);i>(l);--i)
#define   llrep(f,s,i) for(long long i=(f);i!=(s);(f)<(s)?++i:--i)
#define  llrepR(l,r,i) for(long long i=(l);i<(r);++i)
#define  llrepL(r,l,i) for(long long i=(r);i>(l);--i)
#define         rip(x) for(int _i=0;_i<x;++_i)
#define       f0r(n,i) for(int i=0;i<n;++i)
#define      f0rr(n,i) for(int i=n-1;i>=0;--i)

#define   y0 y_9910
#define   y1 y_9911

using namespace std;

template<class T1, class T2> ostream& operator << (ostream &o, pair<T1, T2> x) { return o << x.first << ' ' << x.second; }
template<class T1, class T2> istream& operator >> (istream &o, pair<T1, T2> &x) { return o >> x.first >> x.second; }
template<class T> ostream& operator << (ostream &o, vector<T> &x) { for (auto &el : x) o << el << ' '; return o; }
template<class T> istream& operator >> (istream &o, vector<T> &x) { for (auto &el : x) o >> el; return o; }
template<class T1, class T2> pair<T1, T2> operator + (pair<T1, T2> a, pair<T1, T2> b) { a.first += b.first; a.second += b.second; return a; }
template<class T1, class T2> pair<T1, T2> operator - (pair<T1, T2> a, pair<T1, T2> b) { a.first -= b.first; a.second -= b.second; return a; }
template<class T1, class T2> void operator += (pair<T1, T2> &a, pair<T1, T2> b) { a.first += b.first; a.second += b.second; }
template<class T1, class T2> void operator -= (pair<T1, T2> &a, pair<T1, T2> b) { a.first -= b.first; a.second -= b.second; }

using   ll = long long;
using   ld = double;
using  lld = long double;
using  ull = unsigned long long;
using  str = string;
using  pll = pair <ll, ll>;
using  pii = pair <int, int>;
using  pld = pair <double, double>;
using  vll = vector <long long>;
using   vi = vector <int>;

mt19937 rnd(0);

int      nint() { int x; cin >> x; return x; }
long long nll() { long long x; cin >> x; return x; }
double    nld() { double x; cin >> x; return x; }
char     nchr() { char x; cin >> x; return x; }
str      nstr() { string x; cin >> x; return x; }

long long rand(long long n)              { return rnd() % n; }
long long rand(long long l, long long r) { return rnd() % (r - l + 1) + l; } //[]

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


#ifdef LOCAL
bool _is_local = 1;
#define deb(x) cout << #x << " = " << (x) << endl
#define debn(x, n) { cout << #x << "(" << n << ") = " << \
    "{"; int _f_ = 1; rep(0, n, _i_) {if (!_f_) cout << "|"; cout << x[_i_]; _f_= 0;} cout << "}" << endl;}
#define deba(x) { cout << #x << " (size: " << sz(x) << ") = " << \
    "{"; int _f_ = 1; for (auto o : x) {if (!_f_) cout << "|"; cout << o; _f_ = 0;} cout << "}" << endl;}
#else
bool _is_local = 0;
#define deb(x) ;
#define debn(x, n) ;
#define deba(x) ;
#endif

void
_freopen(),
_freopen_local(),
_solve(),
_precalculation(),
_cin(int &i);

void _init() {
    if (_is_local) { _freopen_local(); srand((int)time(0)); rnd.seed((int)time(0)); }
    else { _freopen(); }
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int main() {
    _init();
    int tests = 1;
    _cin(tests);
    _precalculation();
    for(int i = 0; i < tests; ++i) _solve();
    if (_is_local) cout << "\n\ntime = " << getTime() << endl;
}
//GOOSE!!! was here :(
//And I loved him
//)':

const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
const string _alf = "abcdefghijklmnopqrstuvwxyz";
const string _ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

//--------------------------------------------------------------------------------------------------------------------

//namespace...

//#include <ext/pb_ds/assoc_container.hpp>
//#define    unknown_t int
//#define   lower_than order_of_key
//#define get_ith(s,i) *s.find_by_order(i)
//using namespace __gnu_pbds;
//typedef tree <unknown_t, null_type, less <unknown_t>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//#include <bits/stdc++.h>

//const vector < pair <int, int> > to4 = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//const vector < pair <int, int> > to8 = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
//const vector < pair <int, int> > toK = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

const int      iINF = 2000000007;
const long long INF = 2000000000000000007;

//1000000007
//998244353
const long long MOD = 1000000007;

const int         K = 10;
const int         D = 1010;
const int         N = 100100;

//using namespace

void _precalculation() {
}

void _solve() {
}


//--------------------------------------------------------------------------------------------------------------------
void _cin(int &i) {
//    cin >> i;
}

void _freopen() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
}

void _freopen_local() {
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
}


//
