#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
    char str[20000];
    String();
    String &from_str(const char *);
    const char *c_str();
    int length();
};

String::String()
{
    str[0] = '\0';
    strcpy(str, "1234567890");
}

String &String::from_str(const char *_str)
{
    strcpy(str, _str);
}
const char *String::c_str()
{
    return str;
}
int String::length()
{
    return strlen(str);
}

class EditableString : public String
{
public:
    EditableString &insert(int index, char ch);
    EditableString &del(int index);
    EditableString &replace(int index, char ch);
};

EditableString &EditableString::insert(int index, char ch)
{
    if (index > strlen(str))
        return *this;
    // memcpy(str + index + 1, str + index, strlen(str) - index);
    for (int i = strlen(str); i >= index; i--)
    {
        str[i + 1] = str[i];
    }
    str[index] = ch;
    return *this;
}

EditableString &EditableString::del(int index)
{
    if (index > strlen(str))
        return *this;
    // memcpy(str + index, str + index + 1, strlen(str) - index);
    for (int i = index; i < strlen(str); i++)
    {
        str[i] = str[i + 1];
    }
    return *this;
}

EditableString &EditableString::replace(int index, char ch)
{
    if (index > strlen(str))
        return *this;
    str[index] = ch;
    return *this;
}

int main()
{
    char op, ch;
    int index;
    EditableString myStr;
    bool flag = false;

    while (cin >> op)
    {
        switch (op)
        {
        case 'i':
            cin >> index >> ch;
            // cout << index << endl;
            cout << myStr.insert(index-1, ch).c_str() << endl;
            break;
        case 'd':
            cin >> index;
            // cout << index << endl;
            cout << myStr.del(index-1).c_str() << endl;
            break;
        case 'r':
            cin >> index >> ch;
            // cout << index << endl;
            cout << myStr.replace(index-1, ch).c_str() << endl;
            break;
        default:
            flag = true;
            break;
        };
    }
    return 0;
}