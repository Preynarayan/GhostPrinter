#include "defs.h"

//Main Function
int main()
{
  BuildingType building;
  int choice = -1;
  initBuilding(&building);
  loadBuildingData(&building);
  while(choice !=0){
    printMenu(&choice);
    if(choice ==  1){
      printRooms(&building.rooms);
    } else if(choice == 2){
      printGhostList(&building.ghosts);
    } else if(choice == 3){
      printByLikelihood(&building.ghosts,C_TRUE);
    } else if(choice == 4){
      printByLikelihood(&building.ghosts,C_FALSE);
    }else if(choice == 0){
      printf("Exiting Now\n");
      cleanupBuilding(&building);
    } else{
      printf("Please enter a valid choice\n");
    }
  

  }
  
  return 0;
}

void printMenu(int *choice)
{
  printf("\nMAIN MENU\n");
  printf("  (1) Print rooms\n");
  printf("  (2) Print ghosts\n");
  printf("  (3) Print ghosts by likelihood\n");
  printf("  (4) Print most/least likely ghosts\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%2d", choice);
  while (getchar() != '\n');
}

