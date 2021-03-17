# include<iostream>
# include <stdio.h>
# include<bits/stdc++.h>
using namespace std;

# define ll long long

template <typename num_t> 
struct segtree {
  int n, depth;
  std::vector<num_t> tree, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int l, int r, num_t v) {
	if (l > r) return;
    update(0, 0, n - 1, l, r, v);
  }

  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
    eval_lazy(i, tl, tr);
	
	if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    if (tl == tr) return tree[i];

    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
	if (l > r) return num_t::null_v;
    return query(0, 0, n-1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return num_t::null_v;

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }

  void eval_lazy(int i, int l, int r) {
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
    }

    lazy[i] = num_t();
  }
};

struct min_t {
  long long val;
  static const long long null_v = 9223372036854775807LL;

  min_t(): val(0) {}
  min_t(long long v): val(v) {}

  min_t op(min_t& other) {
    return min_t(min(val, other.val));
  }
  
  min_t lazy_op(min_t& v, int size) {
    return min_t(val + v.val);
  }
};

ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 5432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];

segtree<min_t>st;
pair<ll, ll>range[200005];
ll p[200005]; // Calculating prefix sum;
ll dp[200005];

void solve(int tc=0)
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i = 1;i<n;i++)
    {
        cin>>range[i].first>>range[i].second;
        --range[i].first;
        --range[i].second;

    }

    // Calculating prefix sum
    ll prefix_sum = 0;
    for(int i=0;i<n;i++)
    {
        prefix_sum+=a[i];
        p[i] = prefix_sum;
    }

    // Initialising segment Tree
    //const long long INF = 1e18; // We don't actually need to fill with INF values because previous dp values are alread computed/
    //for(int i=0;i<n;i++) dp[i] = INF;
    memset(dp, 0, sizeof(dp));

    dp[0] = 0;
    st.init(n,dp);

    for(int i=1;i<n;i++)
    {
        dp[i] = p[i] + st.query(range[i].first, range[i].second).val;
        st.update(i, i, dp[i]-p[i-1]);
    }

    for(int i=0;i<n;i++)
        cout<<dp[i]<<" ";

}
int main()
{
    solve();    
}