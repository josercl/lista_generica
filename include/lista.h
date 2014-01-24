/*
 * lista.c
 *
 *  Created on: Mar 28, 2012
 *      Author: eseprin
 */

#ifndef _LISTA_

#define _LISTA_

struct list_entry_t{
	void *data;
	struct list_entry_t *next;
};

struct list_t{
	struct list_entry_t *root;
	int tamano;
};

void initList(struct list_t *);
void showList(struct list_t *, void *((*) (void *)) );
void map(struct list_t *, void *((*) (void *)) );
void addEntry(struct list_t *,struct list_entry_t *);
void removeEntry(struct list_t *, int);
void insertEntry(struct list_t *,struct list_entry_t *, int);
struct list_entry_t *get(struct list_t *,int);

#endif
