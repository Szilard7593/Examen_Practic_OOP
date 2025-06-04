//
// Created by szila on 04/06/2025.
//

#include "Service.h"
#include <cassert>
#include <iostream>

void TesteFunctionalitati() {
    Service service;
    // Test adaugare zbor
    Zbor z1("1", "OTP", "LHR", 180, 100, 500);
    Zbor z2("2", "OTP", "CDG", 90, 10, 300);
    Zbor z3("3", "CLJ", "FCO", 200, 15, 200);
    service.addZbor(z1);
    service.addZbor(z2);
    service.addZbor(z3);
    assert(service.getAllZboruri().size() == 3);

    // Test filtrare durata < 120
    auto filtrate = service.filterByDuratamaimicade2(120);
    assert(filtrate.size() == 1);
    assert(filtrate[0].getId() == "2");

    // Test majorare pret pentru zboruri cu < 20 locuri
    service.majoreazaPretBileteLaZboruriCuPutineLocuri();
    auto toate = service.getAllZboruri();
    for (auto& z : toate) {
        if (z.getLocuriDisponibile() < 20) {
            if (z.getId() == "2") assert(z.getPretBilet() == 300);
            if (z.getId() == "3") assert(z.getPretBilet() == 200);
        }
    }

    // Test stergere zbor
    service.removeZbor("1");
    assert(service.getAllZboruri().size() == 2);

    // Test actualizare zbor
    Zbor z2nou("2", "OTP", "CDG", 95, 10, 350);
    service.updateZbor(z2nou);

    // Test fragmentare zbor peste 8 ore
   

}

void TesteCRUD() {
    Repo repo;
    // Test adaugare zbor
    Zbor z1("1", "OTP", "LHR", 180, 100, 500);
    repo.addZbor(z1);
    assert(repo.getAllZboruri().size() == 1);

    // Test cautare zbor
    Zbor found = repo.findZborById("1");
    assert(found.getId() == "1");

    // Test actualizare zbor



}
