/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 3/12/2017
    copyright            : (C) 2017 par Joan Capell, Hua Yang
    e-mail               : joan.capell-gracia@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H
#include "Trajet.h"
#include "TabTrajets.h"
#include <iostream>
using namespace std;

//--------------------------------------------------- Interfaces utilisées
    //Trajet
    //TabTrajets
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types



/**
 * collection des trajets simples ou composés tels que
 * la ville de destination d'un trajet est la ville de
 * depart du trajet suivant
 */
class TrajetCompose : public Trajet, public TabTrajets
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    /**
     * Methode Afficher
     * ça affiche TC suivi par
     * la liste des trajets separés par une "-"
     */
    void Afficher() const;


    /**
     *
     * @return La ville de depart ud trajet compose
     */
    const char * getDepart() const;



    /**
     *
     * @return ville de destination du trajet compose
     */
    const char * getDestination() const;


    /**
     * Creation d'un clone de Trajet Compose
     * @return pointeur qui point vers le nouveau trajet compose cree
     */
    TrajetCompose * Clone() const;

    const string toString() const;

    const string getTransport() const;



//-------------------------------------------- Constructeurs - destructeur
    /**
     * Constructeur du trajet compose vide de taille t
     * @param t taille
     * constraintes:
     *      t>0
     */
    TrajetCompose (int t);



    /**
     * Constructeur d'un trajet compose
     * à partir d'un tableau de trajets
     * cet constructeur fait une copie de le
     * tableau des trajets reçu
     * @param tab tableau de trajets
     */
    TrajetCompose (const TabTrajets & tab);



    /**
     * Constructeur de copie de TrajetCompose
     * il s'agit d'une copie en profondeur
     * donc un nouveau trajet est cree dans le tas
     * @param t trajet compose à copier
     */
    TrajetCompose(const TrajetCompose & t);



    /**
     * destructeur de TrajetCompose
     * les Trajets qui compose ce Trajet compose
     * vont être detruits aussi
     */
    ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées




//----------------------------------------------------- Attributs protégés



};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H

