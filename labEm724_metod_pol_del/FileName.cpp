#define _USE_MATH_DEFINES
#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double f(double x)
{
    double y = pow(M_E, x) - pow(M_E, -x) - 2;
    return y;
}

double solve_equation(double(*f)(double), double x0)
{
    return f(x0);
}
//--------------------------------------------------------------
// Половинное деление.
// eps > 0, а < b, и f(x) непрерывная на отрезке [а, b] функция,
// имеющая на этом отрезке единственный корень.
//--------------------------------------------------------------
double dihotomia(double a, double b, double eps)
{
    double  ksi = (a + b) / 2;
    if (abs(solve_equation(f, a) - solve_equation(f, b)) <= eps)   
        return (a + b) / 2;
    else
        if (abs(solve_equation(f,ksi)) <= eps)
            return (a + b) / 2;
    double x = ksi;
    if (solve_equation(f, a) * solve_equation(f, ksi) <= 0.0)
    {
        cout << "x" << " = " << x << ", f(x) = " << solve_equation(f, x)
            << endl;
        return dihotomia(a, ksi, eps);
    }
    else
    {
        cout << "x"  << " = " << x << ", f(x) = " << solve_equation(f, x)
            << endl;
        return dihotomia(ksi, b, eps);
    }
}
//--------------------------------------------------------------
int  main()
{
    setlocale(LC_ALL, "Rus");
    double a = 0;
    double b = 1;
    double eps = 0.0001;
    double x = dihotomia(a, b, eps);
    cout << "x" << " = " << x << ", f(x) = " << solve_equation(f, x)
        << endl;
    cout << "Ответ: x" << " = " << x << ", f(x) = " << solve_equation(f, x)
        << ", eps = " << eps;
    return 0;
}

















