#include "sources.h"

bool is_prime(int x){
    if (x == 1){
        return false;
    }
    for (int i = 2; i < (x/2); i++){
        if ((x % i) == 0){
            return false;
        }
    }
    return true;
}