#include <iostream>
#include <cstring>
#include "sources.h"

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    char numbers[line.length() + 1];
    strcpy(numbers, line.c_str());
    char *numtk = strtok(numbers, " ");

    while ( numtk != NULL){
        cout << numtk << " is a prime: " << (is_prime(atoi(numtk)) ? "True" : "False") << endl;
        numtk = strtok(NULL, " "); 
    }
    return 0;
}