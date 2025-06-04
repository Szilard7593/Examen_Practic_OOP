//
// Created by szila on 04/06/2025.
//

#ifndef REPO_H
#define REPO_H
#include <vector>
#include "Zbor.h"


class Repo {
private:
    std::vector<Zbor> zboruri;
public:
    Repo();
    ~Repo();
    void addZbor(const Zbor &zbor);
    void removeZbor(const std::string id);
    void updateZbor(const Zbor &zbor);
    Zbor findZborById(const std::string id);

    void UpdateZbor(Zbor &zbor);

    void UpdatePretZbor(std::string id, int pretNou);

    std::vector<Zbor> getAllZboruri() const;


};



#endif //REPO_H
