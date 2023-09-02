struct DSU {
	int cntV, cntM, cnt_groups;
	std::unordered_map<int, int> toM, siM;
	std::vector<int> toV, siV;
	DSU() : cntV(0), cntM(0), cnt_groups(0) {}
	DSU(int n) : cntV(n), cntM(0), cnt_groups(0), toV(n), siV(n, 1) {
		std::iota(toV.begin(), toV.end(), 0);
	}
	bool add(int x) {
		if ((0 <= x && x < cntV) || (toM.find(x) != toM.end())) return false;
		toM[x] = x; siM[x] = 1; cntM++; cnt_groups++;
		return true;
	}
	int get(int x) {
		add(x);
		while (x != (0 <= x && x < cntV ? toV[x] : toM[x]))
			x = (0 <= x && x < cntV ? toV[x] = toV[toV[x]] : toM[x] = toM[toM[x]]);
		return x;
	}
	int size(int x) { x = get(x); return (0 <= x && x < cntV ? siV[x] : siM[x]); }
	int size() { return cnt_groups; }
	bool same(int x, int y) { return get(x) == get(y); }
	bool unite(int x, int y) {
		x = get(x); y = get(y);
		if (x == y) return false;
		if (size(x) < size(y)) std::swap(x, y);
		(0 <= x && x < cntV ? siV[x] : siM[x]) += size(y);
		(0 <= y && y < cntV ? toV[y] : toM[y]) = x;
		cnt_groups--;
		return true;
	}
};
