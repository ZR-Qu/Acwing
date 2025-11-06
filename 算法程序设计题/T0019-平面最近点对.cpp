#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Point {
    int x, y;
};

LL distSq(const Point &p1, const Point &p2) {
    LL dx = (LL)p1.x - p2.x;
    LL dy = (LL)p1.y - p2.y;
    return dx * dx + dy * dy;
}

bool compareX(const Point &a, const Point &b) { return a.x < b.x; }
bool compareY(const Point &a, const Point &b) { return a.y < b.y; }

LL solve(const vector<Point> &P) {
    LL ans = LLONG_MAX;
    for (int i = 0; i < (int)P.size(); ++i)
        for (int j = i + 1; j < (int)P.size(); ++j)
            ans = min(ans, distSq(P[i], P[j]));
    return ans;
}

LL closestUtil(vector<Point> &Px, vector<Point> &Py) {
    int n = Px.size();
    if (n <= 3) return solve(Px);

    int mid = n / 2;
    Point midPoint = Px[mid];

    vector<Point> Px_left(Px.begin(), Px.begin() + mid);
    vector<Point> Px_right(Px.begin() + mid, Px.end());

    vector<Point> Py_left, Py_right;
    Py_left.reserve(mid);
    Py_right.reserve(n - mid);

    for (auto &p : Py) {
        if (p.x < midPoint.x || (p.x == midPoint.x && Py_left.size() < Px_left.size()))
            Py_left.push_back(p);
        else
            Py_right.push_back(p);
    }

    LL dL = closestUtil(Px_left, Py_left);
    LL dR = closestUtil(Px_right, Py_right);
    LL d = min(dL, dR);

    vector<Point> strip;
    strip.reserve(n);
    for (auto &p : Py) {
        LL dx = (LL)p.x - midPoint.x;
        if (dx * dx < d) strip.push_back(p);
    }

    LL best = d;
    for (int i = 0; i < (int)strip.size(); ++i) {
        for (int j = i + 1; j < (int)strip.size(); ++j) {
            LL dy = (LL)strip[j].y - strip[i].y;
            if (dy * dy >= best) break;
            best = min(best, distSq(strip[i], strip[j]));
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Point> Px(n), Py(n);
    for (int i = 0; i < n; ++i) {
        cin >> Px[i].x >> Px[i].y;
        Py[i] = Px[i];
    }

    sort(Px.begin(), Px.end(), compareX);
    sort(Py.begin(), Py.end(), compareY);

    cout << closestUtil(Px, Py) << endl;
    return 0;
}
