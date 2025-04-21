#include <bits/stdc++.h>
using namespace std;
void Swap(int a, int b)
{
    cout << "Before is " << a << " and " << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "After swap is " << a << " and " << b << endl;
}
bool even_odd(int n)
{
    if (n % 2 == 0)
    {
        return 1;
    }
    return 0;
}
void natural_no(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << sum;
}
void Prime(int n)
{
    for (int num = 2; num <= n; num++)
    {
        int cnt = 0;

        for (int i = 1; i <= num; i++)
        {
            if (num % i == 0)
            {
                cnt++;
            }
        }

        if (cnt == 2)
        {

            cout << num << " is prime no " << endl;
        }
    }
}
void Gratest(int a, int b, int c)
{

    if (a > b && a > c)
    {
        cout << "A is Greater ";
    }
    else if (b > c && b > a)
    {

        cout << "B is Greater";
    }
    else if (c > a && c > b)
    {
        cout << " C is Greater";
    }
    else
    {
        cout << "Some element are equal";
    }
}
int gcd(int a, int b)
{
    if ((a == 1 || b == 1) || a == b)
    {
        return a;
    }
    if (a > b)
    {
        return gcd(a - b, b);
    }
    else
    {
        return gcd(a, b - a);
    }
}
int lcm(int a, int b)
{
    int res = (a * b) / gcd(a, b);
    return res;
}
void turnery_gratest(int a, int b)
{
    int max = (a > b) ? a : b;
    cout << max;
}
void leap_year(int year)
{
    for (int i = 2010; i <= year; i++)
    {

        if ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0))
        {
            cout << i << " is a leap year" << endl;
        }
        else
        {
            cout << i << " Not a leap year " << endl;
        }
    }
}
void IsVowel(string c)
{
    char arr[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    string s = "AEIOUaeiou";
    for (int i = 0; i < c.length(); i++)
    {
        bool isvowel = false;
        for (int j = 0; j < 10; j++)
        {
            if (c[i] == arr[i])
            {
                isvowel = true;
                break;
            }
        }
        if (isvowel)
        {
            cout << c[i] << " is a Vowel" << endl;
        }
        else
        {
            cout << c[i] << " is not vowel" << endl;
        }
    }
}
void Small_calculator()
{
    int a, b;
    char choice;
    char continueChoice;
    int store = 0;

    do
    {
        cout << "Enter the First Number: ";
        cin >> a;
        cout << "Enter the Second Number: ";
        cin >> b;

        cout << "Choose an operation (+, -, *, /): ";
        cin >> choice;

        int res;
        switch (choice)
        {
        case '+':
            res = a + b;
            store += res;
            cout << "Result: " << res << endl;
            break;
        case '-':
            res = a - b;
            store += res;
            cout << "Result: " << res << endl;
            break;
        case '*':
            res = a * b;
            store += res;
            cout << "Result: " << res << endl;
            break;
        case '/':
            if (b != 0)
            {
                res = a / b;
                store += res;
                cout << "Result: " << res << endl;
            }
            else
            {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid choice. Please enter a valid operation." << endl;
        }
        cout << "Accumulated Result: " << store << endl;
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueChoice;

    } while (continueChoice == 'y' || continueChoice == 'Y'); // Continue if user enters 'y' or 'Y'
    cout << "Final Accumulated Result: " << store;
    cout << "Thank you for using the calculator!" << endl;
}
int fabonica(int n)
{
    if (n <= 1)
        return n;
    int next = 1;
    int prev = 0;
    int sum;
    for (int i = 2; i <= n; i++)
    {
        sum = next + prev;
        prev = next;
        next = sum;
        cout << " " << sum;
    }
}
int reverse_no(int n)
{
    int temp = 0;
    while (n > 0)
    {

        temp = (temp * 10) + n % 10;
        n = n / 10;
    }
    return temp;
}
int palandrome(int n)
{
    int temp = reverse_no(n);
    if (temp == n)
    {
        cout << n << " is palandrome";
    }
    else
    {
        cout << "not a palandrome";
    }
}
void Amstrong_no(int n)
{
    int last_digit = 0;
    int sum = 0;
    int cube;
    int orignal = n;
    while (n > 0)
    {
        last_digit = n % 10;
        cube = last_digit * last_digit * last_digit;
        sum += cube;
        n = n / 10;
    }
    if (orignal == sum)
    {
        cout << "Yes an amstrong no ";
    }
    else
    {
        cout << "Not A amstrong No:";
    }
}
void Decimal_to_Binary(int n)
{
    // vector<int> arr;
    // while (n > 0)
    // {

    //     arr.push_back(n % 2);
    //     n = n / 2;
    // }
    // for (int i = arr.size() - 1; i >= 0; i--)
    // {
    //     cout << arr[i];
    // }
    // reveresd binary
    // int tempp = 0;
    // while (n > 0)
    // {
    //     tempp = n % 2;
    //     cout << " " << tempp;
    //     n = n / 2;
    // }
    // without loop
    int r, base = 1, binary = 0;
    while (n > 0)
    {
        r = n % 2;
        binary = binary + r * base;
        n = n / 2;
        base = base * 10;
    }
    cout << " " << binary;
}
int binary_to_decimal(int n)
{
    int rem = 0;
    int base = 1;
    int decimal = 0;
    while (n > 0)
    {
        rem = n % 10;
        decimal = decimal + rem * base;
        n = n / 10;
        base = base * 2;
    }
    return decimal;
}
int Decimal_to_octal(int n)
{
    int octal = 0;
    int base = 1;
    int reminder;
    while (n > 0)
    {
        reminder = n % 8;
        octal = octal + reminder * base;
        n = n / 8;
        base = base * 10;
    }
    return octal;
}
void binary_to_octal(int n)
{
    int decimal = binary_to_decimal(n);
    cout << Decimal_to_octal(decimal);
}
int nth_term_AP(int a, int d, int n)
{
    cout << (a + (n - 1) * d);
}
void even_odd_bitwise(int n)
{
    // uisng Xor ^ operator
    // if ((n ^ 1) == (n + 1))
    // {
    //     cout << "the no is even:";
    // }
    // else
    // {
    //     cout << "The no is odd:";
    // }

    // using & operator
    // if (!(n & 1))
    // {
    //     cout << "The no is even";
    // }
    // else
    // {
    //     cout << "no is odd";
    // }

    // using || operator
    // if ((n | 1) > n)
    // {
    //     cout << "The no is even ";
    // }
    // else
    // {
    //     cout << "The no is odd";
    // }
}
int Addition_using_bitwise(int a, int b)
{
    int k = (a & b) << 1;
    int res = a ^ b;
    if (k == 0)
    {
        return res;
    }

    Addition_using_bitwise(a, b);
}
int zero_in_no(int n)
{
    int cnt = 0;

    while (n > 0)
    {
        if ((n % 10) == 0)
        {
            cnt++;
        }
        n = n / 10;
    }
    cout << cnt;
}
int trailing_zeros(int n)
{
    int count = 0;
    while (n % 10 == 0 && n != 0)
    {
        count++;
        n = n / 10;
    }
    cout << count;
}
void pattern1(int n) // 1+2-3-4+5+6-7-8---n
{
    int i = 1;

    int sum = 0;
    while (i <= n)
    {
        int j = i + 1;
        int temp = i + j;
        sum += temp;
        i += 2;
        j += 2;
        if (i <= n)
        {
            int temp2 = -(i + j);
            sum += temp2;
            i += 2;
        }
    }
    cout << "The result of the series up to " << n << " terms is: " << sum << endl;
}
void pattern2(int n) // (2*4*8) + (16*32*64) + n
{
    int i = 2;
    int sum = 0;
    while (i <= n)
    {
        int j = i * 2;
        int k = j * 2;
        sum += i * j * k;
        i = k * 2;
    }
    cout << "The sum of " << n << " digit is " << sum;
}
void pattern3(int n) // (1*2)+(3*4)+(5*6)---n
{
    int i = 1;
    int sum = 0;
    while (i <= n)
    {
        int j = i + 1;
        sum += i * j;
        i += 2;
    }
    cout << "The sum of " << n << " digit is " << sum;
}
void pattern4(int n) // 1-2 + 3-4 + 5-6-----n
{
    int i = 1;
    int sum = 0;
    while (i <= n)
    {
        int j = i + 1;
        sum += i - j;
        i += 2;
    }
    cout << "The sum of " << n << " digit is " << sum;
}
void pattern5(int n) // (5*10*20) + (40* 80*160)
{
    int i = 5;
    long long sum = 0;
    while (i <= n)
    {
        int j = i * 2;
        int k = j * 2;
        sum += i * j * k;
        i = k * 2;
    }
    cout << "The sum of " << n << " digit is " << sum;
}

int main()
{
    // //area and parameter
    // int side;
    // cout << "enter the side of the square" << endl;
    // cin >> side;
    // int area;
    // area = side * side;
    // cout << "Area of the follwing  Square is :" << area << endl;
    // int parameter;
    // parameter = 4 * side;
    // cout << "The parameter of the follwing square is :" << parameter;

    // Swap(12, 21);

    // int n;
    // cout << "Enter The N: ";
    // cin >> n;
    // if (even_odd(n))
    // {
    //     cout << "The no is even" << endl;
    // }
    // else
    // {
    //     cout << "The no is odd" << endl;
    // }

    // natural_no(3);

    // Prime(10);
    // Gratest(12, 21, 56);
    // cout << gcd(98, 56);
    // cout << __gcd(98, 56);
    // cout << lcm(98, 56);
    // turnery_gratest(21, 22);
    // leap_year(2020);
    // IsVowel("saiyam");
    // Small_calculator();
    // fabonica(7);
    // cout << reverse_no(12345);
    // palandrome(1221);
    // Amstrong_no(156);
    // Decimal_to_Binary(5);
    // binary_to_decimal(101010);
    // Decimal_to_octal(6);
    // binary_to_octal(110);
    // nth_term_AP(7, 2, 3);
    // even_odd_bitwise(20);
    // cout << Addition_using_bitwise(15, 38);
    // zero_in_no(15000);
    // trailing_zeros(130900);
    // pattern1(8);
    // pattern2(3);
    // pattern3(5);
    // pattern4(6);
    // pattern5(6);
}