#include <fstream>
#include <iostream>
#include <string.h>
using namespace std; 

float * read_file(string filename, int *n_points);
float add_values(float *x, float *y, int n_points);

int main(){
  float *x=NULL;
  float *y=NULL;
  int n_x=0;
  int n_y=0;
  float valor=0;

  x = read_file("valores_x.txt", &n_x);
  y = read_file("valores_y.txt", &n_y);
  
  cout <<"El producto punto es: "<<add_values(x, y, n_x)<<endl;
  
  return 0;
}

float * read_file(string filename, int *n_points){
  int n_lines=0;
  ifstream infile; 
  string line;
  int i;
  float *array;

  /*cuenta lineas*/
  infile.open(filename); 
  getline(infile, line);
  while(infile){
    n_lines++;
    getline(infile, line);
  }
  infile.close();
  *n_points = n_lines;

  /*reserva la memoria necesaria*/
  array = new float[n_lines];

  /*carga los valores*/
  i=0;
  infile.open(filename); 
  getline(infile, line);  
  while(infile){
    array[i] = atof(line.c_str());
    i++;
    getline(infile, line);
  }
  infile.close();

  return array;
}

float add_values(float *x, float *y, int n_points){
  float a=0;
  int i;
  for(i=0;i<n_points;i++){
    float b=x[i]*y[i];
    cout<<b<<endl;
    a += b;
  }
  return a;
}