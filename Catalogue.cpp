#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>

#include "Catalogue.h"
#include "Tableau.h"
#include "Trajets.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

#define NOM_FICHIER "catalogue.txt"

using namespace std;

// Constructeur par défaut
//Construit un tableau dynamique vide de taille 0
//----------------------------------------------
Catalogue::Catalogue()
{
	cout << "Appel constructeur Catalogue"<<endl;
	tabCata = new Tableau(0);
}

//Demande à l'utilisateur de saisir un TS ou TC et l'ajoute au Catalogue
//----------------------------------------------------------------------
void Catalogue::SaisieSimple()
{

		int nbEscales = -1;

		while(nbEscales < 0)
		{
			cout << ("Combien d'escales ?\r\n");
			cin >> nbEscales;

			if (nbEscales >= 0 )
			{
				cout << ("Indiquer la ville de départ\r\n");
				char *villeDep = new char[20];
				cin >>  villeDep;

				cout << ("Indiquer la ville d'arrivée\r\n");
				char *villeArr = new char[20];
				cin >>  villeArr;

				cout << ("Indiquer le moyen de transport\r\n");
				char *moyTrans = new char[20];
				cin >>  moyTrans;

				TrajetSimple *leTrajet = new TrajetSimple(villeDep,villeArr,moyTrans);


				if(nbEscales==0)
				{
					Ajouter(leTrajet);

					delete [] villeArr;
					delete [] villeDep;
					delete [] moyTrans;
					delete leTrajet;
				}

				else
				{
					TrajetCompose *monTrajComp = new TrajetCompose();
					monTrajComp->Ajouter(leTrajet);

				//COPIE VILLE ARR -> DEP
				char * villeArriveeTamp = new char[20];
				for(unsigned int i=0; i<strlen(villeArr); i++)
				{
					villeArriveeTamp[i] = villeArr[i];
				}

				delete [] villeArr;
				delete [] villeDep;
				delete [] moyTrans;

				delete leTrajet;


			for(int i = 0; i<nbEscales; i++)
			{


				cout << ("Indiquer la ville suivante\r\n");
				villeArr = new char[20];
				cin >>  villeArr;

				cout << ("Indiquer le moyen de transport\r\n");
				moyTrans = new char[20];
				cin >>  moyTrans;

				leTrajet = new TrajetSimple(villeArriveeTamp,villeArr,moyTrans);

				monTrajComp->Ajouter(leTrajet);

				delete [] villeArriveeTamp;
				delete leTrajet;

				villeArriveeTamp = new char[20];
				for(unsigned int i=0; i<strlen(villeArr); i++)
				{
					villeArriveeTamp[i] = villeArr[i];
				}
				delete [] villeArr;
				delete [] moyTrans;


			}

			Ajouter(monTrajComp);
			delete monTrajComp;

			delete [] villeArriveeTamp;
		}
		}


		else
		{
			cout << ("Mauvaise saisie\r\n");
		}
	}
}

//Ajoute un Trajet au Catalogue
//-----------------------------
void Catalogue::Ajouter(Trajets * monTrajet)
{
	tabCata->Ajouter(monTrajet);
}

//Destructeur
//-----------
Catalogue::~Catalogue()
{
	//cout << "Appel destructeur Catalogue" << endl;
	delete tabCata;
}

//Affiche tous les trajets du Catalogue
//-------------------------------------
void Catalogue::Afficher()
{
	cout << "Affichage du catalogue :\r\n----------------------------\r\n";

	tabCata->Afficher();
}

//Demande la saisie d'une VD et une VA et trouve tous les trajets uniques (1 TS ou 1 TC)
//qui correspondent et les affiche
//-------------------------------------
void Catalogue::RechercheSimple()
{
	char** ptTabVDVA = SaisieParamRecherche();

	tabCata->recherche(ptTabVDVA[0], ptTabVDVA[1]); // VD VA

	for(unsigned int i = 0; i<2; i++)
	{
		delete [] ptTabVDVA[i];
	}
	delete  ptTabVDVA;
}

//Renvoi un Tableau dynamique de tous les Trajets (CONVERTIS en TC) qui partent d'une VD
//--------------------------------------------------------------------------------------
Tableau * Catalogue::RechercheAll(char * villeDep)
{
	Tableau * tabDepuisVD; // Tableau De Tous Les "trajets" partant de la ville de départ

	tabDepuisVD = tabCata->getTrajVilleDep(villeDep);  //affectation

	TrajetCompose * monTC;
	TrajetSimple * monTS;

	for(int i = 0; i< tabDepuisVD->getCardActu();i++) //On veut que des TC donc on transforme les TS en TC
	{

		if(tabDepuisVD->getCaseTab(i)->estTrajetSimple())
		{
			monTC = new TrajetCompose();

			monTS = new TrajetSimple(tabDepuisVD->getCaseTab(i)->getVD(),tabDepuisVD->getCaseTab(i)->getVA(),tabDepuisVD->getCaseTab(i)->getMT());

			monTC->Ajouter(monTS); // ON A QUE DES TC

			tabDepuisVD->Ajouter(monTC);

			delete tabDepuisVD->getCaseTab(i);

			tabDepuisVD->supprimer(i); // On supprime le TS associé



			delete monTC;
			delete monTS;
		}
	}

	return tabDepuisVD;
}

//TROUVE ET AFFICHE TOUTES LES COMPOSITIONS DE TRAJETS qui vont d'une VD à VA
//---------------------------------------------------------------------------
void Catalogue::RechercheComplexe()
{
	char** ptTabVilleDepVilleArr = SaisieParamRecherche();

	bool continuer = true;
	int compteurTabSuivant;

	// on cherche touts les trajs depuis Dep -> monTab
	Tableau * monTab = RechercheAll(ptTabVilleDepVilleArr[0]);
	Tableau * monTabTourSuivant;
	Tableau * tabPoten;

	while(continuer == true)
	{

		 //Stocke les trajets pour le tour suivant
		 monTabTourSuivant= new Tableau(0);
		 compteurTabSuivant = 0;

		for(int i=0;i<monTab->getCardActu();i++)
		{
			//Pour chaque TC !!

			//Si on est arrivé on affiche le Trajet
			if(strcmp(monTab->getCaseTab(i)->getVA(),ptTabVilleDepVilleArr[1]) == 0 )
			{
				monTab->getCaseTab(i)->Afficher();
				delete monTab->getCaseTab(i);
				monTab->supprimer(i);
				continue;
			}

			//On voit à quels autres trajets il mène
			tabPoten = RechercheAll(monTab->getCaseTab(i)->getVA());

			for(int j=0;j<tabPoten->getCardActu();j++)
			{
				// On vérifie pour chaque trajet potentiel s'il est valide :

				// on vérifie pas déjà passé
				if(monTab->getCaseTab(i)->estDejaPasse(tabPoten->getCaseTab(j)->getVA())==false)
				{
					monTabTourSuivant->Ajouter(monTab->getCaseTab(i));
					monTabTourSuivant->getCaseTab(compteurTabSuivant)->Ajouter(tabPoten->getCaseTab(j));
					compteurTabSuivant++;
				}
			}
			delete tabPoten;
		}


		//copie de monTabTourSuivant dans monTab

		delete monTab; // [] ou pas [] ? Normalement il faut les mettre je crois, sinon ça ne delete que la case pointée et pas toutes les cases

		monTab = new Tableau();

		int m;
		for(m=0; m<monTabTourSuivant->getCardActu(); m++)
		{
			monTab->Ajouter(monTabTourSuivant->getCaseTab(m));
		}

		delete monTabTourSuivant;

		if (monTab->estVide() == true)
		{
			continuer = false;
			delete monTab;
		}
	}

	for(unsigned int i = 0; i<2; i++)
	{
		delete [] ptTabVilleDepVilleArr[i];
	}
	delete [] ptTabVilleDepVilleArr;
}

char** Catalogue::SaisieParamRecherche()
{
	char ** tabVDVA = new char*[2];

	cout << ("RECHERCHE : Indiquer la ville de départ\r\n");
	tabVDVA[0] = new char[20];
	cin >>  tabVDVA[0];

	cout << ("RECHERCHE : Indiquer la ville d'arrivée\r\n");
	tabVDVA[1] = new char[20];
	cin >>  tabVDVA[1];

	cout << endl << endl <<"Résultats :\r\n----------------------------\r\n";

	return tabVDVA;
}

void Catalogue::Sauvegarder()
{
	ofstream fichier(NOM_FICHIER, ios::out | ios::trunc);  // on ouvre en écriture

        if(fichier)  // si l'ouverture a fonctionné
        {
             for(int i = 0; i < tabCata->getCardActu(); i++)
             {
				 tabCata->getCaseTab(i)->SauvegarderTraj(fichier);
			 }

            fichier.close();
        }
        else
        {
            cerr << "Impossible d'ouvrir le fichier !" << endl;
			cerr << "Sauvegarde échouée" << endl;
		}
}

void Catalogue::Lecture()
{
	ifstream fichier(NOM_FICHIER, ios::in);  // on ouvre le fichier en lecture
	string ligne;
	vector<string> ligneSplit;

        if(fichier)  // si l'ouverture a réussi
        {
           while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"

					 {
							//cout << "ligne" <<endl;
							//cout << ligne <<endl;
							//cout << ligne.at(1) <<endl;

							if(ligne.at(1) == 'S')// Si c'est un TS
							{
								ligneSplit = split(ligne);

								//Rectification du moyenTransp
								ligneSplit[3] = ligneSplit[3].substr(0, ligneSplit[3].length() - 1); // on retire le dernier carac

								TrajetSimple * monTS = new TrajetSimple(ligneSplit[1].c_str(),ligneSplit[2].c_str(),ligneSplit[3].c_str());

								Ajouter(monTS);

								delete monTS;
							}

			        else if(ligne.at(1) == 'C')// Si c'est un TC
			        {
						
// PROB ICI
						TrajetCompose * monTC = new TrajetCompose();

						while(true)
						{
							//cout << ligne.compare("TC/") << endl;
							getline(fichier, ligne);
							if(ligne[0] == '/')
							{break;}
							ligneSplit = split(ligne);
							
							//Rectification du moyenTransp
							ligneSplit[3] = ligneSplit[3].substr(0, ligneSplit[3].length() - 1); // on retire le dernier carac

							TrajetSimple * monTS = new TrajetSimple(ligneSplit[1].c_str(),ligneSplit[2].c_str(),ligneSplit[3].c_str());
							monTS->Afficher();
							monTC->Ajouter(monTS);

							delete monTS;
						}

							Ajouter(monTC);
							delete monTC;
					}
					else
					{
						cerr << "ERREUR : fichier corrompu" << endl;
					}

					}

            fichier.close();  // on referme le fichier

        }

        else
				{
					cerr << "Erreur à l'ouverture !" << endl;
				}
}

vector<string> Catalogue::split(string s)
{
	string delimiteur = " ";
	int pos = 0;
	int pos1 = 0;

	vector<string> sSplit;

	for(unsigned int i =0; i < s.length() ; i++)
	{
		// SUBSTRING( int posInitiale, LONGUEUR);

		pos1 = s.find(delimiteur, pos);
		sSplit.push_back(s.substr(pos, pos1-pos));
		pos = pos1+1;

	}

	return sSplit;
}
