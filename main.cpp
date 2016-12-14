#include <iostream>
#include "Catalogue.h"

using namespace std;


int main()
{
	Catalogue * monCatalogue;
	monCatalogue = new Catalogue(); //Catalogue contenant tous les trajets


// Boucle Menu
//-----------------------------------------------------
	int choix= 0;

	while (choix != 7)
	{
		cout << "Voulez-vous :" << endl <<"1 Faire une saisie"<< endl <<"2 Faire une recherche simple"<< endl <<"3 Faire une recherche complexe" << endl<<"4 Afficher le catalogue" << endl<< "5 Sauvegarder le Catalogue" << endl << "6 Charger le catalogue" << endl << "7 quitter" << endl ;
		cin >> choix;

		switch (choix)
		{
			case 1:
				monCatalogue->SaisieSimple();
				break;

			case 2:
				monCatalogue->RechercheSimple();
				break;

			case 3:
				monCatalogue->RechercheComplexe();
				break;

			case 4:
				monCatalogue->Afficher();
				break;

			case 5:
				monCatalogue->Sauvegarder();
				break;
			case 6:
				monCatalogue->Lecture();
				break;
			case 7:
				break;

		}
	}
	

	delete monCatalogue;
//-----------------------------------------------------

    return 0;
}
