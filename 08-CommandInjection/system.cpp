// this example illustrates how to inject shell commands into the input stream

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace::std;

int main() {

    // 1: test how system() works
    // system("pwd");

    // 2: make an interactive program
    string name;
    cout << "What is your name? ";

    // cin >> name;
    // try entering "bob" w/o quotes--everything works
    // try entering "bob johnson" or "bob; johnson" w/o quotes--cin gets only "bob"; need to replace it with getline()

    // 3: allow enterinng a whole line with spaces
    std::getline(std::cin, name);
    // now also try:
    // bob; ls
    // bob; touch myfile.txt
    // bob; mkdir test
    // bob; mkdir test; cp *.cpp test
    // bob; sudo apt-get install libncurses5-dev libncursesw5-dev       // installs ncurses
    // bob; sudo useradd bob; sudo passwd bob; su - bob              // creates a new accout and sets the password; then type whoami
    //      use     cat /etc/passwd     to list existing users
    //      use     sudo userdel bob      to delete the user

    string command = "echo Hi there, " + name ;
    system(command.c_str());
}

/* spotting the issue:
    look for system() and similar commands; they should never be used, if at all possible

validate the input and sanitize the data:
    * The deny-list approach looks for matches demonstrating that the data is invalid, and accepts everything else as valid
    * The allow-list approach looks for the set of valid data, and rejects anything else
    * The “quoting” approach transforms data so that there cannot be anything unsafe
*/
