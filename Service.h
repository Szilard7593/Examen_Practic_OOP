//
// Created by szila on 04/06/2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include "Repo.h"


class Service {
private:
    Repo repo;
public:
    Service();
    ~Service();
    void addZbor(const Zbor &zbor);
    void removeZbor(const std::string id);
    void updateZbor(const Zbor &zbor);
    Zbor findZborById(const std::string id);
    std::vector<Zbor> getAllZboruri() const;
    std::vector<Zbor> filterByDuratamaimicade2( int durata);
    void majoreazaPretBileteLaZboruriCuPutineLocuri();

};



#endif //SERVICE_H
