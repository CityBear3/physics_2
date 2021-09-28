#include "iostream"
#include "iomanip"
#include "cmath"

class TrapezoidalRule {
    private:
        int a;
        int b;
        int n;
        double dx;

    public:
        TrapezoidalRule(int init_a, int init_b, double init_dx);

        double calculate(double (*targetFunc)(double));
};


TrapezoidalRule::TrapezoidalRule(int init_a, int init_b, double init_dx) {
    a = init_a;
    b = init_b;
    dx = init_dx;
    n = (b - a) / dx;
}


double TrapezoidalRule::calculate(double (*targetFunc)(double)) {
    double x = a;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double next_x = x + dx;
        sum += (targetFunc(x) + targetFunc(next_x)) * dx / 2;
        x = next_x;
    }

    return sum;
}


void input(int&, int&, double&);


double targetFunc_1(double);


double targetFunc_2(double);


int main() {
    int a, b;
    double dx;
    input(a, b, dx);

    TrapezoidalRule tr(a, b, dx);

    double result_1 = tr.calculate(targetFunc_1);
    double result_2 = tr.calculate(targetFunc_2);
    double cmp_1 = std::sqrt(M_PI) / 2;
    double cmp_2 = 1.0 / 2;

    std::cout << "計算結果：" << std::fixed << std::setprecision(6) << result_1 << std::endl;
    std::cout << "近似値；" << std::fixed << std::setprecision(6) << cmp_1 << std::endl;
    std::cout << "計算結果：" << std::fixed << std::setprecision(6) << result_2 << std::endl;
    std::cout << "近似値；" << std::fixed << std::setprecision(6) << cmp_2 << std::endl;
}

void input(int &a, int &b, double &dx) {
    std::cin >> a;
    std::cin >> b;
    std::cin >> dx;
}


double targetFunc_1(double x) {
    double arg = - (x * x);
    return std::exp(arg);
}


double targetFunc_2(double x) {
    double arg = - (x * x);
    return x * std::exp(arg);
}