//Program to sort the String in Ascending Order

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int n;
    string name;
    getline(cin,name);
    n=name.length();

    for (int i = 0; i <n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
		{
            if (name[i] > name[j])
			{ 
                char temp = name[i];
                name[i] = name[j];
                name[j] = temp;
            }
        }
    }
    cout << "Converted String: " << name;
}