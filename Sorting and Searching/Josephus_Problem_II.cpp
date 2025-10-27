#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    k++;
    ordered_set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);

    long long idx = 0;
    while (!s.empty()) {
        idx = (idx + k - 1) % s.size();
        auto it = s.find_by_order(idx);
        cout << *it << " ";
        s.erase(it);
    }
}
