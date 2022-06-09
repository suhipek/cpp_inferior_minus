#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

class Distance
{
protected:
    int x, y, z, w;

public:
    Distance(int, int, int, int);
    virtual int getDis() = 0;
};


Distance::Distance(int _x, int _y, int _z, int _w)
{
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}

class ManhattanDistance : public Distance
{
public:
    int getDis();
    using Distance::Distance;
};

int ManhattanDistance::getDis()
{
    return abs(x - z) + abs(y - w);
}

class EuclideanDistance : public Distance
{
public:
    int getDis();
    using Distance::Distance;
};

int EuclideanDistance::getDis()
{
    return (x - z) * (x - z) + (y - w) * (y - w);
}

int main()
{
    int x, y, z, w;
    cin >> x >> y >> z >> w;
    ManhattanDistance mDis(x, y, z, w);
    EuclideanDistance eDis(x, y, z, w);
    cout << mDis.getDis() << ' ' << eDis.getDis();
    return 0;
}