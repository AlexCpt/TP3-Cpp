#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <vector>


class Tableau;
class Trajets;

class Catalogue
{
	
	public:

	//Constructeur / Destructeur :
	Catalogue();
	~Catalogue();
	//------------------------

	void SaisieSimple();
	/* Cette méthode ne prend pas de paramètre formel. Cette méthode est 
	 * appelée dès que l'utilisateur demande un nouveau trajet. Il 
	 * demande à l'utilisateur le nombre d'escale qui compose le trajet 
	 * (0 désignant un trajet simple). En fonction de cette saisie au
	 * clavier, la méthode demande les informations qui lui permet de
	 * créer le nouveau trajet, qui sera ajouté au tableau pointé par tabCata, grace
	 * à l'appel de la méthode Ajouter.
	 */
	
	void Ajouter(Trajets * monTrajet);
	/* Cette méthode prend en paramètre un trajet et appel la méthode 
	 * Ajouter de tableau. Ce trajet, sera Ajouter au tableau pointé
	 * par tabCata
	 */
	void Afficher();
	/* Cette méthode ne prend pas de paramètre formel. Ell est appelée 
	 * lorsque l'utilisateur demande un affichage des trajets Elle appelle la
	 * méthode Afficher de Tableau, qui affichera tous les Trajets.
	 */
	 
	void RechercheSimple();
	/* Cette méthode demande à l'utilisateur où il souhaite aller et 
	 * depuis quelle ville, mais la recherche se fera sans escales. 
	 * Elle stocke les deux informations dans un pointeur. Les informations 
	 * permettentvoid Catalogue::Sauvegarder() l'appel de la méthode recherche de tabCata 
	 */
	void RechercheComplexe();
	/* Cette méthode demande à l'utilisateur où il souhaite aller et 
	 * depuis quelle ville, la recherche cherche des toutes les possibilités
	 * de relier les deux villes, elle peut proposer des trajets composés
	 * de plusieurs trajets 
	 */
	 
	Tableau * RechercheAll(char * villeDep);
	/* Cette méthode prend en paramètre formel la ville de depart. Elle
	 * appelle la méthode getTrajVilleDep et met le retour dans un tableau
	 * qu'elle crée au préalable. Pour des raisons pratiques pour la suite,
	 * elle transforme chaque trajet simple en trajet composé (la classe
	 * trajet simple n'ayant pas de méthode ajouter)   
	 */
	 
	char** SaisieParamRecherche();
	/* Cette méthode est appelé lorsqu'une des deux méthodes recherches
	 * est appelée. Elle permet à l'utilisateur de saisir la ville de 
	 * départ et la ville d'arrivée du trajet qu'il souhaite faire. La
	 * méthode renvoie un pointeur sur deux pointeurs de char qui contiennent
	 * les deux saisies.
	 */

	void Sauvegarder();
	
	void Lecture();
	
	std::vector<std::string> split(std::string s);

	protected:

	Tableau *tabCata; //Tableau dynamique de Trajets


};


#endif
