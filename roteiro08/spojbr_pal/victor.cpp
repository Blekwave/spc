#include <cstdio>
#include <cstdlib>

// Nostalgia might be taking over. C time.

bool isPalindrome(char *f, char *l){
    while(f < l){
        if (*f != *l){
            return false;
        }
        f++; l--;
    }
    return true;
}

int minPalindromes(char *start, char *end){
    int count = 0;
    while (start != end){
        char *l;
        for (l = end - 1; l > start; l--){
            if (*l == *start and isPalindrome(start, l)){
                break;
            }
        }
        count++;
        start = l + 1;
    }
    return count;
}

int main(){
    int n;
    int test_number = 1;
    while (true){
        std::scanf("%d", &n);
        if (n == 0){
            break;
        }
        std::fgetc(stdin); // line break

        char *str = (char *) std::malloc(n + 1);
        std::fgets(str, n + 1, stdin);
        std::fgetc(stdin); // line break

        int result = minPalindromes(str, str + n);
        std::printf("Teste %d\n%d\n\n", test_number, result);
        test_number++;

        std::free(str);
    }
}
