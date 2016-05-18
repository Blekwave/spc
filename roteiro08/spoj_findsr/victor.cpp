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
