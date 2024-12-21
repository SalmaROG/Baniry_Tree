#include <iostream>
#include"Tree.h"

int main()
{
    Tree* racine = new Tree(10);

    racine->inserer(25);
    racine->inserer(3);
    racine->inserer(45);
    racine->inserer(50);
    racine->inserer(9);
    racine->inserer(11);
    racine->inserer(2);
    racine->inserer(1);
    racine->inserer(4);
    racine->inserer(8);
    racine->inserer(28);
    racine->inserer(30);
    racine->inserer(5);
    racine->inserer(7);

    
    cout << "Parcours en largeur : ";
    racine->afficherEnLargeur();
    cout << endl;

    int valeurRecherchee = 0;
    if (racine->Rechercher(valeurRecherchee)) {
        cout << "La valeur " << valeurRecherchee << " a ete trouvee dans l'arbre." << endl;
    }
    else {
        cout << "La valeur " << valeurRecherchee << " n'a pas ete trouvee dans l'arbre." << endl;
    }
 
    return 0;  
}

