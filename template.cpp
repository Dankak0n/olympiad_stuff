//#0.2.1
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
#define          sz(a) ((int32_t)(a).size())
#define         all(a) a.begin(),a.end()
#define         unq(x) (x.resize(unique(x.begin(),x.end())-x.begin()))
#define       popcount __builtin_popcountll
#define      maxbit(x) (__lg(x)-(!(x)))
#define    getbit(x,i) (((x)>>(i))&1)
#define  setbit(x,i,b) ((b)?(x)|=((b)<<(i)):(x)&=((~(b))-((1LL)<<(i))))
#define        IN(a,n) for(int32_t _i_=0;_i_<(n);++_i_){cin>>a[_i_];}
#define     IN2(a,n,m) for(int32_t _i_=0;_i_<(n);++_i_){for(int32_t _j_=0;_j_<(m);++_j_){cin>>a[_i_][_j_];}}
#define       OUT(a,n) for(int32_t _i_=0;_i_<(n);++_i_){cout<<a[_i_]<<' ';}
#define    OUT2(a,n,m) for(int32_t _i_=0;_i_<(n);++_i_){for(int32_t _j_=0;_j_<(m);++_j_){cout<<a[_i_][_j_]<<' ';}cout<<'\n';}
#define      ROUT(a,n) for(int32_t _i_=(n)-1;_i_>=0;--_i_){cout<<a[_i_]<<' ';}
#define    FILL(a,n,x) for(int32_t _i_=0;_i_<(n);++_i_){a[_i_]=(x);}
#define FILL2(a,n,m,x) for(int32_t _i_=0;_i_<(n);++_i_){for(int32_t _j_=0;_j_<(m);++_j_){a[_i_][_j_]=(x);}}
#define     rep(f,s,i) for(int32_t i=(f);i!=(s);(f)<(s)?++i:--i)
#define    repR(l,r,i) for(int32_t i=(l);i<(r);++i)
#define    repL(r,l,i) for(int32_t i=(r);i>(l);--i)
#define   llrep(f,s,i) for(long long i=(f);i!=(s);(f)<(s)?++i:--i)
#define  llrepR(l,r,i) for(long long i=(l);i<(r);++i)
#define  llrepL(r,l,i) for(long long i=(r);i>(l);--i)
#define         rip(x) for(int32_t _i=0;_i<x;++_i)
#define       f0r(n,i) for(int32_t i=0;i<n;++i)
#define      f0rr(n,i) for(int32_t i=n-1;i>=0;--i)

#define y0 y_0_
#define y1 y_1_

#ifdef LOCAL
#define deb(x) std::cout<<"\n----\n"<<#x<<" = "<<(x)<<"\n----\n"<<std::endl;
#define debn(x,n) { std::cout<<"\n----\n"<<#n<<" = "<<(n)<<std::endl<<#x<<" = "; for(int _ii_=0;_ii_<(n);_ii_++) std::cout<<x[_ii_]<<' '; std::cout<<"\n----\n"<<std::endl; }
#else
#define deb(x) ;
#define debn(x,n) ;
#endif

int32_t _global_id, _global_tests;
bool _global_fastio;
char *_global_fopenr = nullptr, *_global_fopenw = nullptr;
inline void _settings(), _before_all(), _solve(), _after_s(), _after_all();

int main() {
	_settings();
	if (_global_fastio) { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); }
	if (_global_fopenr) freopen(_global_fopenr, "r", stdin);
	if (_global_fopenw) freopen(_global_fopenw, "w", stdout);
	if (_global_tests < 1) std::cin >> _global_tests;
	_before_all();
	for (_global_id = 0; _global_id < _global_tests; ++_global_id) _solve(), _after_s();
	_after_all();
}
//GOOSE!!! was here :( And I loved him )':

//shortened--------------------------------------------------------------------------------------------
namespace shortened {
namespace operations {
template<class T1, class T2> std::ostream& operator<<(std::ostream &o, std::pair<T1, T2> x) { return o << x.first << ' ' << x.second; }
template<class T1, class T2> std::istream& operator>>(std::istream &o, std::pair<T1, T2> &x) { return o >> x.first >> x.second; }
template<class T> std::ostream& operator<<(std::ostream &o, std::vector<T> &x) { for (auto &el : x) o << el << ' '; return o; }
template<class T> std::ostream& operator<=(std::ostream &o, std::vector<T> &x) { o << x.size() << '\n'; o << x << '\n'; return o; }
template<class T> std::istream& operator>>(std::istream &o, std::vector<T> &x) { for (auto &el : x) o >> el; return o; }
template<class T1, class T2> std::pair<T1, T2> operator+(std::pair<T1, T2> a, std::pair<T1, T2> b) { a.first += b.first; a.second += b.second; return a; }
template<class T1, class T2> std::pair<T1, T2> operator-(std::pair<T1, T2> a, std::pair<T1, T2> b) { a.first -= b.first; a.second -= b.second; return a; }
template<class T1, class T2> void operator+=(std::pair<T1, T2> &a, std::pair<T1, T2> b) { a.first += b.first; a.second += b.second; }
template<class T1, class T2> void operator-=(std::pair<T1, T2> &a, std::pair<T1, T2> b) { a.first -= b.first; a.second -= b.second; }
}

namespace types {
using   ll = long long;
using   ld = double;
using  lld = long double;
using uint = unsigned int;
using  ull = unsigned long long;
using  str = std::string;
using  pii = std::pair<int, int>;
using  pll = std::pair<long long, long long>;
using  pld = std::pair<double, double>;
using   vi = std::vector<int>;
using  vch = std::vector<char>;
using  vll = std::vector<long long>;
using  vvi = std::vector<std::vector<int>>;
using vvch = std::vector<std::vector<char>>;
using vvll = std::vector<std::vector<long long>>;
}
}
//end_shortened----------------------------------------------------------------------------------------

//useful-----------------------------------------------------------------------------------------------
namespace useful {
namespace functions {
char        nchr() { char x; std::cin >> x; return x;        }
double       nld() { double x; std::cin >> x; return x;      }
int32_t     nint() { int32_t x; std::cin >> x; return x;     }
long long    nll() { long long x; std::cin >> x; return x;   }
std::string nstr() { std::string x; std::cin >> x; return x; }
template<class T> inline T abs(T x) { return (x < 0 ? -x : x); }
template<class T1, class T2> auto max(T1 a, T2 b) { return (a < b ? b : a); }
template<class T1, class T2> auto min(T1 a, T2 b) { return (a < b ? a : b); }
template<class T1, class T2> T1 maxx(T1 &a, T2 b) { a = std::max(a, (T1)b); return a; }
template<class T1, class T2> T1 minn(T1 &a, T2 b) { a = std::min(a, (T1)b); return a; }
template<class T>            void renew(T &a, int32_t n) { a.clear(); a.resize(n); }
template<class T1, class T2> void renew(T1 &a, int32_t n, T2 x) { a.clear(); a.resize(n, x); }
double _get_time() { return clock() / (double)CLOCKS_PER_SEC; }
}

namespace constants {
const std::vector<std::pair<int32_t, int32_t>> to4 = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const std::vector<std::pair<int32_t, int32_t>> to8 = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
const std::vector<std::pair<int32_t, int32_t>> toK = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
const std::string _alf = "abcdefghijklmnopqrstuvwxyz";
const std::string _ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int       iINF = 2000000007;
const long long INF  = 2000000000000000007;
const long long MOD1 = 1000000007;
const long long MOD2 = 998244353;
}
}
//end_useful-------------------------------------------------------------------------------------------

//namespace...

using namespace std;
using namespace shortened::operations;
using namespace shortened::types;
using namespace useful::functions;
using namespace useful::constants;
//using namespace...

void _after_s() {
//	std::cout << '\n';
}

void _after_all() {
#ifdef LOCAL
	std::cout << "\n\ntime = " << useful::functions::_get_time() << std::endl;
#else
#endif
}

const long long MOD = 1000000007;
const int         K = 10;
const int         D = 1010;
const int         N = 100100;

void _before_all() {}

void _solve() {
}

//-----------------------------------------------------------------------------------------------------
void _settings() {
	_global_tests  = 1;
	_global_fastio = 1;
#ifdef LOCAL
	static char fropenr[] = "input.txt";//input.txt
	static char fropenw[] = "";//output.txt
#else
	_global_fastio = 1;
	static char fropenr[] = "";//input.txt
	static char fropenw[] = "";//output.txt
#endif
	_global_fopenr = fropenr;
	_global_fopenw = fropenw;
}
