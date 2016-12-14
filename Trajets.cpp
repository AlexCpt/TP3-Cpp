#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "Trajets.h"

using namespace std;



Trajets::Trajets() // CONSTR
{
	//cout <<"constructeur traj"<<endl;
}



Trajets::~Trajets() //DEST
{
 //cout << "destructeur traj" << endl;
}

void Trajets::CopieTraj(Trajets * const trajACop)
{

}

void Trajets::Afficher() //AFFI
{

}

bool Trajets::rechercheTraj(char* VD, char* VA)
{
	return true;
}

char * Trajets::getVD()
{
	cout << "ERREUR T getVD \n";
	char * maChaine;
	return maChaine;  // A CHANGER
}

char * Trajets::getVA()
{
	cout << "ERREUR T getVA\n";
	char * maChaine;
	return maChaine;  // A CHANGER
}

char * Trajets::getMT()
{
	cout << "ERREUR T getMT\n";
	char * maChaine;
	return maChaine;  // A CHANGER
}

 bool Trajets::estTrajetSimple()
{
	cout << "erreur T est TrajetSimple\n";
	return false;
}

 bool Trajets::estDejaPasse(const char* ville)
{
	cout << "erreur T estDejapasse\n";

 return false;
}

void Trajets::testType()
{
	cout<<"Trajets\n";
}

void Trajets::Ajouter(Trajets * monTraj)
{
	cout << "erreur T Ajouter";
}

Trajets * Trajets::getTC(const int i)
{
	
}
	
 int Trajets::nbTrajActu()
 {
    return -1;
 }
 
 void Trajets::SauvegarderTraj(ofstream& fichier)
 {
	 
 }

