
#include <iostream>
#include <cstring>

#include "Tableau.h"
#include "Trajets.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

using namespace std;

//Constructeur par défaut Tableau vide ou de taille cardMax
//---------------------------------------------------------
Tableau::Tableau(unsigned int card)
{
	//cout <<"constructeur tableau"<<endl;
	cardMax = card;
	ptTableau = new Trajets*[cardMax];
	cardActu = 0;
}

//Constructeur qui prend en paramètre un tab de Trajets et la taille du tab
//-------------------------------------------------------------------------
Tableau::Tableau (Trajets t [], unsigned int nbElements)
{
	cardMax = nbElements;
	ptTableau = new Trajets*[cardMax];
	cardActu = 0;

	for (unsigned int i=0; i<nbElements ;i++)
	{
			cardActu++;
			*ptTableau[cardActu-1] = t[i];
	}

}

//Destructeur
//-----------
Tableau::~Tableau() //DEST
{
	//cout <<"destructeur tableau"<<endl;
	for(unsigned int i=0; i<cardActu; i++)
	{
		delete ptTableau[i];
	}	
	
	delete [] ptTableau;
}

//Ajoute un Trajet au tableau dynamique
//-------------------------------------
int Tableau::Ajouter (Trajets * aAjouter)
{
	cardActu++;


			if(cardActu > cardMax)
			{
				Ajuster(1);
			}
	
			if(aAjouter->estTrajetSimple())
			{
				TrajetSimple * monTS = new TrajetSimple();
				monTS->CopieTraj(aAjouter);
				ptTableau[cardActu-1] = monTS;
			}
			else
			{
				TrajetCompose * monTC = new TrajetCompose();
				monTC->CopieTraj(aAjouter);
				ptTableau[cardActu-1] = monTC;
			}

				

	return 1;

}

//Agrandi le tableau si besoin
//---------------------------------------------------------
void Tableau::Ajuster (int delta) // DELTA >0 POUR l'INSTANT
{
	if(delta > 0)
    {
		Trajets ** maCopie = new Trajets*[cardActu];
		
		for(unsigned int i = 0; i<cardActu; i++)
		{
			maCopie[i] = ptTableau[i];
		}

		
			delete [] ptTableau;
			ptTableau = new Trajets*[cardMax + delta];
			for(unsigned int i = 0; i<cardActu; i++)
			{
				ptTableau[i] = maCopie[i];
			}

			cardMax = cardMax + delta;
		
		delete [] maCopie;
	}
}

//Appelle la fonction Afficher() de chaque Trajet du Tableau
//---------------------------------------------------------
void Tableau::Afficher()
{
    if(cardActu != 0)
    {
        for(unsigned int i=0; i < cardActu;i++)
        {
			ptTableau[i]->Afficher();
        }

    }
}

//Renvoi le nombre d'éléments actuels du tab
//------------------------------------------
int Tableau::getCardActu()
{
	return cardActu;
}

//Appelle Afficher() des Trajets qui correspondent exactement à VD VA
//-------------------------------------------------------------------
void Tableau::recherche(char* VD, char* VA)
{
	for(unsigned int i=0; i < cardActu;i++)
        {
			if(ptTableau[i]->rechercheTraj(VD,VA))
			{
				ptTableau[i]->Afficher();
			}
        }
}

//Renvoi un pointeur vers le trajet indice i
//------------------------------------------
Trajets * Tableau::getCaseTab(unsigned int i)
{
	if(i<cardActu)
	{
	return ptTableau[i];
	}
	else
	{
	cerr << "Probleme get case tab";
	}
}

//Renvoi un tab qui contient tous les Trajets partant d'une VD
//-------------------------------------------------------------
Tableau *Tableau::getTrajVilleDep(char* VD)
{
	Tableau * monTableau = new Tableau(0);

	for(unsigned int i=0; i < cardActu;i++)
        {
			if(strcmp(ptTableau[i]->getVD(), VD)==0)
			{
				monTableau->Ajouter(ptTableau[i]);
			}
        }

        return monTableau;
}

//Supprime un élément du tab à l'indice indiceEnlev
//-------------------------------------------------
void Tableau::supprimer(const unsigned int indiceEnlev)
{
	if(indiceEnlev < cardActu)
	{
		//COPIE
		 Trajets** maCopie = new Trajets*[cardActu-1];

		 int compteurCopie=0;

		for(unsigned int i = 0; i<cardActu; i++)
		{
			if(i != indiceEnlev)
			{
				maCopie[compteurCopie] = ptTableau[i];
				compteurCopie++;
			}
		}

		delete [] ptTableau;
        ptTableau = new Trajets*[cardMax];

        for(unsigned int i = 0; i<cardActu-1; i++)
        {
            ptTableau[i] = maCopie[i];
        }

        cardActu--;
    

    delete [] maCopie;
	}
	else
	{
		cerr << "erreur suppression indiceEnlev = " << indiceEnlev <<" et cardActu = "<<cardActu<<endl;
	}
}

//Renvoi true si le tab est vide
//-------------------------------------------------
bool Tableau::estVide()
{
	if(cardActu ==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Tableau::copieTab( Tableau *  autreTab) 
{
	if(cardActu != 0)
	{
		for(unsigned int i; i<cardActu; i++)
		{
			delete  ptTableau[i];
		}
		delete  ptTableau;
	}

	ptTableau = new Trajets*[cardActu];
	for(int i = 0; i<autreTab->getCardActu(); i++) 
	{
			this->Ajouter(autreTab->getCaseTab(i));
	}
}
