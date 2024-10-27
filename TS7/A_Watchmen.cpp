// https://codeforces.com/gym/561586/problem/A
#include <iostream>
#include <unordered_map>
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> x_count, y_count;
    unordered_map<pair<int, int>, int, pair_hash> point_count;
    int x, y;
    long long count = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        count += x_count[x];
        x_count[x]++;
        count += y_count[y];
        y_count[y]++;
        count -= point_count[{x, y}];
        point_count[{x, y}]++;
    }
    cout << count << endl;
    return 0;
}
