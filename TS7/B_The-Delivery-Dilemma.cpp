// PROBLEM 1443C - DELIVERY DILEMMA
// https://codeforces.com/gym/561586/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        // Pair delivery times with pickup times and sort by delivery times
        vector<pair<long long, long long>> dishes(n);
        for (int i = 0; i < n; ++i) dishes[i] = {a[i], b[i]};
        sort(dishes.begin(), dishes.end());
        
        // Sum of all pickup times
        long long total_pickup_time = accumulate(b.begin(), b.end(), 0LL);
        
        // Minimum time needed (case where all dishes are picked up by Petya)
        long long min_time = total_pickup_time;
        
        // Check cases where i-th dish is the last one delivered
        for (int i = 0; i < n; i++) {
            long long last_delivery_time = dishes[i].first;
            total_pickup_time -= dishes[i].second;
            min_time = min(min_time, max(last_delivery_time, total_pickup_time));
        }
        
        cout << min_time << endl;
    }
    
    return 0;
}
