//
// Created by szila on 04/06/2025.
//

#ifndef UI_H
#define UI_H
#include "Service.h"


class Ui {
private:
    Service service;
public:
    Ui();
    ~Ui();
    void run();
    static void showMenu();

    void AddZborT0();

    void printAllZboruri();

    void ZborDuratamaimicade2ore();

    void FragmentareZboruriIndoua();

    void AfisareStatisticiZboruri();

    void MajoreazaPretDirect();

    void FragmentareZboruriin3();


    void MajoreazaPretDirectInUi();

    void afiseazaStatisticiZboruri();
};



#endif //UI_H
