#include <iostream>
#include <queue>
#include <list>
#include <map>

int main() {
    std::string name, nameRequired;
    int N, M, nTest = 1;

    while(true) {
        std::cin >> N;
        if(N == 0)     break;
        if(nTest != 1) std::cout << "\n";

        std::map<std::string, std::list<std::string> > adjList;
        std::queue<std::string> zeroInDegree, result;
        std::vector<std::string> names;

        std::cout << "Teste " << nTest << "\n";

        for(int i = 0; i < N; i++) {
            std::cin >> name;
            names.push_back(name);
            adjList[name] = std::list<std::string>();
        }
        for(int i = 0; i < N; i++) {
            std::cin >> name >> M;
            for(int j = 0; j < M; j++) {
                std::cin >> nameRequired;
                adjList[name].push_back(nameRequired);
            }
        }

        for(int i = 0; i < N; i++) {
            auto elem = adjList[names[i]];
            if(elem.empty()) {
                zeroInDegree.push(names[i]);
                adjList.erase(names[i]);
            }
        }

        while(!zeroInDegree.empty()) {
            name = zeroInDegree.front();
            zeroInDegree.pop();

            result.push(name);

            for(int i = 0; i < N; i++) {
                auto& currFriend = adjList[names[i]];
                if(currFriend.empty()) continue;
                for(auto req = currFriend.begin(); req != currFriend.end(); req++) {
                    if(*req == name) {
                        currFriend.erase(req);
                        break;
                    }
                }
                if(currFriend.empty()) {
                    zeroInDegree.push(names[i]);
                    adjList.erase(names[i]);
                }
            }
        }

        if(result.size() == N) {
            while(!result.empty()) {
                std::cout << result.front() << " ";
                result.pop();
            }
        } else {
            std::cout << "impossivel";
        }

        std::cout << "\n";

        nTest++;
    }

    return 0;
}
