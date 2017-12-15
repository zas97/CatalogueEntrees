/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 3/12/2017
    copyright            : (C) 2017 par Joan Capell, Hua Yang
    e-mail               : joan.capell-gracia@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H

#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées
    //Trajet
//------------------------------------------------------------- Constantes
const int LONGUEUR_TRANSPORT = 10;
const int LONGUEUR_VILLES = 50;
//------------------------------------------------------------------ Types



/**
 * TrajetSimple qui contient
 * la ville de depart la ville d'arrive
 * et le moyen de transport
 */
class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


    /**
     * @return nom ville d'arrive
     */
    virtual const char * getDestination() const;



    /**
     *
     * @return nom ville de depart
     */
    virtual const char * getDepart() const;


    /**
     * affiche la ville de depart
     * la ville d'arrive
     * et le moyen de transport
     */
    virtual void Afficher() const;


    /**
     * creation d'une clone de TrajetSimple
     * @return pointeur vers le clone crée
     */
    virtual TrajetSimple * Clone() const;

    const string toString() const;

    virtual const string getTransport() const;



//-------------------------------------------- Constructeurs - destructeur

    /**
     * Constructeur du trajet simple
     * @param depart nom ville de depart
     * @param destination nom ville d'arrive
     * @param trans transport utilisé
     */
    TrajetSimple (const char * depart, const char * destination, char * trans);



    /**
     * Constructeur de TrajetSimple par copie
     * il s'agit d'une copie en profondeur
     * donc un nouveau TrajetSimple est ajouté
     * dans le tas
     * @param t TrajetSimple à copier
     */
    TrajetSimple(const TrajetSimple & t);



    /**
     * destructeur de TrajetSimple
     */
    virtual ~TrajetSimple ( );


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char * transport;
    char * destination;
    char * depart;


};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H

