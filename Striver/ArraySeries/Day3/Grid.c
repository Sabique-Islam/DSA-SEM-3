/*

TLE :)

TC: O(2^(m+n))

SC: O(m+n) → For recursion stack

int pathHelper(int i, int j, int m, int n){
    if( (i == m-1) && (j == n-1) ) return 1;
    if( (i >= m) || (j >= n) ) return 0;
    else return pathHelper(i+1 ,j ,m ,n) + pathHelper(i ,j+1 ,m, n);
}

int uniquePaths(int m, int n) {
    return pathHelper(0, 0, m, n);
}

*/

int uniquePaths(int m, int n) {
    int N = m+n-2; // (m-1 + n-1)
    int R = n-1; // m-1 since nCr = nC(n-r)

    double res = 1;

    for(int i=1; i<=R; i++){
        res = res*(N-R+i)/i;
    }
    return (int)res;
}
