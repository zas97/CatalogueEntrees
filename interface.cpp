/*************************************************************************
                           interface.cpp (main)
interface qui permet à l'utilisateur cree un Catalogue, ajouter des
trajets et rechercher de parcours, il s'agit d'une interface qui est
controle avec la terminal, l'utilisateur saisi des chiffre pour choisir
les differents options du menu
                             -------------------
    début                : 3/12/2017
    copyright            : (C) 2017 par Joan Capell, Hua Yang
    e-mail               : joan.capell-gracia@insa-lyon.fr
*************************************************************************/
#include <iostream>
#include <cstring>
#include "Catalogue.h"
#include "TrajetCompose.h"

using namespace std;






/**
 * c'est methode permet à l'utilisateur de choisir un moyen de transport
 * dans la liste des moyens disponible
 * @return moyen de transport choisit
 */
crduTransport getTransport(){
    //il demande de nouveau le trajet si l'utilisateur
    //ne saisit pas correctement
    while(true) {
        cout << "1: Train" << endl;
        cout << "2: Auto" << endl;
        cout << "3: Bateau" << endl;
        cout << "4: Avion" << endl;
        cout << "Choisisez un transport" << endl;
        int transport;
        cin >> transport;
        if(transport < 1 || transport > 4){
            cout<<"transport invalide"<<endl;
            cout<<"s'il vous plait, choisisez un transport de la liste"<<endl;
            continue;
        }
        return static_cast<crduTransport > (transport-1);
    }


}



int main(){

    Catalogue catalogue(100);
    //l'utilisateur choisi c'est qu'il veut faire avec le catalogue
    int ordre;
    cout<<"1: ajouter un trajet simple"<<endl;
    cout<<"2: ajouter un trajet compose"<<endl;
    cout<<"3: Afficher la liste de trajets"<<endl;
    cout<<"4: rechercher un parcours"<<endl;
    cout<<"5: chargement d'un catalogue"<<endl;
    cout<<"6: sauvagarde du catalogue"<<endl;
    cout<<"tapez le numero de l'action que vous voulez realiser, tapez -1 pour sortir"<<endl;
    while(cin>>ordre && ordre !=-1){
        switch(ordre){
            //ajouter un trajet simple
            case 1 : {
                cout << "ecrivez la ville de depart:" << endl;
                char depart[50];
                cin >> depart;
                cout << "ecrivez la ville de destination:" << endl;
                char destination[50];
                cin >> destination;
                crduTransport transport = getTransport();
                catalogue.AjouterTrajet(depart, destination, transport);
                cout<<endl;
                break;
            }
            //ajouter un trajet compose
            case 2 : {

                TrajetCompose tc(5);
                bool saisi = true;
                int nTrajets = 0;
                cout << "ecrivez la ville de depart du trajet:" << endl;
                char depart[50];
                cin >> depart;
                while(saisi) {
                    cout << "ecrivez la ville de destination du trajet:" << endl;
                    cout<<"ecrivez -1 si vous voulez arreter la saisi"<<endl;
                    char destination[50];
                    cin >> destination;
                    if(strcmp(destination,"-1")==0){
                        saisi=false;
                        break;
                    }
                    crduTransport transport = getTransport();
                    tc.AjouterTrajet(depart, destination, transport);
                    strcpy(depart,destination);
                }
                catalogue.AjouterTrajet(tc);
                break;
            }
            //afficher ce qu'il y a dans le catalogue
            case 3: {
                cout << "le catalogue contient:" << endl;
                catalogue.Afficher();
                cout<<endl;
                break;
            }
            //rechercher un parcours entre de villes

            case 4: {
                //il realise pas de recherche si le catalogue est plein
                if(catalogue.getNelements()==0){
                    cout<<"Il y a pas des trajets"<<endl;
                    break;
                }
                cout << "ecrivez la ville de depart du parcours:" << endl;
                char depart[50];
                cin >> depart;
                cout << "ecrivez la ville de destination du parcours:" << endl;
                char destination[50];
                cin >> destination;
                cout << "avec les les trajets disponibles:" << endl;
                catalogue.Afficher();
                cout << "vous pouvez aller de " << depart << " a " << destination << " avec:"<<endl;
                catalogue.Recherche(depart,destination);
                cout<<endl;

                break;
            }
            case 5:{
                cout<<"ecrivez le nom du fichier que vous voulez charger"<<endl;
                char nom[20];
                cin>>nom;
                break;
            }
            case 6:{
                cout<<"ecrivez le nom du fichier que vous voulez sauvagarde"<<endl;
//                char nom[20];
//                cin>>nom;
                char nom[] = "test.txt";
                catalogue.EcrireFichier(nom);
                break;
            }
            //en cas ou l'utilisateur saisit un numero qui est pas dans la liste
            default :{
                cout<<"s'il tu plait, selectione un ordre dans la liste"<<endl;
                cout<<endl;
                break;
            }


        }
        cout<<"1: ajouter un trajet simple"<<endl;
        cout<<"2: ajouter un trajet compose"<<endl;
        cout<<"3: Afficher la liste de trajets"<<endl;
        cout<<"4: rechercher un parcours"<<endl;
        cout<<"5: chargement d'un catalogue"<<endl;
        cout<<"6: sauvagarde du catalogue"<<endl;
        cout<<"tapez le numero de l'action que vous voulez realiser"<<endl;

    }

}