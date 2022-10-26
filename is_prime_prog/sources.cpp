#include <string.h>
#include "sources.h"

bool is_prime(long num)
{
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}

void printNum(long num)
{
    std::cout << num << " is a prime: " << (is_prime(num) ? "True" : "False") << "\n"; 
}