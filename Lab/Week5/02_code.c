#include <stdio.h>
#include <stdlib.h>

// Structure to store each point and its distance squared
typedef struct {
    int x, y;
    int distSq;
} Point;

// Insert point in descending order of distance (front = farthest)
void insertPQ(Point pq[], int *size, Point p) {
  	int i = *size-1;
    while (i>=0 && pq[i].distSq<p.distSq)
    {
        pq[i+1] = pq[i];
        i--;
    }
    pq[i +1] =p;
    (*size)++;
}

// Delete max (farthest point, at index 0)
Point deleteMaxPQ(Point pq[], int *size) {
    Point max =pq[0];
    for (int i =1; i< *size;i++)
    {
        pq[i- 1] =pq[i];
    }
    (*size)--;
    return max;
}

// If new point is closer, replace the farthest one

void replaceIfCloser(Point pq[], int *size, int k, Point p) {
	if (*size<k)
    {
        insertPQ(pq,size,p);
    } 
    else if(p.distSq< pq[0].distSq) 
    {
        deleteMaxPQ(pq,size);
        insertPQ(pq,size,p);
    }
}


//Driver code, DO NOT EDIT!
int main() {
    int n, k;
    scanf("%d", &n);

    Point points[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
        points[i].distSq = points[i].x * points[i].x + points[i].y * points[i].y;
    }
    scanf("%d", &k);

    // Priority Queue array
    Point pq[k + 1]; // +1 just to avoid edge shift issues
    int size = 0;

    // Process all points
    for (int i = 0; i < n; i++) {
        replaceIfCloser(pq, &size, k, points[i]);
    }

    for (int i = 0; i < size; i++) {
        printf("%d %d\n", pq[i].x, pq[i].y);
    }

    return 0;
}