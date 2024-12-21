#include "Tree.h"

//Constructeur
Tree::Tree(int val):value(val),left(nullptr),right(nullptr)
{
}

//Insertion
void Tree::inserer(int val)
{
    queue<Tree*> file;
    file.push(this); 

    
    while (!file.empty()) {
        Tree* courant = file.front();
        file.pop();

        
        if (!courant->left) {
            courant->left = new Tree(val);
            return;
        }
        
        else {
            file.push(courant->left);
        }

        
        if (!courant->right) {
            courant->right = new Tree(val);
            return;
        }
        
        else {
            file.push(courant->right);
        }
    }
}

//Affichage
void Tree::afficherEnLargeur()
{
    if (!this) return;

    queue<Tree*> file;
    file.push(this);

    while (!file.empty()) {
        Tree* courant = file.front();
        file.pop();

        cout << courant->value << " ";

        if (courant->left) {
            file.push(courant->left);
        }
        if (courant->right) {
            file.push(courant->right);
        }
    }
}

//Recherche
bool Tree::Rechercher(int val)
{
    if (this == nullptr) {
        return false;
    }

    queue<Tree*> file; 
    file.push(this);    

    while (!file.empty()) {
        
        Tree* courant = file.front();
        file.pop();
        if (courant->value == val) {
            return true; 
        }

        if (courant->left) {
            file.push(courant->left);
        }
        if (courant->right) {
            file.push(courant->right);
        }
    }
    return false;

}

//Destructeur
Tree::~Tree() 
{
    queue<Tree*> file;
    file.push(this);

    while (!file.empty()) 
    {
        Tree* courant = file.front();
        file.pop();

        
        if (courant->left) 
        {
            file.push(courant->left);
        }
        if (courant->right) 
        {
            file.push(courant->right);
        }

        
        delete courant;
    }
}

