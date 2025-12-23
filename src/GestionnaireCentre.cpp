#include "GestionnaireCentre.h"

// Etudiant
void GestionnaireCentre::ajouterEtudiant(const std::string& nom, const std::string& prenom, int id, std::string niveau, std::string matiere,int nbrSeance){
        if (niveau=="5ème") {
            listeEtudiants.push_back(new Etudiant5eme(nom,prenom,id));
            listeEtudiants.back()->inscrire_matiere(matiere, nbrSeance);
        }
        else if(niveau=="6ème")
        {
            listeEtudiants.push_back(new Etudiant6eme(nom,prenom,id));
            listeEtudiants.back()->inscrire_matiere(matiere, nbrSeance);
        }
        else if(niveau=="Bac"){
            listeEtudiants.push_back(new EtudiantBac(nom,prenom,id));
            listeEtudiants.back()->inscrire_matiere(matiere, nbrSeance);
            }
        else{
            std::cout << "Ce niveau n'est pas disponible :\n";
        }
}

void GestionnaireCentre::afficherListeEtudiants() const {
    std::cout << "Liste des etudiants :\n";
    for (const auto& etudiant : listeEtudiants) {
        // std::cout << "ID: " << etudiant->getID() << ", Nom: " << etudiant->getNom() << ", Prénom: " << etudiant->getPrenom()
        //           << ", Niveau: " << etudiant->getNiveau() << "\n";
        etudiant->afficherEtudiant();
    }
}

//ToVerifie
Etudiant* GestionnaireCentre::getEtudiantById(int id)  {
    for (Etudiant* etudiant : listeEtudiants) {
        if (etudiant != nullptr && etudiant->getID() == id) {
            return etudiant;
        }
    }
    std::cout << "Aucun étudiant trouvé avec l'ID " << id << "." << std::endl;
    return nullptr;
}

void GestionnaireCentre::sInscrireEtudiantSeance(int idEtudiant, std::string matiere, int nbrSeance){
    Etudiant* etudiant = getEtudiantById(idEtudiant);
    etudiant->inscrire_matiere(matiere, nbrSeance);
    // etudiant->sInscrireSeance(matiere, nbrSeance);
}


// Enseignant
void GestionnaireCentre::ajouterEnseignant(const Enseignant& enseignant) {
    listeEnseignants.push_back(enseignant);
}

void GestionnaireCentre::modifierEnseignant(int index, const Enseignant& nouvelEnseignant) {
    if (index >= 0 && index < listeEnseignants.size()) {
        listeEnseignants[index] = nouvelEnseignant;
    } else {
        std::cerr << "Index invalide pour la modification de l'enseignant.\n";
    }
}

void GestionnaireCentre::afficherListeEnseignants() const {
    std::cout << "Liste des enseignants :\n";
    for (const auto& enseignant : listeEnseignants) {
        std::cout << "ID: " << enseignant.getID() << ", Nom: " << enseignant.getNom()
                  << ", Matière: " << enseignant.getMatiere() << "\n";
    }
}

void GestionnaireCentre::supprimerEnseignant(int index) {
    if (index >= 0 && index < listeEnseignants.size()) {
        listeEnseignants.erase(listeEnseignants.begin() + index);
    } else {
        std::cerr << "Index invalide pour la suppression de l'enseignant.\n";
    }
}

Enseignant* GestionnaireCentre::getEnseignantById(int id) {
    for (Enseignant& enseignant : listeEnseignants) {
        if (enseignant.getID() == id) {
            return &enseignant;
        }
    }
    std::cout << "Aucun enseignant trouvé avec l'ID " << id << "." << std::endl;
    return nullptr;
}


// Groupe
void GestionnaireCentre::creerGroupe(const int id, const std::string& niveau) {
    Groupe nouveauGroupe(id, niveau);
    listeGroupes.push_back(nouveauGroupe);
}

void GestionnaireCentre::afficherListeGroupes() const {
    std::cout << "Liste des groupes :\n";
    for (const auto& groupe : listeGroupes) {
        std::cout << "IdGroup: " << groupe.getID() << ", Niveau: " << groupe.getNiveau() << "\n";
        std::cout << "- Etudiants : " << "\n";
        for (const auto& etudiant : groupe.getEtudiants()) { // Assurez-vous que getEtudiants est une méthode dans la classe Groupe
            if (etudiant != nullptr) { // Vérification si le pointeur n'est pas nul
                std::cout << " - IdEtudiant: " << etudiant->getID() << ", Nom: " << etudiant->getNom() 
                          << ", Prénom: " << etudiant->getPrenom() << ", Niveau: " << etudiant->getNiveau() << "\n";
            }
        }
        std::cout << "- Enseignants : " << "\n";
        for (const auto& enseignant : groupe.getEnseignants()) { // Assurez-vous que getEtudiants est une méthode dans la classe Groupe
            if (enseignant != nullptr) { // Vérification si le pointeur n'est pas nul
                std::cout << " - IdEnseignant: " << enseignant->getID() << ", Nom: " << enseignant->getNom() 
                          << ", Matiere: " << enseignant->getMatiere() << ", Niveau: " << enseignant->getNiveau() << "\n";
            }
        }
    }
}

void GestionnaireCentre::ajouterEtudiantInGroup(const int indexGroupe, const int idEtudiant ) {
    Etudiant* etudiant = getEtudiantById(idEtudiant);
    // etudiant->afficherEtudiant(); //tmp
    listeGroupes[indexGroupe].ajouterEtudiant(etudiant);
}

void GestionnaireCentre::ajouterEnseignantInGroup(const int indexGroupe, const int idEnseignant ) {
    Enseignant* enseignant = getEnseignantById(idEnseignant);
    // enseignant->afficherEnseignant(); //tmp
    listeGroupes[indexGroupe].assignerEnseignant(enseignant);
}

Groupe* GestionnaireCentre::getGroupeById(int idGroupe) {
    for (auto& groupe : listeGroupes) {
        if (groupe.getID() == idGroupe) {
            return &groupe;
        }
    }
    return nullptr;
}


//Seance 
void GestionnaireCentre::affecterGroupeToSeance(int idGroupe, int idSeance, std::string matiere){
    Groupe* grp = getGroupeById(idGroupe);
    Seance nouveauSeance(idSeance, matiere, grp);
    for (auto& enseignant : grp->getEnseignants()) {
        if (enseignant->getMatiere() == matiere) {
            listeSeances.push_back(nouveauSeance);
            std::cout << "Une séance de " << matiere << "et d'identifiant " << idSeance 
            << " est bien créer pour le groupe d'identifiant " << idGroupe << "\n";
            return;
        }
    }
    std::cout << "Aucun enseignant de la matiére '" << matiere << "' n'est assigné pour ce groupe.\n";
}

void GestionnaireCentre::passerSeance(int idSeance){
   Seance* seance=getSeanceById(idSeance);

   for (auto& etudiant : seance->getGroupe()->getEtudiants()) {
        if (etudiant->getSeancesParMatiere(seance->getMatiere())==0){
             std::cout << "L'étudiant qui a un ID : " << etudiant->getID()
                      << " n'a pas le droit d'entrer à ce cours de matière : " << seance->getMatiere() << " il/elle faut repayer" << std::endl;
        }
        else {
            std::cout << "L'étudiant " << etudiant->getNom() << " est présent ? ('oui' ou 'non') :\n$ ";
            std::string input;
            if (std::getline(std::cin, input)){
                std::istringstream iss(input);
                std::string command;
                iss >> command;
                if (command == "oui") {
                    etudiant->marquerPresence(seance->getMatiere());
                } else if (command == "non") {
                    etudiant->marquerAbsence(seance->getMatiere());
                }
            }
        }
    } 
}

void GestionnaireCentre::afficherListeSeances() const {
    std::cout << "Liste des seances :\n";
    for (const auto& seance : listeSeances) {
        std::cout << "- IdSeance: " << seance.getID() << ", Matiere: " << seance.getMatiere()
        << ", Valide: " << seance.getIsValide() << " IdGroupe: " <<  seance.getGroupe()->getID() << "\n";
    
    }
}

Seance* GestionnaireCentre::getSeanceById(int idSeance){
    for (auto& seance : listeSeances) {
        if (seance.getID() == idSeance) {
            return &seance;
        }
    }
    return nullptr;
}
