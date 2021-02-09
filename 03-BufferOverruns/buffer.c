// a simple example of buffer overflow used in class

#include <stdio.h>
#include <string.h>

int IsPasswordOK(){
    char Password[12];
    gets(Password);   // unsafe due to lack of bounds checking on the input size
    return (strcmp(Password, "goodpass")==0);
}

int main (){
    int PwStatus;
    printf("Enter password: ");
    PwStatus=IsPasswordOK();
    if(!PwStatus) {
        printf("Access denied!\n");
        return -1;
    }
    else {
        printf("Access granted!\n");
        return 0;
    }
}