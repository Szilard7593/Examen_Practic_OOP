//
// Created by szila on 04/06/2025.
//
#include <iostream>
#include "Ui.h"
 Ui::Ui() = default;
Ui::~Ui() = default;

void Ui::run() {
    int option;
    do {
        showMenu();
        std::cout << "Alege optiunea: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                AddZborT0();
                break;
            }
            case 2: {
                printAllZboruri();
                break;
            }
            case 3: {
                ZborDuratamaimicade2ore();
                break;

            }
            case 4: {
                MajoreazaPretDirect();
                break;
            }
            case 5: {
                FragmentareZboruriin3();
                                break;
            }
            case 6: {
                AfisareStatisticiZboruri();
                break;
            }

            default:
                std::cout << "Optiune inexistenta" << std::endl;
        }
    } while (option != 7);
}

void Ui::showMenu() {
    std::cout << "1.Adaugare zbor"<< std::endl;
    std::cout << "2.F1.Listare toate zboruri"<< std::endl;
    std::cout << "3.F2.Identificare si listare zbor durata < 2 ore" << std::endl;
    std::cout << "4.F3.Zbor<20pasageri modificare pret" << std::endl;
    std::cout << "5.F4.Escala" << std::endl;
    std::cout << "6.F5.Afisare statistici" << std::endl;
    std::cout << "7.Iesire" << std::endl;
};

void Ui::AddZborT0() {
    std::string id, aeroportPlecare, aeroportDestinatie;
    int durata, locuriDisponibile, pretBilet;
    std::cout << "Introduceti ID-ul zborului: ";
    std::cin >> id;
    std::cout << "Introduceti aeroportul de plecare: ";
    std::cin >> aeroportPlecare;
    std::cout << "Introduceti aeroportul de destinatie: ";
    std::cin >> aeroportDestinatie;
    std::cout << "Introduceti durata zborului (in minute): ";
    std::cin >> durata;
    std::cout << "Introduceti numarul de locuri disponibile: ";
    std::cin >> locuriDisponibile;
    std::cout << "Introduceti pretul biletului: ";
    std::cin >> pretBilet;

    Zbor zbor(id, aeroportPlecare, aeroportDestinatie, durata, locuriDisponibile, pretBilet);
    service.addZbor(zbor);

}

void Ui::printAllZboruri() {
    auto zboruri = service.getAllZboruri();
    for (auto &zbor : zboruri) {
        std::cout << "ID: " << zbor.getId() << ", Plecare: " << zbor.getAeroportPlecare()
                  << ", Destinatie: " << zbor.getAeroportDestinatie() << ", Durata: "
                  << zbor.getDurata() << ", Locuri disponibile: " << zbor.getLocuriDisponibile()
                  << ", Pret bilet: " << zbor.getPretBilet() << "\n";
    }

}

void Ui::ZborDuratamaimicade2ore() {
    int durataLimita = 120; // 2 ore
    auto zboruriFiltrate = service.filterByDuratamaimicade2(durataLimita);
    for (auto &zbor : zboruriFiltrate) {
        std::cout << "ID: " << zbor.getId() << ", Plecare: " << zbor.getAeroportPlecare()
                  << ", Destinatie: " << zbor.getAeroportDestinatie() << ", Durata: " << zbor.getDurata()<<std::endl;

    }
}

void Ui::FragmentareZboruriIndoua() {
    auto zboruri = service.getAllZboruri();
    bool fragmentat = false;
    for (auto& zbor : zboruri) {
        if (zbor.getDurata() > 480) {
            // Sterge zborul original
            service.removeZbor(zbor.getId());
            // Calculeaza valori pentru cele doua zboruri
            int durata1 = zbor.getDurata() / 3;
            int durata2 = zbor.getDurata() /3;
            int durata3 = zbor.getDurata() - durata2 -durata1;
            int locuri1 = zbor.getLocuriDisponibile() / 3;
            int locuri2 = zbor.getLocuriDisponibile() / 3;
            int locuri3 = zbor.getLocuriDisponibile() - (locuri1 + locuri2);
            int pret1 = zbor.getPretBilet() / 3;
            int pret2 = zbor.getPretBilet() - (pret1+pret1) ;
            int pret3 = zbor.getPretBilet() - pret2;
            // Creeaza doua zboruri noi cu escala tehnica
            Zbor zbor1(zbor.getId() + "_A", zbor.getAeroportPlecare(), "Escala_Tehnica", durata1, locuri1, pret1);
            Zbor zbor2(zbor.getId() + "_B", "Escala_Tehnica", zbor.getAeroportDestinatie(), durata2, locuri2, pret2);
            Zbor zbor3(zbor3.getId() + "C","Punctul de escala trei",zbor.getAeroportDestinatie(),durata3,locuri3,pret3 );
            service.addZbor(zbor1);
            service.addZbor(zbor2);
            service.addZbor(zbor3);
            fragmentat = true;
        }
    }
    if (fragmentat)
        std::cout << "Zborurile peste 8 ore au fost fragmentate in doua cu escala tehnica!\n";
    else
        std::cout << "Nu exista zboruri cu durata peste 8 ore!\n";
}


void Ui::AfisareStatisticiZboruri() {
    auto zboruri = service.getAllZboruri();
    int totalZboruri = zboruri.size();
    int totalLocuri = 0;
    int totalPret = 0;

    for ( auto& zbor : zboruri) {
        totalLocuri += zbor.getLocuriDisponibile();
        totalPret += zbor.getPretBilet();
    }

    std::cout << "Total zboruri: " << totalZboruri << std::endl;
    std::cout << "Total locuri disponibile: " << totalLocuri << std::endl;
    std::cout << "Total pret bilete: " << totalPret << std::endl;
}

void Ui::MajoreazaPretDirect() {
    auto zboruri = service.getAllZboruri();
    bool modificat = false;
    for (auto& zbor : zboruri) {
        if (zbor.getLocuriDisponibile() < 20) {
            int pretNou = static_cast<int>(zbor.getPretBilet() * 1.1);
            zbor.setPretBilet(pretNou);
            service.updateZbor(zbor);
            modificat = true;
        }
    }
    if (modificat)
        std::cout << "Preturile biletelor pentru zborurile cu mai putin de 20 de locuri au fost majorate cu 10%." << std::endl;
    else
        std::cout << "Nu exista zboruri cu mai putin de 20 de locuri!" << std::endl;
    printAllZboruri();
}

void Ui::FragmentareZboruriin3() {
    auto zboruri = service.getAllZboruri();
    bool fragmentat = false;
    for (auto& zbor : zboruri) {
        if (zbor.getDurata() > 720) {
            service.removeZbor(zbor.getId());
            int durata1 = zbor.getDurata() / 3;
            int durata2 = zbor.getDurata() / 3;
            int durata3 = zbor.getDurata() - durata1 - durata2;
            int locuri1 = zbor.getLocuriDisponibile() / 3;
            int locuri2 = zbor.getLocuriDisponibile() / 3;
            int locuri3 = zbor.getLocuriDisponibile() - locuri1 - locuri2;
            int pret1 = zbor.getPretBilet() / 3;
            int pret2 = zbor.getPretBilet() / 3;
            int pret3 = zbor.getPretBilet() - pret1 - pret2;
            Zbor zbor1(zbor.getId() + "_A", zbor.getAeroportPlecare(), "Escala1", durata1, locuri1, pret1);
            Zbor zbor2(zbor.getId() + "_B", "Escala1", "Escala2", durata2, locuri2, pret2);
            Zbor zbor3(zbor.getId() + "_C", "Escala2", zbor.getAeroportDestinatie(), durata3, locuri3, pret3);
            service.addZbor(zbor1);
            service.addZbor(zbor2);
            service.addZbor(zbor3);
            fragmentat = true;
        }
    }
    if (fragmentat)
        std::cout << "Zborurile peste 12 ore au fost fragmentate in 3 cu doua escale tehnice!\n";
    else
        std::cout << "Nu exista zboruri cu durata peste 12 ore!\n";
}