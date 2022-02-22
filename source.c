
#include<stdio.h>
#include<stdlib.h>
#include"vector.c" // libary with vector functions

double ax,ay,az,bx,by,bz;
double x, y, z;

double vectors[][3] = {
  {0,0,0}
};

void options2VECTOR(){
  int option;
  char vector1, vector2;
  printf("Vector A: (%f, %f, %f)\n", ax,ay,az);
  printf("Vector B: (%f, %f, %f)\n", bx,by,bz);
  printf("Options:\n");
  printf("[1] Plus vector\n");
  printf("[2] Kryds produkt/cross\n");
  printf("[3] Quit\n");

  scanf("%d &c &c", &option, &vector1, &vector2);
  switch (option) {
    case 1:
    plus(ax,ay,az,bx,by,bz);
    break;
    case 2:
    cross(ax,ay,az,bx,by,bz);
    break;
    case 3:
    exit(0);
  }
  options2VECTOR();
}

int main(int argc, char * argv[]){
  int count;
  if(argc < 2){
    printf("Usage: \n ./program amount_of_vectors Ax Ay Az Bx By Bz\n");
    exit(0);
  }
  sscanf(argv[1], "%d", &count);

  for(int i; i <= count; i++){
    printf("X, Y, Z til vector %d", i);
    scanf("%d %d %d", &x, &y, &z);
    vectors[i][0] = x;
    vectors[i][1] = y;
    vectors[i][2] = z;
  }

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
