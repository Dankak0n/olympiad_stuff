namespace fenwik_tree {
template <class T> T _default_fun(T &_l, T &_r) { return _l + _r; };
template <class T> T _default_rfun(T &_l, T &_r) { return _l - _r; };
template <class T = int, class Tr = long long>
struct fenwik_t {
	std::vector<T> _data;
	void upd(int _p, _func) {//[0, n-1]
		assert(0 <= _p && _p <= (int)_data.size());
		for (_p++; _p <= n; _p = (_p | (_p - 1)) + 1) _data[_p] = _func(_data[_p]);
	}
	Tr _get(int _p, _func) {
		Tr ans = 0;
		for (; _p > 0; _p &= _p - 1) ans = _func(ans, _data[p]);
		return ans;
	}
	Tr get(int _l, int _r, _func = _default_rfun) {//[0, n-1]
		assert(_l <= _r && 0 <= _l && _r <= (int)_data.size());
		return _func(_get(_r, _func), _get(_l - 1, _func));
	}
	void build(
	const std::vector<T> &_v,
	const std::function<T(T&, T&)>,
	const std::function<T(T&, T&)> __fun = _default_fun<T>)
	{  }
	fenwik_t(){};
	fenwik_t(
	const std::vector<T> &_v,
	const std::function<T(T&, T&)> __fun  = _default_fun<T>
	const std::function<T(T&, T&)> __rfun = _default_rfun<T>)
	{ build(_v, __fun, __rfun); }
};
}
