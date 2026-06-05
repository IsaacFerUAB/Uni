class Racional
{
public:
void llegeix();
void mostra();
private:
float m_numerador, m_denominador;
};

// Els mètodes llegeix i mostra permeten, respectivament, llegir de teclat el numerador i el denominador,
//  i mostrar per pantalla el valor del nombre racional.
// Volem fer un programa que permeti llegir un nombre racional de teclat i multiplicar-lo o bé per un altre nombre racional,
//  o bé per un nombre real, i mostrar el resultat per pantalla.
// Us demanem:
// 
// a) Implementeu els operadors necessaris de la classe Racional per poder fer la multiplicació tant per un altre nombre racional com per un nombre real.
// 
// b)
// Utilitzant els operadors anteriors, implementeu el programa principal que: 
// 1) llegeix un nombre racional; 
// 2) pregunta a l’usuari si vol fer la multiplicació per un altre racional o un real; 
// 3) llegeix el valor corresponent per pantalla; 
// 4) fa la multiplicació i 
// 5) mostra el resultat per pantalla.
// El programa principal ha de ser el més simple possible, aprofitant tota la funcionalitat dels operadors que haureu definit a la classe Racional.

Racional Racional::operator*(const Racional& R) const
{
    Racional solucio;
    solucio.m_numerador = m_numerador * R.m_numerador;
    solucio.m_denominador = m_denominador * R.m_denominador;
    return solucio;
}

Racional Racional::operator*(const int& real) const
{
    Racional solucio;
    solucio.m_numerador = m_numerador * real;
    solucio.m_denominador = m_denominador;
    return solucio;
}

int main()
{
    Racional n1;
    Racional resultat;
    int real = 0;
    n1.llegeix();
    
    cout << "Vol fer la multiplicació per un altre racional (1) o un real (2)?" << endl;
    cin << r;
    

    if(r == 1)
    {
        n2.llegeix();
        resultat = n1 * n2;
    }else if(r == 2)
    {
        cin >> real;
        resultat = n1 * real;
    }
    resultat.mostra();
    return 0;
}