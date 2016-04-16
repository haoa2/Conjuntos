Conjuntos
=========

Proyecto de una librería para el manejo de Conjuntos matemáticos adecuadamente.

Permite el uso de las siguientes operaciones:

    -Unión
    -Intersección
    -Diferencia
    -Doferencia Simétrica
    -Complemento
    -Producto Cartesiano*

Permite realizar las comprobaciones pertinentes:
    
    -Igualdad
    -Subconjunto
    -Subconjunto Propio

La sintáxis básica es la siguiente:

    Conjunto<T> objeto1();

    T = Tipo de dato. (int, float etc..)

Una referencia rápida de la librería es la siguiente:

    +--------------+------------------------+----------+---------------------------------+
    | OPERACIÓN/   |        MÉTODO          | REGRESA  |           EXPLICACIÓN           |
    | COMPROBACIÓN |                        |          |                                 |
    +---------------------------------------+----------+---------------------------------+
    | Unión        | Union(Conjunto)        | Conjunto | Devuelve el conjunto resultante |
    |              |                        |          | de la operación Unión.          |
    +--------------+------------------------+----------+---------------------------------+
    | Intersección | Interseccion(Conjunto) | Conjunto | Devuelve el conjunto resultante |
    |              |                        |          | de la operación Intersección.   |
    +--------------+------------------------+----------+---------------------------------+
    | Diferencia   | Diferencia(Conjunto)   | Conjunto | Devuelve el conjunto resultante |
    |              |                        |          | de la operación Diferencia.     |
    +--------------+------------------------+----------+---------------------------------+
    | Diferencia   | DiferenciaSim(Conjunto)| Conjunto | Devuelve el conjunto resultante |
    | Simétrica    |                        |          | de la Diferencia Simétrica      |
    +--------------+------------------------+----------+---------------------------------+
    | Producto     | ProductoCart(Conjunto) | Conjunto | Devuelve el conjunto resultante |
    | Cartesiano   |                        |          | de la operación Producto Carte- |
    |              |                        |          | siano. (Sus elementos se convi- |
    |              |                        |          | erten en Pairs (STL)).          |
    +--------------+------------------------+----------+---------------------------------+
    | Complemento  | Complemento(Conjunto)  | Conjunto | Devuelve el conjunto resultante |
    |              |                        |          | de la operación Complemento.    |
    +--------------+------------------------+----------+---------------------------------+
    | Igualdad     | Igualdad(Conjunto)     | bool     | Devuelve cierto, si los conjun- |
    |              |                        |          | tos son iguales, falso en caso  |
    |              |                        |          | contrario.                      |
    +--------------+------------------------+----------+---------------------------------+
    | Suconjunto   | Subconjunto(Conjunto)  | bool     | Devuelve cierto, si el conjunto |
    |              |                        |          | es un subconjunto del conjunto  |
    |              |                        |          | proporcionado, devuelve falso   |
    |              |                        |          | en caso contrario.              |
    +--------------+------------------------+----------+---------------------------------+
    | Suconjunto   | SuconjuntoPropio(Conj  | bool     | Devuelve cierto, si el conjunto |
    | Propio       | unto)                  |          | es un subconjunto propio del    |
    |              |                        |          | conjunto proporcionado, falso   |
    |              |                        |          | en caso contrario.              |
    +--------------+------------------------+----------+---------------------------------+


Los ejemplos del uso de la librería se encuentran dentro de la carpeta "Ejemplos" donde se
abarcan todas las funciones por separado y en conjunto.

Creado por:
    
    Humberto Alejandro Ortega Alcocer 2014 
    <humbertowoody@gmail.com>

Libre Uso. 
