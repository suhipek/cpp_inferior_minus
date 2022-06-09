#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <sys/time.h>
#include <cmath>
#include <string>

using namespace std;

class Rational
{
public:
    Rational(int _a, int _b);
    void reduct();
    void operator=(const Rational &n);
    Rational operator++(int);
    Rational operator+(const Rational &n);
    Rational operator-(const Rational &n);
    friend Rational operator*(const Rational &m, const Rational &n);
    friend Rational operator/(const Rational &m, const Rational &n);
    friend ostream &operator<<(ostream &output, const Rational &n);
    friend istream &operator>>(istream &output, Rational &n);
    int a, b; // a/b
};

Rational::Rational(int _a = 1, int _b = 1)
{
    a = _a;
    b = _b;
    reduct();
}

void Rational::reduct()
{
    if (a == 0 || b == 0)
        return;
    int t = 1, _a = a, _b = b;
    if (_a < _b)
    {
        _a = b;
        _b = a;
    }
    while (t != 0)
    {
        t = _a % _b;
        _a = _b;
        _b = t;
    }
    a /= _a;
    b /= _a;
}

void Rational::operator=(const Rational &n)
{
    this->a = n.b;
    this->b = n.a;
}

Rational Rational::operator++(int)
{
    return Rational(a + b, b);
}

Rational Rational::operator+(const Rational &n)
{
    return Rational(this->a * n.b + n.a * this->b, this->b * n.b);
}

Rational Rational::operator-(const Rational &n)
{
    return Rational(this->a * n.b - n.a * this->b, this->b * n.b);
}

Rational operator*(const Rational &m, const Rational &n)
{
    return Rational(m.a * n.a, m.b * n.b);
}

Rational operator/(const Rational &m, const Rational &n)
{
    return Rational(m.a * n.b, m.b * n.a);
}

ostream &operator<<(ostream &output, const Rational &_n)
{
    Rational n(_n.a, _n.b);
    if (n.a == 0 || n.b == 0)
        output << 0;
    else if (n.b == 1 || n.b == -1)
        output << n.b * n.a;
    else if (n.b < 0)
        output << -n.a << '/' << -n.b;
    else
        output << n.a << '/' << n.b;
    return output;
}

istream &operator>>(istream &input, Rational &n)
{
    char slash;
    input >> n.a >> slash >> n.b;
    return input;
}

int main()
{
    int q, op;
    Rational a, b;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> a >> b;
            cout << a + b << endl;
            break;
        case 2:
            cin >> a >> b;
            cout << a - b << endl;
            break;
        case 3:
            cin >> a >> b;
            cout << a * b << endl;
            break;
        case 4:
            cin >> a >> b;
            cout << a / b << endl;
            break;
        case 5:
            cin >> a;
            cout << a++ << endl;
            break;
        case 6:
            cin >> a;
            b = a;
            cout << b << endl;
            break;
        case 0:
            cin >> a;
            cout << a << endl;
            break;
        }
    }
    return 0;
}