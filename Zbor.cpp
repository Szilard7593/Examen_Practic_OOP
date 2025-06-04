//
// Created by szila on 04/06/2025.
//

#include "Zbor.h"
#include <string>

Zbor::Zbor() {
    id = "0";
    aeroportPlecare = "0";
    aeroportDestinatie = "0";
    durata = 0;
    locuriDisponibile = 0;
    pretBilet = 0;
}
Zbor::Zbor(std::string id, std::string aeroportPlecare, std::string aeroportDestinatie, int durata, int locuriDisponibile, int pretBilet) {
    this->id = id;
    this->aeroportPlecare = aeroportPlecare;
    this->aeroportDestinatie = aeroportDestinatie;
    this->durata = durata;
    this->locuriDisponibile = locuriDisponibile;
    this->pretBilet = pretBilet;
}

Zbor::Zbor(const Zbor &zbor) {
    this->id = zbor.id;
    this->aeroportPlecare = zbor.aeroportPlecare;
    this->aeroportDestinatie = zbor.aeroportDestinatie;
    this->durata = zbor.durata;
    this->locuriDisponibile = zbor.locuriDisponibile;
    this->pretBilet = zbor.pretBilet;
}

Zbor::~Zbor() {
    // Destructor logic if needed
}

std::string Zbor::getId() {
    return id;
}

std::string Zbor::getAeroportPlecare() {
    return aeroportPlecare;
}

std::string Zbor::getAeroportDestinatie() {
    return aeroportDestinatie;
}

int Zbor::getDurata() {
    return durata;
}

int Zbor::getLocuriDisponibile() {
    return locuriDisponibile;
}

int Zbor::getPretBilet() {
    return pretBilet;
}

void Zbor::setId(std::string id) {
    this->id = id;
}

void Zbor::setAeroportPlecare(std::string aeroportPlecare) {
    this->aeroportPlecare = aeroportPlecare;
}

void Zbor::setAeroportDestinatie(std::string aeroportDestinatie) {
    this->aeroportDestinatie = aeroportDestinatie;
}

void Zbor::setDurata(int durata) {
    this->durata = durata;
}

void Zbor::setLocuriDisponibile(int locuriDisponibile) {
    this->locuriDisponibile = locuriDisponibile;
}

void Zbor::setPretBilet(int pretBilet) {
    this->pretBilet = pretBilet;
}


