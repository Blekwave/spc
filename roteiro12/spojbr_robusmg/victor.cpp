#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::pow;

int getMinCost(vector<int> &costs){
    int min_cost = 0;
    for (int cost : costs){
        min_cost += cost;
    }
    return min_cost;
}


double getRobustness(vector<int> &counts, vector<double> &rates){
    double rob = 1;
    for (unsigned i = 0; i < counts.size(); i++){
        rob *= 1 - pow(rates[i], counts[i]);
    }
    return rob;
}

double runCase(int layers, int cost_limit, vector<int> &costs,
        vector<double> &rates){
    int min_weight = getMinCost(costs);

    if (min_weight > cost_limit){
        return 0;
    }

    vector<int> min_counts(layers, 1);

    vector<double> robustness{getRobustness(min_counts, rates)};
    vector<vector<int>> best_counts{min_counts};


    for (int dw = 1; min_weight + dw <= cost_limit; dw++){
        double best = robustness[dw - 1];
        vector<int> new_best_counts = best_counts[dw - 1];
        for (int layer = 0; layer < layers; layer++){
            int ldw = dw - costs[layer];
            if (ldw >= 0){
                vector<int> lcounts = best_counts[ldw];
                lcounts[layer]++;
                double rob = getRobustness(lcounts, rates);
                if (rob > best){
                    best = rob;
                    new_best_counts = lcounts;
                }
            }
        }
        robustness.push_back(best);
        best_counts.push_back(new_best_counts);
    }

    return robustness.back();
}

int main(){
    int layers, cost_limit;

    while (true){
        cin >> layers >> cost_limit;
        if (layers == 0 and cost_limit == 0){
            break;
        }

        vector<int> costs;
        vector<double> rates;

        for (int i = 0; i < layers; i++){
            int cost;
            double rate;
            cin >> cost >> rate;
            costs.push_back(cost);
            rates.push_back(rate);
        }

        double result = runCase(layers, cost_limit, costs, rates);
        cout << std::fixed << std::setprecision(3) << result << "\n";
    }

    return 0;
}
