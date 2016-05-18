#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using std::vector;
using std::printf;
using std::scanf;

const int MAX = 1000000000;

vector<int> regularSieve(int bound){
    vector<bool> is_prime(bound + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    int max_prime = std::ceil(std::sqrt(bound));
    for (int prime = 2; prime <= max_prime; prime++){
        if (is_prime[prime]){
            for (int multiple = prime * 2; multiple <= bound; multiple += prime){
                is_prime[multiple] = false;
            }
        }
    }
    vector<int> primes;
    for (int n = 0; n <= bound; n++){
        if (is_prime[n]){
            primes.push_back(n);
        }
    }
    return primes;
}

const int SEGMENT_SIZE = 65536;

vector<int> segmentedSieve(int lower, int upper, vector<int> &primes){
    vector<int> results;

    auto it = primes.begin();
    while (it != primes.end()){
        if (*it >= lower){
            break;
        }
        it++;
    }

    while (it != primes.end()){
        if (*it  >= upper){
            break;
        }
        results.push_back(*it);
        it++;
    }

    int from = std::max(lower, primes.back() + 1);

    while (from < upper){
        int size = std::min(SEGMENT_SIZE, upper - from);
        vector<bool> could_be_prime(size, true);
        for (int prime : primes){
            int start_offset = (prime - from % prime) % prime;
            for (int multiple = start_offset; multiple < size; multiple += prime){
                could_be_prime[multiple] = false;
            }
        }
        for (int i = 0; i < size; i++){
            if (could_be_prime[i]){
                results.push_back(from + i);
            }
        }
        from += SEGMENT_SIZE;
    }

    return results;
}

int main(){
    vector<int> smallPrimes = regularSieve(178); // ceil(sqrt(31624)) = 178
    vector<int> rootPrimes = segmentedSieve(2, 31624, smallPrimes); // ceil(sqrt(1 billion)) = 31624

    int cases;
    scanf("%d", &cases);
    while (cases--){
        int from, to;
        scanf("%d %d", &from, &to);
        for (int prime : segmentedSieve(from, to + 1, rootPrimes)){
            printf("%d\n", prime);
        }
        printf("\n");
    }
    return 0;
}
