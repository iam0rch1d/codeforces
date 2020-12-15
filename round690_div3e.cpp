#include <algorithm>
#include <cstring>
#include <complex>
#include <deque>
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
using pii = pair<int, int>;

#define ALL(x) x.begin(), x.end()
#define IALL(x) x.rbegin(), x.rend()
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define FOR_(i, x, y) for (int i = x; i <= y; i++)
#define IFOR(i, x, y) for (int i = y; i > x; i--)
#define IFOR_(i, x, y) for (int i = y; i >= x; i--)
#define REP(i, x) FOR(i, 0, x)
#define SUBSTR(s, l, r) s.substr(l, r - l + 1)
#define DEBUG(x) cerr << "\033[1;35m" << x << "\033[0m\n"

template<typename T>
void chmax(T &m, const T q) { m = max(m, q); }

template<typename T>
void chmin(T &m, const T q) { m = min(m, q); }

template<typename T>
void sort_unique(vector<T> &v) {
    sort(ALL(v));
    v.erase(unique(v.begin(), v.end()), v.end());
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

ll cnt[200001];

ll nC3(ll n) {
    return n * (n - 1) * (n - 2) / 6;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout << fixed << setprecision(10);

    int t;

    cin >> t;

    while (t--) {
        int n;
        ll ans = 0;
        int left = 1;
        int right = 1;
        int selections = 1;

        cin >> n;

        REP(i, n) {
            int ai;

            cin >> ai;

            cnt[ai]++;
        }

        if (n < 3) {
            cout << "0\n";

            continue;
        }

        while (true) {
            if ()

        }

        cout << ans << '\n';

        memset(cnt, 0, sizeof(cnt));
    }

    return 0;
}
