#ifndef AJOUTERDESOPPORTUNITES_H_INCLUDED
#define AJOUTERDESOPPORTUNITES_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

void ajouterDesOpportunites()
{
    ofstream myFile;
    string link = "Opportunities";
    myFile.open(link.c_str(),ios_base::app);

    string description;
    int prix,cashFlow;

    if(myFile){
        cout << "-> Description de l'Opportunite (utiliser '_' comme espace) : ";
        cin >> description;
        cout << "-> Prix de l'Opportunite : ";
        cin >> prix;
        cout << "-> CashFlow de Opportunite  : ";
        cin >> cashFlow;
        cout << endl;
        myFile << description <<'\t'<< prix <<'\t'<< cashFlow<< endl;
        cout << " ... Opportunite Ajouter... " << endl;

    }else{
        cout << "-> !...File execution impossible...!";
    }
    myFile.close();
}


#endif // AJOUTERDESOPPORTUNITES_H_INCLUDED
