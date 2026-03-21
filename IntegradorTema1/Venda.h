#include <iostream>
#include "Data.h"
typedef enum
{
TIPUS_A,
TIPUS_B,
TIPUS_C,
TIPUS_NO_ASSIGNAT
} TIPUS_VENDA;


class Venda
{
public:
    Venda();
    Venda(const string& data, float import_, const string& producte, TIPUS_VENDA tipus);

    bool operator<(const Venda& v) const;
    float getComissio() const;
    Data getData() const;

private:
    Data m_data;
    string m_producte;
    float m_import;
    TIPUS_VENDA m_tipus;
};