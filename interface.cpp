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

static const string transports[] = {"Train","Auto","Bateau","Avion"};




/**
 * c'est methode permet à l'utilisateur de choisir un moyen de transport
 * dans la liste des moyens disponible
 * @return moyen de transport choisit
 */
string getTransport(){
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
        return transports[transport-1];
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
                char depart[LONGUEUR_VILLES];
                cin >> depart;
                cout << "ecrivez la ville de destination:" << endl;
                char destination[LONGUEUR_VILLES];
                cin >> destination;
                char transport[LONGUEUR_TRANSPORT];
                strcpy(transport,getTransport().c_str());
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
                char depart[LONGUEUR_VILLES];
                cin >> depart;
                bool premier = true;
                while(saisi) {
                    cout << "ecrivez la prochain ville de destination du trajet:" << endl;
                    if(!premier) cout<<"ecrivez -1 si vous avez deja saisi tout le trajet"<<endl;
                    char destination[50];
                    cin >> destination;
                    if(!premier && strcmp(destination,"-1")==0){
                        saisi=false;
                        break;
                    }
                    char transport[LONGUEUR_TRANSPORT];
                    strcpy(transport,getTransport().c_str());
                    tc.AjouterTrajet(depart, destination, transport);
                    strcpy(depart,destination);
                    premier = false;
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
                int ordre5;
                cout<<"ecrivez le nom du fichier que vous voulez charger"<<endl;
                char nom[50];
                cin>>nom;
                cout<<"choisir parmi ses 4 scenarios svp"<<endl;
                cout<<"1. je lis tout"<<endl;
                cout<<"2. je ne lis que de type trajet simple/composee"<<endl;
                cout<<"3. je lis les trajets avec depart ou destination specifiee"<<endl;
                cout<<"4. je lis les trajets des numero de ligne indiquees"<<endl;
                cout<<"tapez le numero de l'action que vous voulez realiser"<<endl;
                cin>>ordre5;
                switch(ordre5){
                    case 1:{
                        cout<<"tous les trajets:"<<endl;
                        cout<<" "<<endl;
                        cout<<(catalogue.LectureFichier1(nom) ? "lecture avec succes":"lecture echoue")<<endl;
                        cout<<" "<<endl;
                        break;//break case 5.1
                    }
                    case 2:{
                        int ordre52;
                        cout<<endl;
                        cout<<"1. je lis les trajets simples"<<endl;
                        cout<<"2. je lis les trajets composee"<<endl;
                        cout<<"tapez le numero de l'action que vous voulez realiser"<<endl;
                        cout<<endl;
                        cin>>ordre52;
                        switch(ordre52){
                            case 1:{
                                cout<<"tous les trajets simples:"<<endl;
                                cout<<" "<<endl;
                                cout<<(catalogue.LectureFichier21(nom) ? "lecture avec succes":"lecture echoue")<<endl;
                                cout<<" "<<endl;
                                break; //break case 5.2.1
                            }
                            case 2:{
                                cout<<"tous les trajets composees:"<<endl;
                                cout<<" "<<endl;
                                cout<<(catalogue.LectureFichier22(nom) ? "lecture avec succes":"lecture echoue")<<endl;
                                cout<<" "<<endl;
                                break; //break case 5.2.2
                            }
                        }
                        break;//break case 5.2
                    }
                    case 3:{
                        cout << "ecrivez la ville de depart et de destination,ecrivez une espace entre" << endl;
                        cout << " le depart et destination,si vous savez pas le depart ou la destination, mettez '00'"<<endl;
                        cout << "eg: 00 Paris ou Lyon 00"<<endl;
                        char depart[LONGUEUR_VILLES];
                        char destination[LONGUEUR_VILLES];
                        cin >> depart;
                        cin >> destination;
                        cout<<" "<<endl;
                        cout<<(catalogue.DepartDestination(depart,destination,nom) ? "lecture avec succes":"lecture echoue")<<endl;
                        cout<<" "<<endl;
                        break; //break 5.3
                    }
                    case 4:{
                        int a;
                        int b;
                        catalogue.LisSansAjout(nom);
                        cout<<"ecrivez une intervalle eg:1 2"<<endl;
                        cin>>a;
                        cin>>b;
                        if(a>=b) {
                            cout<<"l'intervalle n'est pas valide"<<endl;
                            break;
                        }
                        cout<<" "<<endl;
                        cout<<(catalogue.Intervalle(a,b,nom) ? "lecture avec succes":"lecture echoue")<<endl;
                        cout<<" "<<endl;
                        break;
                    }
                }
                break; //break de case 5
            }
            case 6:{
                cout<<endl;
                cout<<"ecrivez le chemin du fichier que vous voulez sauvagarde"<<endl;
                char nom[20];
                cin>>nom;
                cout<<endl;
                cout<<"vous voulez sauvegarde...?"<<endl;
                cout<<"1. Tous le trajets"<<endl;
                cout<<"2. Les trajets simples"<<endl;
                cout<<"3. Les trajets composes"<<endl;
                cout<<"4. Selon la ville de depart"<<endl;
                cout<<"5. Selon la ville d'arrive"<<endl;
                cout<<"6. Selon la ville de depart et arrive"<<endl;
                cout<<"7. Un interval des trajets"<<endl;
                int choix;
                cin>>choix;
                switch(choix){
                    case 1:{
                        catalogue.EcrireFichier(nom);
                        break;
                    }
                    case 2:{
                        catalogue.EcrireFichier(nom,true,false);
                        break;
                    }
                    case 3:{
                        catalogue.EcrireFichier(nom,false,true);
                        break;
                    }
                    case 4:{
                        cout<<"ecrivez la ville de depart"<<endl;
                        char depart[LONGUEUR_VILLES];
                        cin>>depart;
                        catalogue.EcrireFichier(nom,depart, true);
                        break;
                    }
                    case 5:{
                        cout<<"ecrivez la ville de destination"<<endl;
                        char destination[LONGUEUR_VILLES];
                        cin>>destination;
                        catalogue.EcrireFichier(nom,destination, false);
                        break;
                    }
                    case 6:{
                        cout<<"ecrivez la ville de depart"<<endl;
                        char depart[LONGUEUR_VILLES];
                        cin>>depart;
                        cout<<"ecrivez la ville de destination"<<endl;
                        char destination[LONGUEUR_VILLES];
                        cin>>destination;
                        catalogue.EcrireFichier(nom,depart,destination);
                        break;
                    }
                    case 7:{
                        cout<<"vous allez a sauvagarder les trajets entre l'interval [premier,dernier]"<<endl;
                        int premier;
                        cout<<"saisisez le premier trajet"<<endl;
                        cin>>premier;
                        int dernier;
                        cout<<"saisisez le dernier trajet"<<endl;
                        cin>>dernier;
                        catalogue.EcrireFichier(nom,premier,dernier);
                        break;
                    }
                    default:{
                        cout<<"l'option n'est pas dans la liste"<<endl;
                        break;
                    }
                }
                cout<<"fichier sauvagarde sous le nom: "<<nom<<endl;

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
