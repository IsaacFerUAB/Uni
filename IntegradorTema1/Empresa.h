#include <iostream>
#include <string>
using namespace std;
const int MAX_EMPLEATS = 100;

class Empresa {
public:
float importComissio(const Data& dataInici, const Data& dataFi) const;
Empresa(int nEmpleats, string empleats[MAX_EMPLEATS]);

private:
int m_nEmpleats;
Empleat m_empleats[MAX_EMPLEATS];
};