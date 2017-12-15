/*************************************************************************
                           TabTrajets  -  description
                             -------------------
    début                : 3/12/2017
    copyright            : (C) 2017 par Joan Capell, Hua Yang
    e-mail               : joan.capell-gracia@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TabTrajets> (fichier TabTrajets.h) ----------------
#if ! defined ( TabTrajets_H )
#define TabTrajets_H
#include <iostream>
using namespace std;

#include "Trajet.h"
#include "TrajetSimple.h"



//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

/**
 * declaration de la classe Trajet compose
 * pour indiquer à TabTrajets que TrajetCompose
 * existe. Il est pas posible de incluir TrajetCompose.h
 * parce que TrajetCompose inclu TabTrajets
 */
class TrajetCompose;


/**
 * Cette classe contient un tableau des trajets qui peuvent être
 * simples ou composes, tous ces methodes servent à realiser
 * des operations dans ce tableau, on peut:
 * -ajouter des trajets à partir de:
 *      -un trajet
 *      -une ville de depart et d'arrive (TrajetSimple)
 *      -une list de villes de depart et d'arrive (TrajetCompose)
 * -ajuster la taille du tableau
 * -obtenir un element du tableau
 */
class TabTrajets
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    /**
     * le methode fait une copie du trajet passe en parametre
     * et ajoute cette copie dans le tableau de trajets
     * si le tableau est plein il augmente la taille du tableau en 1
     * pour pouvoir ajouter le trajet
     * @param t trajet à ajouter
     * @return vrais si la taille du tableau a ete modifie pour ajouter
     *         faux si la taille n'a pas ete modifie
     */
    bool AjouterTrajet(const Trajet &t);




    /**
     * le methode cree un TrajetSimple et ajoute ce Trajet dans
     * le tableau de trajets si le tableau est plein
     * il augmente la taille du tableau en 1 pour pouvoir ajouter le trajet
     * @param depart nom ville de depart
     * @param destination nom de la ville de arrive
     * @param transport transport utilise
     * @return vrais si la taille du tableau a ete modifie pour ajouter
     *         faux si la taille n'a pas ete modifie
     */
    bool AjouterTrajet(char *depart, char *destination, char *transport);




    /**
     * le methode cree un TrajetCompose
     * forme par des Trajets simples et ajoute ce Trajet dans
     * le tableau de trajets si le tableau est plein
     * il augmente la taille du tableau en 1pour pouvoir ajouter le trajet
     * contraintes:
     *          le nombre d'elements de departs destinations et transport
     *          doit etre egal
     * @param departs liste de villes de depart
     * @param destinations liste de villes d'arrive
     * @param transports liste des transports
     * @return vrais si la taille du tableau a ete modifie pour ajouter
     *         faux si la taille n'a pas ete modifie
     *
     */
    bool AjouterTrajet(char **villes,  char **transports, const int nbElements);


    /**
     * contraintes:
     *          pos < taille
     * @param pos position element renvoyer
     * @return element du tableau situe en @pos
     */
    Trajet * getElement(int pos) const;



    /**
     * @return taille du tableau
     */
    int getTaille() const;


    /**
     * affiche chaque element du tableau separe par une saute de ligne
     */
    virtual void Afficher() const;

    /**
     *
     * @return nombre de cases ocupes dans le tableau
     */
    int getNelements() const;


    /**
     * ajuste la taille du tableau à taille+delta
     * il fait rien en cas de que delta <0 et l'ajustement
     * du tableau suppose la supresion des elements
     * @param delta
     * @return vrais si l'ajustement a ete fait
     *         faux si l'ajustament n'a pas ete fait
     */
    bool AjusterTaille(int delta);

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

    /**
     * constructeur par copie, il fait un copie de chaque
     * element de tabTrajets et il l'alloue dans la copie de
     * tabTrajets
     * @param tab TabTrajets aà copier
     */
    TabTrajets(const TabTrajets & tab);


    /**
     * Constructeur de TabTrajets de taille t
     * @param t taille
     */
    TabTrajets ( int t );

    /**
     * destructeur de TabTrajet
     * les Trajets contenus dans tabTrajet vont être detruits aussi
     */
    virtual ~TabTrajets ( );




//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées


//----------------------------------------------------- Attributs protégés
    //nombre de cases totales dans le tableau
    int taille;
    //tableau de pointeurs de type trajet
    Trajet ** tabTrajets;
    //nombre de cases occupes dans le trajet
    int nElements;

};

//-------------------------------- Autres définitions dépendantes de <TabTrajets>

#endif // TabTrajets_H

