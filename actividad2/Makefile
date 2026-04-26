PROYECTO=programa
CFLAGS=-Wall
CC=gcc
RESULTADOS=resultados.dat


all: $(PROYECTO) run

%.o: %.c
	$(CC) -c $< $(CFLAGS)

run: $(PROYECTO)
	@echo "Ejecutando programa..."
	./$(PROYECTO)
	@echo "Resultados guardados en resultados.dat"

$(PROYECTO): muestreo.o procesamiento.o archivos.o
	@echo "Compilando..."
	$(CC) $^ -o $@

.PHONY: clean

ver:
	cat $(RESULTADOS)

clean:
	@echo "Limpiando..."
	rm -f *.o *.dat $(PROYECTO)
