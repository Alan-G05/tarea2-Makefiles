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


<h1 style="background-color: #c1c1c1; text-align: center">Proyecto Julia (Conjunto de Julia)</h1>
<div style="text-align: justify">
Este proyecto implementa la generación y visualización del Conjunto de Julia, familia de fractales perteneciente al campo del Análisis Complejo.

El programa está dividido en dos etapas principales:


**1. Cálculo numérico (C++)**
- El archivo main.cpp calcula los valores del conjunto de Julia evaluando la divergencia de puntos en el plano complejo.
- El resultado se guarda en un archivo de texto (julia_set.txt).

**2. Visualización (Gnuplot)**
- El script julia_set.gp toma los datos generados y produce una imagen (julia_set.png) representando el fractal.

Todo el proceso está automatizado mediante un archivo Makefile, que permite ejecutar todo con un solo comando, `make`.

## ¿Cómo funciona el programa?
### 1.- Cálculo del fractal
Se recorre una cuadrícula de puntos en el plano (x, y).
Para cada punto, se evalúa una iteración del tipo:
$$z_{n+1} = z_n^2 + c$$

donde:
- c=−0.70176−0.3842i (constante del conjunto de Julia)
- Se calcula cuántas iteraciones tarda en divergir (si lo hace)
- Los datos se guardan como: x, y, iteraciones

Salida: julia_set.txt

### 2.- Generación de la imagen
Usa Gnuplot para leer el archivo .txt y genera una imagen en formato:
- PNG (por defecto)
- PDF o LaTeX (opcional)

Configura:
- Fondo negro
- Sin ejes
- Paleta de colores personalizada

Salida: julia_set.png

### 3.- Automatización con Makefile
El archivo Makefile conecta todo el flujo:

Cálculo → Archivo .txt → Imagen → Apertura automática

## Requisitos
- Compilador de C++ (se usará g++)
- Gnuplot
- xdg-open
- GNU Make

Para verificar si se tiene instalado `make` (GNU Make), se puede ingresar el comando `make -v` en la terminal de Linux. Si aparece un mensaje indicando que no se encuentra el comando, se puede instalar con `sudo apt install make` o `sudo apt install build-essential`, la diferencia es que el primero instala GNU Make, y el segundo instala gcc, g++, make, libc6-dev y dpkg-dev.
Por otro lado, si aparece un mensaje indicando la versión de GNU Make, make está instalado en el sistema.

Es recomendable ejecutar `sudo apt update` y `sudo apt upgrade` para actualizar el sistema operativo antes de instalar make.

## Instrucciones de uso
Para ejecutar todo el proyecto: Ir a la carpeta del proyecto y ejecutar el comando `make`, esto ejecutará automáticamente:
1. Compilación del programa
2. Generación de datos
3. Generación de la imagen
4. Apertura del resultado

Para limpiar los archivos generados: Ir a la carpeta del proyecto y ejecutar el comando `make clean`.

## Explicación del Makefile
### Variables
```
CXX = g++
CXXFLAGS = -std=c++23 -O3
```
Define el compilador y opciones de optimización.
```
GP = julia_set.gp 
TXT = $(GP:.gp=.txt)
PNG = $(GP:.gp=.png)
```
Genera automáticamente nombres de archivos relacionados. El primero es el nombre original del archivo 'julia_set.gp'.

En TXT se reemplaza la extensión '.gp' por '.txt', es decir, esta línea: `TXT = $(GP:.gp=.txt)` lee el valor de variable GP (julia_set.gp), busca la extensión '.gp' y la reemplaza por '.txt'; el resultado de reemplazar '.gp' por '.txt' en 'julia_set.pg' lo asigna a la variable TXT. Por ello, TXT = julia_set.txt

Para la imagen en formato PNG se realiza algo similar a lo descrito en el párrafo anterior; se toma el valor de GP (julia_set.gp), se busca la extensión '.gp' y se reemplaza por '.png'. El resultado de reemplazar '.gp' por '.png' en 'julia_set.gp' lo asigna a la variable PNG. PNG = julia_set.png

Esto mantiene consistencia en los nombres de archivos sin necesidad de escribirlos manualmente en múltiples lugares del Makefile.
```
APP = julia
```
Nombre del archivo ejecutable final
### Regla principal
```
all: run plot open
```
Es el objetivo por defecto. Ejecuta en orden:
1. run
2. plot
3. open

### Compilación automática
```
%.o: %.cpp
```
Convierte .cpp -> .o
```
$(APP): $(OBJS)
```
Enlaza los objetos para generar el ejecutable

###Ejecución
```
run: $(APP)
```
Si _julia_ no existe, lo compila
Luego, lo ejecuta:
```
./julia
```
Esto genera julia_set.txt
### Graficación
```
plot: $(TXT)
```
Usa Gnuplot:
```
gnuplot julia_set.gp
```
Esto genera _julia_set.png_
### Apertura automática
```
open:
	xdg-open $(PNG) &
```
Abre automáticamente la imagen generada
### Limpieza
```
clean:
	rm *.o $(APP) *.txt *.png
```
Elimina todos los archivos generados

Hay un archivo adicional llamado _test.gp_. Este archivo genera una visualización alternativa del conjunto de Mandelbrot directamente en Gnuplot, no forma parte del flujo principal del Makefile y sirve como prueba o referencia.

En resumen, el proyecto calcula y visualiza el conjunto de Julia mediante un programa en C++ que genera datos numéricos, los cuales son procesados por Gnuplot para producir una imagen. El Makefile automatiza todo el proceso, permitiendo compilar, ejecutar, graficar y visualizar el resultado con un solo comando: `make`.

## Instalación de paquetes que no se tienen
Durante la ejecución del proyecto, pueden aparecer errores indicando que ciertos comandos no están disponibles. Por ejemplo, al ejecutar:
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

1       2     4     8     5    10
1       0     0     0     1    0
0.08   -0.09 -0.09 -0.09 0.08 -0.09 

