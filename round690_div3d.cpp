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

#define INF 987654321

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout << fixed << setprecision(10);

    int t;

    cin >> t;

    while (t--) {
        int n;
        int aMax = 0;
        int s = 0;
        set<int> divisors;
        int minOperations = INF;

        cin >> n;

        vector<int> a(n);

        for (int &ai : a) {
            cin >> ai;

            chmax(aMax, ai);

            s += ai;
        }

        if (all_of(ALL(a), [aMax](int i) { return i == aMax; })) {
            cout << "0\n";

            continue;
        }

        divisors.insert(s);

        for (int i = 2; i * i <= s; i++) {
            if (s % i == 0) {
                if (i >= aMax) divisors.insert(i);

                if (s / i >= aMax) divisors.insert(s / i);
            }
        }

        for (int divisor : divisors) {
            int left = 0;
            int right = 0;
            int sum = a[0];
            int operations = 0;

            while (true) {
                if (sum < divisor) sum += a[++right];
                else if (sum == divisor) {
                    operations += right - left;
                    left = ++right;

                    if (left >= n) break;

                    sum = a[left];
                } else {
                    operations = INF;

                    break;
                }
            }

            chmin(minOperations, operations);
        }

        cout << minOperations << '\n';
    }

    return 0;
}
