#include <iostream>
using namespace std;


int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}


int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\n--- SEARCH MENU ---\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search (Array must be sorted)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter element to search: ";
    cin >> key;

    int result;

    if (choice == 1) {
        result = linearSearch(arr, n, key);
    }
    else if (choice == 2) {
        result = binarySearch(arr, n, key);
    }
    else {
        cout << "Invalid choice!";
        return 0;
    }

    if (result != -1)
        cout << "Element found at position: " << result + 1;
    else
        cout << "Element not found";

    return 0;
}