
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double x_array[100];
double y_array[100];
double z_array[100];
double returnarray[50];
double x, y, z;

//FILE * outputfile;

void ArraySplit(double nums[], int indexcount){
  int count = 0;
  if(indexcount < 6){
    printf("Requires at least 2 vectors");
  }else{
    for(int i = 0; i <= indexcount; i+1-1){
      if(count == indexcount/3){
        break;
      }
      x_array[count] = nums[i];
      y_array[count] = nums[i + 1];
      z_array[count] = nums[i + 2];
      count++;
      i += 3;
    }
  }
}

void ArrayClear(){
  memset(x_array, 0, sizeof x_array);
  memset(y_array, 0, sizeof y_array);
  memset(z_array, 0, sizeof z_array);
  memset(returnarray, 0, sizeof returnarray);
  x = 0.0;
  y = 0.0;
  z = 0.0;
}

double *cross(double nums[], int indexcount, int save){
  ArrayClear();

  ArraySplit(nums, indexcount);

  x += (y_array[0] * z_array[1]) - (z_array[0] * y_array[1]);
  y += (z_array[0] * x_array[1] - (x_array[0] * z_array[1]));
  z += (x_array[0] * y_array[1]) - (y_array[0] * x_array[1]);
  if(indexcount > 6){
    double tempx, tempy, tempz;
    for(int i = 2; i < indexcount/3; i++){
      tempx = (y * z_array[i]) - (z * y_array[i]);
      tempy = (z * x_array[i]) - (x * z_array[i]);
      tempz = (x * y_array[i]) - (y * x_array[i]);

      x = tempx;
      y = tempy;
      z = tempz;
    }
  }

  printf("\nCross product: (%f, %f, %f)\n\n", x, y, z);
  switch(save){
    case 1:
    returnarray[0] = x;
    returnarray[1] = y;
    returnarray[2] = z;
    return returnarray;
  }
//  system("clear");
}

double *plus(double nums[], int indexcount, int save){
  ArrayClear();

  ArraySplit(nums, indexcount);

  for(int i = 0; i <= (indexcount/3)-1; i++){
    x += x_array[i];
    y += y_array[i];
    z += z_array[i];
  }
    printf("\nAdded vectors: (%f, %f, %f)\n\n",x,y,z);
    switch(save){
      case 1:
      returnarray[0] = x;
      returnarray[1] = y;
      returnarray[2] = z;
      return returnarray;
    }
  //  system("clear");
}

void skalar(double nums[], int indexcount){
  ArrayClear();
  ArraySplit(nums, indexcount);

  x = (x_array[0] * x_array[1]);
  y = (y_array[0] * y_array[1]);
  z = (z_array[0] * z_array[1]);
  if(indexcount > 6){
    double tempx, tempy, tempz;
    for(int i = 2; i < indexcount/3; i++){
      tempx = (x * x_array[i]);
      tempy = (y * y_array[i]);
      tempz = (z * z_array[i]);
      x = tempx;
      y = tempy;
      z = tempz;
    }
  }
  double sum = x+y+z;
  printf("\nScalar product: %f\n\n", sum);
//  system("clear");
}

void length(double nums[], int indexcount){
  ArrayClear();
  //ArraySplit(nums, indexcount);
  x = nums[0];
  y = nums[1];
  z = nums[2];
  double output = sqrt(x+y+z);
  printf("\nLength of vector: %f\n\n", output);
  //system("clear");
}
