//#Long 0.0.1

#define  _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#ifndef LOCAL_DANKAKON
#pragma comment(linker, "/STACK:200000000")
#endif

#define P pair
#define V vector
#define fi first
#define se second
#define re return
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gr greater
#define pob pop_back
#define con continue
#define ba(a) (a).back()
#define sq(x) ((x)*(x))
#define sz(a) ((ll)(a).size())
#define all(a) (a).begin(),(a).end()
#define unq(a) ((a).resize(unique((a).begin(),(a).end())-(a).begin()))
#define cntbit __builtin_popcountll
#define lilbit __builtin_ctzll
#define maxbit(x) ((x)<=0?-1:__lg(x))
#define getbit(x,i) (((x)>>(i))&1)
#define setbit(x,i,b) ((!!(b))!=(((x)>>(i))&1)?(x)^=(1LL<<(i)):42)
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define llrep(i,l,r) for(long long i=(l);i<(r);++i)
#define repL(i,r,l) for(int i=(r);i>(l);--i)
#define llrepL(i,r,l) for(long long i=(r);i>(l);--i)
#define rip(x) for(int J_J_=0;J_J_<(x);++J_J_)
#define f0r(i,n) for(int i=0;i<(n);++i)
#define f0rr(i,n) for(int i=(n)-1;i>=0;--i)
#define y0 y_0_
#define y1 y_1_
#define data DaTa
#define get GeT

int _GId;
int _GTestsCnt;
bool _GFastio;
bool _GShowDebug;
char *_GFopenr = nullptr;
char *_GFopenw = nullptr;
inline void _settings();
inline void _beforeAll();
inline void _solve();
inline void _afterS();
inline void _afterAll();

signed main() {
_settings();
if (_GFastio) { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); }
if (_GFopenr[0]) freopen(_GFopenr, "r", stdin);
if (_GFopenw[0]) freopen(_GFopenw, "w", stdout);
if (_GTestsCnt < 1) std::cin >> _GTestsCnt;
_beforeAll();
for (_GId = 0; _GId < _GTestsCnt; ++_GId) _solve(), _afterS();
_afterAll();
}
//GOOSE!!! was here :( And I loved him )':

//debug------------------------------------------------------------------------------------------------
#ifdef LOCAL_DANKAKON
#define debn(x, n) { cout << __LINE__ << ": " << #x << "(" << n << ") = " << \
    "{"; int _f_ = 1; rep(_i_, n) {if (!_f_) cout << "|"; cout << x[_i_]; _f_= 0;} cout << "}" << endl;}
#define deba(x) { cout << __LINE__ << ": " << #x << " (size: " << sz(x) << ") = " << \
    "{"; int _f_ = 1; for (auto o : x) {if (!_f_) cout << "|"; cout << o; _f_ = 0;} cout << "}" << endl;}

#define _name(name, _1, _2, _3, _4, _5, N, ...) name ## N
#define _dbg(x) cout << #x << " = " << x << "   "
#define _dbg1(x) _dbg(x)
#define _dbg2(x, ...) _dbg(x); _dbg1(__VA_ARGS__)
#define _dbg3(x, ...) _dbg(x); _dbg2(__VA_ARGS__)
#define _dbg4(x, ...) _dbg(x); _dbg3(__VA_ARGS__)
#define _dbg5(x, ...) _dbg(x); _dbg4(__VA_ARGS__)
#define deb(...) do { cout << __LINE__ << ": "; _name(_dbg, __VA_ARGS__, 5, 4, 3, 2, 1, 0)(__VA_ARGS__); cout << endl;} while (0)

#else
#define deb(...) ;
#define debn(x, n) ;
#define deba(x) ;
#define endl "\n"
#endif
//end_debug--------------------------------------------------------------------------------------------

//random-----------------------------------------------------------------------------------------------
static std::random_device __rd;
static std::mt19937 RNG(__rd());
inline size_t rndn(size_t _max) {
    std::uniform_int_distribution<> _ret(0, _max);
    return _ret(RNG);
}
inline long long rndlr(long long _l, long long _r) {
    return 1LL * rndn(_r - _l) + _l;
}
//end_random-------------------------------------------------------------------------------------------

//shortened--------------------------------------------------------------------------------------------
template<class T1, class T2> std::ostream& operator<<(std::ostream &o, std::pair<T1, T2> x) { return o << x.first << ' ' << x.second; }
template<class T1, class T2> std::istream& operator>>(std::istream &o, std::pair<T1, T2> &x) { return o >> x.first >> x.second; }
template<class T> std::ostream& operator<<(std::ostream &o, std::vector<T> &x) { for (auto &el : x) o << el << ' '; return o; }
template<class T> std::ostream& operator<<(std::ostream &o, std::set<T> &x) { for (auto &el : x) o << el << ' '; return o; }
template<class T> std::ostream& operator<<(std::ostream &o, std::multiset<T> &x) { for (auto &el : x) o << el << ' '; return o; }
template<class T1, class T2> std::ostream& operator<<(std::ostream &o, std::map<T1, T2> &x) { o << '['; for (auto &el : x) o << '(' << el.first << ", " << el.second << ")\t"; o << ']'; return o; }
template<class T1, class T2> std::ostream& operator<<(std::ostream &o, std::unordered_map<T1, T2> &x) { o << '['; for (auto &el : x) o << '(' << el.first << ", " << el.second << ")\t"; o << ']'; return o; }
template<class T> std::ostream& operator<=(std::ostream &o, std::vector<T> &x) { o << x.size() << '\n' << x; return o; }
template<class T> std::istream& operator>>(std::istream &o, std::vector<T> &x) { for (auto &el : x) o >> el; return o; }
template<class T1, class T2> std::pair<T1, T2> operator+(std::pair<T1, T2> a, std::pair<T1, T2> b) { a.first += b.first; a.second += b.second; return a; }
template<class T1, class T2> std::pair<T1, T2> operator-(std::pair<T1, T2> a, std::pair<T1, T2> b) { a.first -= b.first; a.second -= b.second; return a; }
template<class T1, class T2> void operator+=(std::pair<T1, T2> &a, std::pair<T1, T2> b) { a.first += b.first; a.second += b.second; }
template<class T1, class T2> void operator-=(std::pair<T1, T2> &a, std::pair<T1, T2> b) { a.first -= b.first; a.second -= b.second; }

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
using  mvi = std::map<int, std::vector<int> >;
using  mvl = std::map<int, std::vector<long long> >;
using mlvi = std::map<long long, std::vector<int> >;
using mlvl = std::map<long long, std::vector<long long> >;
//end_shortened----------------------------------------------------------------------------------------

//useful-----------------------------------------------------------------------------------------------
inline int nint() { int x; std::cin >> x; return x; }
inline char nchr() { char x; std::cin >> x; return x; }
inline double nld() { double x; std::cin >> x; return x; }
inline long long nll() { long long x; std::cin >> x; return x; }
inline std::string nstr() { std::string x; std::cin >> x; return x; }
template<class T1, class T2> inline auto max(T1 a, T2 b) { return (a < b ? b : a); }
template<class T1, class T2> inline auto min(T1 a, T2 b) { return (a < b ? a : b); }
template<class T1, class T2> inline T1 maxx(T1 &a, T2 b) { a = std::max(a, (T1)b); return a; }
template<class T1, class T2> inline T1 minn(T1 &a, T2 b) { a = std::min(a, (T1)b); return a; }
inline double _get_time() { return clock() / (double)CLOCKS_PER_SEC; }
namespace to4 {
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
}
namespace to8 {
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
}
namespace toK {
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
}
const std::string _alf = "abcdefghijklmnopqrstuvwxyz";
const std::string _ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int       iINF = 2000000007;
const long long INF  = 2000000000000000007;
const long long MOD1 = 1000000007;
const long long MOD2 = 998244353;
//end_useful-------------------------------------------------------------------------------------------

//namespace

void _beforeAll() {
}

void _solve() {
}

//-----------------------------------------------------------------------------------------------------
void _settings() {
_GTestsCnt = 1;
_GFastio   = 1;
#ifdef LOCAL_DANKAKON
_GFopenr = strdup("input.txt");//input.txt
_GFopenw = strdup("");//output.txt
#else
_GFopenr = strdup("");//input.txt
_GFopenw = strdup("");//output.txt
#endif
}

void _afterS() {
#ifdef LOCAL_DANKAKON
#else
#endif
}

void _afterAll() {
#ifdef LOCAL_DANKAKON
std::cout << "\n__________\ntime = " << _get_time() << std::endl;
#else
#endif
}
