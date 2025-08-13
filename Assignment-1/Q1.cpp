//Menu Program for Array Operations: Create, Display, Insert, Delete, Linear Search, and Exit

#include <iostream>
using namespace std;

void createArray(int arr[], int &size) 
{
    cout << "Enter the number of elements: ";
    cin >> size;

    for (int i = 0; i < size; ++i) 
    {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> arr[i];
    }
}

void displayArray(const int arr[], int size) 
{
    cout << "Array elements: ";
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &size, int element, int position) 
{
    if (position < 0 || position > size) 
    {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = size; i > position; --i) 
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    ++size;
}

void deleteElement(int arr[], int &size, int position) 
{
    if (position < 0 || position >= size) 
    {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = position; i < size - 1; ++i) 
    {
        arr[i] = arr[i + 1];
    }
    --size;
}

int linearSearch(const int arr[], int size, int element) 
{
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] == element) 
        {
            return i; // Return the index of the found element
        }
    }
    return -1; // Element not found
}

int main() 
{
    int arr[255];
    int size = 0;
    int choice;

    do 
    {
        cout << "\n----------------Menu---------------\n";
        cout << "1. Create Array\n";
        cout << "2. Display Array\n";
        cout << "3. Insert Element\n";
        cout << "4. Delete Element\n";
        cout << "5. Linear Search\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
            
                createArray(arr, size);
                break;
            

            case 2:
            
                displayArray(arr, size);
                break;
            

            case 3: 
            
                int element, position;
                
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position to insert at (0 to " << size << "): ";
                cin >> position;
                insertElement(arr, size, element, position);
                break;
            

            case 4: 
            
                int position;
                cout << "Enter position to delete from (0 to " << (size - 1) << "): ";
                cin >> position;
                deleteElement(arr, size, position);
                break;
            

            case 5: 
            
                int element;
                cout << "Enter element to search for: ";
                cin >> element;
                int index = linearSearch(arr, size, element);

                if (index != -1) 
                {
                    cout << "Element found at index: " << index << endl;
                } 
                else 
                {
                    cout << "Element not found!" << endl;
                }
                break;
            
            case 6:
            
                cout << "Exiting program." << endl;
                break;
            
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } 
    while (choice != 6);

    return 0;
}