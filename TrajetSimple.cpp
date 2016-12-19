
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

#include "TrajetSimple.h"

#define taille_defaut 20



using namespace std;

//Constructeur TrajetSimple VD VA MT
//----------------------------------
TrajetSimple::TrajetSimple(const char* VD, const char* VA, const char* MT)
{
	//cout <<"constrcucteur TS"<<endl;
	villeDep = new char[sizeof(VD)];
	villeArr = new char[sizeof(VA)];
	moyenTransp = new char[sizeof(MT)];

	strcpy(villeDep, VD);
	strcpy(villeArr, VA);
	strcpy(moyenTransp, MT);

}
/*
TrajetSimple::TrajetSimple(string VD, string VA, string MT)
{
	//cout <<"constrcucteur TS"<<endl;
	villeDep = new char[sizeof(VD)]; // sizeof?
	villeArr = new char[sizeof(VA)];
	moyenTransp = new char[sizeof(MT)];

	strcpy(villeDep, VD);
	strcpy(villeArr, VA);
	strcpy(moyenTransp, MT);

}*/

//Constructeur par défaut ????????????????????????
//-------------------------------------------------
TrajetSimple::TrajetSimple()
{
	villeDep = new char[taille_defaut];
	villeArr = new char[taille_defaut];
	moyenTransp = new char[taille_defaut];
	//cout <<"constrcucteur TS"<<endl;
}

//Destructeur
//-----------
TrajetSimple::~TrajetSimple()
{
	//cout << "destruteur TS" << endl;
	delete [] villeDep;
	delete [] villeArr;
	delete [] moyenTransp;


}

//Affiche les infos du TS
void TrajetSimple::Afficher()
{
		cout << "TS : (VDP = " << villeDep << ", VA = "<< villeArr << ", MT = " << moyenTransp << ")" << endl;
}

//Copie un TS dans this(TS)
//-------------------------
void TrajetSimple::CopieTraj(TrajetSimple * const trajACop)
{
	delete [] villeDep;
	delete [] villeArr;
	delete [] moyenTransp;

	villeDep = new char[sizeof(trajACop->villeDep)];
	villeArr = new char[sizeof(trajACop->villeArr)];
	moyenTransp = new char[sizeof(trajACop->moyenTransp)];

	strcpy(villeDep, trajACop->villeDep);
	strcpy(villeArr, trajACop->villeArr);
	strcpy(moyenTransp, trajACop->moyenTransp);

	//cout << "copieTraj TS" <<endl;

}

//Renvoi true si VD et VA correspondent
//--------------------------------------
bool TrajetSimple::rechercheTraj(char* VD, char* VA)
{
	bool OK = true;
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
char * TrajetSimple::getVD()
{
	return villeDep;

}

//Renvoi VA
//---------
char * TrajetSimple::getVA()
{
	return villeArr;

}

//Renvoi MT
//---------
char * TrajetSimple::getMT()
{
	return moyenTransp;

}

//Renvoi true si TS
//-----------------
bool TrajetSimple::estTrajetSimple()
{
	return true;
}

bool TrajetSimple::estDejaPasse(const char* ville)
{

	cout<< "erreur TS estDejaPasse\n";

	return false;
}

void TrajetSimple::CopieTraj(Trajets * const trajACop)
{
	delete [] villeDep;
	delete [] villeArr;
	delete [] moyenTransp;

	villeDep = new char[sizeof(trajACop->getVD())];
	villeArr = new char[sizeof(trajACop->getVA())];
	moyenTransp = new char[sizeof(trajACop->getMT())];

	strcpy(villeDep, trajACop->getVD());
	strcpy(villeArr, trajACop->getVA());
	strcpy(moyenTransp, trajACop->getMT());

	//cout << "copieTraj TS \n";
}

void TrajetSimple::testType()
{
	cout<<"TrajetSimple\n";
}

 void TrajetSimple::SauvegarderTraj(ofstream& fichier)
 {
	 string str;

	  if(fichier)  // si l'ouverture a fonctionné
        {

			 str = "TS ";
			 str += villeDep;
			 str += " ";
			 str += villeArr;
			 str += " ";
			 str += getMT();
			 str += "\r\n";

			 fichier << str;
		}
 }
