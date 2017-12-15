/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 3/12/2017
    copyright            : (C) 2017 par Joan Capell, Hua Yang
    e-mail               : joan.capell-gracia@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel

#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher(void) const{
    cout<<"de "<<depart<<" a "<<destination<<" en "<<transport;
}

const char * TrajetSimple::getDepart() const{
    return depart;
}

const char * TrajetSimple::getDestination() const{
    return destination;
}

TrajetSimple * TrajetSimple::Clone() const{
    return new TrajetSimple(*this);
}

const string TrajetSimple::toString() const {
    string dep(depart);
    string dest(destination);
    return "TS "+dep+" "+dest+" "+transport;

}

const string TrajetSimple::getTransport() const {
    string r(transport);
    return r;
}




//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur


/**
 * pour creer un trajet simple on fait une copie en profondeur
 * du nom de la ville de depart et destination
 * @param dep
 * @param dest
 * @param trans
 */
TrajetSimple::TrajetSimple(const char * dep, const char * dest, char * trans)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    //la longuer de la chaine depart est egal celle du nom passe plus 1
    //car on doit tenir en compte que il faut allour quelque parte la fin
    //de chaine (le caractere \0)
    depart = new char[LONGUEUR_VILLES];
    destination = new char[LONGUEUR_VILLES];
    transport = new char[LONGUEUR_TRANSPORT];
    strcpy(depart,dep);
    strcpy(destination,dest);
    strcpy(transport,trans);

} //----- Fin de TrajetSimple
TrajetSimple::TrajetSimple(const TrajetSimple &t){
    depart = new char[LONGUEUR_VILLES];
    destination = new char[LONGUEUR_VILLES];
    transport = new char[LONGUEUR_TRANSPORT];
    strcpy(depart,t.depart);
    strcpy(destination,t.destination);
    strcpy(transport,t.transport);
}

/**
 * il faut liberer du tas les chaines depart et destination
 */
TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete [] depart;
    delete [] destination;
    delete [] transport;
}




//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


