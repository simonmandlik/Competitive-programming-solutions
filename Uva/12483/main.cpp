#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    double dist(Point A) {
        return sqrt(pow(A.x - x, 2) + pow(A.y - y, 2));
    }

    double dist(Point A, Point B) {
        double scale = ((x - A.x) * (B.x - A.x) + (y - A.y) * (B.y - A.y)) /
                       ((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));

        return dist(Point(A.x + scale * (B.x - A.x), A.y + scale * (B.y - A.y)));
    }

    double distB(Point A, Point B) {
        if ((x - A.x) * (B.x - A.x) + (y - A.y) * (B.y - A.y) <= 1e-6)
            return dist(A);
        if ((x - B.x) * (A.x - B.x) + (y - B.y) * (A.y - B.y) <= 1e-6)
            return dist(B);
        return dist(A, B);
    }
};

int main() {
    int n, L, H;
    while (!cin.eof()) {
        cin >> n >> L >> H;
        double result = L;
        Point pa, pb;
        int y1, y2;
        for (int i = 0; i < n; i++) {
            cin >> y1 >> pa.x >> pa.y;

            int a = i & 1 ? L : 0;
            int b = i & 1 ? 0 : L;
            result = min(result, pa.distB(Point(b, 0), Point(b, H)));

            if (i > 0) {
                result = min(result, pb.distB(Point(a, y1), pa));
            }
            y2 = y1;
            pb = pa;
        }
        cout << fixed << setprecision(2) << result << endl;

    }

}