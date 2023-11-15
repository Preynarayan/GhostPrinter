//Assignment 4 room.c by Prayanshu Narayan S#101144277
#include "defs.h"
/* 
  Function: Initalize a room

  Purpose:  Initialize a room with an id, name

  Params:   
            RoomType *room: room to initialize
            int id : the room Id
            Char* name: the name of the room
            


    Output: RoomArrayType *arr: Array to add to 
*/
void initRoom(int id, char *name, RoomType **room){
    (*room) = (RoomType*)malloc(sizeof(RoomType));
    (*room)->id = id;
    strcpy((*room)->name, name);
    initGhostList(&(*room)->ghosts);
}

void initRoomArray(RoomArrayType *arr){
    arr->size = 0;

}

/* 
  Function:Add room to Room Array

  Purpose:  Add room to Room Array

  Params:   RoomArrayType *arr: Array to add to  
            RoomType *r: room to add to the array
            


    Output: RoomArrayType *arr: Array to add to 
*/
void addRoom(RoomArrayType *arr, RoomType *r){
    arr->elements[arr->size++] = r; 
}

/* 
  Function: Clean up Room Array

  Purpose:  Clean up the room array

  Params:   RoomArrayType *arr 
            


    Output: 
*/
void cleanupRoomArray(RoomArrayType *arr){
    int i = 0;
    while(i < arr->size){
        cleanupGhostList(&arr->elements[i]->ghosts);
        free(arr->elements[i]);
        i++;
    }
    

}

/* 
  Function: Print Rooms

  Purpose:  print rooms and all the ghost in the room

  Params:   const RoomArrayType *arr: the array to print 
            


    Output: to terminal
*/
void printRooms(const RoomArrayType *arr){
    for(int i = 0; i < arr->size; i++){
        printf("Room %5d: %s\n", arr->elements[i]->id, arr->elements[i]->name);
        printf("-----------------------\n");
        if(arr->elements[i]->ghosts.head == NULL){
            printf("No ghosts in this room!\n");

        }
        
        printGhostList(&arr->elements[i]->ghosts);
        printf("-----------------------\n");
        printf("\n");

    }

}