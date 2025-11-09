/*
--------------------------------------------------------------------------------------------------------
Tipos de datos en C++
-------------------------------------------------------------------------------------------------------

- Caracteres -> Para caracteres:

        · char -> Pueden ser caracteres o enteros pequeños de un byte tamaño. 
                RgValores: -128 a 127 / unsigned 0 255.

        · char8_t -> Pueden ser caracteres Unicode de ocho bits de un byte de tamaño.

        · char16_t -> Pueden ser caracteres Unicode de dieciseis bits de dos bytes de tamaño.

        · char32_t -> Pueden ser caracteres Unicode de treinta y dos bits de cuatro bytes de tamaño.

        · wchar_t -> Pueden ser caracteres Unicode de cuatro bytes de tamaño.

- Enteros ->  Para números enteros:

        · short -> para números pequeños de dos bytes de tamaño de dos bytes.
                RgValores: -32.768 a 23.767 / unsigned.

        · int -> números enteros de tamaño de cuatro bytes.
                RgValores: -2.147.483.648 a 2.147.483.647 / unsigned.

        · long -> para números enteros largos de tamaño de cuatro bytes.
                RgValores: -2.147.483.648 a 2.147.483.647 / unsigned.

        · long long -> para números enteros muy largos de tamaño de ocho bytes.
                RgValores: -9.223.372.775.808 a 9.223.372.775.807 / unsigned.

- Decimales -> Para valores con decimales:

        · float -> Parte decima 7 dígitos de un tamaño de cuatro bytes.
                RgValores: 1.2e -38 a 3,4e 38.

        · double -> Parte decimal de 15 dígitos de tamaño ocho bytes.
                RgValores: 2,2e -308 a 1.8e 308.

        · long double -> Parte decimal de 19 dígitos de tamaño ocho bytes.
                RgValores: 3,3e -4932 a 1,2 4932.

        - Booleanos -> condiciones que pueden ser verdaderas o falsas:

        · bool -> Para valores lógicos verdadero/falso de tamaño un byte.
                RgValores: true / false.

--------------------------------------------------------------------------------------------------------
*/

/*
--------------------------------------------------------------------------------------------------------
Variables:

Una variable es un espacio en la memoria del ordenador donde se almacenará un valor
que podrá cambiar (variar) durante el programa.

Memoría RAM -> Memoría de acceso volatil. Los datos guardados aquí solo se mantienen
almacenados mientras el ordenador este encendido.

Las variables en C++ tienen tipo. C++ es un lenguaje tipado.

--------------------------------------------------------------------------------------------------------
*/