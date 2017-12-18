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


    /**
     * sauvegarde un catalogue a un fichier, par defaut les la variable simple et compose
     * sont tous vrai, dans ce cas la, il correspond au le cas qu'on sauvegarde tous les trajets
     * dans la catalogue. quand on appelle la fonction en precisant la variable simple est vrai,
     * on est dans le cas ou on sauvegarde tous les trajets simples, le meme pour la variable
     * compose.
     * @param simple   est vrai par defaut ou dans le cas ou on ne veut que les trajets simples
     * @param compose  est vrai par defaut ou dans le cas ou on ne veut que les trajets composes
     * @param nomFichier  le chemin du fichier
     */
    void EcrireFichier(char * nomFichier,bool simple = true,bool compose = true) const;


    /**
     * sauvegarde un catalogue a un fichier,  lire les trajets avec la numero qui est dans
     * une intervalle fermee.
     * @param premier  indique la borne inferieur de l'intervalle fermee
     * @param dernier  indique la borne superieur de l'intervalle fermee
     * @param nomFichier  le chemin du fichier
     */
    void EcrireFichier(char * nomFichier, int premier, int dernier) const;


    /**
     * sauvegarde un catalogue a un fichier, lire les trajets avec la depart ou destination specifiee
     * @param nomFichier  le chemin du fichier
     * @param ville  soit depart, soit destination specifiee
     * @param estDepart  indique la ville est depart ou pas
     */
    void EcrireFichier(char * nomFichier,char * ville, bool estDepart) const;


    /**
     * sauvegarde un catalogue a un fichier, lire les trajets avec le depart et la destination
     * specifiee en meme temps.
     * @param nomFichier  le chemin du fichier
     * @param dep  le depart specifiee
     * @param arrive  la destination specifiee
     */
    void EcrireFichier(char * nomFichier,char * dep, char * arrive) const;


    /**
     * afficher tous les trajets qui sont dans le catalogue
     * @param nomFichier le chemin du fichier
     */
    bool LisSansAjout(char* nomFichier) const;


    /**
     * charge un catalogue avec un fichier, lire tous les trajets
     */
    bool LectureFichier1(char * nomFichier);


    /**
     * charge un catalogue avec un fichier, lire tous les trajets simples
     * @param nomFichier  le chemin du fichier
     */
    bool LectureFichier21(char * nomFichier);


    /**
     * charge un catalogue avec un fichier, lire tous les trajets composes
     * @param nomFichier  le chemin du fichier
     */
    bool LectureFichier22(char * nomFichier);


    /**
     * charge un catalogue avec un fichier, lire les trajets avec le depart
     * ou/et la destination specifiee. quand l;utilisateur ne sait pas
     * le depart ou la destiantion, il va saisir "00".
     * @param nomFichier  le chemin du fichier
     * @param dep   le depart saisi par l'utilisateur,
     * @param dest  la destination saisi par l'utilisateur
     */
    bool DepartDestination(char* dep,char* dest,char* nomFichier);


    /**
     * charge un catalogue avec un fichier, lire tous les trajets qui
     * sont dans l'intervalle saisi par l'utilisateur
     * @param  a   la borne inferieur de l'intervalle
     * @param  b   la borne superieur de l'intervalle
     * @param nomFichier  le chemin du fichier
     */
    bool Intervalle(int a ,int b,char* nomFichier);


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