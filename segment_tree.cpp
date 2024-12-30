struct segmenttree {
	int n;
	vector<int> st;

	void init(int _n) {
		this->n = _n;
		st.resize(4 * n, 0);
	}

	void build(int start, int ending, int node, int &k, int c, vector<int> &v) {
		// leaf node base case
		if (start == ending) {
			st[node] = v[start];
			k = c;
			return;
		}

		int mid = (start + ending) / 2;

		// left subtree is (start,mid)
		build(start, mid, 2 * node + 1, k, c + 1, v);

		// right subtree is (mid+1,ending)
		build(mid + 1, ending, 2 * node + 2, k, c + 1, v);
		if ((k - c) % 2 == 0)st[node] = st[2 * node + 1] | st[2 * node + 2];
		else st[node] = st[2 * node + 1] ^ st[2 * node + 2];

	}

	int query(int start, int ending, int l, int r, int node) {
		return st[node];
	}

	void update(int start, int ending, int node, int k, int c, int index, int value) {
		// base case
		if (start == ending) {
			st[node] = value;
			k = c;
			return;
		}

		int mid = (start + ending) / 2;
		if (index <= mid) {
			// left subtree
			update(start, mid, 2 * node + 1, k, c + 1, index, value);
		}
		else {
			// right
			update(mid + 1, ending, 2 * node + 2, k, c + 1, index, value);
		}

		if ((k - c) % 2 == 0)st[node] = st[2 * node + 1] | st[2 * node + 2];
		else st[node] = st[2 * node + 1] ^ st[2 * node + 2];

		return;
	}

	void build(vector<int> &v) {
		int k;
		build(0, n - 1, 0, k, 0, v);
	}

	int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int x, int y) {
		int k;
		update(0, n - 1, 0, k, 0, x, y);
	}
};
