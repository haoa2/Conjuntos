#include <iostream>
#include "../LibConjuntos/Conjunto.hpp"


int main(int argc, char const *argv[])
{
	float entrada;
	char opcion;

	std::cout << "Programa para ejecutar operaciones con Conjuntos" << std::endl;

	std::string nom1, nom2;

	std::cout << "Introduce el nombre del conjunto 1: ";
	std::cin >> nom1;
	std::cout << "Introduce el nombre del conjunto 2: ";
	std::cin >> nom2;

	Conjunto<float> c1(nom1), c2(nom2), Universo("Universo");

	try
	{
		// Leer datos del primer conjunto.
		std::cout << "Introduzca los elementos del Conjunto " << nom1 <<  "." << std::endl;
		do{
			std::cout << "Introduzca el elemento a agregar: ";
			std::cin >> entrada;
			do{
				std::cout << "¿Desea agregar otro elemento? S/N> ";
				std::cin >> opcion;
			}while(opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');
			c1.agregar(entrada);
		}while(opcion == 'S' || opcion == 's');

		// Leer datos del segundo conjunto.
		std::cout << "Introduzca los elementos del Conjunto " << nom2 <<  "." << std::endl;
		do{ 
			std::cout << "Introduzca el elemento a agregar: ";
			std::cin >> entrada;
			do{
				std::cout << "¿Desea agregar otro elemento? S/N> ";
				std::cin >> opcion;
			}while(opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');
			c2.agregar(entrada);
		}while(opcion == 'S' || opcion == 's');

		// Leer datos del conjunto universo.
		std::cout << "Introduzca los elementos del Conjunto Universo." << std::endl;
		do{
			std::cout << "Introduzca el elemento a agregar: ";
			std::cin >> entrada;
			do{
				std::cout << "¿Desea agregar otro elemento? S/N> ";
				std::cin >> opcion;
			}while(opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');
			Universo.agregar(entrada);
		}while(opcion == 'S' || opcion == 's');

		std::cout << "Realizando las operaciones básicas entre los 3 Conjuntos." << std::endl << std::endl;
		
		std::cout << "Contenido de los conjuntos:" << std::endl;
		std::cout << c1 << std::endl;
		std::cout << c2 << std::endl;
		std::cout << Universo << std::endl << std::endl;

		std::cout << "Operaciones: " << std::endl << std::endl;

		std::cout << "Unión:" << std::endl;
		std::cout << "\t" << c1.Union(c2) << std::endl;
		std::cout << "Intersección:" << std::endl;
		std::cout << "\t" << c1.Interseccion(c2) << std::endl;
		std::cout << "Diferencia:" << std::endl;
		std::cout << "\t" << c1.Diferencia(c2) << std::endl;
		std::cout << "Diferencia (Con operador):" << std::endl;
		std::cout << "\t" << c1-c2 << std::endl;
		std::cout << "Diferencia Simétrica:" << std::endl;
		std::cout << "\t" << c1.DiferenciaSim(c2) << std::endl;
		std::cout << "Complemento:" << std::endl;
		std::cout << "\t" << c1.Complemento(Universo) << std::endl;
		// TODO: Fix Producto Cartesiano
		/*
		std::cout << "Producto Cartesiano:" << std::endl;
		std::cout << "\t" << c1.ProductoCart(c2) << std::endl << std::endl;
		*/
		std::cout << std::endl;

		std::cout << "Comprobaciones:" << std::endl << std::endl;

		std::cout << "Igualdad entre los Conjuntos:" << std::endl;
		std::cout << "\t" << (c1.Igual(c2) ? "Si " : "No ") << "son iguales." << std::endl;
		std::cout << nom1 << " subconjunto de " << nom2 << ":" << std::endl;
		std::cout << "\t" << nom1 << (c1.Subconjunto(c2) ? " si" : " no") << " es subconjunto de " << nom2 << std::endl;
		std::cout << nom1 << " subconjunto propio de " << nom2 << ":" << std::endl;
		std::cout << "\t" << nom1 << (c1.SubconjuntoPropio(c2) ? " si" : " no") << " es subconjunto propio de " << nom2 << std::endl;

		std::cout << "Fin de las Comprobaciones." << std::endl << std::endl;

		c1.agregar(c2);
		c2.agregar(c1);
        c2.agregar(c2);

		std::cout << c1 << std::endl;
		std::cout << c2 << std::endl;

        std::cout << "\t" << nom1 << " subconjunto (ahora con conjuntos) de " << nom2 << ":" << std::endl;
        std::cout << "\t\t-" << (c1.Subconjunto(c2) ? "Si." : "No." ) << std::endl;
	}
	catch(ExcepcionConjunto& c)
	{
		std::cout << "ERROR(" << c.id() << "): " << c.mensaje() << std::endl;
	}

	std::cout << "Programa hecho por: Humberto Alejandro Ortega Alcocer." << std::endl;
	return 0;
}
