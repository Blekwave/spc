// O problema envolve encontrar as "string roots" de uma string, ou seja, o
// menor trecho que, concatenado consigo mesmo um número inteiro de vezes,
// forma a string original. Para encontrar tal valor, a solução proposta
// itera pelos divisores do comprimento da string (visto que a raiz da
// string tem que ter tamanho divisor do comprimento da string principal
// ou então é impossível que ela forme a string original ao ser multiplicada
// por um número inteiro) em ordem crescente.
// Para cada divisor d, o algoritmo checa se os primeiros d caracteres da string
// se repetem ao longo da string inteira. Caso isso ocorra, os primeiros d
// caracteres formam uma string root e, portanto, essa string, concatenada
// len(string)/d vezes forma a string original. O algoritmo sempre para, pois
// no pior caso, a string inteira é a sua raiz.
#include <cstdio>
#include <cstring>
#include <cstdlib>

char hay[100002];

int main(){

    while (true){
        std::fgets(hay, 100002, stdin);
        int len = std::strlen(hay);
        hay[len - 1] = '\0';
        len--;

        if (hay[0] == '*' && hay[1] == '\0'){
            break;
        }

        int div = 1;

        while (div < len){
            if (len % div == 0){
                bool valid = true;
                for (int i = 0; valid && i < div; i++){
                    char c = hay[i];
                    for (int j = div + i; j < len; j += div){
                        if (hay[j] != c){
                            valid = false;
                            break;
                        }
                    }
                }
                if (valid){
                    break;
                }
            }
            div++;
        }

        std::printf("%d\n", len / div);
    }

    return 0;
}
