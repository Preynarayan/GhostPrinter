#include "defs.h"

void printGhostType(GhostEnumType ghostType){
    if(ghostType == 0){
        printf("Type      Poltergeist");
    }
    else if(ghostType == 1){
        printf("Type           Wraith");
    }else if(ghostType == 2){
        printf("Type          Phantom");
    }else if(ghostType == 3){
        printf("Type          Bullies");
    }else if(ghostType == 4){
        printf("Type            Other");
    }
}
