/*
	ExcepcionConjunto.hpp

	Manejo de las Excepciones para las operaciones con 
	Conjuntos. 

	Humberto Alejandro Ortega Alcocer - 2014 <humbertowoody@gmail.com>
*/
#ifndef EXCEPCION_CONJUNTO_HPP
#define EXCEPCION_CONJUNTO_HPP

#include <string>
#include <sstream>

#define NUMERO_ERRORES					4
#define ERROR_DESCONOCIDO 				"0 ¡Error Desconocido!"
#define ERROR_NOMBRE_DEMASIADO_CORTO	"1 Nombre del Conjunto demasiado Corto ó Nulo."
#define ERROR_NOMBRE_DEMASIADO_LARGO	"2 Nombre del Conjunto demasiado Largo."
#define ERROR_CONJUNTO_VACIO 			"3 El Conjunto se encuentra vacío."
#define ERROR_CONJUNTO_UNIVERSO_VACIO 	"4 El Conjunto Universo proporcionado se encuentra vacío."

class ExcepcionConjunto
{
public:
	ExcepcionConjunto(std::string Msg = ERROR_DESCONOCIDO);

	inline std::string mensaje() const { return msg; }
	inline int id() const { return no_error; }

private:
	std::string msg;
	int no_error;
};

ExcepcionConjunto::ExcepcionConjunto(std::string Msg)
{
	std::stringstream ss(Msg);

	ss >> no_error;

	if (no_error < 0 || no_error > NUMERO_ERRORES)
	{
		no_error = 0;
	}

	std::string::size_type pos = Msg.find(' ');

	if (no_error <= NUMERO_ERRORES && pos != std::string::npos)
	{
		msg = Msg.substr(pos+1);
	}
	else
	{
		msg = Msg + " (¡Ésta excepción no es conocida ni soportada!)";
	}
}
#endif