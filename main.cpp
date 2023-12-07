#include "Components/Reader/Reader.hpp"
#include "Components/Tester/tester.cpp"
#include <iostream>
int main(int argc, char **argv)
{
    if (argc > 1 && std::string(argv[1]) == "--run-tests")
    {
        // Ejecutar las pruebas
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
    else
    {
        int option;
        Reader csv;
        KDTree kdtree(2);
        int n;
        std::cout << "Seleccione una opcion:" << std::endl;
        std::cout << "1. 1000 points" << std::endl;
        std::cout << "2. 10000 points" << std::endl;
        std::cout << "3. 20000 points" << std::endl;
        std::cout << "4. TESTS" << std::endl;
        std::cin >> option;
        if (option == 1)
            kdtree = csv.readAndConvert(1);
        else if (option == 2)
            kdtree = csv.readAndConvert(2);
        else if (option == 3)
            kdtree = csv.readAndConvert(3);
        else if (option == 4)
        {
            testing::InitGoogleTest();
            return RUN_ALL_TESTS();
        }
        else
        {
            std::cout << "Opcion invalida." << std::endl;
            return 1;
        }
        // Menú principal
        int choice;
        do
        {
            std::cout << "\nSeleccione una operacion:" << std::endl;
            std::cout << "1. Imprimir KDTree" << std::endl;
            std::cout << "2. Buscar punto" << std::endl;
            std::cout << "3. Salir" << std::endl;
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                kdtree.print();
                break;
            case 2:
                int x, y, z;
                std::cout << "Ingrese las coordenadas (x, y, z) del punto a buscar: ";
                std::cin >> x >> y >> z;
                kdtree.search(Vec3D(x, y, z)) ? std::cout << "El punto existe en el KDTree." << std::endl : std::cout << "El punto no existe en el KDTree." << std::endl;
                break;
            case 3:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida." << std::endl;
                break;
            }
        } while (choice != 3);
    }
    return 0;
}