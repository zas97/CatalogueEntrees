/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 3/12/2017
    copyright            : (C) 2017 par Joan Capell, Hua Yang
    e-mail               : joan.capell-gracia@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H
#include "TabTrajets.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


/**
 * Catalogue contient une colection des trajets qui peuvent être simples ou composes
 * il permet recherché les possibles parcours d’une ville a une autre en utilisant différents trajets.
 */
class Catalogue : public TabTrajets
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    /**
     *
     * Recherche et affiche les combinaison de Trajets du catalogue pour
     * aller de depart a destination
     * @param depart nom ville de depart
     * @param destination nom ville de destination
     * @return nombre de posibles combinaisons des trajets pour aller de depart a destination
     */
    int Recherche(const char *depart, const char *destination) const;

    bool EcrireFichier(char * nomFichier) const;
    bool LectureFichier(char * nomFichier);


//-------------------------------------------- Constructeurs - destructeur
    /**
     * Constructeur de copie
     * il s'agit d'une copie en profondeur
     * donc un nouveau Catalogue est cree dans le tas
     * @param unCatalogue
     */
    Catalogue ( const Catalogue & unCatalogue );



    /**
     * Constructeur du Catalogue vide de taille t
     *
     * @param t taille
     * Contrat:
     *      t>0
     */
    Catalogue ( int t );



    /**
     * Destructeur de catalogue
     * les Trajets qui compose ce Trajet compose
     * vont être detruits aussi
     */
    virtual ~Catalogue ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    /**
     * methode utilise par le methode publique Recherche, on a besoin
     * de cet methode pour utiliser l'algorithme de la recursivité
     * @param depart
     * @param destination
     * @param utilise
     * @param parcours
     * @param index
     * @param count
     */
    void Recherche(const char *depart, const char *destination, bool *utilise, int *parcours, int index, int &count) const;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H

