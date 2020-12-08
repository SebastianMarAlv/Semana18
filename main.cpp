//
// Sebastian Marquez Alvarez A01632483.
//
//
//
// 08/12/2020.

#include "Records.h"

int main() {
    Records pops;
    int option = 1;
    while (option) {
        bool option_done = false;
        while (!option_done) {
            std::cout   << "Introduzca el tipo de busqueda a realizar: " << std::endl
                        << "\t 1 para filtrar por anios" << std::endl
                        << "\t 2 para filtrar por precio" << std::endl
                        << "\t 3 para filtrar por marca" << std::endl
                        << "\t 4 para filtrar por media" << std::endl
                        << "\t 0 para salir" << std::endl;
            try {
                std::cin >> option;
                option_done = true;
            } catch (std::exception& e) {
                std::cout << "No se entendio el comando, intentalo de nuevo" << std::endl;
            }
        }

        switch (option) {
            case 1:
                pops.get_by_year();
                break;
            case 2:
                pops.get_by_price();
                break;
            case 3:
                pops.get_by_brand();
                break;
            case 4:
                pops.get_by_media();
                break;
            default:
                break;
        }
    }
    std::cout << "Cerrando programa" << std::endl;
    return 0;
}