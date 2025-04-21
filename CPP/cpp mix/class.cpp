#include <bits/stdc++.h>
using namespace std;
class employee
{
public:
    int rollno;
    string name;
    employee()
    {
        cout << "default constructor" << endl;
    }
    employee(int rollno, string name)
    {
        this->rollno = rollno;
        this->name = name;
    }
    void print()
    {
        cout << "Name->" << this->name << endl;
        cout << "rollno->" << this->rollno << endl;
    }
    // copy constructor
    employee(employee &d)
    {
        cout << "copy consstructor called" << endl;
        this->name = d.name;
        this->rollno = d.rollno;
    }
    // distrcutor caleed
    ~employee()
    {
        cout << "diostrctor called " << endl;
    }
};
class b
{
public:
    void operator+()
    {
        cout << "this is a opertaor overloading :";
    }
    void operator()()
    {
        cout << "this is operator ()";
    }
};
class add // friend function
{
    int a, b;

    friend int sum(add obj1);

public:
    add(int x, int y) // Constructor to initialize values
    {
        a = x;
        b = y;
    }
    void display()
    {
        cout << "This is the example of the friend function." << endl;
    }
};
int sum(add obj1)
{
    return obj1.a + obj1.b;
}

int main()
{
    // employee s(12, "saiyam");
    // s.print();
    // // copy condtructor
    // employee r(s);
    // r.print();
    // employee e1;
    // employee *e2 = new employee;
    // delete e2;
    // b obj1, obj2;
    // int a = 9;
    // int c = 10;
    // a + c;
    // obj1();
    add obj1(12, 23);
    cout << sum(obj1);
    return 0;
}