#include <bits/stdc++.h>
using namespace std;

void first_max_element(vector<int> &arr)
{
    int firstMax = INT_MIN;
    int maxIndex = -1;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (firstMax < arr[i])
        {
            firstMax = arr[i];
            maxIndex = i;
        }
    }
    if (maxIndex == -1)
    {
        cout << "No element found in the array." << endl;
        return;
    }
    cout << "First largest element is: " << firstMax << " at index: " << maxIndex << endl;
}

int main()
{
    vector<int> arr = {1, 3, 4, 35, 46, 75, 67, 75, 58};
    first_max_element(arr);
}

// /// or
// #include <bits/stdc++.h>
// using namespace std;

// void all_max_elements(vector<int> &arr)
// {
//     int firstMax = INT_MIN;
//     vector<int> indices;
//     int n = arr.size();

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > firstMax)
//         {
//             firstMax = arr[i];
//             indices.clear();
//             indices.push_back(i);
//         }
//         else if (arr[i] == firstMax)
//         {
//             indices.push_back(i);
//         }
//     }

//     if (indices.empty())
//     {
//         cout << "No element found in the array." << endl;
//         return;
//     }

//     cout << "Largest element is: " << firstMax << " at indices: ";
//     for (int idx : indices)
//     {
//         cout << idx << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     vector<int> arr = {1, 3, 4, 35, 46, 75, 67, 75, 58};
//     all_max_elements(arr);
// }
