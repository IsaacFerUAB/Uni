#include "venda_entrades.h"


VendaEntrades::VendaEntrades() {}
VendaEntrades::VendaEntrades(int nSeients)
{
    seientsTeatre_m = nSeients;
    nEspectacles_m = 0;
}


void VendaEntrades::afegeixEspectacle(const string& nom, const string& dia, float preu)
{
    llistaRepresentacions_m[nEspectacles_m] = Espectacle(nom, dia, preu, seientsTeatre_m);
    nEspectacles_m++;
}

EstatCompra VendaEntrades::compraEntrades(const string& nom, string& dia, int nEntrades, float& preu, int seients[MAX_SEIENTS_COMPRA])
{
    int j = 0;
    
    int index = -1; //primera butaca trobada
    int conteo = 0; //butacas consecutivas
    bool started = false;
    bool compraPosibleAdj = false;
    int sCompra = 0;
    float valorDescompte = 0.0;
    float descompteTotal = 0.0;

    //CONMPROVAR ENTRADES VALIDES I DESCOMPTE
    if(nEntrades > MAX_SEIENTS_COMPRA){
        return ERROR_SEIENTS;
    }

    if(nEntrades > 5){
        descompteTotal += 5;
    }


//ASIGNACIO (adj o separados)
    for(int i = 0; i < nEspectacles_m; i++) //BUSCAR ESPECTACULO
    {
        if(llistaRepresentacions_m[i].getNom() == nom && llistaRepresentacions_m[i].getDia() == dia )
        {
            
            Espectacle& espectacle = llistaRepresentacions_m[i]; //GUARDO EL ESPECTACULO

            //Primer, buscarem si hi ha suficients seients lliures amb numeració consecutiva per cobrir el
            //nombre total d’entrades que es volen comprar.
            while(j < seientsTeatre_m && compraPosibleAdj == false )
            {
                if(espectacle.getOcupacio(j) == false)
                {
                    if(started)
                    {
                    conteo++;
                    }else
                    {
                        index = j;
                        started = true;
                        conteo++;
                    }
                }else
                {
                    started = false;
                    conteo = 0;
                    index = -1;
                }

                if(conteo == nEntrades)
                {
                    compraPosibleAdj = true;
                }
                j++;
            }//while CONSECUTIVO -> asientos = for(index hasta index + ntikets -1)  _ i x x _ (n = 2) 

            j = 0;
            if(compraPosibleAdj == true)
            {
                for(sCompra; sCompra < nEntrades; sCompra++)
                {
                    seients[sCompra] = index + sCompra +1;
                    espectacle.ocuparSeient(index + sCompra);
                }
                
                valorDescompte = ( nEntrades * espectacle.getPreu() * descompteTotal )/ 100.0;
                preu = (nEntrades * espectacle.getPreu()) - valorDescompte;
                return COMPRA_OK;
            }else //NO ADJECENTS + 10descuento
            {
                int butacasLliures = 0; //comprovo que hi han asients lliures
                for (int k = 0; k < seientsTeatre_m; k++) {
                    if (espectacle.getOcupacio(k) == false) {
                        butacasLliures++;
                    }
                }

                if (butacasLliures < nEntrades) {
                    return ERROR_SEIENTS;
                }
                while(j < seientsTeatre_m && sCompra < nEntrades)
                {
                    if(espectacle.getOcupacio(j) == false)
                    {
                        seients[sCompra] = j+1;
                        espectacle.ocuparSeient(j);
                        sCompra++;
                    }
                    j++;
                    
                }
                descompteTotal += 10;
                valorDescompte = ( nEntrades * espectacle.getPreu() * descompteTotal )/ 100.0;
                preu = (nEntrades * espectacle.getPreu()) - valorDescompte;
                return COMPRA_OK;
            }

        }
        
    } //for espectacles
    return ERROR_ESPECTACLE;

}

EstatCompra VendaEntrades::anulaCompra(const string& nom, const string& dia, int nEntrades, int seients[MAX_SEIENTS_COMPRA])
{
    int butaca = -1;

    

    for(int i = 0; i < nEspectacles_m; i++)
    {
        

        if(llistaRepresentacions_m[i].getNom() == nom && llistaRepresentacions_m[i].getDia() == dia )
        {
            
        for(int s = 0; s < nEntrades; s++) //butaca ya libre?
        {
            butaca = seients[s] - 1;
            if (llistaRepresentacions_m[i].getOcupacio(butaca) == false) 
            {
                return ERROR_SEIENTS;
            }
        }

        for(int j = 0; j < nEntrades; j++)
            {
                
                butaca = seients[j] - 1;
                llistaRepresentacions_m[i].desocuparSeient(butaca);
            }
            return COMPRA_OK;
        }
    }
    return ERROR_ESPECTACLE;
}

void VendaEntrades::recuperaOcupacio(const string& nom, const string& dia, bool ocupacioSeients[MAX_SEIENTS])
{
    bool recuperat = false;
    int i = 0;
    while(!recuperat && i < MAX_ESPECTACLES)
    {
        if(llistaRepresentacions_m[i].getNom() == nom && llistaRepresentacions_m[i].getDia() == dia )
        {
        for(int j = 0; j < MAX_SEIENTS; j++)
            {
                ocupacioSeients[j] = llistaRepresentacions_m[i].getOcupacio(j);
            }
            recuperat = true;
        }
        i++;
    }

}

