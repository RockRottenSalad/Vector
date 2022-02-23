
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

FILE * outputfile;

/*void cross(double nums[], int indexcount){
  double output1 = (ay * bz) - (az * by);
  double output2 = (az * bx) - (ax * bz);
  double output3 = (ax * by) - (ay * bx);
  printf("\nCross product: (%f, %f, %f)\n\n", output1, output2, output3);
}*/

void cross(double nums[], int indexcount){
  double x, y, z;

  double x_array[100];
  double y_array[100];
  double z_array[100];

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

  x += (y_array[0] * z_array[1]) - (z_array[0] * y_array[1]);
  y += (z_array[0] * x_array[1] - (x_array[0] * z_array[1]));
  z += (x_array[0] * y_array[1]) - (y_array[0] * x_array[1]);
  if(indexcount > 6){
    double tempx, tempy, tempz;
    for(int i = 2; i < indexcount/3; i++){
  //    printf("%f %f %f-",x_array[i],y_array[i], z_array[i]);
      tempx = (y * z_array[i]) - (z * y_array[i]);
      tempy = (z * x_array[i]) - (x * z_array[i]);
      tempz = (x * y_array[i]) - (y * x_array[i]);

      x = tempx;
      y = tempy;
      z = tempz;
    }
  }

  printf("\nCross product: (%f, %f, %f)\n\n", x, y, z);
}

/*void plus(double ax, double ay, double az, double bx, double by, double bz){
  double sum1 = (ax + bx);
  double sum2 = (ay + by);
  double sum3 = (az + bz);
  printf("\nAdded vectors: (%f, %f, %f)\n\n", sum1, sum2, sum3);
  outputfile = fopen("output.txt", "a");
  fprintf(outputfile, "\nVector A: (%f, %f, %f)\nVector B: (%f, %f, %f)\n", ax, ay, az, bx, by, bz);
  fprintf(outputfile, "Added vectors: (%f, %f, %f)", sum1, sum2, sum3);
  fclose(outputfile);
}*/

void plus(double nums[], int indexcount){
  double x_array[100];
  double y_array[100];
  double z_array[100];

  double x, y, z;
  int count = 0;
  if(indexcount < 6){
    printf("Requires at least 2 vectors");
  //  exit();
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
  for(int i = 0; i <= (indexcount/3)-1; i++){
    x += x_array[i];
    y += y_array[i];
    z += z_array[i];
  }
    printf("Added vectors: (%f, %f, %f)\n",x,y,z);

}

void skalar(double nums[], int indexcount){
  //double Sum = (ax * bx) + (ay * by) + (az * bz);
  double x_array[100];
  double y_array[100];
  double z_array[100];
  double x, y, z;

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
  x = (x_array[0] * x_array[1]);
  y = (y_array[0] * y_array[1]);
  z = (z_array[0] * z_array[1]);
  if(indexcount > 6){
    double tempx, tempy, tempz;
    for(int i = 2; i < indexcount/3; i++){
      printf("%f %f %f", x_array[2], y_array[2], z_array[2]);
      tempx = (x * x_array[i]);
      tempy = (y * y_array[i]);
      tempz = (z * z_array[i]);
      x = tempx;
      y = tempy;
      z = tempz;
    }
  }
  double sum = x+y+z;
  printf("\nScalar product: %f\n", sum);
}
