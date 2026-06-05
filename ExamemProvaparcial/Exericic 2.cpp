typedef struct
{
    string titol;
    int valoracio;
} Valoracio;



class Pelicula
{
public:
    string getTitol() const { return m_titol; }
    float getValoracioMitjana() const { return m_valoracio_mitjana; }
    private:
    string m_titol;
    float m_valoracio_mitjana;
};

class SistemaValoracions
{
private:
    Usuari m_usuaris[MAX_USUARIS];
    int m_nUsuaris;
    Pelicula m_pelicules[MAX_PELICULES];
    int m_nPelicules;
};
// Implementeu els constructors necessaris de la classe Usuari perquè
//  puguem inicialitzar un objecte de la classe de qualsevol d’aquestes dues formes:
// a)
// Inicialitzar un usuari buit amb nom igual a la cadena buida, sense valoracions ni usuaris afins.
// b)
// Inicialitzar un usuari amb un nom, una llista de valoracions de pel·lícules i una llista 
// d’usuaris afins determinats que s’especifiquen en el moment de cridar al constructor.

class Usuari
{
public:
    Usuari() : m_nom(""), m_nValoracions(0), m_nUsuarisAfins(0) {}
    Usuari(string nom, int val, int usuaris, Valoracio m_valoracions[], string m_usuarisAfins[]);
    string getNom() const { return m_nom; }
    float getValoracioMitjana();
private:
    string m_nom;
    Valoracio m_valoracions[MAX_VALORACIONS];
    int m_nValoracions;
    string m_usuarisAfins[MAX_USUARIS_AFINS];
    int m_nUsuarisAfins;
};

Usuari::Usuari(string nom, int val, int usuaris, Valoracio m_valoracions[], string m_usuarisAfins[])
{
    m_nom = nom;
    m_nValoracions = val;
    m_nUsuarisAfins = usuaris;

    for(int i = 0; i < m_nValoracions; i++)
    {
        m_valoracions[i].titol = m_valoracions[i].titol;
        m_valoracions[i].valoracio = m_valoracions[i].valoracio;
    }


    for(int x = 0; x < m_nUsuarisAfins; x++)
    {
        m_usuarisAfins[x] = m_usuarisAfins[x];
    }
}

// Implementeu un mètode de la classe SistemaValoracions que rebi com a paràmetre el nom d’un fitxer i guardi en el fitxer,
//  per tots els usuaris, el seu nom, la valoració mitjana que ha fet de totes pel·lícules que ha vist, i el nom de tots els seus usuaris afins.
// Si per implementar aquest mètode cal afegir mètodes addicionals a la classe Usuari els podeu afegir i els haureu d’implementar també.


class SistemaValoracions
{
public:
    void GuardaUsuari(Usuari usuari);
private:
    Usuari m_usuaris[MAX_USUARIS];
    int m_nUsuaris;
    Pelicula m_pelicules[MAX_PELICULES];
    int m_nPelicules;
};
int 

class Usuari
{
public:
    string getNom() const { return m_nom; }
    float getValoracioMitjana() const;
    void getUsuarisAfins(string usuarios[]) const;
private:
    string m_nom;
    Valoracio m_valoracions[MAX_VALORACIONS];
    int m_nValoracions;
    string m_usuarisAfins[MAX_USUARIS_AFINS];
    int m_nUsuarisAfins;
};


float Usuari::getValoracioMitjana()
{
    float mitjana = 0.0;

    for(int i = 0; i < m_nValoracions){
        mitjana =+ m_valoracions[i].valoracio;
    }
    mitjana = mitjana / m_nValoracions;
    return mitjana;
}

string Usuari::getUsuariAfi(int index) const
{
    return m_usuarisAfins[index];
}
int Usuari::getNUsuarisAfins() const
{
    return m_nUsuarisAfins;
}

// Implementeu un mètode de la classe SistemaValoracions que rebi com a paràmetre el nom d’un fitxer i guardi en el fitxer,
//  per tots els usuaris, el seu nom, la valoració mitjana que ha fet de totes pel·lícules que ha vist, i el nom de tots els seus usuaris afins.
// Si per implementar aquest mètode cal afegir mètodes addicionals a la classe Usuari els podeu afegir i els haureu d’implementar també.

void SistemaValoracions::GuardaUsuari(string nomFitxer)
{
    ofstream fitxer;
    fitxer.open(nomfitxer);
    
    string nom = "";
    Usuari& usuari;
    float VM = 0.0;
    string usuarisAfins[MAX_USUARIS_AFINS];
    int nU_A = 0;

    for(int i = 0; i < m_nUsuaris; i++)
    {
        usuari = m_usuaris[i];
        nom = usuari.getNom();
        VM = usuari.getValoracioMitjana();
        nU_A = usuari.getNUsuarisAfins();
        
        fitxer << nom << ", ";
        fitxer << VM << ", ";
        for(int a = 0; a < nU_A; a++)
        {
            fitxer << usuari.getUsuariAfi(a) << " ";
        }
        
    }

    // NOM,VM,UA1-UA2-UA3.


    x = usuari.m_nValoracions
}