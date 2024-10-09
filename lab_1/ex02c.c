#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include "mycom.h"

double f1(double x)
{
  return (4.0 / (1.0 + x*x));
}

double f2(double x)
{
  return (4.0 / (1.0 + x*x / 2.0));
}

double f3(double x)
{
  return (4.0 / (1.0 + 2.0 * x*x));
}

double f4(double x)
{
  return (4.0 / (1.0 + x*x + 2.0));
}

double f5(double x)
{
  return (4.0 / (1.0 + x*x - 0.5));
}

double f6(double x)
{
  return (4.0 / (1.0 + pow(x*x, 4)));
}

double f7(double x)
{
  return (4.0 / (1.0 + exp(x*x)));
}

double f8(double x)
{
  return (4.0 / (1.0 + log(x*x)));
}

double f9(double x)
{
  return (4.0 / (1.0 + sin(x*x)));
}

int main(int argc, char *argv[])
{	
  int nc=1000000000;
  double t1, t2, dt, sum;

  t1 = mytime(0); sum = integrate(f1,0.0,1.0,nc); t1 = mytime(1);

  t2 = mytime(0); sum = integrate(f2,0.0,1.0,nc); t2 = mytime(1);
  dt = 1.0/dabs(t2-t1);
  printf("Time: %lf %lf sec \"\\\". perf.: %le GFlops\n",t1,t2,dt);

  t2 = mytime(0); sum = integrate(f3,0.0,1.0,nc); t2 = mytime(1);
  dt = 2.0/dabs(t2-t1);
  printf("Time: %lf %lf sec \"*\". perf.: %le GFlops\n",t1,t2,dt);

  t2 = mytime(0); sum = integrate(f4,0.0,1.0,nc); t2 = mytime(1);
  dt = 1.0/dabs(t2-t1);
  printf("Time: %lf %lf sec \"+\". perf.: %le GFlops\n",t1,t2,dt);

  t2 = mytime(0); sum = integrate(f5,0.0,1.0,nc); t2 = mytime(1);
  dt = 2.0/dabs(t2-t1);
  printf("Time: %lf %lf sec \"-\". perf.: %le GFlops\n",t1,t2,dt);

  t2 = mytime(0); sum = integrate(f6,0.0,1.0,nc); t2 = mytime(1);
  dt = 1.0/dabs(t2-t1);
  printf("Time: %lf %lf sec \"pow\". perf.: %le GFlops\n",t1,t2,dt);

  t2 = mytime(0); sum = integrate(f7,0.0,1.0,nc); t2 = mytime(1);
  dt = 1.0/dabs(t2-t1);
  printf("Time: %lf %lf sec \"exp\". perf.: %le GFlops\n",t1,t2,dt);
 
  t2 = mytime(0); sum = integrate(f8,0.0,1.0,nc); t2 = mytime(1);
  dt = 1.0/dabs(t2-t1);
  printf("Time: %lf %lf sec \"log\". perf.: %le GFlops\n",t1,t2,dt);
 
  t2 = mytime(0); sum = integrate(f9,0.0,1.0,nc); t2 = mytime(1);
  dt = 1.0/dabs(t2-t1);
  printf("Time: %lf %lf sec \"sin\". perf.: %le GFlops\n",t1,t2,dt);

  return 0;
}



/*
Servers:
Time: 2.789519 2.763695 sec "\". perf.: 3.872367e+01 GFlops
Time: 2.789519 2.770417 sec "*". perf.: 1.047011e+02 GFlops
Time: 2.789519 2.752257 sec "+". perf.: 2.683699e+01 GFlops
Time: 2.789519 2.754353 sec "-". perf.: 5.687312e+01 GFlops
Time: 2.789519 22.876323 sec "pow". perf.: 4.978393e-02 GFlops
Time: 2.789519 8.960452 sec "exp". perf.: 1.620500e-01 GFlops
Time: 2.789519 9.454769 sec "log". perf.: 1.500319e-01 GFlops
Time: 2.789519 10.125019 sec "sin". perf.: 1.363234e-01 GFlops
*/