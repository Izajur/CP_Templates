int t[4*N];
void build_tree(int v, int tl, int tr, int arr[]) {
	if(tl==tr) {
		t[v] = arr[tl];
		return;
	}
	else {
		int tm = (tl+tr)/2;
		build_tree(2*v, tl, tm, arr);
		build_tree(2*v+1, tm+1, tr, arr);
		t[v] = min(t[2*v], t[2*v+1]);
	}
}
int min_query(int v, int tl, int tr, int l, int r, int arr[]) {
	if(l>r)
		return INT_MAX;
	else if(l==tl and r==tr)
		return t[v];
	else {
		int tm = (tl+tr)/2;
		return min(min_query(2*v, tl, tm, l, min(r, tm), arr),
					min_query(2*v+1, tm+1, tr, max(l, tm+1), r, arr));
	}
}
