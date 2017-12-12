#include <iostream>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TabTrajets.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
using namespace std;


void ajouterTrajets(Catalogue & catalogue){
    //TS1
    catalogue.AjouterTrajet("Lyon","Bordeaux",Train);

    //TC2
    char * departs[] = {"Lyon","Marseille"};
    char * destinations[] = {"Marseille","Paris"};
    crduTransport transports[] = {Bateau,Avion};
    catalogue.AjouterTrajet(departs,destinations,transports);
//    TrajetCompose tc(2);
//    tc.AjouterTrajet("Lyon","Marseille",Bateau);
//    tc.AjouterTrajet("Marseille","Paris",Avion);
//    catalogue.AjouterTrajet(tc);


    //TS3
    catalogue.AjouterTrajet("Lyon","Paris",Auto);


}

void ajouterTrajets2(Catalogue & catalogue){
    //TS1
    TrajetSimple ts1("Lyon","Bordeaux",Train);
    catalogue.AjouterTrajet(ts1);

    //TC2
    TrajetCompose tc(2);
    tc.AjouterTrajet("Lyon","Marseille",Bateau);
    tc.AjouterTrajet("Marseille","Paris",Avion);
    catalogue.AjouterTrajet(tc);


    //TS3
    TrajetSimple ts3("Lyon","Bordeaux",Train);
    catalogue.AjouterTrajet(ts3);

    catalogue.AjouterTrajet("Bordeaux","Paris",Train);
    Catalogue c2(catalogue);
    c2.Afficher();


}






int main() {
    Catalogue catalogue(1);
    catalogue.AjusterTaille(10);
    catalogue.AjusterTaille(-10);
    ajouterTrajets(catalogue);
    ajouterTrajets2(catalogue);
    catalogue.Afficher();
    catalogue.Recherche("Lyon","Paris");

}