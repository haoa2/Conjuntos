Conjuntos
=========

Proyecto de una librería para el manejo de Conjuntos matemáticos adecuadamente.

Permite el uso de las siguientes operaciones:

 - Unión
 - Intersección
 - Diferencia
 - Doferencia Simétrica
 - Complemento
 - Producto Cartesiano*

Permite realizar las comprobaciones pertinentes:
    
 - Igualdad
 - Subconjunto
 - Subconjunto Propio

La sintáxis básica es la siguiente:

    Conjunto<T> objeto1();

    T = Tipo de dato. (int, float etc..)

Una referencia rápida de la librería es la siguiente:

| OPERACIÓN/COMPROBACIÓN   |        MÉTODO          | REGRESA  |           EXPLICACIÓN                      
|--------------|------------------------|----------|----------------------------------
| Unión        | Union(Conjunto)        | Conjunto | Devuelve el conjunto resultante de la operación Unión.
| Intersección | Interseccion(Conjunto) | Conjunto | Devuelve el conjunto resultante de la operación Intersección.
| Diferencia   | Diferencia(Conjunto)   | Conjunto | Devuelve el conjunto resultante de la operación Diferencia.
| Diferencia Simétrica | DiferenciaSim(Conjunto) | Conjunto | Devuelve el conjunto resultante de la operación de Diferencia Simétrica.
|Producto Cartesiano* | ProductorCart(Conjunto) | Conjunto | Devuelve el conjunto resultante de la operación Producto Cartesiano. Sus elementos se convierten en std::pair's de la STL.
| Complemento  | Complemento(Conjunto)  | Conjunto | Devuelve el conjunto resultante de la operación Complemento. 
| Igualdad     | Igualdad(Conjunto)     | bool     | Devuelve cierto, si los conjuntos son iguales, falso en caso contrario.
| Suconjunto   | Subconjunto(Conjunto)  | bool     | Devuelve cierto, si el conjunto es un subconjunto del conjunto proporcionado, devuelve falso en caso contrario.
| Suconjunto Propio | SuconjuntoPropio(Conjunto) | bool | Devuelve cierto, si el conjunto es un subcojunto propio del conjunto proporcionado, falso en caso contrario.

    *El Producto Cartesiano aún no funciona :c
## Ejemplos

Los ejemplos del uso de la librería se encuentran dentro de la carpeta "Ejemplos" donde se
abarcan todas las funciones por separado y en conjunto.

## Autor
    
**Humberto Alejandro Ortega Alcocer 2014**
<humbertowoody@gmail.com>

Libre Uso. 
