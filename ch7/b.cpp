#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <sys/time.h>
#include <cmath>
#include <string>

using namespace std;

struct linkNode
{
    linkNode *next;
    int data;
};

class linkList
{
public:
    linkList()
    {
        head = new linkNode;
        head->data = 1 << 31;
        head->next = nullptr;
        len = 1;
    }
    void ordInsert(int val)
    {
        linkNode *current = head;
        linkNode *last = nullptr;
        linkNode *newNode = new linkNode;
        newNode->data = val;
        // cout << "current->data: " << current->data << endl;
        for (int i = 0; i < len; i++)
        {
            if (current->data == val)
                return;
            if (current->data < val)
            {
                last = current;
                current = current->next;
            }
            else
            {
                newNode->next = current;
                last->next = newNode;
                len++;
                return;
            }
        }
        last->next = newNode;
        newNode->next = nullptr;
        len++;
    }
    void print()
    {
        linkNode *current = head->next;
        for (int i = 1; i < len; i++)
        {
            cout << current->data << ' ';
            current = current->next;
        }
        cout << endl;
    }

private:
    linkNode *head = nullptr;
    int len = 0;
};

bool isPrime(int val)
{
    if (val < 2)
        return false;
    int m = sqrt(val);
    for (int i = 2; i <= m; i++)
    {
        if (val % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    linkList ll;
    string line;
    getline(cin, line);
    istringstream line_iss(line);
    while (line_iss >> n)
    {
        if (!isPrime(n))
            break;
        else
            ll.ordInsert(n);
    }
    ll.print();
}