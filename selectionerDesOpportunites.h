#ifndef SELECTIONERDESOPPORTUNITES_H_INCLUDED
#define SELECTIONERDESOPPORTUNITES_H_INCLUDED

#include "clearScreen.h"
#include <cstdlib>
#include <bits/stdc++.h>

int selectionerDesOpportunite(joueur xox)
{
    ifstream myFile;
    string link = "Opportunities";
    myFile.open(link.c_str());

    int i=1,maxOpp=100;
    string descriptionTb[100];
    int prixTb[maxOpp],cashFlowTb[maxOpp];

    if(myFile){
        while(myFile >> descriptionTb[i] >> prixTb[i] >> cashFlowTb[i]){
                i++;
            }
        }else{
            cout << "-> !...Erreur a ouverture du fichier...!" << endl;
    }
     i-=1;
    srand((unsigned) time(NULL));
    int r = 1 + (rand()% i);

    string description = descriptionTb[r];
    replace(descriptionTb[r].begin(), descriptionTb[r].end(), '_',' ');

    int choice=-1; int select,nbOpp;

  do{
        cout << "       ... Espace Opportunite ..." << endl << endl;
        xox.afficherCountEnBank();
        cout <<"...................................................." << endl;
        cout <<"            Acheter une Opportunite                 " << endl;
        cout <<"...................................................." << endl;
        cout <<"    Description " << "  " << " Prix " << "  " <<" CashFLow " << endl;
        cout <<"...................................................." << endl;
        cout <<"    "<< descriptionTb[r] <<'\t'<< "   " << prixTb[r] <<'\t'<< "   " << cashFlowTb[r] << endl << endl;
        cout << "1. Buy Opportunity" <<'\t'<< "0. Exit" << endl << endl;
        cout << "-> Entre votre choix : ";
        cin >> choice;
        cout << endl;

        int prix = prixTb[r];
        switch(choice)
        {
            case 0:
                choice=-1;
                return choice;
                break;
            case 1:
                if(xox.economieDuJoueur(prix)){
                    xox.reduireArgent(prix);
                    xox.acheterOpportunite(description);
                    choice = -1;
                }else{
                    cout << "!...Desole, votre compte n'est pas suffisant...!" << endl << endl;
                    clrsr();
                    choice = 1;
                }
                break;
            /*case 2:
                select =-1, nbOpp=0;
                    while(select){
                        clrsr();
                        xox.afficherCountEnBank();
                        nbOpp = xox.afficherOpportunite();

                        cout << "-> Entre votre choix : ";
                        cin >> select;

                        if(select == 0){
                            cout << "...Exit Opportunite..." << endl << endl;
                            break;
                        }
                        if(select >= 1 && select <= nbOpp){
                            xox.vendreOpportunite(select);
                            cout << " ... Opportunite vendu ..." << endl << endl;
                            xox.creeCountEnBank();
                            break;
                        }else{
                            select = 1;
                            cout << "-> !...Choix Invalide...!" << endl;
                        }
                    }
                    choice =-1;
                    clrsr();
                    break;
                    */
            default:
                cout << "-> !...Choix Invalide...!" << endl << endl;
                clrsr();
                choice = 1;
                break;
        }
    }while(choice == 1);

    myFile.close();

    return choice;
}

#endif // SELECTIONERDESOPPORTUNITES_H_INCLUDED
