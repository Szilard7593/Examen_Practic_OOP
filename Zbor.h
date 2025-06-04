//
// Created by szila on 04/06/2025.
//

#ifndef ZBOR_H
#define ZBOR_H
#include <string>


class Zbor {
private:
    std::string id;
    std::string aeroportPlecare;
    std::string aeroportDestinatie;
    int durata;
    int locuriDisponibile;
    int pretBilet;
public:
    Zbor();
    Zbor( std::string id, std::string aeroportPlecare, std::string aeroportDestinatie, int durata, int locuriDisponibile, int pretBilet);
    Zbor(const Zbor &zbor);
    ~Zbor();
    std::string getId();
    std::string getAeroportPlecare();
    std::string getAeroportDestinatie();
    int getDurata();
    int getLocuriDisponibile();
    int getPretBilet();
    void setId(std::string id);
    void setAeroportPlecare(std::string aeroportPlecare);
    void setAeroportDestinatie(std::string aeroportDestinatie);
    void setDurata(int durata);
    void setLocuriDisponibile(int locuriDisponibile);
    void setPretBilet(int pretBilet);


};



#endif //ZBOR_H
