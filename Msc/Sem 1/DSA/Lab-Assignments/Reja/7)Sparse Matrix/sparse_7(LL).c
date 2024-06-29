//DEVISE A SCHEME TO REPRESENT A SPARSE MATRIX 'A' AND
//TRANSPOSE THIS REPRESENTATION OF 'A' IN LEXICOGRAPHIC ORDER

#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main (void) {

	int i, j, k, m, n, pos = 1, count = 0;

	printf ("Enter The Number Of Rows & Columns: ");
	scanf ("%d%d", &m, &n);	//ACCEPTING THE NUMBERS OF VERTICES AND EDGES

	int **a = (int**) malloc (m * sizeof (int*));	//INITIALIZING THE MATRIX 'A'
	if (!a) {
		printf ("\n MEMORY ALLOCATION FAILED!\n");
		exit (1);
}
	for (i = 0; i < m; i++) {
		a[i] = (int *) malloc (n * sizeof (int));
		if (!a[i]) {
			printf ("\n MEMORY ALLOCATION FAILED!\n");
			exit (1);
		}
	}

	printf ("\n Enter The Elements Of The Sparse Matrix 'A':\n\n");
	for (i = 0; i < m; i++) {	//INSERTING ELEMENTS IN THE MATRIX 'A'
		printf("\t");
		for (j = 0; j < n; j++) {
			scanf ("%d", &a[i][j]);
			if (a[i][j] != 0)	//CHECKING FOR NON-ZERO ELEMENTS
				count++;	//COUNTING THE NON-ZERO ELEMENTS
		}
	}

	printf ("\n   MATRIX 'A'");
	printf ("\n   ----------\n\n");

	for (j = 0; j < n; j++)	//DISPLAYING THE ENTERED MATRIX
		printf ("\t  %4d]", j);
	printf ("\n");
	for (i = 0; i < m; i++) {
		printf ("\n   A[%d,", i);
		for (j = 0; j < n; j++)
			printf ("\t %6d", a[i][j]);
		printf ("\n");
	}

	if (count >= (m * n / 3) - 1) {	//CHECKING IF THE MATRIX IS SPARSE
		printf ("\n THIS IS NOT A SPARSE MATRIX!");
		exit (0);
	}

	printf ("\n PRESS ANY KEY TO CONTINUE: ");
	getch ();
	system ("CLS");

	//CREATING THE SPARSE MATRIX REPRESENTATION 'S'

	int **s = (int**) malloc ((count + 1) * sizeof (int*));	//INITIALIZING THE MATRIX 'S'
	if (!s) {
		printf ("\n MEMORY ALLOCATION FAILED!\n");
		exit (1);
	}
	for (i = 0; i < (count + 1); i++) {
		s[i] = (int *) malloc (3 * sizeof (int));
		if (!s[i]) {
			printf ("\n MEMORY ALLOCATION FAILED!\n");
			exit (1);
		}
	}

	s[0][0] = m;	//NUMBER OF ROWS IN THE MATRIX 'A'
	s[0][1] = n;	//NUMBER OF COLUMNS IN THE MATRIX 'A'
	s[0][2] = count;	//NUMBER OF NON-ZERO ELEMENTS IN THE MATRIX 'A'

	for (i = 0; i < m; i++) {	//INSERTING ELEMENTS IN THE MATRIX 'S'
		for (j = 0; j < n; j++) {
			if (a[i][j] != 0) {	//CHECKING FOR NON-ZERO ELEMENTS
				s[pos][0]   = i;	//ROW POSITION
				s[pos][1]   = j;	//COLUMN POSITION
				s[pos++][2] = a[i][j];	//NON-ZERO ELEMENT
			}
		}
	}

	printf ("\n   MATRIX 'S'");
	printf ("\n   ----------\n\n");

	for(j = 0; j < 3; j++)	//DISPLAYING THE MATRIX 'S'
		printf ("\t  %4d]", j);
	printf ("\n");
	for (i = 0; i < (count + 1); i++) {
		printf ("\n   S[%d,", i);
		for (j = 0; j < 3; j++)
			printf ("\t %6d", s[i][j]);
		printf ("\n");
	}

//TRANSPOSING THE MATRIX 'S'
//IN LEXICOGRAPHIC ORDER AND STORING IT IN MATRIX 'T'

	int **t = (int**) malloc ((count + 1) * sizeof (int*));	//Initializing The Matrix 'T'
	if (!t) {
		printf ("\n MEMORY ALLOCATION FAILED!\n");
		exit (1);
	}
	for (i = 0; i < (count + 1); i++) {
		t[i] = (int *) malloc (3 * sizeof (int));
		if (!t[i]) {
			printf ("\n MEMORY ALLOCATION FAILED!\n");
			exit (1);
		}
	}

	pos     = 1;
	t[0][0] = n;	//NUMBER OF ROWS IN THE TRANSPOSED MATRIX
	t[0][1] = m;	//NUMBER OF COLUMNS IN THE TRANSPOSED MATRIX
	t[0][2] = count;	//NUMBER OF NON-ZERO ELEMENTS IN THE TRANSPOSED MATRIX

	for (j = 0; j < n; j++) {	//Inserting the elements in the matrix 'T'
		for (k = 1; k < (count + 1); k++) {
			if (s[k][1] == j) {
				t[pos][0]   = s[k][1];	//row position
				t[pos][1]   = s[k][0];	//column position
				t[pos++][2] = s[k][2];	//non-zero element
			}
		}
	}

	printf ("\n   MATRIX 'T'");
	printf ("\n   ----------\n\n");

	for (j = 0; j < 3; j++)	//Displaying the matrix 'T'
		printf ("\t  %4d]", j);
	printf ("\n");
	for (i = 0; i < (count + 1); i++) {
		printf ("\n   T[%d,", i);
		for (j = 0; j < 3; j++)
			printf ("\t %6d", t[i][j]);
		printf ("\n");
	}

	for (i = 0; i < m; i++)	//deallocating 'A'
		free (a[i]);
	free (a);
	for (i = 0; i < (count + 1); i++) {	//Deallocating'S' AND 'T'
		free (s[i]);
		free (t[i]);
	}
	free (s);
	free (t);

	return 0;
}
