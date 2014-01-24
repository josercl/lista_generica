/*
 * main.c
 *
 *  Created on: Mar 28, 2012
 *      Author: eseprin
 */
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "persona.c"

void mostrar(int n) {
	printf("%d\n", n);
}

int main(int argc, char **argv) {
	struct list_t *Lista = (struct list_t *) malloc(sizeof(struct list_t));
	initList(Lista);

	struct list_entry_t *primero = (struct list_entry_t *) malloc(sizeof(struct list_entry_t));
	struct persona *p=(struct persona *)malloc(sizeof(struct persona));
	p->nombre="Jose";
	p->apellido="asda";
	primero->data = p;
	addEntry(Lista, primero);

	struct list_entry_t *segundo = (struct list_entry_t *) malloc(sizeof(struct list_entry_t));
	p=(struct persona *)malloc(sizeof(struct persona));
	p->nombre="asdasdasd";
	p->apellido="zxczxczxc";
	segundo->data = p;
	addEntry(Lista, segundo);

	showList(Lista, (void *) mostrarPersona);

	printf("=====\n");

	free(primero);
	free(segundo);
	free(Lista);

	return 0;
}
