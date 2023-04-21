#ifndef DEPLACEMENTJOUEUR_H_INCLUDED
#define DEPLACEMENTJOUEUR_H_INCLUDED

int deplacementJoueur(joueur xox, int positionActuelle)
{
    int choice=-1;

    switch(positionActuelle)
    {
        case 1:
            clrsr();
            cout << "       ... Espace Downzied ..." << endl << endl;
            downSized(xox);
            break;
        case 3:
            clrsr();
            selectionerDesOpportunite(xox);
            break;
        case 4:
            clrsr();
            cout << "       ... Espace Downzied ..." << endl << endl;
            downSized(xox);
            break;
        case 5:
            clrsr();
            cout << "       ... Espace Charity ..." << endl << endl;
            charity(xox);
            break;
        case 7:
            clrsr();
            selectionerDesOpportunite(xox);
            break;
        case 8:
            clrsr();
            cout << "       ... Espace Downzied ..." << endl << endl;
            downSized(xox);
            break;
        case 9:
            clrsr();
            cout << "       ... Espace Charity ..." << endl << endl;
            charity(xox);
            break;
        case 10:
            clrsr();
            selectionerDesOpportunite(xox);
            break;
        default:
            clrsr();
            cout << "       ... Rien pour le moment :( ..." << endl << endl;
            break;
    }
    clrsr();
    do{

            cout << " ...Votre tour est terminer..." << endl << endl;

            cout << " 1. Continue Party " << endl;
            cout << " 2. Afficher Count " << endl;
            cout << " 0. Exit Party " << endl << endl;
            cout << " -> Enter choix : ";
            cin >> choice;
            cout << endl;

        switch(choice)
        {
            case 0:
                game = 0;
                clrsr();
                cout << " ... Au revoir :) ..." << endl;
                break;
            case 1:
                choice = -1;
                return choice;
                break;
            case 2:
                clrsr();
                xox.afficherCountEnBank();
                clrsr();
                choice=1;
                return choice;
                break;
            default:
                choice = 1;
                return choice;
                break;
        }
    }while(choice == 1);

    return choice;
}

#endif // DEPLACEMENTJOUEUR_H_INCLUDED
