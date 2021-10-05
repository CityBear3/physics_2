#include "iostream"

#include "cmath"


double firstFunc(double);


double secondFunc(double);


class DataFactory{
    private:
        double start;
        double end;
        double interval;

    public:
        DataFactory(double, double, double);
        void Dump(double (*firstTarget)(double), double (*secondTarget)(double));
};


DataFactory::DataFactory(double init_start, double init_end, double init_interval) {
    start = init_start;
    end = init_end;
    interval = init_interval;
}


void DataFactory::Dump(double (*firstTarget)(double), double (*secondTarget)(double)) {
    double x = start;
    while (x <= end) {
        std::cout << x << " " << firstTarget(x) << " " << secondTarget(x) << std::endl;
        x += interval;
    }
}

int main() {
    DataFactory dataFactory(-M_PI, M_PI, M_PI/30);

    dataFactory.Dump(firstFunc, secondFunc);
}


double firstFunc(double x) {
    return x - std::pow(x, 3) / 6 + std::pow(x, 5) / 120;
}


double secondFunc(double x) {
    return std::sin(x);
}