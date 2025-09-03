//Menu Program for Basic Stack Operations using Array

#include <iostream>

using namespace std;

void push(int stack[], int &top, int size)
{
    if(top == size - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        int value;
        cout << "Enter The Value to be Pushed: ";
        cin >> value;
        top++;
        stack[top] = value;
        cout << value << " pushed to stack" << endl;
    }
}

void pop(int stack[], int &top)
{
    if(top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << stack[top] << " popped from stack" << endl;
        top--;
    }
}

void isFull(int stack[], int &top, int size)
{
    if(top == size - 1)
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        cout << "Stack is Not Full" << endl;
        cout << "Available Space: " << size - top - 1 << endl;
    }
}

void isEmpty(int stack[], int &top)
{
    if(top == -1)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is Not Empty" << endl;
        cout << "Number of Elements in Stack: " << top + 1 << endl;
    }
}

void peek(int stack[], int &top)
{
    if(top == -1)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Top Element is: " << stack[top] << endl;
    }
}

void display(int stack[], int &top)
{
    if(top == -1)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack Elements from Top to Bottom: ";
        for(int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "--------------------------------" << endl;
    cout << "Enter the Size of the Stack: ";
    int size;
    cin >> size;
    int stack[size];
    int top = -1;

    int ch;

    while(true)
    {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check if Stack is Full\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Peek\n";
        cout << "6. Display Stack\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        cout << "--------------------------------" << endl;

        switch(ch)
        {
            case 1:
                push(stack, top, size);
                break;
            case 2:
                pop(stack, top);
                break;
            case 3:
                isFull(stack, top, size);
                break;
            case 4:
                isEmpty(stack, top);
                break;
            case 5:
                peek(stack, top);
                break;
            case 6:
                display(stack, top);
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid Choice" << endl;
        }
    }

    return 0;
}