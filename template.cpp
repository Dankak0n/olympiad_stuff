//#0.2.5
#define Lil_Dankakon

#define _USE_MATH_DEFINES
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
#include <cassert>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define P pair
#define V vector
#define fi first
#define se second
#define re return
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define sq(x) ((x)*(x))
#define sz(a) ((int)(a).size())
#define all(a) begin(a),end(a)
#define rall(a) rbegin(a),rend(a)
#define unq(a) ((a).resize(unique((a).begin(),(a).end())-(a).begin()))
#define popcount __builtin_popcountll
#define maxbit(x) (__lg(x)-(!(x)))
#define getbit(x,i) (((x)>>(i))&1)
#define setbit(x,i,b) ((b)!=(((x)>>(i))&1)?(x)^=(1LL<<(i)):42)
#define IN(a,n) for(int32_t _i_=0;_i_<(n);++_i_){cin>>a[_i_];}
#define IN2(a,n,m) for(int32_t _i_=0;_i_<(n);++_i_){for(int32_t _j_=0;_j_<(m);++_j_){cin>>a[_i_][_j_];}}
#define OUT(a,n) for(int32_t _i_=0;_i_<(n);++_i_){cout<<a[_i_]<<' ';}
#define OUT2(a,n,m) for(int32_t _i_=0;_i_<(n);++_i_){for(int32_t _j_=0;_j_<(m);++_j_){cout<<a[_i_][_j_]<<' ';}cout<<'\n';}
#define ROUT(a,n) for(int32_t _i_=(n)-1;_i_>=0;--_i_){cout<<a[_i_]<<' ';}
#define FILL(a,n,x) for(int32_t _i_=0;_i_<(n);++_i_){a[_i_]=(x);}
#define FILL2(a,n,m,x) for(int32_t _i_=0;_i_<(n);++_i_){for(int32_t _j_=0;_j_<(m);++_j_){a[_i_][_j_]=(x);}}
#define FILL3(a,n,m,o,x) for(int32_t _i_=0;_i_<(n);++_i_){for(int32_t _j_=0;_j_<(m);++_j_){for(int32_t _k_=0;_k_<(o);++_k_){a[_i_][_j_][_k_]=(x);}}}
#define FILL4(a,n,m,o,q,x) for(int32_t _i_=0;_i_<(n);++_i_){for(int32_t _j_=0;_j_<(m);++_j_){for(int32_t _k_=0;_k_<(o);++_k_){for(int32_t _l_=0;_l_<(q);++_l_){a[_i_][_j_][_k_][_l_]=(x);}}}}
#define rep(i,f,s) for(int32_t i=(f);i!=(s);(f)<(s)?++i:--i)
#define repR(i,l,r) for(int32_t i=(l);i<(r);++i)
#define repL(i,r,l) for(int32_t i=(r);i>(l);--i)
#define llrep(i,f,s) for(int64_t i=(f);i!=(s);(f)<(s)?++i:--i)
#define llrepR(i,l,r) for(int64_t i=(l);i<(r);++i)
#define llrepL(i,r,l) for(int64_t i=(r);i>(l);--i)
#define rip(x) for(int32_t _i=0;_i<(x);++_i)
#define f0r(i,n) for(int32_t i=0;i<(n);++i)
#define f0rr(i,n) for(int32_t i=(n)-1;i>=0;--i)
#define y0 y_0_
#define y1 y_1_
#define data DaTa

int32_t _G_id, _G_tests_cnt;
bool _G_fastio, _G_show_debug;
char *_G_fopenr = nullptr, *_G_fopenw = nullptr;
inline void _settings(), _before_all(), _solve(), _after_s(), _after_all();

int main() {
_settings();
if (_G_fastio) { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); }
if (_G_fopenr[0]) freopen(_G_fopenr, "r", stdin);
if (_G_fopenw[0]) freopen(_G_fopenw, "w", stdout);
if (_G_tests_cnt < 1) std::cin >> _G_tests_cnt;
_before_all();
for (_G_id = 0; _G_id < _G_tests_cnt; ++_G_id) _solve(), _after_s();
_after_all();
}
//GOOSE!!! was here :( And I loved him )':

//debug------------------------------------------------------------------------------------------------
namespace debug_ns {
template<class T> inline void _VIVOD_(const char * c1, T a, char c2) { std::cout << std::fixed << "=(" << c1 << ")|" << a << "|" << c2; std::fflush(stdout); }
#ifdef LOCAL
#define deb(a) {\
if (typeid(a) == typeid(bool)) { std::cout << #a; debug_ns::_VIVOD_("bool", a, '\n'); }\
if (typeid(a) == typeid(char)) { std::cout << #a; debug_ns::_VIVOD_("char", a, '\n'); }\
if (typeid(a) == typeid(unsigned char)) { std::cout << #a; debug_ns::_VIVOD_("uchar", a, '\n'); }\
if (typeid(a) == typeid(int8_t)) { std::cout << #a; debug_ns::_VIVOD_("int8", a, '\n'); }\
if (typeid(a) == typeid(uint8_t)) { std::cout << #a; debug_ns::_VIVOD_("uint8", a, '\n'); }\
if (typeid(a) == typeid(int16_t)) { std::cout << #a; debug_ns::_VIVOD_("short", a, '\n'); }\
if (typeid(a) == typeid(uint16_t)) { std::cout << #a; debug_ns::_VIVOD_("ushort", a, '\n'); }\
if (typeid(a) == typeid(int32_t)) { std::cout << #a; debug_ns::_VIVOD_("int", a, '\n'); }\
if (typeid(a) == typeid(uint32_t)) { std::cout << #a; debug_ns::_VIVOD_("nint", a, '\n'); }\
if (typeid(a) == typeid(int64_t)) { std::cout << #a; debug_ns::_VIVOD_("ll", a, '\n'); }\
if (typeid(a) == typeid(uint64_t)) { std::cout << #a; debug_ns::_VIVOD_("ull", a, '\n'); }\
if (typeid(a) == typeid(std::string)) { std::cout << #a; debug_ns::_VIVOD_("string", a, '\n'); }\
if (typeid(a) == typeid(float)) { std::cout.precision(10); std::cout << #a; debug_ns::_VIVOD_("float", a, '\n'); }\
if (typeid(a) == typeid(double)) { std::cout.precision(10); std::cout << #a; debug_ns::_VIVOD_("double", a, '\n'); }\
if (typeid(a) == typeid(long double)) { std::cout.precision(10); std::cout << #a; debug_ns::_VIVOD_("L double", a, '\n'); }\
}
#else
#define deb(x) ;
#define debn(x,n) ;
#endif
}
//end_debug--------------------------------------------------------------------------------------------
using namespace debug_ns;


//random-----------------------------------------------------------------------------------------------
namespace random_ns {
size_t rndi(size_t x) { std::uniform_int_distribution<size_t> d(0, x - 1); std::mt19937 e(std::time(nullptr)); return d(e); }
int64_t rndi(int64_t l, int64_t r) { return l + rndi(r - l + 1); }
long double rndf(long double x) { std::uniform_real_distribution<long double> d(0, x); std::mt19937 e((long double)std::time(nullptr)); return d(e); }
long double rndf(long double l, long double r) { return l + rndf(r - l); }
}
//end_random-------------------------------------------------------------------------------------------
using namespace random_ns;


//shortened--------------------------------------------------------------------------------------------
namespace shortened_ns {
namespace operations_ns {
template<class T1, class T2> std::ostream& operator<<(std::ostream &o, std::pair<T1, T2> x) { return o << x.first << ' ' << x.second; }
template<class T1, class T2> std::istream& operator>>(std::istream &o, std::pair<T1, T2> &x) { return o >> x.first >> x.second; }
template<class T> std::ostream& operator<<(std::ostream &o, std::vector<T> &x) { for (auto &el : x) o << el << ' '; return o; }
template<class T> std::ostream& operator<=(std::ostream &o, std::vector<T> &x) { o << x.size() << '\n' << x; return o; }
template<class T> std::istream& operator>>(std::istream &o, std::vector<T> &x) { for (auto &el : x) o >> el; return o; }
template<class T1, class T2> std::pair<T1, T2> operator+(std::pair<T1, T2> a, std::pair<T1, T2> b) { a.first += b.first; a.second += b.second; return a; }
template<class T1, class T2> std::pair<T1, T2> operator-(std::pair<T1, T2> a, std::pair<T1, T2> b) { a.first -= b.first; a.second -= b.second; return a; }
template<class T1, class T2> void operator+=(std::pair<T1, T2> &a, std::pair<T1, T2> b) { a.first += b.first; a.second += b.second; }
template<class T1, class T2> void operator-=(std::pair<T1, T2> &a, std::pair<T1, T2> b) { a.first -= b.first; a.second -= b.second; }
}
namespace types_ns {
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
using   vs = std::vector<std::string>;
using  vll = std::vector<long long>;
using  vvi = std::vector<std::vector<int> >;
using vvch = std::vector<std::vector<char> >;
using vvll = std::vector<std::vector<long long> >;
using  mii = std::map<int, int>;
using  mll = std::map<long long, long long>;
}
}
//end_shortened----------------------------------------------------------------------------------------
using namespace shortened_ns::operations_ns;
using namespace shortened_ns::types_ns;


//useful-----------------------------------------------------------------------------------------------
namespace useful_ns {
namespace functions_ns {
inline int nint() { int x; std::cin >> x; return x; }
inline char nchr() { char x; std::cin >> x; return x; }
inline double nld() { double x; std::cin >> x; return x; }
inline long long nll() { long long x; std::cin >> x; return x; }
inline std::string nstr() { std::string x; std::cin >> x; return x; }
template<class T> inline T abs(T x) { return (x < 0 ? -x : x); }
template<class T1, class T2> inline auto max(T1 a, T2 b) { return (a < b ? b : a); }
template<class T1, class T2> inline auto min(T1 a, T2 b) { return (a < b ? a : b); }
template<class T1, class T2> inline T1 maxx(T1 &a, T2 b) { a = std::max(a, (T1)b); return a; }
template<class T1, class T2> inline T1 minn(T1 &a, T2 b) { a = std::min(a, (T1)b); return a; }
template<class T> inline void renew(T &a, int n) { a.clear(); a.resize(n); }
template<class T1, class T2> inline void renew(T1 &a, int n, T2 x) { a.clear(); a.resize(n, x); }
inline double _get_time() { return clock() / (double)CLOCKS_PER_SEC; }
}
namespace constants_ns {
const std::pair<int, int> to4[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const std::pair<int, int> to8[8] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
const std::pair<int, int> toK[8] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
const std::string _alf = "abcdefghijklmnopqrstuvwxyz";
const std::string _ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int       iINF = 2000000007;
const long long INF  = 2000000000000000007;
const long long MOD1 = 1000000007;
const long long MOD2 = 998244353;
}
}
//end_useful-------------------------------------------------------------------------------------------
using namespace useful_ns::functions_ns;
using namespace useful_ns::constants_ns;


using namespace std;

void _after_s() {
#ifdef LOCAL
#else
#endif
}

void _after_all() {
#ifdef LOCAL
std::cout << "\n__________\ntime = " << useful_ns::functions_ns::_get_time() << std::endl;
#else
#endif
}

const long long MOD = 1000000007;
const int         K = 10;
const int         D = 1010;
const int         N = 100100;

void _before_all() {}

//namespace...

void _solve() {
}

//-----------------------------------------------------------------------------------------------------
void _settings() {
_G_tests_cnt = 1;
_G_fastio    = 1;
#ifdef LOCAL
_G_fopenr = strdup("input.txt");//input.txt
_G_fopenw = strdup("");//output.txt
#else
_G_fopenr = strdup("");//input.txt
_G_fopenw = strdup("");//output.txt
#endif
}
