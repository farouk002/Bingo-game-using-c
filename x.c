//Farouk Kotob
#include <stdio.h>

int walk(int w1, int w2);
int swim(int s);
int fly(int f);

int main(void)
{
  int mx = 1000, my = 154, mz = 3;
  mx += walk(my + 4, mz + 5);
  printf("mx has a value of %d\n", mx);
  return 0;
}

int walk(int w1, int w2)
{
  int a, b;
  a = fly(w2);
  b = swim(w1);
  return -b + a;
}

int swim(int s)
{
  int c;
  c = s % 5;
  printf("%d",c);
  
  // point two

  return c;
}

int fly(int f)
{
  int d;
  d = f * 20;
  
  // point one

  return d;
}