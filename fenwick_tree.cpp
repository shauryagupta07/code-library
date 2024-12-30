struct fenwick {
	vector<int> fn;
	int n;

	void init(int n) {
		this->n = n + 1;
		fn.resize(this->n, 0);
	}

	void add(int x, int y) {
		x++; // 1 based index
		while (x < n) {
			fn[x] += y;
			x += (x & (-x));// last set bit
		}
	}

	// void add(int x, int y) {
	// 	for (x++; x < n; x += (x & (-x))) fn[x] += y;
	// }

	int sum(int x) {
		x++; // 1 based index
		int ans = 0;
		while (x) {
			ans += fn[x];
			x -= (x & (-x));// last set bit
		}
		return ans;
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

};