#ifndef LANCHACOM_H
#define LANCHACOM_H
#include "barco.h"
#include <vector>
class lanchaCom :public barco
{
private:
    std::string nombre = "lancha de combate";
    int HP = 1;
    std::vector<std::pair<int , int>> MovPo;
public:
    lanchaCom();
    lanchaCom(int, int, char);
    void danio(int, int);
    bool muerto();
    ~lanchaCom(){};

};

#endif // LANCHACOM_H
