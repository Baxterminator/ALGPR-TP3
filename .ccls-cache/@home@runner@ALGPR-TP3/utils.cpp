#include "utils.h"
#include <fstream>
using namespace std;


VectAllumettes readfile(){
  VectAllumettes v;
  fstream fichier;
  int size;
  
  fichier.open("allumettes_donnees.txt",ios::in);
  // Lecture de la taille
  if (!fichier.eof()) {
    fichier >> size;
    v.resize(size);
  }
  else {
    return v;
  }
  // Lecture des allumettes
  for (int i = 0; i < size; i++) {
    Allumette elem; 
    if (fichier.eof()) break;

    // Si le fichier n'est pas fini
    fichier >> elem.couleur;
    fichier >> elem.taille;

    v[i] = elem;
  }

  return v;
}

void writeFile(VectAllumettes &liste) {
  int size = liste.size();
  fstream handle;

  // Ecriture du fichier
  handle.open("allumettes_donnes2.txt", ios::out);
  handle << size << endl;
  for (int i = 0; i < size; i++) {
    handle << liste[i].couleur << " " << liste[i].taille << endl;
  }
  handle.close();
}

VectAllumettes generationAleatoire(int size) {
  VectAllumettes out;
  for (int i = 0; i<size; i++) {
    Allumette elem;
    elem.couleur = rand() % 7;
    elem.taille = rand()%20+1;
    out.push_back(elem);
  }
  return out;
}