namespace commod {
namespace modul {
#include <vector>
#include <iostream>
#include <map>
#define gcd __gcd

long long _default_mod = 0;
long long _default_phi = 0;

template<class T1, class T2, class T3>
    T1 add (T1 a, T2 b, T3 m = 0) {
        if (m == (T3)0) m = _default_mod;
        return ( m != 0 ? ( a + b ) % m : a + b );
    }
template<class T1, class T2, class T3>
    T1 sub (T1 a, T2 b, T3 m = 0) {
        if (m == (T3)0) m = _default_mod;
        return ( m != 0 ? ( a - b + m ) % m : a - b );
    }
template<class T1, class T2, class T3>
    T1 mul (T1 a, T2 b, T3 m = 0) {
        if (m == (T3)0) m = _default_mod;
        return ( m != 0 ? ( a * b ) % m : a * b );
    }
template<class T1, class T2, class T3>
    T1 mulc (T1 a, T2 b, T3 m) {
        if (m == 0) m = _default_mod;
        if ((T1)b == (T1)0) return (T1)0;
        T1 ans;
        if ((T1)b % (T1)2 == (T1)1)
            ans = a % m + mulc ( a, b - (T2)1, m );
        else
            ans = mulc ( a, (T2)b / (T2)2, m ) * (T1)2;
        return ans % m;
    }
template<class T1, class T2, class T3>
    T1 powc (T1 a, T2 b, T3 m) {
        if (m == (T3)0) m = _default_mod;
        T1 res = (T1)1 % m;
        while (b != (T2)0) {
            if (b % (T2)2 == (T2)1) { res *= a; res %= m; }
            a *= a; a %= m; b /= (T2)2;
        }
        return res;
    }
template<class T1, class T2>
    T1 div (T1 a, T1 b, T2 m, T2 mod_phi = (T2)0) {
        if (m == (T2)0) m = _default_mod;
        if (mod_phi == (T2)0) mod_phi = m - (T2)1;
        if (_default_phi != 0) mod_phi = _default_phi;
        return mul(a, powc(b, mod_phi - (T2)1, m), m);
    }
template <class T>
    T gcd_ext (T a, T b, T &x, T &y) {
        if(a == (T)0) { x = (T)0; y = (T)1; return b; }
        T x_1, y_1;
        T d = gcd_ext ( b % a, a, x_1, y_1 );
        x = y_1 - ( b / a ) * x_1; y = x_1;
        return d;
    }
template <class T>
    T get_phi (T x) {
        T res = x;
        for (T p = (T)2; p * p <= x; p++)
            if (x % p == (T)0) {
                res -= res / p;
                while (x % p == (T)0) x /= p;
            }
        if (x > (T)1) res -= res / x;
        return res;
    }
    void set_phi (long long x = 0) {
        if (x == 0) {
            _default_phi = get_phi(_default_mod);
        } else {
            _default_phi = x;
        }
    }
    void set_mod (long long x, bool is_prime = true) {
        if (is_prime) {
            _default_phi = x - 1;
        } else {
            _default_phi = get_phi(x);
        }
        _default_mod = x;
    }
template <class T>
    class mod_t {
    private:
        T val, mod, phi;
        bool mod_prime, mod_priority;
    public:
        enum PRIORITY {INTERNAL, DEFAULT};
        void info() {
            std::clog << "Val: " << val << "\n" << "Mod: " << mod << "\n"
            << "Phi: " << phi << "\n" << "Mp : " << mod_prime << "\n"
            << "\n" << "Dmp: " << mod_priority << "\n\n";
        }
        T get_mod() { return (mod_priority == DEFAULT && _default_mod != 0 ? _default_mod : mod); }
        void relax () {
            T m = get_mod();
            if (m != 0) {
                if (val < 0) val += m;
                val = (val < 0 ? (m - (-val % m)) % m : val % m);
            }
        }
        void set_mod (const T &x, bool is_prime = true) {
            mod = x;
            mod_prime = is_prime;
            relax();
        }
        void set_phi (const T &x = 0) {
            if (x == 0 && !mod_prime) phi = get_phi(mod);
                else if (x == 0 && mod_prime) phi = mod - 1;
                    else phi = x;
            mod_prime = (phi == mod - 1);
            relax();
        }
        void set_priority (const bool &priority) { mod_priority = priority; }
        operator T() { return val; }
        explicit mod_t (T nval = 0, T nmod = 0, bool is_prime = true, T nphi = 0) {
            val = nval;
            mod_t::set_mod(nmod, is_prime);
            mod_t::set_phi(nphi);
            set_priority(DEFAULT);
        };
        mod_t operator=(mod_t other)  { val = other.val; relax(); other.relax(); return *this; }
        mod_t operator+=(mod_t other) { relax(); other.relax(); val += other.val; relax(); return *this; }
        mod_t operator-=(mod_t other) { relax(); other.relax(); val -= other.val; relax(); return *this; }
        mod_t operator*=(mod_t other) { relax(); other.relax(); val *= other.val; relax(); return *this; }
        mod_t operator/=(mod_t other) {
            relax(); other.relax();
            val = div(val, other.val,
                      get_mod() > other.get_mod() ? get_mod() : other.get_mod(),
                      get_mod() > other.get_mod() ? phi : other.phi);
            relax(); return *this;
        }
        friend mod_t operator+(mod_t a, mod_t b) { a += b; return a; }
        friend mod_t operator-(mod_t a, mod_t b) { a -= b; return a; }
        friend mod_t operator*(mod_t a, mod_t b) { a *= b; return a; }
        friend mod_t operator/(mod_t a, mod_t b) { a /= b; return a; }
        friend bool operator<(mod_t &a, mod_t &b)  { a.relax(); b.relax(); return a.val < b.val; }
        friend bool operator<=(mod_t &a, mod_t &b) { a.relax(); b.relax(); return a.val <= b.val; }
        friend bool operator>(mod_t &a, mod_t &b)  { a.relax(); b.relax(); return a.val > b.val; }
        friend bool operator>=(mod_t &a, mod_t &b) { a.relax(); b.relax(); return a.val >= b.val; }
        friend bool operator==(mod_t &a, mod_t &b) { a.relax(); b.relax(); return a.val == b.val; }
        friend bool operator!=(mod_t &a, mod_t &b) { a.relax(); b.relax(); return a.val != b.val; }
        friend bool operator!(mod_t &a)            { a.relax(); return !a.val; }
        friend std::istream & operator >> (istream &in,  mod_t &to_in) {to_in.relax(); in >> to_in.val; return in; }
        friend std::ostream & operator << (ostream & out, mod_t & to_out) {to_out.relax(); out << to_out.val; return out; }
    };
    template <class T1, class T2> mod_t<T1> operator+(mod_t<T1> a, T2 b) { return a + (mod_t<T1>)b; }
    template <class T1, class T2> mod_t<T1> operator+(T2 b, mod_t<T1> a) { return (mod_t<T1>)b + a; }
    template <class T1, class T2> void operator+=(mod_t<T1> &a, T2 b) { a += (mod_t<T1>)b; }
    template <class T1, class T2> void operator+=(T2 &b, mod_t<T1> a) { a += (T2)a; }
    template <class T1, class T2> mod_t<T1> operator-(mod_t<T1> a, T2 b) { return a - (mod_t<T1>)b; }
    template <class T1, class T2> mod_t<T1> operator-(T2 b, mod_t<T1> a) { return (mod_t<T1>)b - a; }
    template <class T1, class T2> void operator-=(mod_t<T1> &a, T2 b) { a -= (mod_t<T1>)b; }
    template <class T1, class T2> void operator-=(T2 &b, mod_t<T1> a) { a -= (T2)a; }
    template <class T1, class T2> mod_t<T1> operator*(mod_t<T1> a, T2 b) { return a * (mod_t<T1>)b; }
    template <class T1, class T2> mod_t<T1> operator*(T2 b, mod_t<T1> a) { return (mod_t<T1>)b * a; }
    template <class T1, class T2> void operator*=(mod_t<T1> &a, T2 b) { a *= (mod_t<T1>)b; }
    template <class T1, class T2> void operator*=(T2 &b, mod_t<T1> a) { a *= (T2)a; }
    template <class T1, class T2> mod_t<T1> operator/(mod_t<T1> a, T2 b) { return a / (mod_t<T1>)b; }
    template <class T1, class T2> mod_t<T1> operator/(T2 b, mod_t<T1> a) { return (mod_t<T1>)b / a; }
    template <class T1, class T2> void operator/=(mod_t<T1> &a, T2 b) { a /= (mod_t<T1>)b; }
    template <class T1, class T2> void operator/=(T2 &b, mod_t<T1> a) { a /= (T2)a; }
    template <class T1, class T2> mod_t<T1> operator^(mod_t<T1> a, T2 b) { a.relax(); return powc(a.val, b, a.get_mod()); }
    template <class T1, class T2> void operator^=(mod_t<T1> &a, T2 b) { a = a ^ b; }
}
namespace comba {
template<class T1, class T2>
    T2 factn (const T1 &n, T2 m) {
        T2 ans = (T2)1;
        if (m == (T2)0)
        m = (m == (T2)0 ? modul::_default_mod : m);
        if (m != (T2)0) ans %= m;
        for (int i = 2; i <= n; i++) {
            ans *= (T2)i;
            if (m != (T2)0) ans %= m;
        }
        return ans;
    }
template<class T = int>
    long long factn (const T &n) {
        long long ans = 1;
        if (modul::_default_mod != 0) ans %= modul::_default_mod;
        for (int i = 2; i <= n; i++) {
            ans *= i;
            if (modul::_default_mod != 0) ans %= modul::_default_mod;
        }
        return ans;
    }
template <class T1 = int, class T2>
    T2 fact (const T1 &n, T2 m) {
        static std::map < T2, std::vector <T2> > _fact_arr;
        if (_fact_arr[m].empty())
            _fact_arr[m].push_back((T2)1);
        while (n >= (int)_fact_arr[m].size()) {
            _fact_arr[m].push_back(modul::mul(_fact_arr[m].back(), _fact_arr[m].size(), m));
        }
        return _fact_arr[m][n];
    }
template <class T1 = int, class T2>
    T2 rfact (const T1 &n, T2 m) {
        if (m == (T2)0) m = modul::_default_mod;
        static std::map < T2, std::vector <T2> > _rfact_arr;
        if (_rfact_arr[m].empty())
            _rfact_arr[m].push_back(m == 0 ? (T2)1 : (T2)1 % m);
        while (n >= (T1)_rfact_arr[m].size()) {
            _rfact_arr[m].push_back(modul::div(_rfact_arr[m].back(), (T2)_rfact_arr[m].size(), m));
        }
        return _rfact_arr[m][n];
    }
template <class T>
    T cnk (const int &n, const int &k, const T &m) {
        if (k > n || k < 0) {
            return (T)0;
        } else {
            return fact(n, m) * rfact(k, m) % m * rfact(n - k, m) % m;
        }
    }
    long long cnk (const int &n, const int &k) {
        if (k > n || k < 0) {
            return 0;
        } else {
            return (modul::_default_mod != 0 ? cnk(n, k, modul::_default_mod) : fact(n, 0) * rfact(k, 0) * rfact(n - k, 0));
        }
    }
template <class T1 = int, class T2>
    T2 cnkn (const T1 &n, T1 k, T2 m) {
        if (m == (T2)0) m = modul::_default_mod;
        if (k > n || k < 0) return (T2)0;
        k = (k + k < n ? k : n - k); // k = min(k, n - k);
        static std::map <T2, std::vector < std::vector <T2> > > _cnk_arr;
        static int cur_k = 0, cur_n = 0;
        while (n >= (T1)_cnk_arr[m].size() || k >= (T1)_cnk_arr[m][n].size()) {
            if (cur_k == 0) {
                _cnk_arr[m].push_back({(T2)1});
            } else if (cur_k == cur_n / 2 && cur_n % 2 == 0) {
                _cnk_arr[m][cur_n].push_back(_cnk_arr[m][cur_n - 1][cur_k - 1] * (T2)2);
            } else {
                _cnk_arr[m][cur_n].push_back(_cnk_arr[m][cur_n - 1][cur_k - 1] + _cnk_arr[m][cur_n - 1][cur_k]);
            }
            if (m != (T2)0) _cnk_arr[m][cur_n][cur_k] %= m;
            cur_k++;
            if (cur_k > cur_n / 2) {
                cur_n++;
                cur_k = 0;
            }
        }
        return _cnk_arr[m][n][k];
    }
}
};
