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
    cout<<"de "<<depart<<" a "<<destination<<" en "<<nomTransport(transport);
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
    return "TS "+dep+"-"+dest+" "+nomTransport(transport);

}

const string TrajetSimple::getTransport() const{
    return nomTransport(transport);
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
TrajetSimple::TrajetSimple(const char * dep, const char * dest, crduTransport trans)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    //la longuer de la chaine depart est egal celle du nom passe plus 1
    //car on doit tenir en compte que il faut allour quelque parte la fin
    //de chaine (le caractere \0)
    depart = new char[50];
    destination = new char[50];
    strcpy(depart,dep);
    strcpy(destination,dest);
    transport = trans;

} //----- Fin de TrajetSimple
TrajetSimple::TrajetSimple(const TrajetSimple &t){
    depart = new char[50];
    destination = new char[50];
    strcpy(depart,t.depart);
    strcpy(destination,t.destination);
    transport = t.transport;
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
}




//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
const string TrajetSimple::nomTransport(crduTransport transport) const {
    switch(transport){
        case Train:
            return "Train";
        case Auto:
            return "Auto";
        case Bateau:
            return "Bateau";
        case Avion:
            return "Avion";
        default:
            return "Error";
    }
}

