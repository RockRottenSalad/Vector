
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

FILE * outputfile;

void cross(double ax, double ay, double az, double bx, double by, double bz){
  double output1 = (ay * bz) - (az * by);
  double output2 = (az * bx) - (ax * bz);
  double output3 = (ax * by) - (ay * bx);
  printf("\nCross product: (%f, %f, %f)\n\n", output1, output2, output3);
  outputfile = fopen("output.txt", "a");
  fprintf(outputfile, "\nVector A: (%f, %f, %f)\nVector B: (%f, %f, %f)\n", ax, ay, az, bx, by, bz);
  fprintf(outputfile, "Cross product: (%f, %f, %f)\n", output1, output2, output3);
  fclose(outputfile);
}

void plus(double ax, double ay, double az, double bx, double by, double bz){
  double sum1 = (ax + bx);
  double sum2 = (ay + by);
  double sum3 = (az + bz);
  printf("\nAdded vectors: (%f, %f, %f)\n\n", sum1, sum2, sum3);
  outputfile = fopen("output.txt", "a");
  fprintf(outputfile, "\nVector A: (%f, %f, %f)\nVector B: (%f, %f, %f)\n", ax, ay, az, bx, by, bz);
  fprintf(outputfile, "Added vectors: (%f, %f, %f)", sum1, sum2, sum3);
  fclose(outputfile);
}

void skalar(double ax, double ay, double az, double bx, double by, double bz){
  Sum = (ax * bx) + (ay * by) + (az * bz);
}
