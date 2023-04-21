#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

using namespace std;

class joueur
{
    public:
        joueur();
        ~joueur();
        joueur& nommerJoueur(string nom);
        joueur& afficherCountEnBank();
        joueur& acheterOpportunite(string description);
        int vendreOpportunite(int selectOpportunite);
        int afficherOpportunite();
        joueur& reduireArgent(int prix);
        joueur& actualiserCount();
        joueur& actualiserCashFlow();
        joueur& listOpportunite();
        bool economieDuJoueur(int prix);
        joueur& creeCountEnBank();
        joueur& supprimerCount();
        bool refreshJoueur();
        bool verifierOpportunite();
        int positionJoueur();
        int positionJoueurActuelle(int position);
        bool verifierStatus();
        bool chariterJoueur();
        int downSized();
        joueur& actualiserJoueur();
        joueur& enregistrerJoueur();
        joueur& activerChariter(int charity);

    private:
        string m_nom;
        string m_profession;
        int m_payRate;
        int m_cashFlow;
        int m_savings;
        int m_position;
        int m_expenses;
        int m_charity;
};

bool verifierDesJoueurs(string nom);

#endif // JOUEUR_H
