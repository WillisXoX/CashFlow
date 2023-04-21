#ifndef DEPLACERJOUEUR_H_INCLUDED
#define DEPLACERJOUEUR_H_INCLUDED

#include "nouveauMoins.h"
#include "lancerDie.h"

int deplacerJoueur(joueur xox)
{
    int position,positionActuelle,positionPrecedent;
    int die=0, die2=0;

    clrsr();
    cout << " ...Lancer le die ..." << endl;
    die = lancerDie();
    cout << endl;
    system("pause");
    cout << " -> Die = " << die << endl;
    cout << endl;

    positionPrecedent = xox.positionJoueur();
    position = positionPrecedent;

    if(xox.chariterJoueur())
    {
        cout << " ...Lancer le die encore ..." << endl;
        die2 = lancerDie();
        cout << endl;
        system("pause");

        cout << " -> Die = " << die2 << endl << endl;

        for(int i=1; i<=die+die2; i++){
            if(position == 0 && positionPrecedent != 0){
                nMounth = 1;
            }
            position = positionPrecedent + i;
        }
    }else{
        for(int i=1; i<=die; i++){
            if(position == 0 && positionPrecedent != 0){
                nMounth = 1;
            }
            position = positionPrecedent + i;
        }
    }

    if(position == nbSpaces){
        positionActuelle = nbSpaces;
    }else{
        if(position > nbSpaces){
            nMounth = 1;
            positionActuelle = (position % nbSpaces) - 1;
        }else{
            positionActuelle = position % nbSpaces;
        }
    }

    cout << " -> Position precedent = " << positionPrecedent << endl;
    cout << " -> Position actuelle  = " << positionActuelle << endl << endl;

    return positionActuelle;
}

#endif // DEPLACERJOUEUR_H_INCLUDED
