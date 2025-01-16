#include <stdbool.h>

bool isSelfDistanceZero(bool matrix[4][4] ){
    for (int i = 0; i < 4; i++){
        if(matrix[i][i] != 0){
            return false;

        }
    }
    return true;
}