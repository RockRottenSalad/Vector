
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"vector.c" // libary with vector functions

double ax,ay,az,bx,by,bz;
int rows;

double vectors[][3] = {
  {0,0,0}
};

void options2VECTOR(){
  int option;
  char vector1, vector2;
  for(int i = 1; i <= rows; i++){
    printf("Vector %c: (%f, %f, %f)\n", (i-1)+65,vectors[i-1][0],vectors[i-1][1],vectors[i-1][2]);
  }
  printf("\nOptions:\n");
  printf("[1] Addition with vectors\n");
  printf("[2] Cross product\n");
  printf("[3] Scalar product\n");
  printf("[4] Length of vector\n");
  printf("[5] Quit program\n");

  scanf("%d", &option);

  switch(option){
    case 5:
    exit(0);
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
  double returnvector[10];

  switch (option) {
    case 1:
    plus(vectorvalues, counter, 0);
    break;
    case -1:
    returnvector[] = plus(vectorvalues, counter, 1);
    break;
    case 2:
    cross(vectorvalues, counter, 0);
    break;
    case -2:
    cross(vetorvalues, counter, 1)
    break;
    case 3:
    skalar(vectorvalues, counter, 0);
    break;
    case 4:
    length(vectorvalues, counter, 0);
    break;
    case 5:
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
  options2VECTOR();

  /*if(count == 1){
    sscanf(argv[2], "%lf", &ax);
    sscanf(argv[3], "%lf", &ay);
    sscanf(argv[4], "%lf", &az);
  }else if(count == 2){
    sscanf(argv[2], "%lf", &ax);
    sscanf(argv[3], "%lf", &ay);
    sscanf(argv[4], "%lf", &az);
    sscanf(argv[5], "%lf", &bx);
    sscanf(argv[6], "%lf", &by);
    sscanf(argv[7], "%lf", &bz);
    options2VECTOR();
  }*/

  //printf("%d", output);
  return 0;
}
