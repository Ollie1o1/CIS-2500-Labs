#include <stdio.h>
#include <stdbool.h>

bool isSelfDistanceZero(double matrix[4][4]);

int main (){

    double distanceMatrix[4][4] = {
         {0, 95.1, 119.4, 296.6},
        {95.1, 0, 191.0, 368.6},
        {119.4, 191.0, 0, 191.0},
        {296.6, 368.6, 191.0, 0}
    };

    bool result = isSelfDistanceZero(distanceMatrix);

    if(result){
        printf("All diagonal elements are zero. \n");
    }
    else{
        printf("At least one diagonal element is not zero. \n");
    }
    
    return 0;
}