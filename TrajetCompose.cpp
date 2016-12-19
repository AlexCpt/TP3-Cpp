
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include "Tableau.h"

using namespace std;

//Constructeur par défaut
//-----------------------
TrajetCompose::TrajetCompose()
{
	//cout <<"constrcucteur TC"<<endl;
		tabTC = new Tableau(0);
}

//Destructeur
//------------
TrajetCompose::~TrajetCompose()
{
	//cout <<"destructeur TC"<<endl;
	delete tabTC;
}

//Appelle la fonctin Afficher() de tous les trajets qu'il contient
//----------------------------------------------------------------
void TrajetCompose::Afficher()
{
	cout << "Affichage TC";
		cout << endl << "----------------------------\r\n";

		this->tabTC->Afficher();


		cout << "----------------------------\r\n";
}

//On ajoute un TS dans this(TC)
//-----------------------------
void TrajetCompose::Ajouter(TrajetSimple * monTraj)
{
	tabTC->Ajouter(monTraj);
}

//On ajoute un TC dans this(TC)
//-----------------------------
void TrajetCompose::Ajouter(TrajetCompose * monTraj)
{
	TrajetCompose * monTCCopie = new TrajetCompose();

	monTCCopie->CopieTraj(monTraj);


	tabTC->Ajouter(monTCCopie);
}

void TrajetCompose::Ajouter(Trajets * monTraj)
{

	tabTC->Ajouter(monTraj); // Problème pointeur??
}
#include <string>
//Copie un TC dans this(TC)
//-------------------------
void TrajetCompose::CopieTraj(TrajetCompose * const trajACop)
{
	for(int i=0; i <  trajACop->tabTC->getCardActu(); i++)
	{
		tabTC->Ajouter(trajACop->tabTC->getCaseTab(i)); // PROBLEME DESTRUCTION POINTEURS ?
	}
}

//Copie un T dans this@(TC)
//-------------------------
void TrajetCompose::CopieTraj(Trajets * const trajACop)
{
	for(int i=0; i <  trajACop->nbTrajActu(); i++)
	{
		tabTC->Ajouter(trajACop->getTC(i));
	}
}


// Renvoie True si VD et VA correspondent à ce TC
//-----------------------------------------------
bool TrajetCompose::rechercheTraj(char* VD, char* VA)
{
	bool OK = true;

	char * villeDep = getVD();
	char * villeArr = getVA();


	if(strlen(villeDep) == strlen(VD))
	{
		for(unsigned int i=0; i<strlen(villeDep); i++)
		{
			if(VD[i] != villeDep[i])
			{
				OK = false;
			}
		}
	}
	else
	{
		OK = false;
	}

	if(strlen(villeArr) == strlen(VA))
	{
		for(unsigned int i=0; i<strlen(villeArr); i++)
		{
			if(VA[i] != villeArr[i])
			{
				OK = false;
			}
		}
	}
	else
	{
		OK = false;
	}

	return OK;
}

//Renvoi VD
//---------
char * TrajetCompose::getVD()
{
	return tabTC->getCaseTab(0)->getVD();
}

//Renvoi VA
//----------
char * TrajetCompose::getVA()
{
	return tabTC->getCaseTab(tabTC->getCardActu()-1)->getVA();
}

char * TrajetCompose::getMT()
{
	cout << "erreur TC getMT\n";
	char * maChaine;
	return maChaine;  // A CHANGER
}

//Renvoi true si TS
//-----------------
bool TrajetCompose::estTrajetSimple()
{
	return false;
}

//Renvoi true si dans tous le TC on passe dans ville
//--------------------------------------------------
bool TrajetCompose::estDejaPasse(const char* ville)
{
	cout << "est déjà passe de TC";
	if(strcmp(this->getVD(),ville)==0)
	{
		return true;
	}
	for(int i=0; i<tabTC->getCardActu();i++)
	{
		if(strcmp(tabTC->getCaseTab(i)->getVA(),ville)==0)
		{
			return true;
		}

	}

	return false;
}

Trajets * TrajetCompose::getTC(const int i)
{
	Trajets * monTraj = tabTC->getCaseTab(i);

	return monTraj;
}

int TrajetCompose::nbTrajActu()
{
	return tabTC->getCardActu();
}

void TrajetCompose::testType()
{
	cout<<"TrajetCompose\n";
}


void TrajetCompose::SauvegarderTraj(ofstream& fichier)
{
	string str;

	  if(fichier)  // si l'ouverture a fonctionné
        {

			 str = "TC\r\n";
			 fichier << str;

			for(int i =0; i < tabTC->getCardActu(); i++)
			{
				tabTC->getCaseTab(i)->SauvegarderTraj(fichier);
			}


			 str = "/TC\r\n";

			 fichier << str;
		}
}
