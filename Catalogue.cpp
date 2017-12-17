/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 3/12/2017
    copyright            : (C) 2017 par Joan Capell, Hua Yang
    e-mail               : joan.capell-gracia@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "cstring"
#include <fstream>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Catalogue::LisSansAjout(char * nomFichier) const{
    cout<<" "<<endl;
    ifstream fichier;
    fichier.open(nomFichier);
    if(!fichier){
        return false;
    }
    int it=0;
    while(!fichier.eof()){
        cout<<it+1<<'.'<<' ';
        ++it;
        string type;
        fichier >> type;
        if(type == "TS"){
            char depart[LONGUEUR_VILLES];
            char destination[LONGUEUR_VILLES];
            char transport[LONGUEUR_TRANSPORT];
            fichier >> depart;
            fichier >> destination;
            fichier >> transport;
            cout<<depart<<" ";
            cout<<destination<<" ";
            cout<<transport<<" ";
        }
        else if(type == "TC"){
            int nTrajets;
            fichier >> nTrajets;
            cout<<nTrajets<<" ";
            char ** villes = new char * [nTrajets+1];
            char ** transports = new char * [nTrajets];
            for(int i=0;i<nTrajets+1;i++){
                villes[i] = new char [LONGUEUR_VILLES];
                fichier >> villes[i];
                cout<<villes[i]<<" ";
            }
            for(int i=0;i<nTrajets;i++){
                transports[i] = new char[LONGUEUR_TRANSPORT];
                fichier >> transports[i];
                cout<<transports[i]<<" ";
            }

            //destructeurs
            for(int i=0;i<nTrajets+1;i++){
                delete [] villes[i];
            }
            for(int i=0;i<nTrajets;i++){
                delete [] transports[i];
            }
            delete [] transports;
            delete [] villes;

        }
        cout<<endl;
    }
    return true;
}

bool Catalogue::LectureFichier1(char * nomFichier){
    ifstream fichier;
    fichier.open(nomFichier);
    if(!fichier){
        return false;
    }
    int it=0;
    while(!fichier.eof()){
        cout<<it+1<<"."<<" ";
        ++it;
        string type;
        fichier >> type;
        cout<<type<<" ";
        if(type == "TS"){
            char depart[LONGUEUR_VILLES];
            char destination[LONGUEUR_VILLES];
            char transport[LONGUEUR_TRANSPORT];
            fichier >> depart;
            cout<<depart<<" ";
            fichier >> destination;
            cout<<destination<<" ";
            fichier >> transport;
            cout<<transport<<" ";

            AjouterTrajet(depart,destination,transport);
        }
        else if(type == "TC"){
            int nTrajets;
            fichier >> nTrajets;
            char ** villes = new char * [nTrajets+1];
            char ** transports = new char * [nTrajets];
            for(int i=0;i<nTrajets+1;i++){
                villes[i] = new char [LONGUEUR_VILLES];
                fichier >> villes[i];
                cout<<villes[i]<<" ";
            }
            for(int i=0;i<nTrajets;i++){
                transports[i] = new char[LONGUEUR_TRANSPORT];
                fichier >> transports[i];
                cout<<transports[i]<<" ";
            }
            AjouterTrajet(villes,transports,nTrajets);

            //destructeurs
            for(int i=0;i<nTrajets+1;i++){
                delete [] villes[i];
            }
            for(int i=0;i<nTrajets;i++){
                delete [] transports[i];
            }
            delete [] transports;
            delete [] villes;

        }
        cout<<endl;
    }
    return true;
}

bool Catalogue::LectureFichier21(char * nomFichier){
    ifstream fichier;
    fichier.open(nomFichier);
    if(!fichier){
        return false;
    }

    int it=0;
    while(!fichier.eof()){

        string type;
        fichier >> type;

        if(type == "TS"){
            it++;
            cout<<it<<"."<<" ";
            cout<<type<<" ";

            char depart[LONGUEUR_VILLES];
            char destination[LONGUEUR_VILLES];
            char transport[LONGUEUR_TRANSPORT];
            fichier >> depart;
            cout<<depart<<" ";
            fichier >> destination;
            cout<<destination<<" ";
            fichier >> transport;
            cout<<transport<<" ";
            AjouterTrajet(depart,destination,transport);
            cout<<endl;
        }
        else if(type == "TC"){
            int nTrajets;
            fichier >> nTrajets;
            char ** villes = new char * [nTrajets+1];
            char ** transports = new char * [nTrajets];
            for(int i=0;i<nTrajets+1;i++){
                villes[i] = new char [LONGUEUR_VILLES];
                fichier >> villes[i];
            }
            for(int i=0;i<nTrajets;i++){
                transports[i] = new char[LONGUEUR_TRANSPORT];
                fichier >> transports[i];
            }
            //destructeurs
            for(int i=0;i<nTrajets+1;i++){
                delete [] villes[i];
            }
            for(int i=0;i<nTrajets;i++){
                delete [] transports[i];
            }
            delete [] transports;
            delete [] villes;

        }

    }
    return true;
}

bool Catalogue::LectureFichier22(char * nomFichier){
    ifstream fichier;
    fichier.open(nomFichier);
    if(!fichier){
        return false;
    }
    int it=0;
    while(!fichier.eof()){

        string type;
        fichier >> type;
        if(type == "TS"){
            char depart[LONGUEUR_VILLES];
            char destination[LONGUEUR_VILLES];
            char transport[LONGUEUR_TRANSPORT];
            fichier >> depart;
            fichier >> destination;
            fichier >> transport;
        }
        else if(type == "TC"){
            it++;
            cout<<it<<"."<<" ";
            cout<<type<<" ";
            int nTrajets;
            fichier >> nTrajets;
            cout<<nTrajets<<" ";
            char ** villes = new char * [nTrajets+1];
            char ** transports = new char * [nTrajets];
            for(int i=0;i<nTrajets+1;i++){
                villes[i] = new char [LONGUEUR_VILLES];
                fichier >> villes[i];
                cout<<villes[i]<<" ";
            }
            for(int i=0;i<nTrajets;i++){
                transports[i] = new char[LONGUEUR_TRANSPORT];
                fichier >> transports[i];
                cout<<transports[i]<<" ";
            }
            AjouterTrajet(villes,transports,nTrajets);
            //destructeurs
            for(int i=0;i<nTrajets+1;i++){
                delete [] villes[i];
            }
            for(int i=0;i<nTrajets;i++){
                delete [] transports[i];
            }
            delete [] transports;
            delete [] villes;
            cout<<endl;
        }

    }
    return true;
}

bool Catalogue::DepartDestination(char* dep,char* dest,char* nomFichier){
    ifstream fichier;
    fichier.open(nomFichier);
    if((strcmp(dep,"00")==0)&&(strcmp(dest,"00")==0)){
        return false;

    }else if(strcmp(dep,"00")==0){
        int tCount = 0;
        while(!fichier.eof()){
            string type;
            fichier >> type;

            if(type == "TS"){

                char depart[LONGUEUR_VILLES];
                char destination[LONGUEUR_VILLES];
                char transport[LONGUEUR_TRANSPORT];
                fichier >> depart;
                fichier >> destination;
                fichier >> transport;
                if(strcmp(dest,destination)==0){
                    tCount++;
                    AjouterTrajet(depart,destination,transport);
                    cout<<tCount<<'.'<<"TS"<<' '<<depart<<' '<<destination<<' '<<transport<<endl;
                }
            }
            else if(type == "TC"){
                int nTrajets;
                fichier >> nTrajets;
                char ** villes = new char * [nTrajets+1];
                char ** transports = new char * [nTrajets];
                for(int i=0;i<nTrajets+1;i++){
                    villes[i] = new char [LONGUEUR_VILLES];
                    fichier >> villes[i];
                }
                for(int i=0;i<nTrajets;i++){
                    transports[i] = new char[LONGUEUR_TRANSPORT];
                    fichier >> transports[i];
                }
                if(strcmp(villes[nTrajets],dest)==0){
                    tCount++;
                    AjouterTrajet(villes,transports,nTrajets);
                    cout<<tCount<<'.'<<"TC"<<' ';
                    for(int i = 0;i<nTrajets+1;i++){
                        cout<<villes[i]<<' ';
                    }
                    for(int i = 0;i<nTrajets;i++){
                        cout<<transports[i]<<' ';
                    }
                    cout<<endl;
                }
                //destructeurs
                for(int i=0;i<nTrajets+1;i++){
                    delete [] villes[i];
                }
                for(int i=0;i<nTrajets;i++){
                    delete [] transports[i];
                }
                delete [] transports;
                delete [] villes;
                cout<<endl;
            }

        }
    }else if((strcmp(dep,"00")!=0)&&(strcmp(dest,"00")!=0)){
        int tCount = 0;
        while(!fichier.eof()){

            string type;
            fichier >> type;

            if(type == "TS"){

                char depart[LONGUEUR_VILLES];
                char destination[LONGUEUR_VILLES];
                char transport[LONGUEUR_TRANSPORT];
                fichier >> depart;
                fichier >> destination;
                fichier >> transport;
                if((strcmp(dep,depart)==0)&&(strcmp(dest,destination)==0)){
                    tCount++;
                    AjouterTrajet(depart,destination,transport);
                    cout<<tCount<<'.'<<"TS"<<' '<<depart<<' '<<destination<<' '<<transport<<endl;
                }
            }
            else if(type == "TC"){
                int nTrajets;
                fichier >> nTrajets;
                char ** villes = new char * [nTrajets+1];
                char ** transports = new char * [nTrajets];
                for(int i=0;i<nTrajets+1;i++){
                    villes[i] = new char [LONGUEUR_VILLES];
                    fichier >> villes[i];
                }
                for(int i=0;i<nTrajets;i++){
                    transports[i] = new char[LONGUEUR_TRANSPORT];
                    fichier >> transports[i];
                }
                if((strcmp(villes[0],dep)==0)&&(strcmp(villes[nTrajets],dest)==0)){
                    tCount++;
                    AjouterTrajet(villes,transports,nTrajets);
                    cout<<tCount<<'.'<<"TC"<<' ';
                    for(int i = 0;i<nTrajets+1;i++){
                        cout<<villes[i]<<' ';
                    }
                    for(int i = 0;i<nTrajets;i++){
                        cout<<transports[i]<<' ';
                    }
                    cout<<endl;
                }
                //destructeurs
                for(int i=0;i<nTrajets+1;i++){
                    delete [] villes[i];
                }
                for(int i=0;i<nTrajets;i++){
                    delete [] transports[i];
                }
                delete [] transports;
                delete [] villes;
                cout<<endl;
            }

        }
    }else if((strcmp(dest,"00")==0)){
        int tCount = 0;
        while(!fichier.eof()){
            string type;
            fichier >> type;

            if(type == "TS"){

                char depart[LONGUEUR_VILLES];
                char destination[LONGUEUR_VILLES];
                char transport[LONGUEUR_TRANSPORT];
                fichier >> depart;
                fichier >> destination;
                fichier >> transport;
                if(strcmp(dep,depart)==0){
                    tCount++;
                    AjouterTrajet(depart,destination,transport);
                    cout<<tCount<<'.'<<"TS"<<' '<<depart<<' '<<destination<<' '<<transport<<endl;
                }
            }
            else if(type == "TC"){
                int nTrajets;
                fichier >> nTrajets;
                char ** villes = new char * [nTrajets+1];
                char ** transports = new char * [nTrajets];
                for(int i=0;i<nTrajets+1;i++){
                    villes[i] = new char [LONGUEUR_VILLES];
                    fichier >> villes[i];
                }
                for(int i=0;i<nTrajets;i++){
                    transports[i] = new char[LONGUEUR_TRANSPORT];
                    fichier >> transports[i];
                }
                if(strcmp(villes[0],dep)==0){
                    tCount++;
                    AjouterTrajet(villes,transports,nTrajets);
                    cout<<tCount<<'.'<<"TC"<<' ';
                    for(int i = 0;i<nTrajets+1;i++){
                        cout<<villes[i]<<' ';
                    }
                    for(int i = 0;i<nTrajets;i++){
                        cout<<transports[i]<<' ';
                    }
                    cout<<endl;
                }
                //destructeurs
                for(int i=0;i<nTrajets+1;i++){
                    delete [] villes[i];
                }
                for(int i=0;i<nTrajets;i++){
                    delete [] transports[i];
                }
                delete [] transports;
                delete [] villes;
                cout<<endl;
            }

        }
    }

    return true;
}

bool Catalogue::Intervalle(int a,int b,char* nomFichier){
    ifstream fichier;
    fichier.open(nomFichier);
    if(!fichier){
        return false;
    }

    int tCounter = 0;
    int tCount = 0;
    while(!fichier.eof()){

        string type;
        fichier >> type;

        if(type == "TS"){
            tCounter++;
            char depart[LONGUEUR_VILLES];
            char destination[LONGUEUR_VILLES];
            char transport[LONGUEUR_TRANSPORT];
            fichier >> depart;

            fichier >> destination;

            fichier >> transport;

            if((tCounter<=b)&&(tCounter>=a)){
                tCount++;
                AjouterTrajet(depart,destination,transport);
                cout<<tCount<<'.'<<"TS"<<' '<<depart<<' '<<destination<<' '<<transport<<endl;
            }
        }
        else if(type == "TC"){
            tCounter++;
            int nTrajets;
            fichier >> nTrajets;
            char ** villes = new char * [nTrajets+1];
            char ** transports = new char * [nTrajets];
            for(int i=0;i<nTrajets+1;i++){
                villes[i] = new char [LONGUEUR_VILLES];
                fichier >> villes[i];
            }
            for(int i=0;i<nTrajets;i++){
                transports[i] = new char[LONGUEUR_TRANSPORT];
                fichier >> transports[i];
            }
            if((tCounter<=b)&&(tCounter>=a)){
                tCount++;
                AjouterTrajet(villes,transports,nTrajets);
                cout<<tCount<<'.'<<"TC"<<' ';
                for(int i = 0;i<nTrajets+1;i++){
                    cout<<villes[i]<<' ';
                }
                for(int i = 0;i<nTrajets;i++){
                    cout<<transports[i]<<' ';
                }
                cout<<endl;
            }
            //destructeurs
            for(int i=0;i<nTrajets+1;i++){
                delete [] villes[i];
            }
            for(int i=0;i<nTrajets;i++){
                delete [] transports[i];
            }
            delete [] transports;
            delete [] villes;

        }
    }
    return true;
}

void Catalogue::EcrireFichier(char * nomFichier,bool simple,bool compose) const{
    ofstream fichier(nomFichier);
    bool first = true;
    for(int i=0;i<nElements;i++){
        if(simple && compose) {
            if(!first) {
                fichier << "\n";
            }
            first = false;
            fichier << tabTrajets[i]->toString();
        }
        else if(simple){
            string trajet = tabTrajets[i]->toString();
            if(trajet[1]=='S') {
                if(!first) {
                    fichier << "\n";
                }
                first = false;
                fichier << tabTrajets[i]->toString();
            }
        }
        else{
            string trajet = tabTrajets[i]->toString();

            if(trajet[1]=='C') {
                if(!first) {
                    fichier << "\n";
                }
                fichier << tabTrajets[i]->toString();
                first = false;
            }
        }
    }
    fichier.close();
}
void Catalogue::EcrireFichier(char * nomFichier, int premier, int dernier) const{
    ofstream fichier(nomFichier);
    if(premier < 0 or premier >= nElements or premier > dernier){
        cerr<<"intervall dehors catalogue"<<endl;
        fichier.close();
        return;
    }
    if(dernier < 0 or dernier >= nElements){
        cerr<<"intervall dehors catalogue"<<endl;
        fichier.close();
        return;
    }

    bool first = true;
    for(int i=premier-1;i<=dernier-1;i++){
        if(!first) {
            fichier << "\n";
        }
        first = false;
        fichier << tabTrajets[i]->toString();
    }
    fichier.close();
}
void Catalogue::EcrireFichier(char * nomFichier,char * ville, bool estDepart) const{
    ofstream fichier(nomFichier);
    bool first = true;
    for(int i=0;i<nElements;i++){
        if(estDepart && strcmp(ville,tabTrajets[i]->getDepart()) == 0){
            if(!first) {
                fichier << "\n";
            }
            first = false;
            fichier << tabTrajets[i]->toString();
        }
        if(!estDepart && strcmp(ville,tabTrajets[i]->getDestination()) == 0){
            if(!first) {
                fichier << "\n";
            }
            first = false;
            fichier << tabTrajets[i]->toString();
        }
    }
    fichier.close();

}
void Catalogue::EcrireFichier(char * nomFichier,char * depart, char * destination) const{
    ofstream fichier(nomFichier);
    bool first = true;
    for(int i=0;i<nElements;i++){
        if(strcmp(destination,tabTrajets[i]->getDestination()) == 0 && strcmp(depart,tabTrajets[i]->getDepart()) == 0){
            if(!first) {
                fichier << "\n";
            }
            first = false;
            fichier << tabTrajets[i]->toString();
        }
    }
    fichier.close();

}



/**
 * utilise la recursivite pour trouver le parcours posibles
 * @param depart
 * @param destination
 * @return nb de parcours trouves
 */
int Catalogue::Recherche(const char *depart, const char *destination) const
{
    //d'abord il cree un tableau de bool qui va servir à eviter qu'un parcours
    //utilise deux fois le même trajet
    bool * utilise = new bool[nElements];
    for(int i=0;i<nElements;i++){
        utilise[i]=false;
    }
    //parcours garde la liste de trajets utilises pendant que le parcours est
    //en train d'etre constuit
    int * parcours = new int[nElements];
    //variable passer par refereance pour compter les nb de parcours trouvees
    int count = 0;
    Recherche(depart, destination, utilise, parcours, 0, count);
    cout<<endl;
    delete [] parcours;
    delete [] utilise;
    return count;
}
/**
 * l'algorithme "realise" chaque trajet qui commence par depart, ensuite il
 * cherche d'aller de la ville de d'arrive de ce trajet à la ville de destination
 * @param depart
 * @param destination
 * @param utilise tableau de booleans avec les trajets deja utilises
 * @param parcours parcours suivi
 * @param index pour gerer ou ajouter les trajets au parcours
 * @param count nb de parcours trouves
 */
void Catalogue::Recherche(const char *depart, const char *destination, bool *utilise, int *parcours, int index,
                          int &count) const
{
    //depart=destination
    //ça veut dire qu'on est deja arrive donc
    //on peut afficher le parcours qu'on a suivi
    if(strcmp(depart,destination)==0){
        ++count;
        cout<<"(";
        for(int i=0;i<index-1;i++){
            cout<<"T"<<parcours[i]<<"+";
        }
        cout<<"T"<<parcours[index-1]<<") ";
        return;
    }
    //si le trajet n'a pas ete utilise dans la parcours
    //la ville de depart est pareil a celle de depart du trajet
    //on realise le trajet (on l'ajoute au parcours et on le marque comme utilise)
    //et on recherche de la destiantion du trajet a la destination final
    for(int i=0;i<nElements;i++){
        if(!utilise[i]){
            if(strcmp(depart,tabTrajets[i]->getDepart())==0){
                utilise[i]=true;
                parcours[index]=i+1;
                Recherche(tabTrajets[i]->getDestination(), destination, utilise, parcours, index + 1, count);
                utilise[i]=false;
            }
        }
    }
}

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
/**
 * constructeur de copie
 * il s'agit d'une copie en profondeur donc
 * il faut creer une copie de chaque element de du catalogue
 * @param unCatalogue
 */
Catalogue::Catalogue ( const Catalogue & unCatalogue ) : TabTrajets(unCatalogue)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif

} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue (int t) : TabTrajets(t)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

