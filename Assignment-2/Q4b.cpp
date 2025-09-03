// Write a program to reverse a string.

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string name;
	getline(cin,name);

	int start=0;
	int end=name.length();

	while(start<end)
	{
		int temp = name[start];
		name[start] = name[end];
		name[end] = temp;
		start++;
		end--;
	}
	cout << "Reversed String: " << name;
}