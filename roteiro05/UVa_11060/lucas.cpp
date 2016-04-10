#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>

int main() {
    std::string name, nameRequired;
    int N, M, nTest = 1;

    while(std::cin >> N) {

        std::map<std::string, std::list<std::string> > adjList;
        std::queue<std::string> result;
        std::vector<int> zeroInDegree;
        std::vector<std::string> names;

        for(int i = 0; i < N; i++) {
            std::cin >> name;
            names.push_back(name);
            adjList[name] = std::list<std::string>();
        }
        std::cin >> M;
        for(int i = 0; i < M; i++) {
            std::cin >> nameRequired >> name;
            adjList[name].push_back(nameRequired);
        }

        for(int i = 0; i < N; i++) {
            auto elem = adjList[names[i]];
            if(elem.empty()) {
                zeroInDegree.push_back(i);
                adjList.erase(names[i]);
            }
        }
        std::sort(zeroInDegree.rbegin(), zeroInDegree.rend());

        while(!zeroInDegree.empty()) {
            int index = zeroInDegree.back();
            name = names[index];
            zeroInDegree.pop_back();

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
                    zeroInDegree.push_back(i);
                    adjList.erase(names[i]);
                    std::sort(zeroInDegree.rbegin(), zeroInDegree.rend());
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
