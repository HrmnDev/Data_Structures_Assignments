//Program to Convert Uppercase to Lowercase and Lowercase to Uppercase

#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    cout << "Enter string";
    getline(cin,name);

    int n=name.length();
    for(int i=0;i<n;i++)
    { 
        if(name[i]>=65 && name[i]<=90) //For Uppercase
	        name[i] += 32;  
   
        else if(name[i]==32) //For Whitespace
    	    name[i]=name[i];

	    else  //For Lowercase
            name[i]=name[i]-32;
    }

    cout << "Converted String: " << name;

    return 0;
}