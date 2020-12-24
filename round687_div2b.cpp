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
using pi = pair<int, int>;

#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define FOR_(i, x, y) for (int i = x; i <= y; i++)
#define IFOR(i, x, y) for (int i = y - 1; i >= x; i--)
#define IFOR_(i, x, y) for (int i = y; i >= x; i--)
#define REP(i, x) FOR(i, 0, x)
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

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout << fixed << setprecision(10);

    int t;

    cin >> t;

    while (t--) {
        int n;
        int k;

        cin >> n >> k;

        vector<int> c(n);
        vector<int> colors;

        for (int &ci : c) {
            cin >> ci;

            colors.push_back(ci);
        }

        sort_unique(colors);

        int ans = 1234567;

        for (int color : colors) {
            vector<int> cTemp(c);
            int paintCount = 0;

            FOR(i, 0, n) {
                if (cTemp[i] != color) {
                    FOR(j, 0, k) {
                        if (i + j < n) cTemp[i + j] = color;
                    }

                    paintCount++;
                }
            }

            chmin(ans, paintCount);
        }

        cout << ans << '\n';
    }

    return 0;
}
