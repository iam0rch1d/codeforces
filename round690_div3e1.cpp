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
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vstr = vector<string>;

#define ALL(x) x.begin(), x.end()
#define IALL(x) x.rbegin(), x.rend()
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define FOR_(i, x, y) for (int i = x; i <= y; i++)
#define IFOR(i, x, y) for (int i = y; i > x; i--)
#define IFOR_(i, x, y) for (int i = y; i >= x; i--)
#define REP(i, x) FOR(i, 0, x)
#define SUBSTR(s, l, r) s.substr(l, r - l + 1)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'
#define DEBUG(x) cerr << "\033[1;35m" << (x) << "\033[0m\n"

const int dy[]{0, -1, 0, 1, -1, -1, 1, 1};
const int dx[]{-1, 0, 1, 0, -1, 1, -1, 1};

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

// #### CONSTANTS ####
#define MAX_N 200001

// ##### GLOVALS #####
ll dp[MAX_N][3];

// #### FUNCTIONS ####


// ###### MAIN #######
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout << fixed << setprecision(10);

    dp[0][0] = 1;

    FOR(i, 1, MAX_N) {
        dp[i][0] = 1;

        FOR_(j, 1, min(i, 2)) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }

    int t;

    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        vll a(n);

        for (ll &ai : a) {
            cin >> ai;
        }

        sort(ALL(a));

        ll ans = 0;

        FOR(i, 0, n) {
            int left = i + 1;
            int right = upper_bound(ALL(a), a[i] + 2) - 1 - a.begin();

            ans += dp[right - left + 1][2];
        }

        PRINTLN(ans);
    }

    return 0;
}
