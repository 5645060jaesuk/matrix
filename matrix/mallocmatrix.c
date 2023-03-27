#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100
typedef struct
{
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix
{
	element *data;
	int rows;
	int cols;
	int terms;
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix *a)
{
	SparseMatrix  *b = (SparseMatrix *)malloc(sizeof(SparseMatrix));

	b->rows = a->cols;
	b->cols = a->rows;
	b->terms = a->terms;
	b->data = (element*)malloc(b->terms * sizeof(element));

	if (a->terms > 0)
	{
		int bindex = 0;
		for (int c=0; c < a->cols; c++)
		{
			for (int i = 0; i < a->terms; i++)
			{
				if (a->data[i].col == c)
				{
					b->data[bindex].row = a->data[i].col;
					b->data[bindex].col = a->data[i].row;
					b->data[bindex].value = a->data[i].value;
					bindex++;
				}
			}
		}
	}
	return *b;
}


void matrix_print(SparseMatrix a)
{
	printf("====================\n");
	for (int i = 0; i < a.terms; i++)
	{
		printf("(%d %d %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("====================\n");
}

int main(void)
{

	int rows, cols, terms;
	printf("Enter the size of rows, colums, and non-zero terms:\n");
	scanf_s("%d %d %d", &rows, &cols, &terms);

	SparseMatrix m = { NULL, rows, cols, terms };
	m.data = (element*)malloc(m.terms * sizeof(element));

	printf("Enter row, column, and value pair in order \n");

	for (int i = 0; i < m.terms; i++)
	{
		scanf_s("%d %d %d", &m.data[i].row, &m.data[i].col, &m.data[i].value);
	}

	SparseMatrix result = matrix_transpose2(&m);
	matrix_print(result);

	free(m.data);
	free(result.data);
	return 0;
}
