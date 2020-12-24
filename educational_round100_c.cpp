#include <algorithm>
#include <cstring>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vstr = vector<string>;

#define ALL(x) x.begin(), x.end()
#define IALL(x) x.rbegin(), x.rend()
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define FOR_(i, x, y) for (int i = x; i <= y; i++)
#define IFOR(i, x, y) for (int i = y - 1; i >= x; i--)
#define IFOR_(i, x, y) for (int i = y; i >= x; i--)
#define REP(i, x) FOR(i, 0, x)
#define SUBSTR(s, l, r) s.substr(l, r - l + 1)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'
#define DEBUG(x) cerr << "\033[1;35m" << (x) << "\033[0m\n"

template<typename T>
void chmax(T &m, const T q) { m = max(m, q); }

template<typename T>
void chmin(T &m, const T q) { m = min(m, q); }

template<typename T>
void sort_unique(vector<T> &v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), v.end());
}

template<typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) {
    return make_pair(l.first + r.first, l.second + r.second);
}

template<typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) {
    return make_pair(l.first - r.first, l.second - r.second);
}

template<typename T>
T square(T x) { return x * x; }

template<typename T>
T manhattan(pair<T, T> a, pair<T, T> b) { return abs(b.first - a.first) + abs(b.second - a.second); }

template<typename T>
T euclidean(pair<T, T> a, pair<T, T> b) { return square(b.first - a.first) + square(b.second - a.second); }

#define MAX_N 100001
#define INF 0xffffffff

ll t[MAX_N];
ll x[MAX_N];

ll signOf(ll a) {
    return a > 0 ? 1 : a < 0 ? -1 : 0;
}

bool isSuccessful(ll xi, ll slope, ll t0, ll x0, ll t1, ll t2) {
    ll x1 = slope * (t1 - t0) + x0;
    ll x2 = slope * (t2 - t0) + x0;

    if (x1 > x2) swap(x1, x2);

    return xi >= x1 && xi <= x2;
}

// ###### MAIN #######
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout << fixed << setprecision(10);

    int tc;

    cin >> tc;

    while (tc--) {
        int n;

        cin >> n;

        REP(i, n) cin >> t[i] >> x[i];

        t[n] = INF;

        int ans = 0;
        ll t0Start = -1;
        ll x0Start = 0;
        ll t0Finish = -1;
        ll x0Finish = 0;
        ll slope = 0;

        FOR(i, 0, n) {
            if (t[i] >= t0Finish) {
                t0Start = t[i];
                x0Start = x0Finish;
                t0Finish = t0Start + abs(x[i] - x0Start);
                x0Finish = x[i];
                slope = signOf(x0Finish - x0Start);
            }

            ans += isSuccessful(x[i], slope, t0Start, x0Start, t[i], min(t[i + 1], t0Finish));
        }

        PRINTLN(ans);
    }

    return 0;
}
