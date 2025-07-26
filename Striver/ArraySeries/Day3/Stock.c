#include <stdio.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    int minProfit = prices[0];
    int maxProfit = INT_MIN;

    for(int i=0; i<pricesSize; i++){
        if(prices[i]<minProfit){
            minProfit = prices[i];
        }else if(prices[i] - minProfit > maxProfit){
            maxProfit = prices[i] - minProfit;
        }
    }
    return maxProfit;
}


int main(){

    return 0;
}