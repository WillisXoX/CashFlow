#ifndef AJOUTERDESJOUEURS_H_INCLUDED
#define AJOUTERDESJOUEURS_H_INCLUDED

void ajouterDesJoueurs(string nom)
{
    ofstream myFlux1;
    string link1 = "listeDesJoueurs";
    myFlux1.open(link1.c_str(),ios_base::app);

    if(myFlux1){
            myFlux1 << nom << endl;
    }else{
        cout << "-> !...Erreur a ouverture du fichier...!" << endl << endl;
    }
    cout << " ...Joueur Ajouter ..." << endl << endl;
    myFlux1.close();
}

#endif // AJOUTERDESJOUEURS_H_INCLUDED
