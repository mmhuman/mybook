#include <bits/stdc++.h>
 
using namespace std; 

#define all(v) (v).begin(), (v).end()
#define sz(a) ((long long)(a).size())
#define X first
#define Y second
 
using ll = long long;
using ull = unsigned long long;
using dbl = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll mod) {
    return (ull)rng() % mod;
}
 
const ll INF = 1e9;
const ll LINF = 1e18;
const int MOD = 83456729;
const int MAXN = 100;

struct TKeyMask {

using TKMInt = int;
static vector<TKMInt> sz;
static vector<TKMInt> pref;
static TKMInt max_val;

static void init(const vector<int>& sizes) {
    sz = sizes;
    max_val = 1;
    for (TKMInt x : sz) {
        pref.push_back(max_val);
        max_val *= (x + 1);
    }
    pref.push_back(max_val);
}

TKMInt mask = 0;

auto toVec() {
    vector<int> key;
    TKMInt x = mask;
    for (int i = 0; i < (int)sz.size(); ++i) {
        TKMInt y = x / (sz[i] + 1);
        key.push_back(x - y * (sz[i] + 1));
        x = y;
    }
    return key;
}

void fromVecInit(const vector<int>& key) {
    assert(key.size() == sz.size());
    TKMInt x = 0;
    for (int i = 0; i < (int)sz.size(); ++i) {
        assert(0 <= key[i] && key[i] <= sz[i]);
        x += pref[i] * key[i];
    }
    mask = x;
}

int getAt(int i) {
    assert(0 <= i && i < (int)sz.size());
    return (mask / pref[i]) % (sz[i] + 1);
}

void add(int i, int val) {
    assert(0 <= i && i < (int)sz.size());
    mask += val * pref[i];
}

void upd(int i, int val) {
    assert(0 <= i && i < (int)sz.size());
    add(i, val - getAt(i));
}

};
vector<TKeyMask::TKMInt> TKeyMask::sz;
vector<TKeyMask::TKMInt> TKeyMask::pref;
TKeyMask::TKMInt TKeyMask::max_val;

void solve() {
    vector<int> sz = {1, 2, 3};
    TKeyMask::init(sz);

    cout << TKeyMask::max_val << endl;
    cout << TKeyMask::sz.size() << endl;
}
 
signed main() {
#ifdef LOCAL
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
 
    int T = 1;
    // cin >> T;
    for (int numt = 0; numt < T; ++numt) {
        solve();
    }
 
#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}
