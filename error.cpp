#include "error.h"
#include <stdio.h>

long long errors=0;

void bizzareChars(){
    fprintf(stderr, "%s", "Bizarre characters at point: ");
}

void negativeValue(){
    fprintf(stderr, "%s", "Negative value at point: ");
}

void zeroValue(){
    fprintf(stderr, "%s", "Zero distance at point: ");
}

void angleTooBig(){
    fprintf(stderr, "%s", "Angle exceeding 400 at point: ");
}

void notEnoughArgs(){
    fprintf(stderr, "%s", "Not enough arguments at point: ");
}

void tooManyArgs(){
    fprintf(stderr, "%s", "Too many arguments at point: ");
}

bool checkErrors(){

    bool foundErrors=false;

    for(int i=0; i<ERROR_NUMBER; i++){
        if(errors & (1<<i)){
            foundErrors=true;
            switch(i){
                case 0: 
                    bizzareChars();
                    break;
                case 2:
                    negativeValue();
                    break;
                case 3:
                    zeroValue();
                    break;
                case 4:
                    angleTooBig();
                    break;
                case 5:
                    notEnoughArgs();
                    break;
                case 6:
                    tooManyArgs();
                    break;
            }
            
        }
    }

    return !foundErrors;

}

void clearErrorBuff(){
    errors=0;
}
