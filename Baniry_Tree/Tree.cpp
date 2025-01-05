#include "Tree.h"

//Constructeur : initialise un nœud avec une valeur donnée et des enfants nuls (nullptr)
Tree::Tree(int val) : value(val), left(nullptr), right(nullptr) {}

/*Insertion: insère une valeur dans l'arbre de manière itérative, en utilisant une file (queue)
 pour parcourir l'arbre en largeur.
 L'utilisation d'une file est le bon choix car elle permet de traiter les 
 noeuds dans l'ordre où ils sont rencontrés, ce qui garantit 
 un parcours complet de chaque niveau avant de passer au suivant.
 */
void Tree::inserer(int val)
{
    //File pour parcourir l'arbre niveau par niveau
    queue<Tree*> file;
    file.push(this); //Ajouter la racine de l'arbre dans la file

    //Parcours en largeur pour trouver un emplacement vide
    while (!file.empty()) {
        Tree* courant = file.front(); //Extraire le nœud en tête de la file
        file.pop();

        //Si le nœud gauche est libre, insérer la valeur ici
        if (!courant->left) {
            courant->left = new Tree(val);
            return; //Insertion terminée
        }
        else {
            file.push(courant->left); //Ajouter l'enfant gauche à la file
        }

        //Si le nœud droit est libre, insérer la valeur ici
        if (!courant->right) {
            courant->right = new Tree(val);
            return; //Insertion terminée
        }
        else {
            file.push(courant->right); //Ajouter l'enfant droit à la file
        }
    }
}

//Affichage en largeur : parcourt et affiche les valeurs de l'arbre en largeur (BFS)
void Tree::afficherEnLargeur()
{
    if (!this) return; //Si l'arbre est vide, rien à afficher

    queue<Tree*> file; //File pour parcourir l'arbre
    file.push(this);   //Ajouter la racine à la file

    while (!file.empty()) {
        Tree* courant = file.front(); //Extraire le nœud en tête
        file.pop();

        cout << courant->value << " "; //Afficher la valeur du nœud

        //Ajouter les enfants gauche et droit à la file, s'ils existent
        if (courant->left) {
            file.push(courant->left);
        }
        if (courant->right) {
            file.push(courant->right);
        }
    }
}

//Recherche : vérifie si une valeur existe dans l'arbre en parcourant en largeur
bool Tree::Rechercher(int val)
{
    if (this == nullptr) {
        return false; //Si l'arbre est vide, la valeur n'existe pas
    }

    queue<Tree*> file; //File pour parcourir l'arbre
    file.push(this);   //Ajouter la racine à la file

    while (!file.empty()) {
        Tree* courant = file.front(); //Extraire le nœud en tête
        file.pop();

        //Vérifier si le nœud courant contient la valeur recherchée
        if (courant->value == val) {
            return true; //Valeur trouvée
        }

        //Ajouter les enfants gauche et droit à la file, s'ils existent
        if (courant->left) {
            file.push(courant->left);
        }
        if (courant->right) {
            file.push(courant->right);
        }
    }
    return false; // Valeur non trouvée
}

//Destructeur : libère la mémoire en parcourant l'arbre et en supprimant tous les nœuds
Tree::~Tree()
{
    queue<Tree*> file; //File pour parcourir l'arbre
    file.push(this);   //Ajouter la racine à la file

    while (!file.empty()) {
        Tree* courant = file.front(); //Extraire le nœud en tête
        file.pop();

        // Ajouter les enfants gauche et droit à la file avant de supprimer le nœud courant
        if (courant->left) {
            file.push(courant->left);
        }
        if (courant->right) {
            file.push(courant->right);
        }

        delete courant; //Supprimer le nœud courant
    }
}
