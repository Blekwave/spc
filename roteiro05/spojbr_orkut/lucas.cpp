#include <iostream>
#include <queue>
#include <list>
#include <map>

typedef std::list<std::string>::iterator listIter;
typedef std::map<std::string, std::list<std::string> >::iterator mapIter;

int main() {
    std::string name, nameRequired;
    int N, M, nTest = 1;

    while(true) {
        std::cin >> N;
        if(N == 0) break;

        std::map<std::string, std::list<std::string> > adjList;
        std::queue<std::string> zeroInDegree, result;

        std::cout << "Teste " << nTest << "\n";

        for(int i = 0; i < N; i++) {
            std::cin >> name;
            adjList[name] = std::list<std::string>();
        }
        for(int i = 0; i < N; i++) {
            std::cin >> name >> M;
            for(int j = 0; j < M; j++) {
                std::cin >> nameRequired;
                adjList[name].push_back(nameRequired);
            }
        }

        for(mapIter i = adjList.begin(); i != adjList.end(); i++) {
            if(i->second.empty()) {
                zeroInDegree.push(i->first);
                adjList.erase(i);
            }
        }

        while(!zeroInDegree.empty()) {
            name = zeroInDegree.front();
            zeroInDegree.pop();

            result.push(name);

            for(mapIter currFriend = adjList.begin(); currFriend != adjList.end(); currFriend++) {
                for(listIter req = currFriend->second.begin(); req != currFriend->second.end(); req++) {
                    if(*req == name) {
                        currFriend->second.erase(req);
                        break;
                    }
                }
                if(currFriend->second.empty()) {
                    zeroInDegree.push(currFriend->first);
                    adjList.erase(currFriend);
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

        std::cout << "\n\n";

        nTest++;
    }

    return 0;
}
