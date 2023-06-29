#include <algorithm>
#include <math.h>
#include <iostream>

bool is_inside_parallel(double x1, double y1, double x4, double y4, double x, double y) {
    if (x <= x1) {
            return false;
    }
    if (x >= x4) {
            return false;
    }
    if (y >= y1) {
            return false;
    }
    if (y <= y4) {
            return false;
    }
    return true;
}

bool is_inside(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4, double x, double y) {
    // 说明已经是平行的了
    if (y1 == y2) {
            return is_inside_parallel(x1, y1, x4, y4, x, y);
    }
    double l = std::abs(y4 - y3);
    double r = std::abs(x4 - x3);
    double s = std::sqrt(l*l + r*r);
    double sin = l / s;
    double cos = r / s;
    double x1_new = x1*cos + y1*sin;
    double y1_new = y1*cos - x1*sin;
    double x4_new = x4*cos + y4*sin;
    double y4_new = y4*cos - x4*sin;
    double x_new = x*cos + y*sin;
    double y_new = y*cos - x*sin;
    return is_inside_parallel(x1_new, y1_new, x4_new, y4_new, x_new, y_new);
}

int main() {
    
}