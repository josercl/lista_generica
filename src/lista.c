/*
 * lista.c
 *
 *  Created on: Mar 28, 2012
 *      Author: eseprin
 */
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void initList(struct list_t *l) {
	l->root = NULL;
	l->tamano = 0;
}

void map(struct list_t *list, void *((*mapFunction)(void *))) {
	struct list_entry_t *entry;
	for (entry = list->root; entry; entry = entry->next) {
		mapFunction(entry->data);
	}
}

void showList(struct list_t *list, void *((*showFunction)(void *))) {
	map(list, showFunction);
}

struct list_entry_t *get(struct list_t *list, int index) {
	struct list_entry_t *entry = NULL;
	if (index < list->tamano) {
		int i;
		entry = list->root;
		for (i = 0; i < index; i++) {
			entry = entry->next;
		}
	}
	return entry;
}

void removeEntry(struct list_t *list, int index) {
	struct list_entry_t *anterior, *siguiente;

	anterior = list->root;
	siguiente = NULL;

	if (index >= 0 && index < list->tamano) {

		if (index > 0) {
			anterior = get(list, index - 1);
		}

		if (index + 1 < list->tamano) {
			siguiente = anterior->next->next;
		}

		if (index == 0) {
			list->root = anterior->next;
		}

		anterior->next = siguiente;
	}

	list->tamano--;
}

void insertEntry(struct list_t *list, struct list_entry_t *new, int index) {
	struct list_entry_t *anterior, *siguiente;

	anterior = list->root;

	if (index == 0) {
		new->next = anterior;
		list->root = new;
		list->tamano++;
	}

	if (index > 0 && index <= list->tamano) {

		anterior = get(list, index - 1);

		if(index!=list->tamano){
			siguiente = get(list, index);
		}else{
			siguiente = NULL;
		}

		anterior->next = new;
		new->next = siguiente;

		list->tamano++;
	}
}

void addEntry(struct list_t *list, struct list_entry_t *entry) {
	insertEntry(list,entry,list->tamano);
}
