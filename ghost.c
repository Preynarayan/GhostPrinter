//Assignment 4 ghost.c by Prayanshu Narayan S#101144277
#include "defs.h"

/* 
  Function: Initialize Ghost Linked List

  Purpose:  To initialize a ghost list and set the head and tail to null

  Params:   
            GhostListType * list: the list to initialize

    Output: GhostListType * list: the list to initialize    
*/
void initGhostList(GhostListType *list){
    list->head = NULL;
    list->tail = NULL;
}

/* 
  Function: Initialize Ghost 

  Purpose:  To initialize a ghost list and set the value to null

  Params:   int id: id of the ghost
            GhostEnumType gt:  the type of ghost
            RoomType *r: the room the ghost is in
            float like: the likelihood of the ghost being in the room
            GhostType ** ghost: The ghost to assign it to;


    Output: GhostType ** ghost: The ghost to assign it to;    
*/
void initGhost(int id, GhostEnumType gt, RoomType *r, float like, GhostType **ghost){
    (*ghost) = (GhostType *)malloc(sizeof(GhostType));
    (*ghost)->id = id;
    (*ghost)->ghostType = gt;
    (*ghost)->room = r;
    (*ghost)->likelihood = like;
}

/* 
  Function: Add Ghost 

  Purpose:  To add a ghost to a list 

  Params:   GhostListType *list: the list to add the ghost to 
            GhostType *ghost the ghost to add


    Output: GhostListType *list: the list to add the ghost to    
*/
void addGhost(GhostListType *list, GhostType *ghost){
    NodeType *currNode;
    NodeType *prevNode;
    NodeType *newNode;
    currNode = list->head;
    prevNode = NULL;
    while(currNode!= NULL){
    prevNode = currNode;
    currNode = currNode->next;
    }
    newNode = (NodeType*)malloc(sizeof(NodeType));
    newNode->data = ghost;
    newNode->next = NULL;
    if(prevNode == NULL){
        list->head = newNode;
    } else{
        prevNode->next = newNode;
        list->tail = newNode;
    }
    newNode->next = currNode;
}


/* 
  Function: Clean up a the data in a ghost list 

  Purpose:  To clean up the data in a ghost list

  Params:   GhostListType *list: the list to clean up 
            


    Output: GhostListType *list: the list to clean up   
*/
void cleanupGhostData(GhostListType *list){
    NodeType *currNode;
    NodeType *prevNode;
    currNode = list->head;
    prevNode = NULL;
    while(currNode!= NULL){
    prevNode = currNode;
    currNode = currNode->next;
    free(prevNode->data);
    }
}

/* 
  Function: Clean up a the ghost list nodes

  Purpose:  To clean up the nodes in a ghost list

  Params:   GhostListType *list: the list to clean up 
            


    Output: GhostListType *list: the list to clean up   
*/
void cleanupGhostList(GhostListType *list){
    NodeType *currNode;
    NodeType *prevNode;
    currNode = list->head;
    prevNode = NULL;
    while(currNode!= NULL){
    prevNode = currNode;
    currNode = currNode->next;
    free(prevNode);
    }
}

/* 
  Function: Print ghost 

  Purpose:  Print a ghost 

  Params:   const GhostType *ghost: The Ghost to print 
            


    Output: to terminal
*/
void printGhost(const GhostType *ghost){
    

    printf("Id: %8d", ghost->id);
    printf(" |");
    printGhostType(ghost->ghostType);

    printf(" |");
    if(ghost->room != NULL){
        printf(" Room: %16s", ghost->room->name );

    } else{
        printf(" Room:          Unknown");
    }
    printf(" |");
    printf(" Likelihood: %0.2f\n", ghost->likelihood);




}

/* 
  Function: Print ghost list

  Purpose:  Print a ghost list

  Params:   const GhostListType *list: the list to print 
            


    Output: to terminal
*/
void printGhostList(const GhostListType *list){
    NodeType *currNode;
    NodeType *prevNode;

    currNode = list->head;
    prevNode = NULL;

    while(currNode!= NULL){
    prevNode = currNode;
    currNode = currNode->next;
    printGhost(prevNode->data);
    }

}

/* 
  Function: Add Ghost By Likelihood

  Purpose:  Add Ghost by the likelihood they are in a room

  Params:   GhostListType *list: the ghost list to add to. 
            GhostType * ghost: ghost to add

    Output: GhostListType *list: the ghost list to add to.
*/
void addGhostByLikelihood(GhostListType *list, GhostType *ghost){
    NodeType *newNode;
 
    newNode = (NodeType*)malloc(sizeof(NodeType));
    newNode->data = ghost;
    newNode->next = NULL;
    
    NodeType *currNode;
    NodeType *prevNode;
    currNode = list->head;
    prevNode = NULL;

    while(currNode!= NULL){
        if(currNode == NULL ||currNode->data->likelihood < ghost->likelihood){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;

  
    }
    if(prevNode == NULL){
        newNode->next = list->head;
        list->head = newNode;
        
    } else{
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        
    }
    currNode = list->head;
    prevNode = NULL;
    while(currNode!= NULL){

        prevNode = currNode;
        list->tail = prevNode;
        currNode = currNode->next;  
    }

}

/* 
  Function: Print ghost list by likelyhood

  Purpose:  Print a ghost list by likelyhood

  Params:   const GhostListType *list: the list to print 
            


    Output: to terminal
*/
void printByLikelihood(const GhostListType *origList,int endsOnly){
    GhostListType *temp = (GhostListType*)malloc(sizeof(GhostListType));
    initGhostList(temp);
    NodeType *currNode;

    currNode = origList->head;
    while(currNode != NULL){
        addGhostByLikelihood(temp, currNode->data);
        
        
        currNode = currNode->next;
        
        
    }
    
    if(endsOnly == C_TRUE){
        printGhostList(temp);
    } else if(endsOnly == C_FALSE){
        printf("MOST LIKELY:\n");
        printGhost(temp->head->data);
        printf("LEAST LIKELY:\n");
        printGhost(temp->tail->data);

    }
    cleanupGhostList(temp);
    free(temp);
    
}