#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<long long> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
    
        vector<long long> d(n - 2);
        for (int i = 1; i < n - 1; i++) {
            long long x = max(h[i - 1], h[i + 1]) - h[i] + 1;
            d[i - 1] = max(0LL, x);
        }
    
        long long ans = 0;
        if (n == 3) {
            ans = d[0];
        } else if (n == 4) {
            ans = min(d[0], d[1]);
        } else {
            if ((n - 2) % 2 == 0) {
                int m = n - 2;
                vector<long long> p(m, 0), s(m, 0);
                p[0] = d[0];
                p[1] = d[1];
                for (int i = 2; i < m; i++) {
                    p[i] = d[i] + p[i - 2];
                }
                s[m - 1] = d[m - 1];
                s[m - 2] = d[m - 2];
                for (int i = m - 3; i >= 0; i--) {
                    s[i] = s[i + 2] + d[i];
                }
                ans = min(p[m - 2], s[1]);
                for (int i = 0; i < m; i += 2) {
                    if (i + 3 < m) {
                        ans = min(ans, p[i] + s[i + 3]);
                    }
                }
                for (int i = m - 1; i >= 0; i -= 2) {
                    if (i - 3 >= 0){ ans = min(ans, p[i - 3] + s[i]);}
                }
            } else {
                for (int i = 0; i < n - 2; i += 2) {
                    ans += d[i];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
