#include <stdio.h>

int main(){
    int max, prev, curr, bets;
    scanf("%d", &bets);
    while (bets){
        max = 0, prev = 0;
        while (bets--){
            scanf("%d", &curr);
            prev += curr;
            if (prev < 0)
                prev = 0;
            else if (prev > max)
                max = prev;
        }

        if (max > 0)
            printf("The maximum winning streak is %d.\n", max);
        else
            printf("Losing streak.\n");

        scanf("%d", &bets);
    }
}
