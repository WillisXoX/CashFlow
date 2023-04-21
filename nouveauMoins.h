#ifndef NOUVEAUMOINS_H_INCLUDED
#define NOUVEAUMOINS_H_INCLUDED

int nouveauMoins(joueur xox)
{
    clrsr();
    cout << "        ... Espace Pay Check ..." << endl << endl;
    xox.actualiserJoueur();
    xox.actualiserCashFlow();
    xox.actualiserCount();
    xox.afficherCountEnBank();

    nMounth = 0;
    return nMounth;
}

#endif // NOUVEAUMOINS_H_INCLUDED
