//sparse_table-----------------------------------------------------------------------------------------
#include<cmath>
#include<vector>
#include<functional>
namespace sparse_table {
template <class T> std::function<T(T&, T&)> _default_cmp = [](T &_l, T &_r){ return (_l < _r ? _l : _r); };
template <class T = int>
class sparse_t {
public:
	std::vector<std::vector<T>> _st;
	std::function<T(T&, T&)> _cmp_;
	void build(const std::vector<T> &_v, const std::function<T(T&, T&)> _cmp = _default_cmp<T>) {
		_cmp_ = _cmp;
		_st.push_back(_v);
		for (int i = 1; !_st.back().empty(); i++) {
			_st.push_back({});
			for (int j = 0; j + (1 << i) <= (int)_v.size(); j++) {
				_st.back().push_back(_cmp_(_st[i - 1][j],  _st[i - 1][j + (1 << (i - 1))]));
			}
		}
	}
	sparse_t(){};
	sparse_t(const std::vector<T> &_v, const std::function<T(T&, T&)> _cmp = _default_cmp<T>) { sparse_table::sparse_t<T>::build(_v, _cmp); }
	T get(int _l, int _r) {
		int _sz = _r - _l + 1;
		for (int i = log2(_sz) - 2;; i++) {
			if (i >= 0 && _sz < (1 << (i + 1))) {
				_sz = i;
				break;
			}
		}
		return (_cmp_(_st[_sz][_l],  _st[_sz][_r - (1 << _sz) + 1]));
	}
};
}
//end_sparse_table-------------------------------------------------------------------------------------
