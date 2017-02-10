#include <stdio.h>
int main() /* main function */
{
  int s, x;
  printf("Area calculation:\n(1) Square\n(2) Cube\n(3) Circle\n"); /* area calculation */
  printf("Please make a selection:\n"); /* make a selection */
  scanf("%d", &s); 

  while ( s < 1 || s > 3 ){
  printf("Incorrect choice\n");
  printf("Area calculation:\n(1) Square\n(2) Cube\n(3) Circle\n");
  printf("Please make a selection:\n"); /* make a selection */
  scanf("%d", &s);
}
/* when select is 1 */
  if ( s == 1 ){
  printf("Enter a positive number:\n");
  scanf("%d", &x);
  while ( x < 1 ){
  printf("Number can't be negative or zero\n\n");
  printf("Enter a positive number:\n");
  scanf("%d", &x);
} 
  if ( x > 0 ){
  printf("Length of the side of square is %d\nArea of square if %d\n", x, x * x);
}
}
/* when select is 2 */
  if ( s == 2 ){
  printf("Enter a positive number:\n");
  scanf("%d", &x);
  while ( x < 1 ){
  printf("Number can't be negative or zero\n\n");
  printf("Enter a positive number:\n");
  scanf("%d", &x);
}
  if ( x > 0 ){
  printf("Length of the side of cube is %d\nArea of cube is %d\n", x, 6 * x * x);
}
}
/* when select is 3 */
  if ( s == 3 ){
  printf("Enter a positive number:\n");
  scanf("%d", &x);
  while ( x < 1 ){
  printf("Number can't be negative or zero\n\n");
  printf("Enter a positive number:\n");
  scanf("%d", &x);
}
  if ( x > 0){
printf("Radius of circle is %d\nArea of circle is %.2f\n", x, 3.14159 * x * x);
}
}
 
  return 0;
}
