#include "Etudiant6eme.h"

void Etudiant6eme::afficherMatiereDisponible() const {
    std::cout << "Matières disponibles pour un étudiant de 6ème : ";
    for (const auto& matiere : matieres_disponibles) {
        std::cout << matiere << " ";
    }
    std::cout << std::endl;
}

const std::string& Etudiant6eme::afficherNiveau() const {
    static const std::string niveau = "6ème";
    return niveau;
}

void Etudiant6eme::inscrire_matiere(const std::string& matiere, int nombre_seance) {
    if (std::find(std::begin(matieres_disponibles), std::end(matieres_disponibles), matiere) != std::end(matieres_disponibles)) {
        matiere_inscrits.push_back(matiere);
        sInscrireSeance(matiere, nombre_seance);
        std::cout << prenom << " " << nom << " est inscrit au cours de " << matiere << "." << std::endl;
    } else {
        std::cout << prenom << " " << nom << " ne peut pas s'inscrire au cours de " << matiere << "." << std::endl;
    }
}
