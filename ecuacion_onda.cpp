#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;



int main()
{
  double c = 1.0;

  double T = 5.0;

  double dt = 0.0001;

  double dx = 0.0001;//pow(D*dt, 0.5);

  double L = 1.0 ;

  int nx = (L/dx) +1 ;

  double numerador = dt*dt*c*c/(dx*dx);

  int n1 = nx/4.0;

  int t = 0;

  double pi = 3.14159;

  bool termino = false;

  bool primera = true;

  bool segunda = true;

  double* nuevo = new double[nx];

  double* viejo = new double[nx];

  double* segundo_viejo = new double[nx];

  double* segunda_foto = new double[nx];

  double* tercera_foto = new double[nx];

  double* original = new double[nx];

  double* tiempos = new double[4];

  tiempos[0] = 0.0;

  for (int i = 0; i < nx; i++)
    {
      viejo[i] = sin(2.0*pi*i*dx);
      original[i] = sin(2.0*pi*i*dx);
      
    }

  while(nuevo[n1] > -0.99999999)
     {
       
     
      if(t==0)
	{
	  for(int i = 1; i < nx-1; i++)
	    {
	      double a  = numerador*(viejo[i+1] + viejo[i-1] - 2.0*viejo[i]);

	      nuevo[i] = (a + 2.0*viejo[i])/2.0;
	    }

	}
      else
	{
	   for(int i = 1; i < nx-1; i++)
	     {
	       double a  = numerador*(viejo[i+1] + viejo[i-1] - 2.0*viejo[i]);
	       
	       nuevo[i] = a + 2.0*viejo[i] - segundo_viejo[i];
	     }

	}
      
	      

      if( nuevo[n1]-0.5 < 0.01 && primera)
	{
	  primera = false;
	  tiempos[1] = t*dt;
	  for(int i = 0; i < nx; i++)
	    {
	      segunda_foto[i] = nuevo[i];
	    }

	}

	
	if( nuevo[n1]+0.5 < 0.01 && !primera && segunda)
	{
	  segunda = false;
	  tiempos[2] = t*dt;
	  for(int i = 0; i < nx; i++)
	    {
	      tercera_foto[i] = nuevo[i];
	    }

	}
	  

      for(int i = 1; i < nx-1; i++)
	{
	  segundo_viejo[i] = viejo[i];
	  
	  viejo[i] = nuevo[i];
	}

      tiempos[3] = t*dt;

      t++;
    }

  for(int i = 0; i < nx; i++)
    {
      cout << i*dx << " " << original[i] << " " << segunda_foto[i] << " " << tercera_foto[i] << " " << nuevo[i] << " " << tiempos[i] << endl;
    }

  return 0;
}
