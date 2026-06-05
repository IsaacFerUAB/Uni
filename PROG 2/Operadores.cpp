
#include <iostream>
using namespace std;


class Data
{
public:
Data() { m_dia = 0; m_mes = 0; m_any = 0; }
Data(int dia, int mes, int any) : m_dia(dia), m_mes(mes), m_any(any) { }
void setData(int dia, int mes, int any) { m_dia = dia; m_mes = mes; m_any = any;}
void setDia(int dia) { m_dia = dia; }
void setMes(int mes) { m_mes = mes; }
void setAny(int any) { m_any = any; }
void llegeix();
int getDia() const { return m_dia; }
int getMes() const { return m_mes; }
int getAny() const { return m_any; }
private:
int m_dia, m_mes, m_any;
};

bool Data::operator<(const Data& d)
{
    if(m_any < d.m_any) {return true;}
    if(m_any > d.m_any) {return false;}
    
    if(m_mes < d.m_mes) {return true;}
    if(m_mes > d.m_mes) {return false;}

    if(m_dia < d.m_dia) {return true;}
    return false;
}

bool Data::operator==(const Data& d)
{
    if (m_any == d.m_any && m_mes == d.m_mes && m_dia == d.m_dia)
    {
        return true;
    }
    return false;
}

bool Data::operator<=(const Data& d)
{
    if(*this<d) {return true;}
    if(*this==d){return true;}
    return false;
}

Data Data::operator+(int dies)
{
    Data original = *this;
    original =+ dies;
    return original;
}

Data& Data::operator++() {
    m_dia++;
    if (m_dia > diesMes(m_mes, m_any)) { // Ens hem passat de mes?
        m_dia = 1;
        m_mes++;
        if (m_mes > 12) { // Ens hem passat d'any?
            m_mes = 1;
            m_any++;
        }
    }
    return *this;
}

// 2. Sumar N dies (Reaprofitem ++)
Data& Data::operator+=(int dies) {
    for (int i = 0; i < dies; i++) {
        ++(*this); // Cridem a l'operador ++ que acabem de fer
    }
    return *this;
}


istream& operator>>(istream& input, Data& data)
{
    int any,mes,dia;

    cout << "Any:";
    input >> any;
    data.setAny(any);

    cout << "Mes:";
    input >> mes;
    data.setMes(mes);

    cout << "Dia:";
    input >> dia;
    data.setDia(dia);


    return input;
}

ostream& operator<<(ostream& output, const Data& data)
{
    int dia,mes,any;
    dia = data.getDia();
    mes = data.getMes();
    any = data.getAny();
    output << dia << "/" << mes << "/" << any;
    return output;
}


void Data::llegeix(const string& nomarchiu)
{
    ifstream f;
    f.open(nomarchiu);

    if(f.is_open)
    {
        f >> m_dia >> m_mes >> m_any;
    }
    f.close();
}

void Data::Guarda(const string& nomarchiu) const
{
    ofstream f;
    f.open(nomarchiu);

    if(f.is_open())
    {
        f << m_dia << " " << m_mes << " " << m_any;
    }
    f.close();
}
