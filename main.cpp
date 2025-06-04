#include <iostream>

#include "Service.h"
#include "Teste.h"
#include "Ui.h"

int main() {
    TesteCRUD();
    TesteFunctionalitati();
    Repo repo;
    Service service;
    Ui ui;
    ui.run();
}
