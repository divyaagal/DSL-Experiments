#include <iostream>
using namespace std;

int main()
{
    char x;
    int arr[5], a[5], b[5], i, pos, value;
    int n = 4;   // size of array

    do
    {
    cout << "\n1. Create arrays";
    cout << "\n2. Display arrays";
    cout << "\n3. Addition";
    cout << "\n4. Subtraction";
    cout << "\n5. Maximum element (Array 1)";
    cout << "\n6. Minimum element (Array 1)";
    cout << "\n7. Insert element in Array 1";
    cout << "\n8. Exit";
    cout << "\nEnter your choice: ";

    int ch;
    cin >> ch;

    switch (ch)
    {
    case 1:
    cout << "Enter elements for array 1:\n";
    for (i = 0; i < n; i++)
    cin >> arr[i];

    cout << "Enter elements for array 2:\n";
    for (i = 0; i < n; i++)
    cin >> a[i];
    break;

    case 2:
    cout << "Array 1: ";
    for (i = 0; i < n; i++)
    cout << arr[i] << " ";

    cout << "\nArray 2: ";
    for (i = 0; i < n; i++)
    cout << a[i] << " ";
    cout << endl;
    break;

    case 3:
    cout << "Addition of arrays: ";
    for (i = 0; i < n; i++)
    {
    b[i] = arr[i] + a[i];
    cout << b[i] << " ";
    }
    cout << endl;
    break;

    case 4:
    cout << "Subtraction of arrays: ";
    for (i = 0; i < n; i++)
    {
    b[i] = arr[i] - a[i];
    cout << b[i] << " ";
    }
    cout << endl;
    break;

    case 5: {
    int max = arr[0];
    for (i = 1; i < n; i++)
    {
    if (arr[i] > max)
    max = arr[i];
    }
    cout << "Maximum element in Array 1: " << max << endl;
    break;
    }
    case 6: {
    int min = arr[0];
    for (i = 1; i < n; i++)
    {
    if (arr[i] < min)
    min = arr[i];
    }
    cout << "Minimum element in Array 1: " << min << endl;
    break;
    }
     case 7:
    cout << "Enter position to insert (0-4): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> value;

    for (i = n; i > pos; i--)
    arr[i] = arr[i - 1];

    arr[pos] = value;
    n++;

    cout << "Array after insertion: ";
    for (i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
    break;

    case 8:
    cout << "Exiting program...";
    return 0;

    default:
    cout << "Invalid choice!";
    }

    cout << "\nDo you want to continue? (y/n): ";
        cin >> x;
    } while (x == 'y' || x == 'Y');
    return 0;
}
