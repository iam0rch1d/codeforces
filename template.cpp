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

#define F first
#define S second
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

template<typename T>
void chmax(T &m, const T q) { m = max(m, q); }

template<typename T>
void chmin(T &m, const T q) { m = min(m, q); }

template<typename T>
void chmodadd(T &x, T q, T mod) { x = (x + q) % mod; }

template<typename T>
T modmul(T x, T y, T mod) { return x * y % mod; }

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


// ##### GLOVALS #####


// #### FUNCTIONS ####


// ###### MAIN #######
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout << fixed << setprecision(10);

    int tc;

    cin >> tc;

    while (tc--) {

    }

    return 0;
}
