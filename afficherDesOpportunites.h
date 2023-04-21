#ifndef AFFICHERDESOPPORTUNITES_H_INCLUDED
#define AFFICHERDESOPPORTUNITES_H_INCLUDED

#include <algorithm>

using namespace std;

void afficherDesOpportunites(){

     ifstream myFile;
     string link = "Opportunities";
     myFile.open(link.c_str());

     string description;
     int prix,cashFlow;

     if(myFile){
            cout <<"...................................................." << endl;
            cout <<"         Liste de touts les Opportunites" << endl;
            cout <<"...................................................." << endl;
            cout <<"    Description " << "  " << " Prix " << "  " <<" CashFLow " << endl;
            cout <<"...................................................." << endl;
            while(myFile >> description >> prix >> cashFlow){
                replace(description.begin(), description.end(), '_',' ');
                cout <<"    "<< description <<'\t'<< "   " << prix <<'\t' << cashFlow << endl;
            }
        }else{
            cout << "-> !...Erreur a ouverture du fichier...!" << endl;
    }
    myFile.close();
}

#endif // AFFICHERDESOPPORTUNITES_H_INCLUDED
