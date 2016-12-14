#ifndef TRAJETCOMPOSE_H
#define TRAJETCOMPOSE_H

#include "Trajets.h"

class TrajetSimple;
class Tableau;

class TrajetCompose : public Trajets
{
	public:

	TrajetCompose();
	~TrajetCompose(); // destrc

	void Ajouter(TrajetSimple * monTraj);
	/* Cette méthode prend en paramètre un trajet simple et appelle la
	 * méthode ajouter de l'objet appelant. Le trajet en parametre sera
	 * ajouté à l'objet appelant
	 */ 

	void Ajouter(TrajetCompose * monTraj);
	/* Cette méthode prend en paramètre un trajet compose et appelle la
	 * méthode ajouter de l'objet appelant. Le trajet en parametre sera
	 * ajouté à l'objet appelant
	 */ 

	void Ajouter(Trajets * monTraj);
	/* Cette méthode prend en paramètre un trajet et appelle la
	 * méthode ajouter de l'objet appelant. Le trajet en parametre sera
	 * ajouté à l'objet appelant
	 */ 

	void Afficher();
	/* Cette méthode est appelé lorsque l'on souhaite afficher un trajet
	 * composé. La méthode parcourt les trajets du trableau de trajet de
	 * l'objet appelant et demande leur affichage. De manière récursive,
	 * on aura l'affichage que des trajets simples qui compose le trajet
	 * compose
	 */ 

	void CopieTraj(TrajetCompose * const trajACop);
	/* Cette méthode prend un parametre un trajet compose, qu'elle copiera
	 * dans le tableau de trajet de l'objet appelant. La méthode écrase la
	 * mémoire occupé par le tableau de l'objet appelant et copie ensuite
	 * le trajet compose en parametre dans le tableau qui vient d'etre 
	 * supprimé
	 */ 

	void CopieTraj(Trajets * const trajACop);
	/*
	 */ 

	bool rechercheTraj(char* VD, char* VA);
	/*
	 */ 

	char * getVD();
	/* Renvoie la ville de départ du premier trajet composant l'objet appelant
	 */ 

	char * getVA();
	/* Renvoie la ville d'arrivée de dernier trajet composant l'objet appelant
	 */ 

	char * getMT();
	/*
	 */ 
	 
	bool estTrajetSimple();
	/* Renvoie false
	 */ 	
	
	bool estDejaPasse(const char* ville);
	/* Prend en parametre une ville et test si cette ville à déjà été visitée
	 * durant le trajets. La méthode parcourt le pointeur de trajets et 
	 * renvoie false si le nom de la ville en parametre n'est pas trouvé,
	 * true sinon
	 */ 	
	
	Trajets * getTC(const int i);
	/* Renvoie le trajet à la case i (mis en parametre formel) du pointeur
	 * de trajet de l'objet appelant
	 */ 	
	
	int nbTrajActu();
	/* Renvoie le nombre de trajet que contient le pointeur de trajet de
	 * l'objet appelant
	 */ 	
	
	void testType();
	/*
	 */ 
	 
	void SauvegarderTraj(std::ofstream& fichier);

	protected:

	Tableau *tabTC;


};




#endif
