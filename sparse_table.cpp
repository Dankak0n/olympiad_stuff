//sparse_table-----------------------------------------------------------------------------------------
#include<cmath>
#include<vector>
namespace sparse_table {
template <class T = int, class F = std::less<T>>
class sparse_t {
public:
	std::vector<std::vector<T>> _st;
	void build(const std::vector<T> &_v) {
		_st.push_back(_v);
		for (int i = 1; !_st.back().empty(); i++) {
			_st.push_back({});
			for (int j = 0; j + (1 << i) <= (int)_v.size(); j++) {
				_st.back().push_back(F()(_st[i - 1][j],  _st[i - 1][j + (1 << (i - 1))]) ?
				                         _st[i - 1][j] : _st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	sparse_t(){};
	sparse_t(const std::vector<T> &_v) { sparse_table::sparse_t<T, F>::build(_v); }
	T get(int _l, int _r) {
		int _sz = _r - _l + 1;
		for (int i = log2(_sz) - 2;; i++) {
			if (i >= 0 && _sz < (1 << (i + 1))) {
				_sz = i;
				break;
			}
		}
		return (F()(_st[_sz][_l],  _st[_sz][_r - (1 << _sz) + 1]) ?
		            _st[_sz][_l] : _st[_sz][_r - (1 << _sz) + 1]);
	}
};
}
//end_sparse_table-------------------------------------------------------------------------------------
