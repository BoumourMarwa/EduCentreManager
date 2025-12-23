#include <iostream>
#include <sstream>
#include "GestionnaireCentre.h"
#include "Enseignant.h"
#include "Groupe.h"

int main() {
    GestionnaireCentre gestionnaire;

    std::string input;
    std::cout << "Entrez une commande ('quit' pour quitter) :\n$ ";

    while (std::getline(std::cin, input)) {
        if (input == "quit") {
            break; // Sort de la boucle si la commande est "quit"
        }

        std::istringstream iss(input);
        std::string command;
        iss >> command;

        if (command == "ajouterEnseignant") {
            int id;
            std::string nom, matiere, niveau;
            iss >> id >> nom >> matiere >> niveau;
            Enseignant nouvelEnseignant(id, nom, matiere, niveau);
            gestionnaire.ajouterEnseignant(nouvelEnseignant);
        } else if (command == "modifierEnseignant") {
            int indice, id;
            std::string nom, matiere, niveau;
            iss >> indice >> id >> nom >> matiere, niveau;
            Enseignant nouvelEnseignant(id, nom, matiere, niveau);
            gestionnaire.modifierEnseignant(indice, nouvelEnseignant);
        } else if (command == "supprimerEnseignant") {
            int indice;
            iss >> indice;
            gestionnaire.supprimerEnseignant(indice);
        } else if (command == "ajouterEtudiant") {
            std::string  nom, prenom,niveau, matiere;
            int nbrSeance, idEtudiant ;
            iss >> nom >> prenom >> idEtudiant >> niveau >> matiere >> nbrSeance;
            gestionnaire.ajouterEtudiant(nom, prenom, idEtudiant, niveau, matiere, nbrSeance);
        } else if (command == "sInscrireEtudiantSeance") {
            std::string matiere;
            int nbrSeance, idEtudiant ;
            iss >> idEtudiant >> matiere >> nbrSeance;
            gestionnaire.sInscrireEtudiantSeance(idEtudiant, matiere, nbrSeance);
        } else if (command == "afficherListeEnseignants") {
            gestionnaire.afficherListeEnseignants();
        } else if (command == "afficherListeEtudiants") {
            gestionnaire.afficherListeEtudiants();
        } else if (command == "CreerGroupe") {
            int id;
            std::string niveau;
            iss >> id >> niveau;
            gestionnaire.creerGroupe(id, niveau);
        } else if (command == "afficherListeGroupes") {
            gestionnaire.afficherListeGroupes();
        } else if (command == "ajouterEtudiantInGroupe") {
            int idGroupe;
            int idEtudiant;
            iss >> idGroupe >> idEtudiant;
            gestionnaire.ajouterEtudiantInGroup(idGroupe, idEtudiant);
        } else if (command == "ajouterEnseignantInGroupe") {
            int idGroupe;
            int idEnseignant;
            iss >> idGroupe >> idEnseignant;
            gestionnaire.ajouterEnseignantInGroup(idGroupe, idEnseignant);
        } else if (command == "affecterGroupeToSeance") {
            int idGroupe, idSeance;
            std::string matiere;
            iss >> idGroupe >> idSeance >> matiere;
            gestionnaire.affecterGroupeToSeance(idGroupe, idSeance, matiere);
        } else if (command == "afficherListeSeances") {
            gestionnaire.afficherListeSeances();
        } else if (command == "passerSeance") {
            int idSeance;
            iss >> idSeance;
            gestionnaire.passerSeance(idSeance);
        } else {
            std::cout << "Commande non reconnue.\n";
        }

        std::cout << "\nEntrez une nouvelle commande ('quit' pour quitter) :\n$ ";
    }

    return 0;
}
