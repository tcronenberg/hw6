#include <iostream>

using namespace std;

void detK(double*, double, double, double, const int, const int, const double);

int main(){
  const int N = 100000, a = 10, b = 28, T = 100;
  const double dt = T/double(N), c = 8/3.0;
  
  double x = 1, y = 1, z = 1;
  double t = 0;
  double k1[3], k2[3], k3[3], k4[3];
  
  cout << t << "\t" << x << "\t" << y << "\t" << z << endl;
  
  for(int i = 1; i <= N; i++){
      t += dt;
      
      detK(k1, x, y, z, a ,b, c);
      detK(k2, x + dt / 2.0 * k1[0] , y + dt / 2.0 * k1[1] , z + dt / 2.0 * k1[2], a ,b, c);
      detK(k3, x + dt / 2.0 * k2[0] , y + dt / 2.0 * k2[1] , z + dt / 2.0 * k2[2], a ,b, c);
      detK(k4, x + dt * k3[0] , y + dt * k3[1] , z + dt * k3[2], a ,b, c);
      
      x += dt / 6.0 * ( k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0] );
      
      y += dt / 6.0 * ( k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1] );
      
      z += dt / 6.0 * ( k1[2] + 2 * k2[2] + 2 * k3[2] + k4[2] );
      
      cout << t << "\t" << x << "\t" << y << "\t" << z << endl;  
  }
  
  return 0;
}

void detK(double* k, double x, double y, double z, const int a, const int b, const double c){
  k[0] = a * ( y - x );
  k[1] = x * ( b - z ) - y;
  k[2] = x * y - c * z; 
}