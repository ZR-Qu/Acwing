#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

// 快速幂，避免pow误差
double myPow(double x, int n) {
    double res = 1.0;
    for (int i = 0; i < n; ++i) {
        res *= x;
    }
    return res;
}

// 定义 f(x) = x^41 + x^3 + 1
double f(double x) {
    return myPow(x, 41) + myPow(x, 3) + 1;
}

// 定义 f'(x) = 41 * x^40 + 3 * x^2
double df(double x) {
    return 41 * myPow(x, 40) + 3 * x * x;
}

int main() {
    double x;
    cout << "输入初始猜测值 x0: ";
    cin >> x;

    int max_iter = 100;           // 最大迭代次数
    double tol = 1e-3;            // 收敛精度
    int iter = 0;

    while (iter < max_iter) {
        double fx = f(x);
        double dfx = df(x);

        if (fabs(dfx) < 1e-12) {   // 避免除以0
            cout << "导数太小，牛顿法失败。" << endl;
            break;
        }

        double delta = fx / dfx;
        x = x - delta;

        cout << "第 " << iter + 1 << " 次迭代: x = " << x << endl;

        if (fabs(delta) < tol) {
            cout << "收敛成功！最终近似根为 x = " << x << endl;
            break;
        }

        iter++;
    }

    if (iter == max_iter) {
        cout << "达到最大迭代次数，未收敛。" << endl;
    }

    return 0;
}
