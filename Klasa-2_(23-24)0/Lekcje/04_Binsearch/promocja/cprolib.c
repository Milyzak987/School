/* Przykładowa biblioteka interakcyjna do zadania Promocja */

#include "cprolib.h"

#include <assert.h>
#include <stdio.h>

static int czy_zainicjalizowana = 0;
static int czy_pytanie = 0;

static int gn, gm, gu[500001], gv[500001];

void inicjuj(int* n, int* m, int* z) {
	int i;

	assert(czy_zainicjalizowana == 0);
	scanf("%d %d %d", n, m, z);
	gm = *m;
	gn = *n;

	for(i = 1; i <= *m; i ++){
		scanf("%d %d", &gu[i], &gv[i]);
	}

	czy_zainicjalizowana = 1;
}

void pobierz_promocje(int i, int* u, int *v) {
	assert(czy_zainicjalizowana == 1);
	assert(1 <= i && i <= gm);
	*u = gu[i];
	*v = gv[i];
}

void pobierz_zapytanie(int* v, int* t) {
	assert(czy_zainicjalizowana == 1);
	assert(czy_pytanie == 0);

	scanf("%d %d", v, t);
	czy_pytanie = 1;
}

void odpowiedz(int x) {
	assert(czy_zainicjalizowana == 1);
	assert(czy_pytanie == 1);
	assert(1 <= x && x <= gn);

	printf("%d\n", x);
	czy_pytanie = 0;
}
