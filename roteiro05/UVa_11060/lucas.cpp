#include <iostream>
#include <queue>
#include <list>
#include <map>

int main() {
    std::string name, nameRequired;
    int N, M, nTest = 1;

    while(std::cin >> N) {
        if(nTest != 1) std::cout << "\n";

        std::map<std::string, std::list<std::string> > adjList;
        std::vector<std::string> names;
        std::queue<std::string> zeroInDegree, result;

        for(int i = 0; i < N; i++) {
            std::cin >> name;
            adjList[name] = std::list<std::string>();
            names.push_back(name);
        }
        std::cin >> M;
        for(int i = 0; i < M; i++) {
            std::cin >> nameRequired >> name;
            adjList[name].push_back(nameRequired);
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
                auto currBev = adjList[names[i]];
                if(currBev.empty()) continue;
                for(auto req = currBev.begin(); req != currBev.end(); req++) {
                    if(*req == name) {
                        currBev.erase(req);
                        break;
                    }
                }
                if(currBev.empty()) {
                    zeroInDegree.push(names[i]);
                    adjList.erase(names[i]);
                }
            }
        }

        std::cout << "Case #" << nTest << ":  Dilbert should drink beverages in this order:";
        while(!result.empty()) {
            std::cout << " " << result.front();
            result.pop();
        }
        std::cout << ".\n\n";

        nTest++;
    }

    return 0;
}
