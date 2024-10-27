#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n), b(m);
        
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];
        
        // Frequency map for b
        unordered_map<int, int> freq_b;
        for (int num : b) {
            freq_b[num]++;
        }
        
        // Sliding window frequency map for a
        unordered_map<int, int> window_freq;
        int match_count = 0, result = 0;

        // Initialize the first window
        for (int i = 0; i < m; ++i) {
            int num = a[i];
            if (window_freq[num] < freq_b[num]) match_count++;
            window_freq[num]++;
        }
        
        // Check if the first window is good
        if (match_count >= k) result++;

        // Slide the window over the rest of a
        for (int i = m; i < n; ++i) {
            int outgoing = a[i - m];
            int incoming = a[i];

            // Remove outgoing element from window
            if (window_freq[outgoing] <= freq_b[outgoing]) match_count--;
            window_freq[outgoing]--;

            // Add incoming element to window
            if (window_freq[incoming] < freq_b[incoming]) match_count++;
            window_freq[incoming]++;

            // Check if this window is good
            if (match_count >= k) result++;
        }

        cout << result << endl;
    }
    
    return 0;
}
