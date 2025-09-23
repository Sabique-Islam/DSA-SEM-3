#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} Element;

typedef struct {
    int rows;
    int cols;
    int num;       // number of non-zero elements
    Element *e;    // array of non-zero elements
} SparseMatrix;

// Function to create a sparse matrix
SparseMatrix Create_SparseMatrix(int rows, int cols, int num) {
    SparseMatrix s;
    s.rows = rows;
    s.cols = cols;
    s.num = num;
    s.e = (Element*)malloc(num * sizeof(Element));

    printf("Enter row, column and value for each non-zero element:\n");
    for (int i = 0; i < num; i++) {
        scanf("%d %d %d", &s.e[i].row, &s.e[i].col, &s.e[i].val);
    }

    return s;
}

// Function to display sparse matrix
void Display(SparseMatrix s) {
    int k = 0;
    for (int i = 0; i < s.rows; i++) {
        for (int j = 0; j < s.cols; j++) {
            if (k < s.num && s.e[k].row == i && s.e[k].col == j)
                printf("%d ", s.e[k++].val);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

// Transpose of sparse matrix
SparseMatrix Transpose_of_SparseMatrix(SparseMatrix s) {
    SparseMatrix t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.num = s.num;
    t.e = (Element*)malloc(s.num * sizeof(Element));

    int k = 0;
    for (int i = 0; i < s.cols; i++) {
        for (int j = 0; j < s.num; j++) {
            if (s.e[j].col == i) {
                t.e[k].row = s.e[j].col;
                t.e[k].col = s.e[j].row;
                t.e[k].val = s.e[j].val;
                k++;
            }
        }
    }

    return t;
}

// Add two sparse matrices
SparseMatrix Add_SparseMatrices(SparseMatrix s1, SparseMatrix s2) {
    if (s1.rows != s2.rows || s1.cols != s2.cols) {
        printf("Matrix dimensions do not match for addition.\n");
        exit(1);
    }

    SparseMatrix sum;
    sum.rows = s1.rows;
    sum.cols = s1.cols;
    sum.e = (Element*)malloc((s1.num + s2.num) * sizeof(Element));

    int i = 0, j = 0, k = 0;

    while (i < s1.num && j < s2.num) {
        int pos1 = s1.e[i].row * s1.cols + s1.e[i].col;
        int pos2 = s2.e[j].row * s2.cols + s2.e[j].col;

        if (pos1 < pos2)
            sum.e[k++] = s1.e[i++];
        else if (pos1 > pos2)
            sum.e[k++] = s2.e[j++];
        else {
            sum.e[k] = s1.e[i];
            sum.e[k++].val = s1.e[i].val + s2.e[j].val;
            i++; j++;
        }
    }

    while (i < s1.num)
        sum.e[k++] = s1.e[i++];
    while (j < s2.num)
        sum.e[k++] = s2.e[j++];

    sum.num = k;
    return sum;
}

// Multiply two sparse matrices
SparseMatrix Multiply_SparseMatrices(SparseMatrix s1, SparseMatrix s2) {
    if (s1.cols != s2.rows) {
        printf("Matrix dimensions do not match for multiplication.\n");
        exit(1);
    }

    SparseMatrix product;
    product.rows = s1.rows;
    product.cols = s2.cols;
    product.num = 0;
    product.e = (Element*)malloc(s1.num * s2.num * sizeof(Element)); // max possible

    for (int i = 0; i < s1.rows; i++) {
        for (int j = 0; j < s2.cols; j++) {
            int sum = 0;
            for (int k1 = 0; k1 < s1.num; k1++) {
                if (s1.e[k1].row == i) {
                    for (int k2 = 0; k2 < s2.num; k2++) {
                        if (s2.e[k2].col == j && s2.e[k2].row == s1.e[k1].col)
                            sum += s1.e[k1].val * s2.e[k2].val;
                    }
                }
            }
            if (sum != 0) {
                product.e[product.num].row = i;
                product.e[product.num].col = j;
                product.e[product.num].val = sum;
                product.num++;
            }
        }
    }

    return product;
}

int main() {
    SparseMatrix s1 = Create_SparseMatrix(2, 3, 4);
    SparseMatrix s2 = Create_SparseMatrix(2, 3, 3);

    printf("\nMatrix 1:\n"); Display(s1);
    printf("\nMatrix 2:\n"); Display(s2);

    SparseMatrix sum = Add_SparseMatrices(s1, s2);
    printf("\nSum Matrix:\n"); Display(sum);

    SparseMatrix t = Transpose_of_SparseMatrix(s1);
    printf("\nTranspose of Matrix 1:\n"); Display(t);

    SparseMatrix s3 = Create_SparseMatrix(3, 2, 4);
    SparseMatrix prod = Multiply_SparseMatrices(s1, s3);
    printf("\nProduct Matrix:\n"); Display(prod);

    return 0;
}
