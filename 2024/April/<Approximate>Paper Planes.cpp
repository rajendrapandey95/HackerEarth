#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

double sq(double a) {
    return a * a;
}

double dist(array<double, 3> p1, array<double, 3> v1, array<double, 3> p2, array<double, 3> v2, double t) {
    double ret = 0;
    for (int i = 0; i < 3; i++) {
        double u = p1[i] + t * v1[i];
        double v = p2[i] + t * v2[i];
        ret += sq(u - v);
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    array<double, 3> masao_pts, masao_vel, bo_pts, bo_vel;

    for (int i = 0; i < 3; i++)
        cin >> masao_pts[i];
    for (int i = 0; i < 3; i++)
        cin >> masao_vel[i];
    for (int i = 0; i < 3; i++)
        cin >> bo_pts[i];
    for (int i = 0; i < 3; i++)
        cin >> bo_vel[i];

    double l = 0, r = t;
    for (int lp = 0; lp < 1000; lp++) {
        double t1 = l + (r - l) / 3;
        double t2 = l + 2 * (r - l) / 3;

        double d1 = dist(masao_pts, masao_vel, bo_pts, bo_vel, t1);
        double d2 = dist(masao_pts, masao_vel, bo_pts, bo_vel, t2);

        if (d2 < d1)
            l = l + (r - l) / 3;
        else if (d2 > d1)
            r = l + 2 * (r - l) / 3;
        else {
            l = l + (r - l) / 3;
            r = l + 2 * (r - l) / 3;
        }
    }

    double d = dist(masao_pts, masao_vel, bo_pts, bo_vel, l);

    double ans = sqrt(d);
    cout << fixed;
    cout.precision(6);
    cout << ans << endl;

    return 0;
}
