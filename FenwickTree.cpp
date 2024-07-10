#include <vector>

using std::vector;
using ll = long long;

class FenwickTree {
public:
    FenwickTree(int n) : maxPositions(n), tree(n + 1, 0) {}

    void add(int pos, ll val) {
        int treePos = pos + 1;
        while (treePos <= maxPositions) {
            tree[treePos] += val;
            treePos += (treePos & -treePos);
        }
    }

    void update(int pos, ll oldVal, ll newVal) {
        ll diff = newVal - oldVal;
        add(pos, diff);
    }

    ll sum(int begin, int end) {
        return accumulatedValue(end + 1) - accumulatedValue(begin);
    }

private:
    ll accumulatedValue(int pos) const {
        ll value = 0;
        while (pos > 0) {
            value += tree[pos];
            pos -= (pos & -pos);
        }
        return value;
    }

    int maxPositions;
    vector<ll> tree;
};
