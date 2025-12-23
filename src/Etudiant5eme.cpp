#include "Etudiant5eme.h"

void Etudiant5eme::afficherMatiereDisponible() const {
    std::cout << "Matières disponibles pour un étudiant de 5ème : ";
    for (const auto& matiere : matieres_disponibles) {
        std::cout << matiere << " ";
    }
    std::cout << std::endl;
}

// void Etudiant5eme::afficherEtudiant() const {
    
// }


const std::string& Etudiant5eme::afficherNiveau() const {
    static const std::string niveau = "5ème";
    return niveau;
}

//TMP
void Etudiant5eme::inscrire_matiere(const std::string& matiere, int nombre_seance) {
    if (std::find(std::begin(matieres_disponibles), std::end(matieres_disponibles), matiere) != std::end(matieres_disponibles)) {
        matiere_inscrits.push_back(matiere);
        sInscrireSeance(matiere, nombre_seance);
        std::cout << prenom << " " << nom << " est inscrit au cours de " << matiere << "." << std::endl;
    } else {
        std::cout << prenom << " " << nom << " ne peut pas s'inscrire au cours de " << matiere << "." << std::endl;
    }
}
