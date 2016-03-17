/*

    Para cada caso de teste o programa lê os ingressos
    na ordem e assim que encontra um valor igual ao número
    de ingressos checados até o momento, exibe-o na saída
    e passa para o próximo teste.

*/

#include <iostream>
#include <string>

int main(){
    int num_testes = 1;
    int num_ingressos, ingresso_atual, num_part;

    std::string dump;

    while(true) {
        std::cin >> num_part;
        if(num_part == 0) break;

        std::cout << "Teste " << num_testes << "\n";
        ++num_testes;
        num_ingressos = 0;

        do {
            std::cin >> ingresso_atual;
        } while(ingresso_atual != ++num_ingressos);

        std::cout << ingresso_atual << "\n";

        std::getline(std::cin, dump);
    }

    return 0;        
}
