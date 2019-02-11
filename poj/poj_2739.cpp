#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stdint.h>
#include<signal.h>

void oopsie(int sig) {
    printf("Exception bois\n");
    exit(1);
}


using namespace std;
// Get all primes up until max
vector<int64_t> gen_primes(uint64_t max) {
    vector<int64_t> primes;
    vector<int64_t> multiple_eliminates;
    int64_t max_sqrt = ceil(sqrt(static_cast<double> (max)));
    for (unsigned i = 2; i <= max; i++) {
        // If less than sqrt, dont add any additional to the multiple_eliminates vector
        bool divides = false;
        for (unsigned rem = 0; rem < multiple_eliminates.size(); rem++) {
            if (i % multiple_eliminates[rem] == 0) divides = true;
        }
        if (!divides) {
            if (i < max_sqrt)
                multiple_eliminates.push_back(i);
            primes.push_back(i);
        }
    }
    return primes;
}

unsigned get_num_conseq_prime_strings(const vector<int64_t> & primes, uint64_t target) {
    if (primes.size() == 0) return 0;
    unsigned number = 0;
    unsigned left_ptr = 0, right_ptr = 0;
    int64_t total_sum = primes[0];
    if (primes.size() == 0) return 0;
    // Get the total sum of all the numbers
    while (left_ptr <= right_ptr && right_ptr < primes.size()) {
        if (total_sum == target) {
            number += 1;
            total_sum += primes[++right_ptr];
        }
        else if (total_sum < target) {
            total_sum += primes[++right_ptr];
        }
        else if (total_sum > target) {
            total_sum -= primes[left_ptr++];
        }
    }
    return number;
}

int main() {
    signal(SIGFPE, oopsie);
    string input;
    int num;
    do {
        cin >> input;
        num = atoi(input.c_str());
        if (num == 0) break;
        vector<int64_t> primes = gen_primes(num);
        unsigned answer = get_num_conseq_prime_strings(primes, num);
        cout << answer << endl;
    } while (num != 0);
}
