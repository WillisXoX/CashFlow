#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <windows.h>
int game = 1, nbSpaces=10, nMounth=0;
#include "joueur.h"
#include "inGame.h"
#include "clearScreen.h"
#include "nouveauMoins.h"
#include "ajouterDesOpportunites.h"
#include "ajouterDesJoueurs.h"
#include "afficherDesOpportunites.h"
#include "checkRatRace.h"
#include "deplacerJoueur.h"
#include "selectionerDesOpportunites.h"
void charity(joueur xox);
void downSized(joueur xox);
void ratRace(joueur xox);
#include "deplacementJoueur.h"
#include "lancerDie.h"

using namespace std;


int main()
{
     joueur xox;
     int choice = -1, edit = -1;
     string nom;
     SetConsoleTitle(" CashFLow Game ");

    do{
        cout << "          ...CashFlow Game 101 - Demo Version..." << endl << endl;
        cout << "1. New party." << endl;
        cout << "2. Resume party." << endl;
        cout << "3. About game." << endl;
        cout << "4. Edit game." << endl;
        cout << "0. Exit." << endl << endl;
        cout << " -> Entre votre choix : ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case 0:
                cout << " ... Au revoir :) ..." << endl;
                break;

            case 1:
                clrsr();
                cout << "           ...Welcome to the CashFlow Game 101..." << endl << endl;
                cout << " Enter nom : ";
                cin >> nom;
                clrsr();
                break;

            case 2:
                cout << "           ... Resume game ..." << endl << endl;
                if(xox.refreshJoueur()){
                    xox.afficherCountEnBank();
                    choice = 2;
                }else{
                    clrsr();
                    choice = -1;
                }

                break;

            case 3:
                cout << "           ... About CashFlow Game ..." << endl << endl;
                cout << " Rien pour le moment :( " << endl << endl;
                choice = -1;
                clrsr();
                break;

            case 4:
                do{
                    clrsr();
                    cout << "           ... Edit Game ..." << endl << endl;
                    cout << "1. Ajouter Opportunites." << endl;
                    cout << "2. Supprimer Joueurs." << endl;
                    cout << "3. Afficher Opportunites." << endl;
                    cout << "0. Exit." << endl << endl;
                    cout << " -> Entre votre choix : ";
                    cin >> edit;
                    cout << endl;

                    switch(edit){
                        case 1:
                            clrsr();
                            ajouterDesOpportunites();
                            edit = -1;
                            break;
                        case 2:
                            if(xox.refreshJoueur()){
                                xox.supprimerCount();
                            }
                              edit = -1;
                              break;
                        case 3:
                            afficherDesOpportunites();
                            cout << endl;
                            edit = -1;
                            break;
                        case 0:
                            clrsr();
                            edit = 1;
                            break;
                        default:
                            clrsr();
                            edit = -1;
                            break;
                    }
                }while(edit == -1);
                choice = -1;
                break;

            default:
                clrsr();
                choice = -1;
                return choice;
                break;
        }
    }while(choice == -1);

   if(choice == 1){
        ajouterDesJoueurs(nom);
        xox.nommerJoueur(nom);
        xox.creeCountEnBank();
        xox.afficherCountEnBank();

         ratRace(xox);

    }else if(choice == 2){
        ratRace(xox);
    }

    xox.~joueur();

    return 0;
}
void charity(joueur xox)
{
    int choice = -1, choice2 = -1;

    do{
        cout << " -> Voulez vous joueur en charity mode ? " << endl;
        cout << "1. Oui                 0. Non "<< endl << endl;
        cout << " -> Entre votre choix : ";
        cin >> choice;
        cout << endl;
        switch(choice){
            case 0:
                choice = 0;
                break;
            case 1:
                clrsr();
                cout << "       ... Espace Charity ..." << endl << endl;
                cout << " -> Ce mode vous coutera 10% de vous economie a chaque tour." << endl;
                cout << " -> Mais vous permetra de lancer le die deux fois." << endl;
                cout << "1. Je suis d'accord                   0. Non, j'ai changer d'avais" << endl << endl;
                cout << " -> Entre votre choix : ";
                cin >> choice2;
                cout << endl;

                do{
                    switch(choice2){

                    case 0:
                        choice = 0;
                        break;
                    case 1:
                        choice = 1;
                        xox.activerChariter(choice);
                        break;
                    default:
                        choice2 = -1;
                        break;
                    }
                }while(choice2 == -1);
                break;
            default:
                choice = -1;
                clrsr();
                break;
        }
    }while(choice == -1);

}
void downSized(joueur xox)
{
    xox.downSized();
}
void ratRace(joueur xox)
{
    int position=0;
    while(inGame() && checkRatRace(xox)){

        position = deplacerJoueur(xox);
        xox.positionJoueurActuelle(position);

        if(nMounth == 1){
            nouveauMoins(xox);
        }
        deplacementJoueur(xox,position);
    }
        if(!checkRatRace(xox)){
        clrsr();
        cout << "          ... Felicitations ..." << endl << endl;
        cout << "    \.Vous est sortie de la Rat race./" << endl << endl;
    }

}

