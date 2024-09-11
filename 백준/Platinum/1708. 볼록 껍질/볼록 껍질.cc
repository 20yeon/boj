#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct point {
    ll x, y;
    bool operator < (const point& p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator == (const point& p) const {
        return x == p.x && y == p.y;
    }
};

ll cross(const point& o, const point& a, const point& b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<point> convexhull(vector<point>& points) {
    sort(points.begin(), points.end());

    // Remove duplicates
    points.erase(unique(points.begin(), points.end()), points.end());

    vector<point> lower, upper;

    // Build the lower hull
    for (const auto& p : points) {
        while (lower.size() >= 2 && cross(lower[lower.size() - 2], lower.back(), p) <= 0) {
            lower.pop_back();
        }
        lower.push_back(p);
    }

    // Build the upper hull
    for (int i = points.size() - 1; i >= 0; i--) {
        while (upper.size() >= 2 && cross(upper[upper.size() - 2], upper.back(), points[i]) <= 0) {
            upper.pop_back();
        }
        upper.push_back(points[i]);
    }

    // Remove the last point of each half because it's repeated at the beginning of the other half
    if (lower.size() > 0) lower.pop_back();
    if (upper.size() > 0) upper.pop_back();

    // Concatenate lower and upper hull to get the full convex hull
    lower.insert(lower.end(), upper.begin(), upper.end());

    return lower;
}

int n;
vector<point> points;

void input() {
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
}

void solve() {
    vector<point> hull = convexhull(points);
    cout << hull.size(); // Output the size of the convex hull
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
