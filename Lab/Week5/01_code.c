#include <stdio.h>

// Insert element into priority queue (descending order)
void insertPQ(int pq[], int *size, int value) {
    if (value <= 0) 
        return;
    int i = (*size)-1;
    
    while (i>=0 && pq[i]<value)
    {
        pq[i+1] = pq[i];
        i--;
    }
    pq[i+1] = value;
    (*size)++;
}

// Delete max (first element)
int deleteMaxPQ(int pq[], int *size) {
  if (*size == 0)
  {
    return 0;
  }
    
    int temp = pq[0];
    
    for (int i=1; i<*size; i++)
    {
        pq[i-1] = pq[i];
    }
    (*size)--;
    return temp;
}

int maximumScore(int a, int b, int c) {
    int pq[3];
    int size = 0;
    int score = 0;

    // Insert piles into PQ
    insertPQ(pq, &size, a);
    insertPQ(pq, &size, b);
    insertPQ(pq, &size, c);

    //Implement rest of the code to find the maximum score
    while (size>1) 
    {
            int x = deleteMaxPQ(pq, &size);
            int y = deleteMaxPQ(pq, &size);
            x--;y--;
            score++;
            insertPQ(pq, &size, x);
            insertPQ(pq, &size, y);
        }
    return score;
}

// Driver code, do not change!
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int result = maximumScore(a, b, c);
    printf("%d\n", result);

    return 0;
}