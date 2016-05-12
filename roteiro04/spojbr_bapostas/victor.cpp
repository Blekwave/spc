// O problema consiste em determinar a maior subsequência contígua em um vetor.
// Para isso, é armazenado o valor da subsequência atual, inicializado como 0,
// assim como o valor da subsequência máxima. Itera-se, então, ao longo do
// vetor, e, para cada valor lido, o valor é somado à soma atual. Se essa soma
// é maior que a máxima registrada, a máxima é redefinida como a soma atual. Se
// a soma resulta em um número negativo, seu valor é corrigido para zero.

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
