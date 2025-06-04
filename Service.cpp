//
// Created by szila on 04/06/2025.
//

#include "Service.h"
Service::Service() {

}

Service::~Service() = default;


void Service::addZbor(const Zbor &zbor) {
    repo.addZbor(zbor);
}

void Service::removeZbor(const std::string id) {
    repo.removeZbor(id);
}

void Service::updateZbor(const Zbor &zbor) {
    repo.updateZbor(zbor);
}

Zbor Service::findZborById(const std::string id) {
    return repo.findZborById(id);
}

std::vector<Zbor> Service::getAllZboruri() const {
    return repo.getAllZboruri();
}

std::vector<Zbor> Service::filterByDuratamaimicade2(int durata) {
    std::vector<Zbor> filteredZboruri;
    for (auto &zbor : repo.getAllZboruri()) {
        if (zbor.getDurata() < durata) {
            filteredZboruri.push_back(zbor);
        }
    }
    return filteredZboruri;
}

void Service::majoreazaPretBileteLaZboruriCuPutineLocuri() {
    auto zboruri = repo.getAllZboruri();
    for (auto &zbor : zboruri) {
        if (zbor.getLocuriDisponibile() < 20) {
            int pretNou = static_cast<int>(zbor.getPretBilet() * 1.1);
            zbor.setPretBilet(pretNou);
            repo.updateZbor(zbor); // actualizează zborul modificat în Repo
        }
    }
}


