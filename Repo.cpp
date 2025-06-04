//
// Created by szila on 04/06/2025.
//

#include "Repo.h"

Repo::Repo() {
    // Constructor logic if needed
}

Repo::~Repo() {
    // Destructor logic if needed
}

void Repo::addZbor(const Zbor &zbor) {
    zboruri.push_back(zbor);
}

std::vector<Zbor> Repo::getAllZboruri() const {
    return zboruri;
}

void Repo::removeZbor(const std::string id) {
    for (auto it = zboruri.begin(); it != zboruri.end(); ++it) {
        if (it->getId() == id) {
            zboruri.erase(it);
            return;
        }
    }
}

void Repo::updateZbor(const Zbor &zbor) {
    for (auto existingZbor : zboruri) {
        if (existingZbor.getId() == existingZbor.getId()) {
            existingZbor = zbor; // Update the existing zbor with the new one
            return;
        }
    }
}

Zbor Repo::findZborById(const std::string id) {
    for (auto &zbor : zboruri) {
        if (zbor.getId() == id) {
            return zbor; // Return the found zbor
        }
    }
}

void Repo::UpdateZbor(Zbor &zbor) {
    for (auto &Zbor : zboruri) {
        if (Zbor.getId() == zbor.getId()) {
            Zbor = zbor; // Update the existing zbor with the new one
            return;
        }
    }
}

void Repo::UpdatePretZbor(const std::string id, int pretNou) {
    for (auto &zbor : zboruri) {
        if (zbor.getId() == id) {
            zbor.setPretBilet(pretNou); // Update the price of the found zbor
            return;
        }
    }
}