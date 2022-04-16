#include "utils.h"
#include "affichage.h"
#include "tris.h"
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

const int MAX_ITER = 100;

int main() {
  VectAllumettes v;
  high_resolution_clock::time_point t1, t2;
  long t_inser = 0, t_bulle =0, t_rapide=0;

  for (int iter = 0; iter<MAX_ITER; iter++) {
    v = generationAleatoire(1000);
    
    // Insertion
    t1 = high_resolution_clock::now();
    tri_insertion(v.size(),v);
    t2 = high_resolution_clock::now();
    t_inser += duration_cast<microseconds>( t2 - t1 ).count();

    // Tri à bulle
    t1 = high_resolution_clock::now();
    tri_bulle(v);
    t2 = high_resolution_clock::now();
    t_bulle += duration_cast<microseconds>( t2 - t1 ).count();

    // Tri rapide
    t1 = high_resolution_clock::now();
    tri_rapide(v);
    t2 = high_resolution_clock::now();
    t_rapide += duration_cast<microseconds>( t2 - t1 ).count();
  }
  
  cout << "Tris à insertion : " <<  t_inser/MAX_ITER << "µs" << endl;
  cout << "Tris à bulle : " <<  t_bulle/MAX_ITER<< "µs" << endl;
  cout << "Tris rapide : " <<  t_rapide/MAX_ITER<< "µs" << endl;
}

