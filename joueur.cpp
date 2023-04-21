#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
#include "joueur.h"

using namespace std;

joueur::joueur()
{
    m_nom = "Joueur";
    m_profession = "Enseignant";
    m_payRate  = 0;
    m_cashFlow = 0;
    m_savings  = 0;
    m_expenses = 0;
    m_position = -1;
    m_charity  = 0;

}

joueur& joueur::nommerJoueur(string nom)
{
    string profession[5] = {"Docteur","Mecanisine","Engineer","Enseignant","Plumbier"};
    int payRate[5] = {4000,2000,5000,2500,3000};

    srand((unsigned) time(NULL));
    int r = 0 + (rand()% 5);

    m_nom = nom;
    m_profession = profession[r];
    m_payRate = payRate[r];
    m_cashFlow = 0;
    m_savings = 5000;
    m_expenses = 9 * m_payRate / 10;
    m_position = -1;
    m_charity = 0;

    return *this;
}
joueur& joueur::creeCountEnBank()
{
    ofstream myFlux,myFlux1;
    string link = m_nom+"_Account";
    string link1 = m_nom+"_Opportunities";

    myFlux.open(link.c_str(),ios_base::out);
    myFlux1.open(link1.c_str(),ios_base::out);


    if(myFlux){
            myFlux << m_nom <<'\t'<< m_profession <<'\t'<< m_payRate <<'\t'<< m_savings <<'\t'<< m_cashFlow <<'\t' << m_expenses <<'\t'<< m_position <<'\t'<< m_charity << endl;
    }else{
        cout << "-> !...Erreur a ouverture du fichier...!" << endl << endl;
    }
    myFlux.close();
    myFlux1.close();

    return *this;
}

joueur& joueur::acheterOpportunite(string description)
{
    ifstream myFile;
    ofstream oppFile;
    string link = "Opportunities";
    myFile.open(link.c_str());
    string link1 = m_nom+"_Opportunities";
    oppFile.open(link1.c_str(),ios_base::app);

    int i=1,maxOpp=100;
    int prixTb[maxOpp],cashFlowTb[maxOpp];
    string descriptionTb[maxOpp];
    if(myFile){
        while(myFile >> descriptionTb[i] >> prixTb[i] >> cashFlowTb[i]){
                if(description == descriptionTb[i]){
                    oppFile << descriptionTb[i] <<'\t'<< prixTb[i] <<'\t'<< cashFlowTb[i] << endl;
                    cout << " ... Opportunite Ajouter... " << endl << endl;
                    break;
                }
                i++;
            }
        }else{
            cout << "-> !...Erreur a ouverture du fichier...!" << endl << endl;
    }
    myFile.close();
    oppFile.close();

    return *this;
}

joueur& joueur::afficherCountEnBank()
{
    actualiserJoueur();

    cout << "... Game Card ..." << endl << endl;
    cout << " Nom Joueur : " << m_nom << endl;
    cout << " Profession : " << m_profession << endl;
    cout << " Salary/moins  : " << m_payRate << "$/moins" << endl;
    cout << " Saving Account : " << m_savings << "$" << endl;
    cout << " CashFlow/moins : " << m_cashFlow << "$/moins" << endl << endl;

    return *this;
}

int joueur::afficherOpportunite()
{
    ifstream myFile;
    string link = m_nom+"_Opportunities";
    myFile.open(link.c_str());

    int i=1,maxOpp=100;
    string descriptionTb[maxOpp];int prixTb[maxOpp], cashFlowTb[maxOpp];

    cout <<".............................." << endl;
    cout <<"    Vendre une Opportunite" << endl;
    cout <<".............................." << endl;
    cout <<"    Description " << '\t' << "Prix " << endl;
    cout <<".............................." << endl;

    if(myFile){
        while(myFile >> descriptionTb[i] >> prixTb[i] >> cashFlowTb[i]){
            replace(descriptionTb[i].begin(), descriptionTb[i].end(), '_',' ');
            cout << i <<".  "<< descriptionTb[i] << '\t' << prixTb[i] << endl;
            i++;
        }
        cout << "0.  Exit " << endl;
        cout << endl;
    }else{
        cout << "-> !...Erreur de lecture du fichier...!" << endl << endl;
    }
    myFile.close();

    return i-1;
}
bool joueur::economieDuJoueur(int prix)
{
    if(m_savings >= prix){
            return true;
    }else{
        return false;
    }
}

int joueur::vendreOpportunite(int selectOpportunite)
{
    fstream myFile;
    fstream copieFile;

    string link = m_nom+"_Opportunities";
    string link1 = "copie";

    myFile.open(link.c_str());
    copieFile.open(link1.c_str(),ios_base::out);

    int i=1,maxOpp=100,prixTb[100];
    string descriptionTb[maxOpp];
    if(myFile){
        while(myFile >> descriptionTb[i] >> prixTb[i]){
            if(i != selectOpportunite){
                copieFile << descriptionTb[i] <<'\t'<< prixTb[i] << endl;
            }else if(i == selectOpportunite){
                m_savings += prixTb[i];
            }
            i++;
        }
    }else{
        cout << "-> !...Erreur de leccture du fichier...!" << endl << endl;
    }
    myFile.close();
    copieFile.close();

    myFile.open(link.c_str(), ios_base::out);
    myFile.close();

    myFile.open(link.c_str(),ios_base::app);
    copieFile.open(link1.c_str());
    i=1;

    if(copieFile){
        while(copieFile >> descriptionTb[i] >> prixTb[i]){
            myFile << descriptionTb[i] <<'\t'<< prixTb[i] << endl;
            i++;
        }
    }else{
        cout << "-> !...Erreur ecriture du fichier...!" << endl << endl;
    }

    myFile.close();
    copieFile.close();
    remove(link1.c_str());

    return 0;
}

joueur& joueur::reduireArgent(int prix)
{
    m_savings -= prix;
    enregistrerJoueur();
    return *this;
}

joueur& joueur::actualiserCashFlow()
{
    ifstream myFile;
    string link = m_nom+"_Opportunities";
    myFile.open(link.c_str());

    string description;
    int prix,cashFlow,i=1;

    int cash = 0;
    if(myFile){
        cout << "... Real Estates Investments ..." << endl << endl;
        cout <<"    Description " << "  " << " Prix " << "  " <<" CashFlow " << endl;
        cout <<"...................................................." << endl;
        while(myFile >> description >> prix >> cashFlow){
                replace(description.begin(), description.end(), '_',' ');
                cout <<i<<".  "<< description <<'\t'<< "   " << prix <<'\t'<< "   " << cashFlow << endl;
                cash += cashFlow;
                i++;
            }
        cout << endl;
            cout << "-> Total CashFlow = " << cash << "$" << endl << endl;
            m_cashFlow = cash;

        }else{
            cout << "-> !...Erreur a ouverture du fichier...!" << endl;
    }
    enregistrerJoueur();

    return *this;
}
joueur& joueur::actualiserCount()
{
    int remains;

    cout << " -> Salary : " << m_payRate << "$" << endl;
    cout << " -> Expenses : -" << m_expenses << "$" << endl << endl;


    remains = m_payRate - m_expenses;
    m_savings = m_savings + remains + m_cashFlow;
    //cout << " -> Savings : " << m_payRate << "$ - " << m_expenses << "$ = " << m_savings << "$" << endl << endl;

    enregistrerJoueur();

}
bool joueur::refreshJoueur()
{
    string nomCmpt;
    ifstream myFile;

    cout << " Enter le nom du compte utilisateur : ";
    cin >> nomCmpt;
    if(verifierDesJoueurs(nomCmpt)){
    string link = nomCmpt+"_Account";
    myFile.open(link.c_str());

    if(myFile){
            while(myFile >> m_nom >> m_profession >> m_payRate >> m_savings >> m_cashFlow >> m_expenses >> m_position >> m_charity){
            }
    }else{
        cout << "-> !...Erreur de lecture du fichier...!" << endl << endl;
    }
    cout << " ...Party Rafreshie ..." << endl << endl;

    return true;

    }else{
        cout << "-> !...Erreur nom utilisateur ...!" << endl << endl;
    }
    myFile.close();

    return false;
}
bool verifierDesJoueurs(string nom)
{
    ifstream myFlux1;
    string link1 = "listeDesJoueurs";
    myFlux1.open(link1.c_str());
    string nom1;
    if(myFlux1){
        while(myFlux1 >> nom1){
            if(nom1 == nom){
                return true;
            }
        }
    }else{
        cout << "-> !...Erreur a ouverture du fichier...!" << endl << endl;
    }
    myFlux1.close();

    return false;
}

joueur& joueur::supprimerCount()
{
    fstream myFile,copie1;
    string link = m_nom+"_Account";
    string link1 = m_nom+"_Opportunities";
    string link2 = "listeDesJoueurs";
    string link3 = "copie1";

    string nom;

    myFile.open(link2.c_str());
    copie1.open(link3.c_str(),ios_base::out);

    if(myFile){
        while(myFile >> nom){
            if(m_nom != nom){
                copie1 << nom << endl;
            }
        }
    }else{
         cout << "-> !...Erreur de lecture du fichier...!" << endl << endl;
    }

    myFile.close();
    copie1.close();
    myFile.open(link2.c_str(),ios_base::out);
    myFile.close();


    myFile.open(link2.c_str(),ios_base::app);
    copie1.open(link3.c_str());

    if(copie1){
        while(copie1 >> nom){
                myFile << nom << endl;
            }
    }else{
         cout << "-> !...Erreur de lecture du fichier...!" << endl << endl;
    }

    copie1.close();
    myFile.close();

    int supp = remove(link.c_str());
    int supp1 = remove(link1.c_str());
    int supp3 = remove(link3.c_str());

    if((supp == 0 && supp1 == 0 && supp3 == 0) || (supp == 0 && supp3 == 0)){
        cout << " ...Joueur supprimer..." << endl << endl;
    }else{
        cout << "!...Erreur de lecture du fichier...!" << endl << endl;
    }
    return *this;
}

bool joueur::verifierOpportunite()
{
    ifstream myFile;
    string link;
    link = m_nom+"_Opportunities";
    myFile.open(link.c_str());

    int i=1,prixTb[i];
    string descriptionTb[i];

    if(myFile){
        while(myFile >> descriptionTb[i] >> prixTb[i]){
                i++;
            }
            return true;

    }else{
        cout << "-> !...Erreur de lecture du fichier...!" << endl << endl;
    }
    myFile.close();
}

int joueur::positionJoueur()
{
    return m_position;
}

int joueur::positionJoueurActuelle(int position)
{
    m_position = position;
    enregistrerJoueur();
}

bool joueur::verifierStatus()
{
    if(m_cashFlow <= 30 * m_expenses){
        return true;
    }else{
        return false;
    }
}
int joueur::downSized()
{
    actualiserJoueur();

    if(m_charity == 1){
        cout << " -> ...Charity mode terminer... " << endl << endl;
        m_charity = 0;
    }
    if(m_expenses > m_savings){
        m_savings = 0;
        cout << " Vous perdez la totalite des vous depenses : " << endl << endl;
        cout << "-> Savings = " << m_savings << "$" << endl << endl;
    }else{
        int pay;
        cout << " Vous perdez la totalite des vous depenses : " << endl << endl;
        cout << "-> Expenses = -" << m_expenses << "$" <<endl;
        pay = m_savings;
        m_savings -= m_expenses;

        cout << "-> Savings = " << pay << "$ - " << m_expenses << "$ = " << m_savings << "$" << endl << endl;
    }
    enregistrerJoueur();
}
joueur& joueur::actualiserJoueur()
{
    ifstream myFile;
    string link = m_nom+"_Account";
    myFile.open(link.c_str());

    if(myFile){
            while(myFile >> m_nom >> m_profession >> m_payRate >> m_savings >> m_cashFlow >> m_expenses >> m_position >> m_charity){
            }
    }else{
        cout << "-> !...Erreur de lecture du fichier...!" << endl << endl;
    }

    myFile.close();

    return *this;
}

joueur& joueur::enregistrerJoueur()
{
    ofstream myFile;
    string link = m_nom+"_Account";

    myFile.open(link.c_str(),ios_base::out);

    if(myFile){
            myFile << m_nom <<'\t'<< m_profession <<'\t'<< m_payRate <<'\t'<< m_savings <<'\t'<< m_cashFlow << '\t' << m_expenses <<'\t'<< m_position <<'\t'<< m_charity << endl;
    }else{
        cout << "-> !...Erreur a ouverture du fichier...!" << endl << endl;
    }

    myFile.close();

    return *this;
}

bool joueur::chariterJoueur()
{
    actualiserJoueur();

    if(m_charity){

        int pay, res=0;
        cout << " ...Charity mode..." << endl << endl;
        cout << " 10% discount : ";

        pay = 10 * m_savings / 100;
        res = m_savings - pay;
        cout << "Savings = " << m_savings <<"$ - " << pay <<"$ = " << res << "$" << endl << endl;
        m_savings = res;

        enregistrerJoueur();

        return true;
    }else{
        return false;
    }
}

joueur& joueur::activerChariter(int charity)
{
    actualiserJoueur();

    if(m_charity){
        cout << " ...!Desoler, vous est deja en charity mode!... " << endl << endl;
    }else if(m_savings <= 0){
        cout << "!...Desole, votre compte n'est pas suffisant...!" << endl << endl;
    }else{
         cout << " ...Charity mode activer... " << endl << endl;
        m_charity = 1;
    }

    enregistrerJoueur();
}
joueur::~joueur()
{
        m_nom;
        m_profession;
        m_payRate;
        m_cashFlow;
        m_savings;
        m_position;
        m_expenses;
}
