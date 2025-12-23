#include "Etudiant.h"

void Etudiant::sInscrireSeance(const std::string& matiere, int nombre_seance) {
    seancesParMatiere[matiere] = seancesParMatiere[matiere]+nombre_seance;
}

int Etudiant::GetnombreSeance(const std::map<std::string, int>& seancesParMatiere) {
    int somme = 0;
    for (const auto& paire : seancesParMatiere) {
        somme += paire.second;
    }
    return somme;
}

// void Etudiant::getSeancesParMatiere(const std::string& matiere) const {
//     auto it = seancesParMatiere.find(matiere);
//     std::cout << "L'étudiant qui a un ID : " << id
//               << " est inscrit à : " << ((it != seancesParMatiere.end()) ? it->second : 0)
//               << " séance(s) de matière : " << matiere << std::endl;
// }

int Etudiant::getSeancesParMatiere(const std::string& matiere) const {
    auto it = seancesParMatiere.find(matiere);
    if (it != seancesParMatiere.end()) {
        return it->second;
    } else {
        return 0;
    }
}


void Etudiant::marquerAbsence(const std::string& matiere) {
    absences++;
    if (absences >= 2) {
        seancesParMatiere[matiere] = seancesParMatiere[matiere] - 1;
        if (seancesParMatiere[matiere] == 0) {
            std::cout << "L'étudiant qui a un ID : " << id
                  << " doit repayer pour assister au prochain cours de matière : " << matiere << std::endl;
        }
    }
    std::cout << "marqué absent \n"; 

}

void Etudiant::marquerPresence(const std::string& matiere) {
    seancesParMatiere[matiere] = seancesParMatiere[matiere] - 1;
    if (seancesParMatiere[matiere] == 0) {
        std::cout << "L'étudiant qui a un ID : " << id
                  << " doit repayer pour assister au prochain cours de matière : " << matiere << std::endl;
    }
    std::cout << "marqué présent \n"; 
}

void Etudiant::afficherEtudiant() const {
    std::cout << "ID: " << getID() << ", Nom: " << getNom() << ", Prénom: " << getPrenom()
                  << ", Niveau: " << getNiveau() << ", Absences: " << getAbsences() << "\n";
    std::cout << "Seances par matiere :\n";
    for (const auto& seance : seancesParMatiere) {
        std::cout << "- Matiere: " << seance.first << ", Nbr de séances: " << seance.second << "\n";
    }    
}
