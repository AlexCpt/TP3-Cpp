Application : Trajets.o TrajetSimple.o TrajetCompose.o Tableau.o Catalogue.o main.o
	echo "Edition des liens de l'Application"
	g++ -o Application Trajets.o TrajetSimple.o TrajetCompose.o Tableau.o Catalogue.o main.o
Trajets.o : Trajets.cpp Trajets.h TrajetCompose.h
	echo "Compilation de <Trajets.cpp>"
	g++ -c Trajets.cpp
TrajetSimple.o : TrajetSimple.cpp TrajetSimple.h Trajets.h TrajetCompose.h
	echo "Compilation de <TrajetSimple.cpp>"
	g++ -c TrajetSimple.cpp
TrajetCompose.o : TrajetCompose.cpp TrajetCompose.h Tableau.h Trajets.h TrajetSimple.h
	echo "Compilation de <TrajetsCompose.cpp>"
	g++ -c TrajetCompose.cpp
Tableau.o : Tableau.cpp Tableau.h Trajets.h TrajetSimple.h TrajetCompose.h
	echo "Compilation de <Tableau.cpp>"
	g++ -c Tableau.cpp
Catalogue.o : Catalogue.cpp Catalogue.h Trajets.h TrajetSimple.h Tableau.h
	echo "Compilation de <Catalogue.cpp>"
	g++ -c Catalogue.cpp
main.o : main.cpp Catalogue.h
	echo "Compilation de <main.cpp>"
	g++ -c main.cpp

PHONY : clean
clean : rm -f Application Trajet.o TrajetSimple.o TrajetCompose.o TabDynChaine.o Tableau.o Catalogue.o main.o
