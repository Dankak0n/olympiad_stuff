//sparse_table-----------------------------------------------------------------------------------------
#include<cmath>
#include<vector>
#include<cassert>
#include<functional>
namespace sparse_table {
template <class T> T _default_fun(T &_l, T &_r) { return (_l < _r ? _l : _r); };
template <class T = int>
struct sparse_t {
	std::vector<std::vector<T> > _st;
	std::function<T(T&, T&)> _fun;
	void build(const std::vector<T> &_v, const std::function<T(T&, T&)> __fun = _default_fun<T>) {
		_fun = __fun; _st.clear(); _st.push_back(_v);
		for (int i = 1; !_st.back().empty(); i++) {
			_st.push_back({});
			for (int j = 0; j + (1 << i) <= (int)_v.size(); j++)
				_st.back().push_back(_fun(_st[i - 1][j],  _st[i - 1][j + (1 << (i - 1))]));
		}
	}
	sparse_t(){};
	sparse_t(const std::vector<T> &_v, const std::function<T(T&, T&)> __fun = _default_fun<T>) { build(_v, __fun); }
	T get(int _l, int _r) {//[0, n-1]
		assert(_l <= _r && 0 <= _l && _r < (int)_st[0].size());
		int _sz = std::__lg(_r - _l + 1);
		return _fun(_st[_sz][_l],  _st[_sz][_r - (1 << _sz) + 1]);
	}
};
}
//end_sparse_table-------------------------------------------------------------------------------------
