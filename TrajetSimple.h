#ifndef TRAJETSIMPLE_H
#define TRAJETSIMPLE_H

#include "Trajets.h"

class TrajetSimple : public Trajets
{
	public:

	TrajetSimple(const char* VD, const char* VA, const char* MT); // constrct
	//TrajetSimple(std::string VD, std::string VA, std::string MT);
	
	~TrajetSimple(); // destrc
	
	
	TrajetSimple (TrajetSimple const& TrajetACop);
	/* 
	 */ 
	
	TrajetSimple ();
	/*
	 */	
	
	TrajetSimple& operator=(TrajetSimple const& TSACopier);
	/*
	 */

	void CopieTraj(TrajetSimple * const trajACop);
	/* Cette méthode prend un parametre un trajet simple, qu'elle copiera
	 * dans le tableau de trajet de l'objet appelant. La méthode écrase la
	 * mémoire occupé par le tableau de l'objet appelant et copie ensuite
	 * le trajet compose en parametre dans le tableau qui vient d'etre 
	 * supprimé
	 */ 	
	
	void CopieTraj(Trajets * const trajACop);
	/*
	 */	
	
	void Afficher();
	/* Cette méthode est appelé lorsque l'on veut afficher un trajet simple.
	 * Elle affiche la ville de départ, la ville d'arrivée et le moyen de
	 * transport
	 */	
	
	bool rechercheTraj(char* VD, char* VA);
	/* Cette méthode prend en parametre la ville d'arrivée et la ville 
	 * de départ. Elle test si la ville d'arrivée et la ville de départ sont
	 * identiques à celles mises en parametre. Si c'est le cas, la méthode
	 * renvoie true, sinon elle renvoie false
	 */	
	
	char * getVA();
	/* Renvoie la ville d'arrivée de l'objet appelant
	 */	
	
	bool estTrajetSimple();
	/* Renvoie true
	 */	
	
	bool estDejaPasse(const char* ville);
	/*
	 */	
	
	void testType();
	/*
	 */

	char * getVD();
	/* Renvoie la ville de départ de l'objet appelant
	 */
	
	char * getMT();
	/* Renvoie le moyen de transport de l'objet appelant
	 */
	 
	 void SauvegarderTraj(std::ofstream& fichier);

	protected:

	char * villeDep;
	char * villeArr;
	char * moyenTransp;



};



#endif
