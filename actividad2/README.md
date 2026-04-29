# Tarea 2 - Makefiles

<h1 style="background-color: #c1c1c1; text-align: center">Makefiles</h1>

## ¿Qué es GNU Make?
<div style="text-align: justify">
Es una herramienta que permite controlar el proceso de generación y reconstrucción del software.
Automáticamente determina que piezas necesitan ser recompiladas en un programa muy grande generando los comandos adecuados.
Fue implementado por Richard Stallman y Roland McGrath.
</div>

## ¿Qué es un Makefile?
<div style="text-align: justify">
Un archivo make (Makefile) es un archivos de texto que contiene REGLAS que le indican a la herramienta `GNU Make` qué, cómo y bajo qué condiciones generar un resultado. Es decir permite automatizar la compilación, construcción (build) e instalación de proyectos de software.
</div>

## Reglas de un archivo make
Una regla consiste de lo siguiente:
* Un objetivo, lo que make intenta generar.
* Una lista de dependencias, normalmente archivos necesarios para generar el objetivo.
* Una lista de comandos que hay que ejecutar para generar el objetivo a partir de las dependencias especificadas.

## Ventajas de los archivos make
* Son útiles en proyectos donde se deben compilar múltiples archivos fuente.
* Facilitan manejar opciones de compilador especiales.
* Constituye una base de datos de información de dependencia de un proyecto.
* Solo reconstruye los programas cuyos archivos de componentes han cambiado, minizando los tiempos de reconstrucción.

## ¿Para qué sirve?
Con un Makefile se puede automatizar procesos como:
* Compilar programas en C o C++.
* Ejecutar pruebas.
* Limpiar archivos temporales.
* Generar reportes o graficas.
* Ejecutar scripts.
* Copiar archivos a otra carpeta.
* Programar un microcontrolador o una FPGA.
* Encadenar un flujo completo de compilacion, simulacion y ejecucion.

Entre muchas más.


<h1 style="background-color: #c1c1c1; text-align: center">Proyecto Simulación del Perceptrón Simple (Actividad 2)</h1>
<div style="text-align: justify">
Este proyecto implementa la generación de resultados de un perceptrón simple que tiene pesos y bias fijo y toma como entrada 3 datos aleatorios entre 0 y 1.
El programa está dividido en dos etapas principales:


**1. Cálculo de resultados (C)**
- El archivo main.c calcula los resultados de los 3 datos aleatorios entre 0 y 1.

**2. Guardado de datos (C)**
- El archivo archivos.c guarda los datos de salida en un archivo .dat (resultados.dat)

Todo el proceso está automatizado mediante un archivo Makefile, que permite ejecutar todo con un solo comando, `make`.

## ¿Cómo funciona el programa?
### 1.- Cálculo de las salidas
Se realiza la suma ponderada de los pesos y datos:

$$y = f\left(\sum_{i=1}^{3} w_i x_i + b\right)$$

donde:
- w1 = -0.4
- w2 = -0.2
- w3 = 0.1
- b = 0.2

Salida: -

### 2.- Guardado de resultados
El código en archivos.c guarda los resultados en el archivo resultados.dat

Salida: resultados.dat

### 3.- Automatización con Makefile
El archivo Makefile conecta todo el flujo:

Cálculo → Archivo .dat

## Requisitos
- Compilador de C (se usará gcc)
- GNU Make

Para verificar si se tiene instalado `make` (GNU Make), se puede ingresar el comando `make -v` en la terminal de Linux. Si aparece un mensaje indicando que no se encuentra el comando, se puede instalar con `sudo apt install make` o `sudo apt install build-essential`, la diferencia es que el primero instala GNU Make, y el segundo instala gcc, g++, make, libc6-dev y dpkg-dev.
Por otro lado, si aparece un mensaje indicando la versión de GNU Make, make está instalado en el sistema.

Es recomendable ejecutar `sudo apt update` y `sudo apt upgrade` para actualizar el sistema operativo antes de instalar make.

## Instrucciones de uso
Para ejecutar todo el proyecto: Ir a la carpeta del proyecto y ejecutar el comando `make`, esto ejecutará automáticamente:
1. Compilación del programa
2. Generación de resultados
3. Guardado de resultados

Para limpiar los archivos generados: Ir a la carpeta del proyecto y ejecutar el comando `make clean`.

## Explicación del Makefile
### Variables
```
CC=gcc
CFLAGS=-Wall
```
Define el compilador y opciones de compilación
```
PROYECTO=programa
RESULTADOS=resultados.dat
```
Genera automáticamente nombres de archivos relacionados. El primero es el nombre original del proyecto 'programa' y el segundo el nombre dle archivo donde se guardarán los resultados (resultados. dat)

Esto mantiene consistencia en los nombres de archivos sin necesidad de escribirlos manualmente en múltiples lugares del Makefile.

### Regla principal
```
all: $(PROYECTO) run
```
Es el objetivo por defecto. Ejecuta en orden:
1. $(PROYECTO)
2. run

### Compilación automática
```
%.o: %.c
```
Convierte .c -> .o
```
$(PROYECTO): muestreo.o procesamiento.o archivos.o
```
Enlaza los objetos para generar el ejecutable

###Ejecución
```
run: $(PROYECTO)
```
Si _proyecto_ no existe, lo compila
Luego, lo ejecuta:
```
./julia
```
Esto genera resultados.dat

### Limpieza
```
clean:
	rm -f *.o *.dat $(PROYECTO)
```
Elimina todos los archivos generados

En resumen, el proyecto calcula y guarda las salidas de un perceptrón tomando como entrada datos aleatorios entre 0 y 1. El Makefile automatiza todo el proceso, permitiendo compilar, ejecutar y los resultados con un solo comando: `make`.

## Instalación de paquetes que no se tienen
Pueden aparecer errores indicando que ciertos comandos no están disponibles. Por ejemplo, al ejecutar:
```
make plot
```
puede mostrarse el siguiente error:
```
make: gnuplot: No such file or directory
make: *** [Makefile:43: plot] Error 127
```
indicando que Gnuplot no está instalado en el sistema.

Lo anterior se puede verificar ingresando el comando `gnuplot` y se observa:
```
Command 'gnuplot' not found, but can be installed with:
sudo apt install gnuplot-nox  # version 5.4.4+dfsg1-2build1, or
sudo apt install gnuplot-qt   # version 5.4.4+dfsg1-2build1
sudo apt install gnuplot-x11  # version 5.4.4+dfsg1-2build1
```
Para resolverlo, se puede instalar alguna de las versiones disponibles. Por ejemplo:
```
sudo apt install gnuplot
```
Una vez instalado, el comando `make plot` debería ejecutarse correctamente.
</div>