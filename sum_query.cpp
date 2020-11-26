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
		t[v] = t[2*v] + t[2*v+1];
	}
}
int sum_query(int v, int tl, int tr, int l, int r) {
	if(l>r)
		return 0;
	else if(l==tl and r==tr)
		return t[v];
	else {
		int tm = (tl+tr)/2;
		return sum_query(2*v, tl, tm, l, min(r, tm))+
					sum_query(2*v+1, tm+1, tr, max(l, tm+1), r);
	}
}
