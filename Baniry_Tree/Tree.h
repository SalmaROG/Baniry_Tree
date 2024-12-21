#pragma once
#include<iostream>
#include <queue>
#include <memory>
#include <string>
using namespace std;
class Tree
{ private:
	int value;
	Tree* left;
	Tree* right;
  public:
	  //Constructeur
	  Tree(int val);

	  //Inserer un element 
	  void inserer(int val);
 
      //Affichage de l'arbre en largeur 
      void afficherEnLargeur();

	  //Recherche
	  bool Rechercher(int val);
	  //Destructeur
	  ~Tree();

};

