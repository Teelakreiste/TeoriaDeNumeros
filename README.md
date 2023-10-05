# Documentación del Código

## Introducción
Este código implementa un programa en C++ que proporciona varias funciones relacionadas con la teoría de números, incluyendo cálculo de múltiplos, divisores, números primos, MCM (Mínimo Común Múltiplo) y MCD (Máximo Común Divisor). También ofrece funciones para convertir entre diferentes bases numéricas y realizar operaciones de suma en varias bases.

## Requisitos del Sistema
El código utiliza las siguientes bibliotecas estándar de C++:
- `iostream`: Para entrada/salida estándar.
- `windows.h`: Para funciones de manipulación de la consola.
- `conio.h`: Para entrada de teclado.
- `string.h`: Para manipulación de cadenas de caracteres.
- `clocale`: Para configurar la localización.
- `cmath`: Para operaciones matemáticas.

## Funciones Principales

### Función `main`
La función principal `main` es el punto de entrada del programa. Comienza mostrando un banner de bienvenida y solicita al usuario que ingrese su nombre. Luego, muestra un menú con varias opciones y permite al usuario elegir una opción. Dependiendo de la opción seleccionada, se invocan otras funciones para realizar operaciones específicas.

### Función `gotoxy`
```cpp
void gotoxy(int x, int y)
```
Esta función mueve el cursor de la consola a las coordenadas (x, y).

### Funciones `OcultarCursor` y `MostrarCursor`
Estas funciones se utilizan para ocultar y mostrar el cursor de la consola, respectivamente.

### Función `Dos`
```cpp
void Dos()
```
Esta función muestra un banner con el nombre del programa y algunos efectos visuales en la consola.

### Función `Bienvenida`
```cpp
void Bienvenida()
```
La función Bienvenida muestra un mensaje de bienvenida al usuario, solicita su nombre y muestra un agradecimiento por usar el programa.

### Función `WaitKey`
```cpp
void WaitKey()
```
La función WaitKey muestra un mensaje y espera a que el usuario presione cualquier tecla para finalizar el programa.

Funciones Menu y SubMenu
Estas funciones muestran mensajes cuando el programa regresa al menú principal o al sub-menú después de completar una operación.

## Operaciones Matemáticas
### Cálculo de Múltiplos
La función `Multiplos` calcula los múltiplos de un número ingresado por el usuario y muestra los resultados.

### Cálculo de Divisores
La función `Divisores` calcula los divisores de un número ingresado por el usuario y muestra los resultados.

### Determinación de Números Primos o Compuestos
La función `PrimoCompuesto` determina si un número ingresado por el usuario es primo o compuesto y muestra el resultado.

### Cálculo de Números Primos en un Rango
La función `PrimoCompuestoNM` calcula y muestra los números primos y compuestos en un rango especificado por el usuario.

### Cálculo del MCM (Mínimo Común Múltiplo)
La función `MCM` calcula el MCM de dos números ingresados por el usuario y muestra el resultado.

### Cálculo del MCD (Máximo Común Divisor)
La función `MCD` calcula el MCD de dos números ingresados por el usuario y muestra el resultado.

## Conversión de Bases Numéricas
### Conversión de Decimal a Binario
La función `Base10Bas2` convierte un número decimal ingresado por el usuario a su representación binaria y muestra los resultados.

###Conversión de Binario a Decimal
La función `Base2Bas10` convierte un número binario ingresado por el usuario a su representación decimal y muestra los resultados.

###Conversión de Decimal a Hexadecimal
La función `Base10Bas16` convierte un número decimal ingresado por el usuario a su representación hexadecimal y muestra los resultados.

###Conversión de Hexadecimal a Decimal
La función `Base16Bas10` convierte un número hexadecimal ingresado por el usuario a su representación decimal y muestra los resultados.

###Conversión de Decimal a Octal y Viceversa
Las funciones `Base10Base8` y `Base8Base10` convierten números decimales a octales y viceversa, respectivamente.

## Operaciones de Suma
### Suma de Números Decimales
La función `SumaDecimal` permite al usuario ingresar dos números decimales y muestra la suma de los mismos.

### Suma de Números Binarios
La función `SumaBinaria` permite al usuario ingresar dos números binarios y muestra la suma de los mismos.

### Suma de Números Hexadecimales
La función `SumaHexadecimal` permite al usuario ingresar dos números hexadecimales y muestra la suma de los mismos.

## Conclusiones
Este código proporciona una variedad de funciones matemáticas y de conversión de bases numéricas en una interfaz de consola interactiva. El usuario puede elegir entre diferentes operaciones y obtener resultados en tiempo real. El código utiliza funciones de manipulación de la consola para mejorar la experiencia del usuario y proporciona comentarios detallados en cada paso.
