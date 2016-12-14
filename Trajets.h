#ifndef TRAJET_H
#define TRAJET_H






class Trajets
{
	public:

	Trajets(); //constrct
	virtual ~Trajets(); // destrc

	virtual void CopieTraj(Trajets * const trajACop);
	/*
	 */

	virtual void Afficher();
	/*
	 */

	virtual bool rechercheTraj(char* VD, char* VA);
	/*
	 */

	virtual char * getVD();
	/* Méthode virtual qui affiche un message indiquant une erreur si
	 * appelé
	 */

	virtual char * getVA();
	/* Méthode virtual qui affiche un message indiquant une erreur si
	 * appelé
	 */

	virtual char * getMT();
	/* Méthode virtual qui affiche un message indiquant une erreur si
	 * appelé
	 */

	virtual bool estTrajetSimple();
	/* 
	 */

 	virtual bool estDejaPasse(const char* ville);
	/*
	 */

	virtual void testType();
	/*
	 */
	 
	//TrajetCompose * TrajtoTC(Trajets * const traj);
	//TrajetSimple * TrajtoTS(Trajets * const traj);
	
	virtual void Ajouter(Trajets * monTraj);

	virtual Trajets * getTC(const int i);
	/* Renvoie le trajet à la case i (mis en parametre formel) du pointeur
	 * de trajet de l'objet appelant
	 */ 	
	
	virtual int nbTrajActu();
	/* Renvoie le nombre de trajet que contient le pointeur de trajet de
	 * l'objet appelant
	 */ 	
	virtual void SauvegarderTraj(std::ofstream& fichier);


	protected:



};




#endif
