/*
	Conjunto.hpp

	Librería, que permite realizar operaciones con conjuntos.
	Vistos desde el punto de vista matemático.

	Humberto Alejandro Ortega Alcocer 2014 - <humbertowoody@gmail.com>
*/
#ifndef CONJUNTO_HPP
#define CONJUNTO_HPP

// Includes Necesarios
#include <vector>                   // Vectores.
#include <string>
#include <ostream>
#include "ExcepcionConjunto.hpp"    // Excepciones de Conjuntos.

/*
	Conjunto

	Es una colección dentro de un todo M de objetos m bien definidos y separados de
	nuetra intuición o pensamiento.

	Notación:
		M = { m };

	Implementación que permite la manipulación de Conjuntos de manera natural.
*/
template <class P>
class Conjunto
{
    public:
        // Constructores
        Conjunto(std::string n = "Conjunto Nuevo");                         // Constructor Default
        Conjunto(P*, int, std::string n = "Conjunto Nuevo");                // Constructor con Arrays
        Conjunto(const std::vector<P>&, std::string n = "Conjunto Nuevo");  // Constructor con Vectores.
        // Destructor
        ~Conjunto();

        // Gets
        int noElementos() const { return no_elementos; }    // Obtiene el tamaño del Conjunto. (El número de elementos)
        std::string getNombre() const { return nom; }       // Obtiene el nombre del Conjunto.

        // Sets
        void setNombre(std::string);    // Coloca el nombre al Conjunto

        // Funciones Públicas.

        void agregar(P);				     // Agrega un elemento al Conjunto.
        void agregar(const Conjunto&);		         // Agrega un Conjunto al Conjunto
        // Operaciones con Conjuntos
        Conjunto Union(Conjunto) const;            // Unión de 2 Conjuntos.
        Conjunto Interseccion(Conjunto) const;     // Intersección de 2 Conjuntos.
        Conjunto Diferencia(Conjunto) const;       // Diferencia de 2 Conjuntos.
        Conjunto Complemento(Conjunto) const;      // Complemento de un Conjunto contra el Conjuntos Universo.
        // Comprobaciones entre Conjuntos
        bool Igual(Conjunto) const;                // Igualdad de 2 Conjuntos.
        bool Subconjunto(Conjunto) const;          // Subconjunto del Conjunto Actual.
        bool SubconjuntoPropio(Conjunto) const;    // Subconjunto Propio del Actual.
        // Sintáxis Matemática
        bool pertenece(P) const;             // Para detectar si un elemento P pertenece al conjunto actual.
        bool pertenece(Conjunto) const;      // Para detectar si un conjunto P pertenece al conjunto actual.

        // Sobrecarga de Operadores
        Conjunto& operator=(const Conjunto&);   // Asignación
        bool operator==(const Conjunto&) const;       // Igualdad. En realidad, la comprobación de arriba recae a esta.
        bool operator!=(const Conjunto&) const;       // Desigualdad. La negación de la igualdad.
                                                // Operador  para imprimir.

        friend std::ostream& operator<<(std::ostream& os,const  Conjunto<P>& con)
        {
            if (con.no_elementos == 0)
            {
                os << con.nom << " = { }";
            }
            else
            {
                os << con.nom << " = { ";
                for (int i = 0; i < con.vec.size()-1; ++i)
                {
                    os << con.vec.at(i) << ", ";
                }
                
                // Comprobamos si tendrá conjuntos dentro.
                if (con.conjs.empty())
                {
                    os << con.vec.at(con.vec.size()-1) << " }";
                }
                else
                {
                    os << con.vec.at(con.vec.size()-1);
        
                    for (int i = 0; i < con.conjs.size(); ++i)
                    {
                        os << ", { " << con.conjs.at(i).getNombre() << " }";
                    }
                    os << " }"; 
                }
        
            }
            return os;
        }


    private:
        // Datos Miembro.
        std::string nom;
        std::vector<P> vec;
        std::vector< Conjunto > conjs;
        int no_elementos;
        
    protected:
        // Borrar Todo.
        virtual void limpiar()
        {
            vec.clear();
            conjs.clear();
            no_elementos = 0;
            nom = "";
        }
};


/*
    Implementación de la Clase.

    Para clases, que hagan uso de plantillas, la definición e implementación de la 
    clase siempre debe ir en el mismo archivo, dado que el linker, no puede resolver
    adecuadamente las referencias dadas entre ambos archivos objetos.

    Eso dicen.
*/
template <class P>
Conjunto<P>::~Conjunto()
{
    limpiar();
}

template <class P>
Conjunto<P>::Conjunto(std::string n)
{
    no_elementos = 0;
    setNombre(n);
}

template <class P>
Conjunto<P>::Conjunto(P* arr, int tam, std::string n)
{
    for (int i = 0; i < tam; ++i)
    {
        vec.push_back(arr[i]);
    }
    no_elementos = tam;
    setNombre(n);
}

template <class P>
Conjunto<P>::Conjunto(const std::vector<P>& v, std::string n)
{
    vec = v;
    setNombre(n);
    no_elementos = v.size();
}

template <class P>
void Conjunto<P>::agregar(P temp)
{
    if ( !this->pertenece(temp))
    {
        no_elementos++;
        vec.push_back(temp);
    }
}

template <class P>
void Conjunto<P>::agregar(const Conjunto<P>& con)
{
    if( !this->pertenece(con))
    {
        no_elementos++;
        conjs.push_back(con);
    }
}

template <class P>
bool Conjunto<P>::pertenece(P x) const
{
    for (int i = 0; i < this->vec.size(); ++i)
    {
        if(this->vec.at(i) == x)
            return true;
    }
    return false;
}

template <class P>
bool Conjunto<P>::pertenece(Conjunto<P> x) const
{
    for (int i = 0; i < conjs.size(); ++i)
    {
        if (conjs.at(i) == x)
        {
            return true;
        }
    }
    return false;
}

template <class P>
void Conjunto<P>::setNombre(std::string n)
{
    if (n.length() <= 0)
    {
        throw ExcepcionConjunto(ERROR_NOMBRE_DEMASIADO_CORTO);
    }
    else if(n.length() >= 25)
    {
        throw ExcepcionConjunto(ERROR_NOMBRE_DEMASIADO_LARGO);
    }
    else
    {
        this->nom = n;
    }
}

// Sobrecarga de Operadores
// Asignación
template <class P>
Conjunto<P>& Conjunto<P>::operator=(const Conjunto<P>& otro)
{
    limpiar();
    this->vec = otro.vec;
    this->conjs = otro.conjs;
    this->no_elementos = otro.no_elementos;
    return *this;
}

// Desigualdad
template <class P>
bool Conjunto<P>::operator!=(const Conjunto<P>& otro) const
{
    return (!(*this == otro));
}

// Igualdad
template <class P>
bool Conjunto<P>::operator==(const Conjunto<P>& otro) const
{
    if(vec.size() != otro.vec.size())
    {
        return false;
    }
    else if(conjs.size() != otro.conjs.size())
    {
        return false;
    }

    // Los 2 conjuntos son del mismo tamaño de elementos.
    for (int i = 0; i < vec.size(); ++i)
    {
        if (!otro.pertenece(vec.at(i)))
        {
            return false;
        }
    }
    for (int i = 0; i < conjs.size(); ++i)
    {
        if(!otro.pertenece(conjs.at(i)))
        {
            return false;
        }
    }

    // Son iguales.
    return true;
}

// Funciones Miembro
// Igualdad
template <class P>
bool Conjunto<P>::Igual(Conjunto<P> c) const
{
    return (*this == c);
}

// Subconjunto
template <class P>
bool Conjunto<P>::Subconjunto(Conjunto<P> c) const
{
    if ((vec.size() == 0 && conjs.size() == 0) || (c.vec.size() == 0 && c.conjs.size() == 0))
    {
        throw ExcepcionConjunto(ERROR_CONJUNTO_VACIO);
    }
    for (int i = 0; i < vec.size(); ++i)
    {
        if (!c.pertenece(vec.at(i)))
        {
            return false;
        }
    }
    for (int i = 0; i < conjs.size(); ++i)
    {
        if (!c.pertenece(conjs.at(i)))
        {
            return false;
        }   
    }
    return true;
}

// Subconjunto Propio
template <class P>
bool Conjunto<P>::SubconjuntoPropio(Conjunto<P> c) const
{
    if ((vec.size() == 0 && conjs.size() == 0) || (c.vec.size() == 0 && c.conjs.size() == 0))
    {
        throw ExcepcionConjunto(ERROR_CONJUNTO_VACIO);
    }
    if (*this == c)
    {
        return false;
    }
    else
    {
        return this->Subconjunto(c);
    }
}

// Unión
template <class P>
Conjunto<P> Conjunto<P>::Union(Conjunto<P> p) const
{
    if ((vec.size() == 0 && conjs.size() == 0) || (p.vec.size() == 0 && p.conjs.size() == 0))
    {
        throw ExcepcionConjunto(ERROR_CONJUNTO_VACIO);
    }
    Conjunto<P> temp("Resultado");

    // Añadimos los elementos de ambos Conjuntos.
    // La función añadir, se encarga de no repetir
    // Elementos.
    for (int i = 0; i < vec.size(); ++i)
    {
        temp.agregar(vec.at(i));
    }
    for (int i = 0; i < p.vec.size(); ++i)
    {
        temp.agregar(p.vec.at(i));
    }
    for (int i = 0; i < conjs.size(); ++i)
    {
        temp.agregar(conjs.at(i));
    }
    for (int i = 0; i < p.conjs.size(); ++i)
    {
        temp.agregar(p.conjs.at(i));
    }

    return temp;
}

// Intersección
template <class P>
Conjunto<P> Conjunto<P>::Interseccion(Conjunto<P> p) const
{
    if ((vec.size() == 0 && conjs.size() == 0) || (p.vec.size() == 0 && p.conjs.size() == 0))
    {
        throw ExcepcionConjunto(ERROR_CONJUNTO_VACIO);
    }
    Conjunto<P> temp("Resultado");

    for (int i = 0; i < vec.size(); ++i)
    {
        if (p.pertenece(vec.at(i)))
        {
            temp.agregar(vec.at(i));
        }
    }
    for (int i = 0; i < conjs.size(); ++i)
    {
        if (p.pertenece(conjs.at(i)))
        {
            temp.agregar(conjs.at(i));
        }
    }
    return temp;
}

// Diferencia
template <class P>
Conjunto<P> Conjunto<P>::Diferencia(Conjunto<P> p) const
{
    if ((vec.size() == 0 && conjs.size() == 0) || (p.vec.size() == 0 && p.conjs.size() == 0))
    {
        throw ExcepcionConjunto(ERROR_CONJUNTO_VACIO);
    }
    Conjunto<P> temp("Resultado");
    
    for (int i = 0; i < vec.size(); ++i)
    {
        if (!p.pertenece(vec.at(i)))
        {
            temp.agregar(vec.at(i));
        }
    }
    for (int i = 0; i < conjs.size(); ++i)
    {
        if(!p.pertenece(conjs.at(i)))
        {
            temp.agregar(conjs.at(i));
        }
    }
    return temp;
}

// Complemento
template <class P>
Conjunto<P> Conjunto<P>::Complemento(Conjunto<P> p) const
{
    if ((vec.size() == 0 && conjs.size() == 0))
    {
        throw ExcepcionConjunto(ERROR_CONJUNTO_VACIO);
    }
    Conjunto<P> temp("Resultado");
    
    if (p.vec.size() <= 0 && p.vec.size() <= 0)
    {
        throw ExcepcionConjunto(ERROR_CONJUNTO_UNIVERSO_VACIO);
    }

    for (int i = 0; i < p.vec.size(); ++i)
    {
        if (!this->pertenece(p.vec.at(i)))
        {
            temp.agregar(p.vec.at(i));
        }
    }
    for (int i = 0; i < p.conjs.size(); ++i)
    {
        if (!this->pertenece(p.conjs.at(i)))
        {
            temp.agregar(p.conjs.at(i));
        }
    }
    return temp;
}

#endif // CONJUNTO_H