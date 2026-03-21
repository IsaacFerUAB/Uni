#include <iostream>
using namespace std;
#include <string>
class Data
{
public:
Data();
void setData(const string& data){ m_data = data };
bool operator<(const Data& d) const;
bool operator==(const Data& d) const;
bool operator>(const Data& d) const;

int getDia() const {
    int decena = ((data[0] - '0') * 10);
    m_dia = decena + (data[1] - '0');return m_dia; 
}

int getMes() const {
    decena = ((data[3]- '0') * 10);
    m_mes = decena + (data[4] - '0');

    return m_mes;
    }

int getAny() const {
    int miler = ((data[6] - '0') * 1000);
    int centena = ((data[7] - '0') * 100);
    decena = ((data[8] - '0') * 10);
    m_any = decena + (data[9] - '0');

    return m_any; 
    }

private:

    int m_dia;
    int m_mes;
    int m_any;
    string m_data;
};