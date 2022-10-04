#include <iostream>
#include <cstring>
#include "sources.h"

using namespace std;

int main()
{
    char line[256];
    cin.getline(line, 256);

    char *numtk = strtok(line, " ");
    while ( numtk != NULL){
        cout << numtk << " is a prime: " << (is_prime(atoi(numtk)) ? "True" : "False") << endl;
        numtk = strtok(NULL, " "); 
    }
    return 0;
}