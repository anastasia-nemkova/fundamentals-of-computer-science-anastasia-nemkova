#include <stdio.h>
#include <math.h>
int main(void){
   double a, b, c, x1, x2, D;
   scanf("%lf%lf%lf", &a, &b, &c);
   D = b*b - 4*a*c;
   if( D < 0 ){
      printf("No roots\n");}
   else if( D == 0 ){
      x1 = -b/(2*a);
      printf("One root: %lf\n", x1);
   } 
   else {
      x1 = (-b - sqrt(D)) / (2*a);
      x2 = (-b + sqrt(D)) / (2*a);
      printf("Two roots: %lf%lf\n", x1, x2);
   }
   return 0;
}
