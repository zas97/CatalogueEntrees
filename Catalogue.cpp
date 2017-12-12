/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 3/12/2017
    copyright            : (C) 2017 par Joan Capell, Hua Yang
    e-mail               : joan.capell-gracia@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "cstring"
#include <fstream>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Catalogue::EcrireFichier(char * nomFichier) const{
    ofstream fichier(nomFichier);
    for(int i=0;i<nElements;i++){
        fichier << tabTrajets[i]->toString()<<"\n";
    }
    fichier.close();
}

bool Catalogue::LectureFichier(char * nomFichier){

}

/**
 * utilise la recursivite pour trouver le parcours posibles
 * @param depart
 * @param destination
 * @return nb de parcours trouves
 */
int Catalogue::Recherche(const char *depart, const char *destination) const
{
    //d'abord il cree un tableau de bool qui va servir à eviter qu'un parcours
    //utilise deux fois le même trajet
    bool * utilise = new bool[nElements];
    for(int i=0;i<nElements;i++){
        utilise[i]=false;
    }
    //parcours garde la liste de trajets utilises pendant que le parcours est
    //en train d'etre constuit
    int * parcours = new int[nElements];
    //variable passer par refereance pour compter les nb de parcours trouvees
    int count = 0;
    Recherche(depart, destination, utilise, parcours, 0, count);
    cout<<endl;
    delete [] parcours;
    delete [] utilise;
    return count;
}
/**
 * l'algorithme "realise" chaque trajet qui commence par depart, ensuite il
 * cherche d'aller de la ville de d'arrive de ce trajet à la ville de destination
 * @param depart
 * @param destination
 * @param utilise tableau de booleans avec les trajets deja utilises
 * @param parcours parcours suivi
 * @param index pour gerer ou ajouter les trajets au parcours
 * @param count nb de parcours trouves
 */
void Catalogue::Recherche(const char *depart, const char *destination, bool *utilise, int *parcours, int index,
                          int &count) const
{
    //depart=destination
    //ça veut dire qu'on est deja arrive donc
    //on peut afficher le parcours qu'on a suivi
    if(strcmp(depart,destination)==0){
        ++count;
        cout<<"(";
        for(int i=0;i<index-1;i++){
            cout<<"T"<<parcours[i]<<"+";
        }
        cout<<"T"<<parcours[index-1]<<") ";
        return;
    }
    //si le trajet n'a pas ete utilise dans la parcours
    //la ville de depart est pareil a celle de depart du trajet
    //on realise le trajet (on l'ajoute au parcours et on le marque comme utilise)
    //et on recherche de la destiantion du trajet a la destination final
    for(int i=0;i<nElements;i++){
        if(!utilise[i]){
            if(strcmp(depart,tabTrajets[i]->getDepart())==0){
                utilise[i]=true;
                parcours[index]=i+1;
                Recherche(tabTrajets[i]->getDestination(), destination, utilise, parcours, index + 1, count);
                utilise[i]=false;
            }
        }
    }
}

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
/**
 * constructeur de copie
 * il s'agit d'une copie en profondeur donc
 * il faut creer une copie de chaque element de du catalogue
 * @param unCatalogue
 */
Catalogue::Catalogue ( const Catalogue & unCatalogue ) : TabTrajets(unCatalogue)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif

} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue (int t) : TabTrajets(t)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

