#include "tris.h"
using namespace std;


// Si a > b (et par couleur croissante si taille égales)
bool compare(const Allumette &a,const Allumette &b) {
  return (a.taille == b.taille) ? (a.couleur >= b.couleur): (a.taille >= b.taille);
}

// =================================
//        Tri par insertion
// =================================

VectAllumettes inserer(VectAllumettes v, int i, int j){
  Allumette a = v[i];
  for (int k=i-1; k>=j; k=k-1){
    v[k+1]=v[k];
  }
  v[j] = a;
  return v;
}

VectAllumettes tri_insertion(int n, VectAllumettes v){
  //init();
  for (int i=1; i < n; i=i+1){
    int j=0;
    while (j<i && compare(v[i],v[j])){
      j = j + 1;
    }
    v = inserer(v,i,j);
    //affiche(v);
  }
  return v;
  //finish();
}


// =================================
//           Tri à bulle
// =================================
void permuter(Allumette* a, Allumette* b) {
  Allumette c = *a;
  *a = *b;
  *b = c;
}

VectAllumettes tri_bulle(VectAllumettes list) {
  // Permutation
  //init();
  for (int max = list.size(); max > 0; max--) {
    for (int i = 0; i < max-1; i++) {
      if (compare(list[i], list[i+1])) {
        permuter(&list[i], &list[i+1]);
      }
      //affiche(list);
    } 
  }
  //finish();
  return list;
}

// =================================
//           Tri rapide
// =================================

void tri_rapide_rec(VectAllumettes &v , int deb , int fin ){
  if (deb<fin){
    Allumette pivot = v[deb];
    int i = deb; 
    for (int j=deb+1; j<=fin; j=j+1){
      if (!compare(v[j],pivot)){
        v = inserer(v,j,i);
        i = i + 1;
      }
    }
    tri_rapide_rec(v,deb,i);
    tri_rapide_rec(v,i+1,fin);
  }
}

VectAllumettes tri_rapide(VectAllumettes v){
  tri_rapide_rec(v,0,v.size()-1);
  return v;
}




