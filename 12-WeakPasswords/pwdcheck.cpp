// a simple example showing how to check and enforce various password strength policies

#include <iostream>
#include <string>
using namespace std;

// this function verifies whether the candidate passwords meets various policy requirements 
// and determines whether it is strong/moderate/weak
void checkPassword(string& input) {
    int pwdLength = input.length();
    bool hasLower = false,
         hasUpper = false,
         hasDigit = false,
         hasSpecial = false,
         hasIllegal = false;
    // the candidate password is required to include at least one of these characters 
    string specialChars = "~!@#$%^&*()_+";  

    for(int i=0; i<pwdLength; i++) {
        if(islower(input[i])) hasLower = true;  // the password includes a lowercase character
        if(isupper(input[i])) hasUpper = true;  // the password includes an uppercase character
        if(isdigit(input[i])) hasDigit = true;  // the password includes a digit
        
        // check if the current character occurs in teh list of special characters 
        if(specialChars.find_first_of(input[i]) != string::npos) hasSpecial = true;
        // and if it also isn't an alphanumeric character, it must be an illegal character 
        else if(!isalnum(input[i])) hasIllegal = true; 
    }

    cout << "Password \"" << input << "\"";
    if(hasLower) cout << " has lowercase chars,";
    if(hasUpper) cout << " has uppercase chars,";
    if(hasDigit) cout << " has digits,";
    if(hasSpecial) cout << " has special chars,";
    if(hasIllegal) cout << " has illegal chars,";
    cout << endl;

    if(hasIllegal) cout << "Password has illegal characters" << endl;
    else {
        cout << "Password strength: ";
        if(hasLower && hasUpper && hasDigit && hasSpecial && (pwdLength >= 10)) cout << "strong" << endl;
        else if((hasLower || hasUpper) && hasDigit && (pwdLength >=6)) cout << "moderate" << endl;
        else cout << "weak" << endl;
    }
}

int main() {
    string password;
    cout << "Please enter a password: ";
    cin >> password;
    checkPassword(password);
}