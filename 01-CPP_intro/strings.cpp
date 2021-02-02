// using C-style strings vs a built-in C++ string class

#include <iostream>
using namespace std;

void string_intro() {
    char greeting1[6] = "Hello";
    char greeting2[6] = {'H', 'e', 'l', 'l', 'o', 0};

    cout << "Greeting message 1: " << greeting1 << endl; 
    cout << "Greeting message 2: " << greeting2 << endl;

    greeting2[5]='!';  // overwrite the terminating 0
    cout << "Greeting message 2: " << greeting2 << endl;
}

#include <string.h>
void c_strings(){
    char str1[10]="yellow";
    char str2[10]="banana";
    char str3[10];
    int len;

    strcpy(str3, str1);
    cout << "strcpy(str3, str1): " << str3 << endl;

    strcat(str1, str2);
    cout << "strcat(str1, str2): " << str1 << endl;

    len = strlen(str1);
    cout << "strlen(str1): " << len << endl;
}

void cpp_strings(){
    string str1="red";
    string str2="apple";
    string str3;
    int len;

    str3 = str1;
    cout << "str3: " << str3 << endl;

    str3 = str1 + " " + str2;
    cout << "str3: " << str3 << endl;

    len = str1.size();
    cout << "str1.size(): " << len << endl;
}


int main(){
    //string_intro();
    c_strings();
    cpp_strings();
}