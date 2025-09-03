//Reverse String using Stack

#include <iostream>
#include <string>

using namespace std;

#include <iostream>

using namespace std;

void push(char stack[], int &top, char element, int size)
{
    if(top == size - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = element;
    }
}

char pull(char stack[], int &top)
{
    if(top == -1)
    {
        cout << "Stack Underflow" << endl;
        return '\0';
    }
    else
    {
        char element = stack[top];
        top--;
        return element;
    }
}

int main()
{
    cout << "--------------------------------" << endl;
    cout << "Enter the String to be Reversed: ";
    string str;
    getline(cin, str);

    int size = str.length();
    char stack[size];
    int top = -1;

    string revstr = "";

    for(int i = 0; i < size; i++)
    {
        push(stack, top, str[i], size);
    }
    
    while(top != -1)
    {
        revstr += pull(stack, top);
    }

    cout << "Reversed String: ";
    cout << revstr << endl;
    cout << "--------------------------------" << endl;

    return 0;
}