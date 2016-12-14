
#ifndef TABLEAU_H
#define TABLEAU_H

class Trajets;

class Tableau
{
	public:

	Tableau(unsigned int card = 0); //constrct
	Tableau (Trajets t [], unsigned int nbElements);  //CONST
	~Tableau(); // destrc

	void Ajuster (int delta);
	/*
	 */ 
	
	void Afficher();
	/* Cette méthode parcourt le tableau en attribut et appelle la méthode
	 * Afficher de chaque. Elle est appelée par la méthode Afficher de 
	 * Catalogue. 
	 */ 
	 
	int getCardActu();
	/* Renvoie le cardActu de l'objet appelant 
	 */ 
	 	
	int Ajouter (Trajets * aAjouter);
	/* Cette Méthode prend en paramètre un pointeur sur un trajet. Si cardActu
	 * est égal à cardMax (après incrémentation de card actu), elle ajuste 
	 * de 1 le tableau. Elle ajoute ensuite le trajet à l'attribut ptTableau
	 */ 
	 
	void recherche(char* VD, char* VA);
	/* Cette méthode prend en paramètre une ville de départ et d'arrivée sous
	 * de pointeurs de char. Elle parcours le tableau et test pour chaque
	 * trajets si la ville de départ et d'arrivée sont celles mises en parametre.
	 * Si c'est le cas, elle l'affiche. Cette méthode est appelée pour la
	 * recherche simple
	 */ 	
	
	Trajets * getCaseTab(unsigned int i);
	/* Renvoie le trajet à la case i (mis en paramètre) du pointeur ptTableau
	 */ 	
	
	Tableau *getTrajVilleDep(char* VD);
	/* Cette méthode prend en parametre une ville de depart et parcourt le
	 * tableau de trajets. Elle crée un tableau dans lequel elle ajoute les trajets
	 * qui ont pour villes de depart celle mise en parametre.
	 */ 	
	
	void supprimer(const unsigned int indiceEnlev);
	/* Cette methode prend en parametre un indice. Elle copie dans un tableau
	 * tampon tout les trajets sauf celui à la case i. On ecrase la mémoire
	 * de de tableau (l'attribut), de l'objet appelant dans lequel on copie
	 * ensuite le tableau tampon
	 */ 	
	
	bool estVide();
	/* Cette méthode renvoie true si cardActu est égal à 0 (Si la chaine est
	 * vide), false sinon
	 */ 	
	
	void copieTab( Tableau *  autreTab);
	/* Cette méthode prend en parametre un tableau. Elle supprime la mémoire
	 * occupée par le ptTableau de l'objet appelant et copie le tableau en
	 * parametre dans ptTableau de l'objet appelant
	 */ 

	protected:

	Trajets ** ptTableau;
	unsigned int cardMax;
	unsigned int cardActu;


};




#endif
