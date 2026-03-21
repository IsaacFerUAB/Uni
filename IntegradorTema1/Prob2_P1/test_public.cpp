#include "Empresa.h"
#include <iostream>
#include <cmath>
#include "Empleat.h"
#include "Venda.h"
#include "Data.h"
using namespace std;

int passed = 0;
int failed = 0;

void check(const string& nom, bool ok, const string& detall = "") {
    if (ok) {
        cout << "  [OK]    " << nom << endl;
        passed++;
    } else {
        cout << "  [FAIL]  " << nom << endl;
        if (!detall.empty())
            cout << "          " << detall << endl;
        failed++;
    }
}

bool floatEq(float a, float b, float eps = 0.01f) {
    return fabs(a - b) < eps;
}

// ============================================================
// Exercici 1: Venda::operator<
// ============================================================
void testEx1() {
    cout << endl << "=== EXERCICI 1: operator< ===" << endl;

    // Test 1: Data anterior es menor
    {
        Venda v1("01/01/2024", 100.0, "A", TIPUS_A);
        Venda v2("15/06/2024", 50.0,  "B", TIPUS_B);
        check("Data anterior es menor",
                (v1 < v2) && !(v2 < v1),
                "v1(01/01/2024) hauria de ser < v2(15/06/2024)");
    }

    // Test 2: Mateixa data, import menor es menor
    {
        Venda v1("10/03/2024", 50.0,  "A", TIPUS_A);
        Venda v2("10/03/2024", 200.0, "B", TIPUS_B);
        check("Mateixa data, import menor es menor",
                (v1 < v2) && !(v2 < v1),
                "Amb mateixa data, v1(import=50) hauria de ser < v2(import=200)");
    }
}

// ============================================================
// Exercici 2: Constructors i setNom
// ============================================================
void testEx2() {
    cout << endl << "=== EXERCICI 2: Constructors i setNom ===" << endl;

    // Test 1: Constructor per defecte
    {
        Empleat e;
        check("Empleat() inicialitza nVendes a 0",
                e.getNVendes() == 0,
                "getNVendes() = " + to_string(e.getNVendes()) + ", esperat 0");
    }

    // Test 2: setNom + Empresa constructor
    {
        string noms[MAX_EMPLEATS] = {"Anna", "Bernat"};
        Empresa emp(2, noms);
        bool ok = (emp.getNEmpleats() == 2) &&
                    (emp.getEmpleat(0).getNom() == "Anna") &&
                    (emp.getEmpleat(1).getNom() == "Bernat");
        check("Empresa(2, {Anna, Bernat}) crea 2 empleats amb noms correctes",
                ok,
                "nEmpleats=" + to_string(emp.getNEmpleats()));
    }
}

// ============================================================
// Exercici 3: Empleat::afegeixVenda
// ============================================================
void testEx3() {
    cout << endl << "=== EXERCICI 3: afegeixVenda ===" << endl;

    // Test 1: Afegir una venda
    {
        Empleat e;
        Venda v("10/05/2024", 100.0, "Prod", TIPUS_A);
        bool ret = e.afegeixVenda(v);
        check("Afegir 1 venda: retorna true, nVendes=1",
                ret && (e.getNVendes() == 1),
                "retorna " + string(ret ? "true" : "false") + ", nVendes=" + to_string(e.getNVendes()));
    }

    // Test 2: Insercio ordenada per data
    {
        Empleat e;
        e.afegeixVenda(Venda("15/06/2024", 100.0, "B", TIPUS_A));
        e.afegeixVenda(Venda("01/01/2024", 50.0,  "A", TIPUS_B));
        e.afegeixVenda(Venda("31/12/2024", 200.0, "C", TIPUS_C));
        bool ok = (e.getNVendes() == 3) &&
                    (e.getVenda(0).getProducte() == "A") &&
                    (e.getVenda(1).getProducte() == "B") &&
                    (e.getVenda(2).getProducte() == "C");
        string ordre = "";
        for (int i = 0; i < e.getNVendes(); i++) {
            if (i > 0) ordre += ", ";
            ordre += e.getVenda(i).getProducte();
        }
        check("3 vendes queden ordenades per data [A, B, C]",
                ok,
              "Obtingut: [" + ordre + "]");
    }
}

// ============================================================
// Exercici 5: getComissio i importComissio
// ============================================================
void testEx5() {
    cout << endl << "=== EXERCICI 5: Comissions ===" << endl;

    // Test 1: getComissio TIPUS_A = 10%
    {
        Venda v("01/01/2024", 1000.0, "P", TIPUS_A);
        check("getComissio TIPUS_A: 10% de 1000 = 100",
              floatEq(v.getComissio(), 100.0),
              "Obtingut: " + to_string(v.getComissio()));
    }

    // Test 2: importComissio amb filtratge de dates
    {
        Empleat e;
        e.setNom("Test");
        e.afegeixVenda(Venda("15/01/2024", 1000.0, "P1", TIPUS_A)); // 100 - FORA
        e.afegeixVenda(Venda("15/03/2024", 2000.0, "P2", TIPUS_B)); // 100 - DINS
        e.afegeixVenda(Venda("15/06/2024", 500.0,  "P3", TIPUS_C)); // 10  - DINS
        Data d1, d2;
        d1.setData("01/02/2024");
        d2.setData("30/09/2024");
        float total = e.importComissio(d1, d2);
        check("importComissio filtra per rang: esperat 110.0",
              floatEq(total, 110.0),
              "Obtingut: " + to_string(total));
    }
}

// ============================================================
// MAIN
// ============================================================
int main() {
    cout << "========================================" << endl;
    cout << " TEST PUBLIC - Exercicis 1, 2, 3, 5" << endl;
    cout << "========================================" << endl;

    testEx1();
    testEx2();
    testEx3();
    testEx5();

    cout << endl << "========================================" << endl;
    cout << " Resultat: " << passed << " OK, " << failed << " FAIL" << endl;
    if (failed == 0)
        cout << " Tots els tests publics passen!" << endl;
    else
        cout << " Hi ha tests que fallen. Revisa el teu codi." << endl;
    cout << "========================================" << endl;

    return (failed == 0) ? 0 : 1;
}
