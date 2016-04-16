Conjuntos
=========

Proyecto de una librería para el manejo de Conjuntos matemáticos adecuadamente.

Permite el uso de las siguientes operaciones:

<<<<<<< HEAD
    -Unión
    -Intersección
    -Diferencia
    -Doferencia Simétrica
    -Complemento
    -Producto Cartesiano*
=======
 - Unión
 - Intersección
 - Diferencia
 - Complemento
>>>>>>> ad1a994c2f95839915300917bd5b569b30cb0e03

Permite realizar las comprobaciones pertinentes:
    
 - Igualdad
 - Subconjunto
 - Subconjunto Propio

La sintáxis básica es la siguiente:

    Conjunto<T> objeto1();

    T = Tipo de dato. (int, float etc..)

Una referencia rápida de la librería es la siguiente:

<<<<<<< HEAD
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
=======
| OPERACIÓN/COMPROBACIÓN   |        MÉTODO          | REGRESA  |           EXPLICACIÓN                      
|--------------|------------------------|----------|----------------------------------
| Unión        | Union(Conjunto)        | Conjunto | Devuelve el conjunto resultante de la operación Unión.
| Intersección | Interseccion(Conjunto) | Conjunto | Devuelve el conjunto resultante de la operación Intersección.
| Diferencia   | Diferencia(Conjunto)   | Conjunto | Devuelve el conjunto resultante de la operación Diferencia.
| Complemento  | Complemento(Conjunto)  | Conjunto | Devuelve el conjunto resultante de la operación Complemento. 
| Igualdad     | Igualdad(Conjunto)     | bool     | Devuelve cierto, si los conjuntos son iguales, falso en caso contrario.
| Suconjunto   | Subconjunto(Conjunto)  | bool     | Devuelve cierto, si el conjunto es un subconjunto del conjunto proporcionado, devuelve falso en caso contrario.
| Suconjunto Propio | SuconjuntoPropio(Conjunto) | bool | Devuelve cierto, si el conjunto es un subcojunto propio del conjunto proporcionado, falso en caso contrario.
>>>>>>> ad1a994c2f95839915300917bd5b569b30cb0e03

## Ejemplos

Los ejemplos del uso de la librería se encuentran dentro de la carpeta "Ejemplos" donde se
abarcan todas las funciones por separado y en conjunto.

## Autor
    
**Humberto Alejandro Ortega Alcocer 2014**
<humbertowoody@gmail.com>

Libre Uso. 
