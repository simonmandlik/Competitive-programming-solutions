#include <bits/stdc++.h>

using namespace std;

class Point {
public:
    double x, y;

    Point(double a, double b): x(a), y(b) {}
    Point() {
            x = y = 0;
    }

    friend Point operator-(Point p1, Point p2) {
        Point p(0, 0);
        p.x = p1.x - p2.x;
        p.y = p1.y - p2.y;
        return p;
    }

    friend Point operator+(Point p1, Point p2) {
        Point p(0, 0);
        p.x = p1.x + p2.x;
        p.y = p1.y + p2.y;
        return p;
    }
};

double dist(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

Point findPoint(Point A, Point B, double rA, double rB) {
    Point C;
    double d = dist(A, B);
    double l = (rA * rA - rB * rB + d * d) / (2 * d);
    double h = sqrt(rA * rA - l * l);
    double u = A.x + (B.x - A.x) * l / d;
    double v = A.y + (B.y - A.y) * l / d;
    Point E(u, v);
    u = (B.x - A.x) / d;
    v = (B.y - A.y) / d;
    double temp = u;
    u = -v;
    v = temp;
    C.x = E.x + (u * h);
    C.y = E.y + (v * h);
    return C;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    Point A, B;
    double ab, bc, cd, da, u, v, size;
    cout << fixed << setprecision(8);
    for (int i = 1; i <= T; ++i) {
        cin >> A.x >> A.y >> B.x >> B.y;
        cin >> bc >> cd >> da;
        ab = dist(A, B);
        u = B.x - A.x;
        v = B.y - A.y;
        size = sqrt(u*u + v*v);
        u /= size;
        v /= size;
        Point Aa;
        Aa.x = A.x + u * (ab - cd);
        Aa.y = A.y + v * (ab - cd);
        Point D = findPoint(A, Aa, da, bc);
        Point Bb;
        Bb.x = A.x + u * (cd);
        Bb.y = A.y + v * (cd);
        Point C = findPoint(Bb, B, da, bc);
        cout << "Case " << T << ":\n";
        cout << C.x << ' ' << C.y << ' ' << D.x << ' ' << D.y << endl;
    }


    return 0;
}