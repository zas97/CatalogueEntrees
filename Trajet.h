/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 3/12/2017
    copyright            : (C) 2017 par Joan Capell, Hua Yang
    e-mail               : joan.capell-gracia@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( Trajet_H )
#define Trajet_H

#include <iostream>
using namespace std;

//--------------------------------------------------- Interfaces utilisées
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types

/**
 * interface mere de TrajetSimple et TrajetCompose
 * sert a permettre la insertion des types TrajetSimple
 * et TrajetCompose dans un même tableau
 */
class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


    virtual void Afficher() const = 0;
    virtual Trajet* Clone() const = 0;
    virtual const char * getDestination() const = 0;
    virtual const char * getDepart() const = 0;
    virtual const string toString() const = 0;
    virtual const string getTransport() const = 0;




//-------------------------------------------- Constructeurs - destructeur

    /**
     * constructeur de Trajet
     */
    Trajet ();

    /**
     * Destructeur de trajet
     */
    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés



};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H

