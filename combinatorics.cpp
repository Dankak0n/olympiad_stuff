namespace commod {
#ifndef Lil_Dankakon
    #include <vector>
    #include <iostream>
    using namespace std;
#endif // Lil_Dankakon
#define gcd __gcd
    long long mod_phi = 0;
    long long default_mod = 0;
    long long default_return_value = 0;
    int cur_k = 0, cur_n = 0;
    std::vector <long long> factorial;
    std::vector <std::vector<long long> > cnk_arr;
//--------------------------------------------------------------------------------------------------------------------
    void cnk_clear() {
        cnk_arr.clear();
    }
    void fac_clear() {
        factorial.clear();
    }
//--------------------------------------------------------------------------------------------------------------------
    long long gcd_ext(long long a, long long b, long long & x, long long & y) {
        if(a == 0) {
            x = 0; y = 1;
            return b;
        }
        long long x1, y1;
        long long d = gcd_ext(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return d;
    }
    long long phi(long long n) {
        long long res = n;
        for(long long p = 2; p * p <= n; ++p) {
            if(n % p == 0) {
                res -= res / p;
            }
            while(n % p == 0) {
                n /= p;
            }
        }
        if(n > 1) {
            res -= res / n;
        }
        return res;
    }
//--------------------------------------------------------------------------------------------------------------------
    void set_mod(long long x, int is_prime) {
        if (is_prime) {
            mod_phi = x - 1;
        } else {
            mod_phi = phi(x);
        }
        default_mod = x;
    }
    void set_mod(long long x) {
        mod_phi = x - 1;
        default_mod = x;
    }
    void set_ret(long long x) {
        default_return_value = x;
    }
//--------------------------------------------------------------------------------------------------------------------
    long long add(long long a, long long b) {
        if (default_mod) {
            return (a + b) % default_mod;
        } else {
            return a + b;
        }
    }

    long long sub(long long a, long long b) {
        if (default_mod) {
            return (a - b < 0 ? a - b + default_mod : a - b) % default_mod;
        } else {
            return a - b;
        }
    }

    long long mulc(long long x, long long y) {
        if (y == 0) {
            return 0;
        }
        long long ans;
        if (y & 1) {
            ans = x % default_mod;
            ans += mulc(x, y - 1);
        } else {
            ans = mulc(x, y / 2);
            ans *= 2;
        }
        return ans % default_mod;
    }

    long long mul(long long a, long long b) {
        if (default_mod) {
            if (__builtin_log10(a) + __builtin_log10(b) >= 18) {
                return mulc(a, b);
            } else {
                return a * b % default_mod;
            }
        } else {
            return a * b;
        }
    }

    long long powc(long long a, long long b) {
        long long res = 1LL % default_mod;
        while (b) {
            if (b & 1) {
                res *= a;
                res %= default_mod;
            }
            a *= a;
            a %= default_mod;
            b >>= 1;
        }
        return res;
    }

    long long div(long long a, long long b) {
        if (b == 0 || __gcd(default_mod, b) != 1) {
            return default_return_value;
        }
        return mul(a, powc(b, mod_phi - 1));
    }
//--------------------------------------------------------------------------------------------------------------------
    long long fac_n(int x) {
        if (x < 0) {
            return default_return_value;
        }
        long long ans = 1;
        for (long long i = 2; i <= x; ++i) {
            ans *= i;
            if (default_mod) {
                ans %= default_mod;
            }
        }
        return ans;
    }

    long long fac_1(int x) {
        if (x < 0) {
            return default_return_value;
        }
        while (x >= (int)factorial.size()) {
            if (factorial.empty()) {
                if (default_mod) {
                    factorial.push_back(1LL % default_mod);
                } else {
                    factorial.push_back(1LL);
                }
            } else {
                if (default_mod) {
                    factorial.push_back(factorial.back() * factorial.size() % default_mod);
                } else {
                    factorial.push_back(factorial.back() * factorial.size());
                }
            }
        }
        return factorial[x];
    }
//--------------------------------------------------------------------------------------------------------------------
    long long Cnk_1(int n, int k) {
        if (k > n || k < 0) {
            return default_return_value;
        }
        if (n == k) {
            if (default_mod) {
                return 1LL % default_mod;
            } else {
                return 1LL;
            }
        }
        return div(fac_1(n), mul(fac_1(n - k), fac_1(k)));
    }

    long long Cnk_n(int n, int k) {
        if (k > n || k < 0) {
            return default_return_value;
        }
        k = min(k, n - k);
        while (n >= (int)cnk_arr.size() || k >= (int)cnk_arr[n].size()) {
            if (cur_k == 0) {
                cnk_arr.push_back({1});
            } else if (cur_k == cur_n / 2 && cur_n % 2 == 0) {
                cnk_arr[cur_n].push_back(cnk_arr[cur_n - 1][cur_k - 1] * 2);
            } else {
                cnk_arr[cur_n].push_back(cnk_arr[cur_n - 1][cur_k - 1] + cnk_arr[cur_n - 1][cur_k]);
            }
            if (default_mod) {
                cnk_arr[cur_n][cur_k] %= default_mod;
            }
            cur_k++;
            if (cur_k > cur_n / 2) {
                cur_n++;
                cur_k = 0;
            }
        }
        return cnk_arr[n][k];
    };
//--------------------------------------------------------------------------------------------------------------------
    struct num_t {
        long long value;
        operator int() const {
            return value;
        }
        operator long long() const {
            return value;
        }
        num_t(){
        }
//-------------------------------------------------------------------------------------
        explicit num_t(long long x) {
            if (default_mod) {
                this->value = x % default_mod;
            } else {
                this->value = x;
            }
        }
//-------------------------------------------------------------------------------------
        num_t operator=(num_t other) {
            value = other.value;
            return *this;
        }
        num_t operator=(long long other) {
            value = other;
            return *this;
        }
        num_t operator=(int other) {
            value = other;
            return *this;
        }

        num_t operator+=(num_t other) {
            value += other.value;
            if (default_mod) {
                value %= default_mod;
            }
            return *this;
        }
        num_t operator-=(num_t other) {
            value -= other.value;
            if (default_mod) {
                if (value < 0) {
                    value += default_mod;
                } else {
                    value %= default_mod;
                }
            }
            return *this;
        }
        num_t operator*=(num_t other) {
            value = mul(value, other.value);
            return *this;
        }
        num_t operator/=(num_t other) {
            value = div(value, other.value);
            return *this;
        }
//-------------------------------------------------------------------------------------
        friend long long operator+(num_t a, num_t b) {
            return add(a, b);
        }
        friend long long operator-(num_t a, num_t b) {
            return sub(a, b);
        }
        friend long long operator*(num_t a, num_t b) {
            return mul(a, b);
        }
        friend long long operator/(num_t a, num_t b) {
            return div(a, b);
        }
//-------------------------------------------------------------------------------------
        friend bool operator>(num_t & a, num_t & b) {
            return a.value > b.value;
        }
        friend bool operator<(num_t & a, num_t & b) {
            return a.value < b.value;
        }
        friend bool operator>=(num_t & a, num_t & b) {
            return a.value >= b.value;
        }
        friend bool operator<=(num_t & a, num_t & b) {
            return a.value <= b.value;
        }
//-------------------------------------------------------------------------------------
        friend std::istream & operator >> (istream & in,  num_t & to_in) {
            in >> to_in.value;
            return in;
        }
        friend std::ostream & operator << (ostream & out, const num_t & to_out) {
            out << to_out.value;
            return out;
        }
    };
//-------------------------------------------------------------------------------------
    template <typename T>
    num_t operator+(num_t a, T b) {
        if (default_mod) {
            return num_t((a.value + (long long)b) % default_mod);
        } else {
            return num_t(a.value + (long long)b);
        }
    }
    template <typename T>
    num_t operator+(T a, num_t b) {
        if (default_mod) {
            return num_t(((long long)a + b.value) % default_mod);
        } else {
            return num_t((long long)a + b.value);
        }
    }
//-------------------------------------------------------------------------------------
    template <typename T>
    void operator+=(num_t & a, T b) {
        a.value += (long long)b;
        if (default_mod) {
            a.value %= default_mod;
        }
    }
    template <typename T>
    void operator+=(T & a, num_t b) {
        a += (long long)b;
        if (default_mod) {
            a %= default_mod;
        }
    }
//-------------------------------------------------------------------------------------
    template <typename T>
    num_t operator-(num_t a, T b) {
        if (default_mod) {
            if (a.value < (long long)b) {
                return num_t((a.value - (long long)b + default_mod) % default_mod);
            } else {
                return num_t((a.value - (long long)b) % default_mod);
            }
        } else {
            return num_t(a.value - (long long)b);
        }
    }
    template <typename T>
    num_t operator-(T a, num_t b) {
        if (default_mod) {
            if ((long long)a < b.value) {
                return num_t(((long long)a - b.value + default_mod) % default_mod);
            } else {
                return num_t(((long long)a - b.value) % default_mod);
            }
        } else {
            return num_t((long long)a - b.value);
        }
    }
//-------------------------------------------------------------------------------------
    template <typename T>
    void operator-=(num_t & a, T b) {
        a.value -= (long long)b;
        if (default_mod) {
            if (a.value < 0) {
                a.value += default_mod;
            } else {
                a.value %= default_mod;
            }
        }
    }
    template <typename T>
    void operator-=(T & a, num_t b) {
        a -= (long long)b;
        if (default_mod) {
            if (a < 0) {
                a += default_mod;
            } else {
                a %= default_mod;
            }
        }
    }
//-------------------------------------------------------------------------------------
    template <typename T>
    num_t operator*(num_t a, T b) {
        return num_t(mul(a, b));
    }
    template <typename T>
    num_t operator*(T a, num_t b) {
        return num_t(mul(a, b));
    }
//-------------------------------------------------------------------------------------
    template <typename T>
    void operator*=(num_t & a, T b) {
        a.value = mul(a.value, (long long)b);
    }
    template <typename T>
    void operator*=(T & a, num_t b) {
        a = mul(a, (long long)b);
    }
//-------------------------------------------------------------------------------------
    template <typename T>
    num_t operator/(num_t a, T b) {
        if (default_mod) {
            return num_t(div(a.value, (long long)b));
        } else {
            return num_t(a.value / (long long)b);
        }
    }
    template <typename T>
    num_t operator/(T a, num_t b) {
        if (default_mod) {
            return num_t(div((long long)a, b.value));
        } else {
            return num_t((long long)a / b.value);
        }
    }
//-------------------------------------------------------------------------------------
    template <typename T>
    void operator/=(num_t & a, T b) {
        a.value = div(a.value, (long long)b);
    }
    template <typename T>
    void operator/=(T & a, num_t b) {
        a = div(a, (long long)b);
    }
//-------------------------------------------------------------------------------------
    template <typename T>
    bool operator<(num_t a, T b) {
        return a.value < (long long)b;
    }
    template <typename T>
    bool operator<(T a, num_t b) {
        return (long long)a < b.value;
    }
    template <typename T>
    bool operator>(num_t a, T b) {
        return a.value > (long long)b;
    }
    template <typename T>
    bool operator>(T a, num_t b) {
        return (long long)a > b.value;
    }
    template <typename T>
    bool operator<=(num_t a, T b) {
        return a.value <= (long long)b;
    }
    template <typename T>
    bool operator<=(T a, num_t b) {
        return (long long)a <= b.value;
    }
    template <typename T>
    bool operator>=(num_t a, T b) {
        return a.value >= (long long)b;
    }
    template <typename T>
    bool operator>=(T a, num_t b) {
        return (long long)a >= b.value;
    }
    template <typename T>
    bool operator==(num_t a, T b) {
        return a.value == (long long)b;
    }
    template <typename T>
    bool operator==(T a, num_t b) {
        return (long long)a == b.value;
    }
}
