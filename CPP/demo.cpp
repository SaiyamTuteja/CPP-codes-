// #include "bits/stdc++.h"
// using namespace std;

// void smallest_largest_no(int arr[], int size)
// {
//     int min = INT_MAX;
//     int max = INT_MIN;

//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] < min) // Fixing condition for min
//         {
//             min = arr[i];
//         }
//         if (arr[i] > max) // Fixing condition for max
//         {
//             max = arr[i];
//         }
//     }
//     cout << "Minimum is: " << min << endl;
//     cout << "Maximum is: " << max << endl;
// }
// void
// int main()
// {
//     int arr[] = {1, 22, 3, 34, 45, 10};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     smallest_largest_no(arr, size);
// }

#include "bits/stdc++.h"
#include "stack"
using namespace std;

int main()
{

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    // pop
    s.pop();
    s.pop();
    // s.pop();
    cout << "Top element is " << s.top() << endl;
    if (s.empty())
    {
        cout << "Stack is empty";
    }
    else
    {
        cout << "Stack is not empty";
    }
}