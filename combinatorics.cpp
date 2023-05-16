namespace combinatorics {
#ifndef Lil_Dankakon
    #include <vector>
    #include <iostream>
    using namespace std;
#endif // Lil_Dankakon
#define gcd __gcd
    long long mod_phi = 0;
    long long default_mod = 0;
    long long default_return_value = 0;
    std::vector <long long> factorial;
    int cur_n = 0, cur_k = 0;
    std::vector <std::vector<long long> > Cnk_arr;
//--------------------------------------------------------------------------------------------------------------------
    long long gcd_ext(long long a, long long b, long long& x, long long& y) {
        if(a == 0) {
            x = 0; y = 1;
            return b;
        }
        long long x1, y1;
        long long d = gcd_ext (b % a, a, x1, y1);
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
        if (y == 0 || x == 0) {
            return 0;
        }
        long long ans;
        if (y & 1) {
            ans = x + mulc(x, y - 1);
        } else {
            ans = mulc(x, y / 2);
            ans %= default_mod;
            ans *= 2;
        }
        return ans % default_mod;
    }

    long long mul(long long a, long long b) {
        if (default_mod) {
            if (__builtin_log(a) + __builtin_log(b) >= 18) {
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
        return mul(a, powc(b, mod_phi - 1));
    }
//--------------------------------------------------------------------------------------------------------------------
    long long fac_n(int x) {
        if (x < 0) {
            if (default_mod) {
                return default_return_value % default_mod;
            } else {
                return default_return_value;
            }
        }
        long long ans = 1;
        for (ll i = 2; i <= x; ++i) {
            ans *= i;
            if (default_mod) {
                ans %= default_mod;
            }
        }
        return ans;
    }

    long long fac_1(int x) {
        if (x < 0) {
            if (default_mod) {
                return default_return_value % default_mod;
            } else {
                return default_return_value;
            }
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
            if (default_mod) {
                return default_return_value % default_mod;
            } else {
                return default_return_value;
            }
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
            if (default_mod) {
                return default_return_value % default_mod;
            } else {
                return default_return_value;
            }
        }
        while (n >= (int)Cnk_arr.size() || k >= (int)Cnk_arr[n].size()) {
            if (cur_k == 0) {
                Cnk_arr.push_back({});
                Cnk_arr[cur_n].push_back(1);
            } else if (cur_k == cur_n) {
                Cnk_arr[cur_n].push_back(1);
            } else {
                Cnk_arr[cur_n].push_back(Cnk_arr[cur_n - 1][cur_k - 1] + Cnk_arr[cur_n - 1][cur_k]);
            }
            if (default_mod) {
                Cnk_arr[cur_n][cur_k] %= default_mod;
            }
            cur_k++;
            if (cur_k > cur_n) {
                cur_n++;
                cur_k = 0;
            }
        }
        return Cnk_arr[n][k];
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
        num_t(long long x) {
            if (default_mod) {
                this->value = x % default_mod;
            } else {
                this->value = x;
            }
        }
        num_t(int x) {
            if (default_mod) {
                this->value = x % default_mod;
            } else {
                this->value = x;
            }
        }
//-------------------------------------------------------------------------------------
        friend operator+(num_t left, num_t right) {
            if (default_mod) {
                return (long long)(left.value + right.value) % default_mod;
            } else {
                return (long long)(left.value + right.value);
            }
        }
        friend operator+(num_t left, long long right) {
            if (default_mod) {
                return (long long)(left.value + right) % default_mod;
            } else {
                return (long long)(left.value + right);
            }
        }
        friend operator+(long long left, num_t right) {
            if (default_mod) {
                return (long long)(left + right.value) % default_mod;
            } else {
                return (long long)(left + right.value);
            }
        }
        friend operator+(num_t left, int right) {
            if (default_mod) {
                return (long long)(left.value + right) % default_mod;
            } else {
                return (long long)(left.value + right);
            }
        }
        friend operator+(int left, num_t right) {
            if (default_mod) {
                return (long long)((long long)left + right.value) % default_mod;
            } else {
                return (long long)((long long)left + right.value);
            }
        }
//-------------------------------------------------------------------------------------
        friend operator-(num_t left, num_t right) {
            if (default_mod) {
                if (left.value < right.value) {
                    return (long long)(left.value - right.value + default_mod) % default_mod;
                } else {
                    return (long long)(left.value - right.value) % default_mod;
                }
            } else {
                return (long long)(left.value - right.value);
            }
        }
        friend operator-(num_t left, long long right) {
            if (default_mod) {
                if (left.value < right) {
                    return (long long)(left.value - right + default_mod) % default_mod;
                } else {
                    return (long long)(left.value - right) % default_mod;
                }
            } else {
                return (long long)(left.value - right);
            }
        }
        friend operator-(long long left, num_t right) {
            if (default_mod) {
                if (left < right.value) {
                    return (long long)(left - right.value + default_mod) % default_mod;
                } else {
                    return (long long)(left - right.value) % default_mod;
                }
            } else {
                return (long long)(left - right.value);
            }
        }
        friend operator-(num_t left, int right) {
            if (default_mod) {
                if (left.value < right) {
                    return (int)(left.value - right + default_mod) % default_mod;
                } else {
                    return (int)(left.value - right) % default_mod;
                }
            } else {
                return (long long)(left.value - right);
            }
        }
        friend operator-(int left, num_t right) {
            if (default_mod) {
                if (left < right.value) {
                    return (long long)((long long)left - right.value + default_mod) % default_mod;
                } else {
                    return (long long)((long long)left - right.value) % default_mod;
                }
            } else {
                return (long long)((long long)left - right.value);
            }
        }
//-------------------------------------------------------------------------------------
        friend operator*(num_t left, num_t right) {
            if (default_mod) {
                return (long long)(left.value * right.value) % default_mod;
            } else {
                return (long long)(left.value * right.value);
            }
        }
        friend operator*(num_t left, long long right) {
            if (default_mod) {
                return (long long)(left.value * right) % default_mod;
            } else {
                return (long long)(left.value * right);
            }
        }
        friend operator*(long long left, num_t right) {
            if (default_mod) {
                return (long long)(left * right.value) % default_mod;
            } else {
                return (long long)(left * right.value);
            }
        }
//-------------------------------------------------------------------------------------
        num_t operator = (num_t other) {
            value = other.value;
            return *this;
        }
        num_t operator = (long long other) {
            value = other;
            return *this;
        }
        num_t operator = (int other) {
            value = other;
            return *this;
        }
//-------------------------------------------------------------------------------------
        num_t operator += (num_t other) {
            value += other.value;
            if (default_mod) {
                value %= default_mod;
            }
            return *this;
        }
        num_t operator += (long long other) {
            value += other;
            if (default_mod) {
                value %= default_mod;
            }
            return *this;
        }
        num_t operator += (int other) {
            value += other;
            if (default_mod) {
                value %= default_mod;
            }
            return *this;
        }
//-------------------------------------------------------------------------------------
        num_t operator *= (num_t other) {
            value *= other.value;
            if (default_mod) {
                value %= default_mod;
            }
            return *this;
        }
        num_t operator *= (long long other) {
            value *= other;
            if (default_mod) {
                value %= default_mod;
            }
            return *this;
        }
        num_t operator *= (int other) {
            value *= other;
            if (default_mod) {
                value %= default_mod;
            }
            return *this;
        }
//-------------------------------------------------------------------------------------
        num_t operator -= (num_t other) {
            value -= other.value;
            if (default_mod) {
                if (value < 0) {
                    value += default_mod;
                }
                value %= default_mod;
            }
            return *this;
        }
        num_t operator -= (long long other) {
            value -= other;
            if (default_mod) {
                if (value < 0) {
                    value += default_mod;
                }
                value %= default_mod;
            }
            return *this;
        }
        num_t operator -= (int other) {
            value -= other;
            if (default_mod) {
                if (value < 0) {
                    value += default_mod;
                }
                value %= default_mod;
            }
            return *this;
        }
//-------------------------------------------------------------------------------------
        friend bool operator  > (const num_t & left, const num_t & right) {
            return left.value > right.value;
        }
        friend bool operator  < (const num_t & left, const num_t & right) {
            return left.value < right.value;
        }
        friend bool operator  >= (const num_t & left, const num_t & right) {
            return left.value >= right.value;
        }
        friend bool operator  <= (const num_t & left, const num_t & right) {
            return left.value <= right.value;
        }
        friend bool operator  > (const num_t & left, const long long & right) {
            return left.value > right;
        }
        friend bool operator  < (const num_t & left, const long long & right) {
            return left.value < right;
        }
        friend bool operator  >= (const num_t & left, const long long & right) {
            return left.value >= right;
        }
        friend bool operator  <= (const num_t & left, const long long & right) {
            return left.value <= right;
        }
        friend bool operator  > (const num_t & left, const int & right) {
            return left.value > right;
        }
        friend bool operator  < (const num_t & left, const int & right) {
            return left.value < right;
        }
        friend bool operator  >= (const num_t & left, const int & right) {
            return left.value >= right;
        }
        friend bool operator  <= (const num_t & left, const int & right) {
            return left.value <= right;
        }
        friend bool operator  < (const int & left, const num_t & right) {
            return       left < right.value;
        }
        friend bool operator  <= (const int & left, const num_t & right) {
            return       left <= right.value;
        }
        friend bool operator  > (const int & left, const num_t & right) {
            return       left > right.value;
        }
        friend bool operator  >= (const int & left, const num_t & right) {
            return       left >= right.value;
        }
        friend bool operator  < (const long long & left, const num_t & right) {
            return       left < right.value;
        }
        friend bool operator  <= (const long long & left, const num_t & right) {
            return       left <= right.value;
        }
        friend bool operator  > (const long long & left, const num_t & right) {
            return       left > right.value;
        }
        friend bool operator  >= (const long long & left, const num_t & right) {
            return       left >= right.value;
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
}
