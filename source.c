
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"vector.c" // libary with vector functions

double ax,ay,az,bx,by,bz;
int rows;

double vectors[][3] = {
  {0,0,0}
};

void AddToVectorList(double *NewVector){
  rows++;
  for(int i = 0; i <= 2; i++){
    vectors[rows-1][i] = NewVector[i];
  }
}

void ModifyVectors(){
  printf("\nOptions:\n[1] Add vector\n[2] Remove vector\n");
  int choice;
  scanf("%d", &choice);
  switch(choice){
    case 1:
    printf("\nHow many vectors would you like to add?\n");
    scanf("%d", &choice);
  //  rows += choice;
  double x, y, z;
  choice = rows+choice;
    for(int i = rows; i < (choice); i++){
      printf("X, Y, Z for vector %c\n", i+65);
      scanf("%lf %lf %lf", &x, &y, &z);
    //  printf("%f", x);
    rows++;
      vectors[rows-1][0] = x;
      vectors[rows-1][1] = y;
      vectors[rows-1][2] = z;
    }
    rows = choice;

    break;
    case 2:
  /*    for(int i2 = 1; i2 <= rows; i2++){
        printf("Vector %c: (%f, %f, %f)\n",(i2-1)+65,vectors[i2-1][0],vectors[i2-1][1],vectors[i2-1][2]);
      }*/
      char input;
      printf("\n\nPlease select !1! vector to remove\n");
      scanf("%s", &input);
      rows--;
      int vectorindex = input-65;
      vectors[vectorindex][0] = 0;
      vectors[vectorindex][1] = 0;
      vectors[vectorindex][2] = 0;
      int loop = 1;
      while(1 == 1){
        vectorindex++;
        if(vectors[vectorindex][0] != 0 && vectors[vectorindex][1] != 0){
          vectors[vectorindex-1][0] = vectors[vectorindex][0];
          vectors[vectorindex-1][1] = vectors[vectorindex][1];
          vectors[vectorindex-1][2] = vectors[vectorindex][2];
        }else{
          break;
        }
        }
      }


  system("clear");
  void options2VECTOR();
  options2VECTOR();
}

void options2VECTOR(){
  int option;
  char vector1, vector2;
  for(int i = 1; i <= rows; i++){
    printf("Vector %c: (%f, %f, %f)\n", (i-1)+65,vectors[i-1][0],vectors[i-1][1],vectors[i-1][2]);
  }
  printf("\nOptions(Include - in front of option to save vector):\n");
  printf("[1] Addition with vectors\n");
  printf("[2] Cross product\n");
  printf("[3] Scalar product\n");
  printf("[4] Length of vector\n");
  printf("[5] Add/Remove vector\n");
  printf("[6] Quit program\n");

  scanf("%d", &option);

  switch(option){
    case 5:
    ModifyVectors();
    break;
    case 6:
    exit(0);
    break;
  }

  printf("\nWhich vectors would you like to use in this operation?(e.g. ABC)\n");
  char input[10];
  scanf("%s", input);
  double vectorvalues[50];
  int counter = 0;
  int temp;
  for(int i = 0; i < strlen(input); i++){
    temp = input[i]-65;
    vectorvalues[counter + 0] = vectors[temp][0];
    vectorvalues[counter + 1] = vectors[temp][1];
    vectorvalues[counter + 2] = vectors[temp][2];
    counter += 3;
  }
  double *returnvector;
  system("clear");

  switch (option) {
    case 1:
    plus(vectorvalues, counter, 0);
    break;
    case -1:
    returnvector = plus(vectorvalues, counter, 1);
    AddToVectorList(returnvector);
    break;
    case 2:
    cross(vectorvalues, counter, 0);
    break;
    case -2:
    returnvector = cross(vectorvalues, counter, 1);
    AddToVectorList(returnvector);
    break;
    case 3:
    skalar(vectorvalues, counter);
    break;
    case 4:
    length(vectorvalues, counter);
    break;
    case 5:

    break;
    case 6:
    exit(0);
  }
  options2VECTOR();
}

int main(int argc, char * argv[]){
  int count;
  double x, y, z;
  sscanf(argv[1], "%d", &count);
  //count = 2;
  rows = count;

  for(int i = 0; i <= (count-1); i++){
    printf("X, Y, Z for vector %c\n", i+65);
    scanf("%lf %lf %lf", &x, &y, &z);
  //  printf("%f", x);
    vectors[i][0] = x;
    vectors[i][1] = y;
    vectors[i][2] = z;
  }
  system("clear");
  options2VECTOR();

  return 0;
}
