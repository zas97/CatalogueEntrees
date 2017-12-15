/*************************************************************************
                           TabTrajets  -  description
                             -------------------
    début                : 3/12/2017
    copyright            : (C) 2017 par Joan Capell, Hua Yang
    e-mail               : joan.capell-gracia@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TabTrajets> (fichier TabTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TabTrajets.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
/**
 * ajoute UNE COPIE du trajet passe en parametre
 * @param t trajet a ajouter
 * @return vrais: modification de taille lors l'ajoute
 *         faux: pas de modification de taill
 */
bool TabTrajets::AjouterTrajet(const Trajet &t)
{
    bool ajuste = false;
    if(nElements >= taille){
        AjusterTaille(1);
        ajuste=true;
    }
    //clone realise la copie et on l'ajoute au tableau
    tabTrajets[nElements] = t.Clone();
    ++nElements;
    return ajuste;
}

bool TabTrajets::AjouterTrajet(char *depart, char *destination, char *transport)
{
    bool ajuste = false;
    if(nElements >= taille){
        AjusterTaille(1);
        ajuste=true;
    }
    tabTrajets[nElements] = new TrajetSimple(depart,destination,transport);
    ++nElements;
    return ajuste;

}

bool TabTrajets::AjouterTrajet(char **villes,  char ** transports, const int nbElements)
{
    bool ajuste = false;
    if(nElements >= taille){
        AjusterTaille(1);
        ajuste=true;
    }

    //on cree le nouveau trajet compose
    TrajetCompose * tc = new TrajetCompose(nbElements);
    //on lui ajoute les trajets simples descrits par les parametres
    for(int i=0;i<nbElements;i++){
        tc->AjouterTrajet(villes[i], villes[i+1], transports[i]);
    }

    //on l'ajout au tableau
    tabTrajets[nElements] = tc;
    ++nElements;
    return ajuste;

}


int TabTrajets::getNelements() const
{
    return nElements;
}




int TabTrajets::getTaille() const
{
    return taille;
}

bool TabTrajets::AjusterTaille(int delta)
{
    //cas ou on devrait suprimer des elements pour ajuster la taille
    if(delta + taille < nElements)
        return false;

    taille += delta;
    //on fait un nouveau tableau avec la nouveau taille
    Trajet ** newTab = new Trajet* [taille];
    //on passe les elements du vieille tableau au nouveau
    for(int i=0;i<nElements;i++){
        newTab[i] = tabTrajets[i];
    }

    Trajet ** aux = tabTrajets;
    tabTrajets = newTab;
    //on suprime le vieille tableau
    delete [] aux;
    return true;
}

void TabTrajets::Afficher() const
{
    for(int i=0;i<nElements;i++)
    {
        cout<<i+1<<" : ";
        tabTrajets[i]->Afficher();
        cout<<endl;
    }
}



Trajet * TabTrajets::getElement(int pos) const
{
    return tabTrajets[pos];
}


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur



TabTrajets::TabTrajets (int t ) : taille(t)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TabTrajets>" << endl;
#endif
    tabTrajets = new Trajet * [taille];
    nElements = 0;
} //----- Fin de TabTrajets

TabTrajets::TabTrajets (const TabTrajets & tab){
    taille = tab.taille;
    nElements = 0;
    tabTrajets = new Trajet * [taille];
    //copie en profondeur donc on doit copie
    //chaqun des elements dans TabTrajets
    for(int i=0;i<tab.nElements;i++){
        AjouterTrajet(*tab.tabTrajets[i]);
    }

}
/**
 * dans le destructeur il faut suprimer tous les elements
 * pointes par le tableau, car on les a ajouté en faisant des copies
 * et suprime le tableau
 */
TabTrajets::~TabTrajets ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TabTrajets>" << endl;
#endif
    for(int i=0;i<nElements;i++){
        delete tabTrajets[i];
    }
    delete [] tabTrajets;
} //----- Fin de ~TabTrajets


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

