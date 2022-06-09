#include <iostream>

using namespace std;

class student
{
public:
    int no, sc;
    bool operator>(const student &a)
    {
        return this->no > a.no;
    }
    student()
    {}
    student(const student & a)
    {
        no = a.no;
        sc = a.sc;
    }
};

void max(student *stus, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (stus[j] > stus[j + 1])
            {
                student temp = stus[j];
                stus[j] = stus[j + 1];
                stus[j + 1] = temp;
            }

    int max = 0;
    for (int i = 0; i < n; i++)
        max = (stus[i].sc > max) ? stus[i].sc : max;
    for (int i = 0; i < n; i++)
        if(stus[i].sc == max)
            cout << stus[i].no << ' ' << stus[i].sc << endl;
}

int main()
{
    student *stus = new student[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> stus[i].no >> stus[i].sc;
    }
    max(stus, 4);
    return 0;
}