#include "Groupe.h"

void Groupe::ajouterEtudiant(Etudiant* etudiant) {
    if (etudiants.size() < 8 && etudiant->afficherNiveau() == niveau) {
        etudiants.push_back(etudiant);
        std::cout << "Étudiant ajouté au groupe." << std::endl;
    } else {
        std::cout << "Impossible d'ajouter l'étudiant à ce groupe, veuillez créer un autre groupe." << std::endl;
    }
}
//TO VEREFY
bool Groupe::isExist(std::string matiere) {
    for (Enseignant* enseignant : enseignants) {
        if (enseignant->getMatiere() == matiere) {
            return true;
        }
    }
    return false;
}

void Groupe::assignerEnseignant( Enseignant* enseignant){
    if (enseignant->getNiveau() == niveau) {
        if (isExist(enseignant->getMatiere())){
            std::cout<<"il exist deja un enseignant de cette matiere pour ce groupe"<<std::endl;
        }
        else {
            enseignants.push_back(enseignant);
            std::cout << "Professeur assigné au groupe." << std::endl;
        }
    } else {
        std::cout << "Impossible d'assigner le professeur au groupe, niveau non compatible." << std::endl;
    }
}

void Groupe::afficherGroupe() const {
    std::cout << "Groupe de niveau " << niveau << " contient : " << etudiants.size() << " étudiant(s)." << std::endl;
}
//TO DO
//void Groupe::afficherEnseignantsDuGroupe() const{

    //if (professeur.getNiveau() == niveau) {
       // std::cout << "Professeur : " << professeur.getNom() << " enseigne Matière : " << professeur.getMatiere()
              //    << " (Niveau : " << professeur.getNiveau() << ")" << std::endl;
   // }
//}
