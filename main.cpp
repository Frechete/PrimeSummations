#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

const int MAX = 1001;


std::vector<int> p;
std::vector<long>n(MAX);


void sieve() {
    int isPrime[MAX] = {  }; 
    for (int i = 2; i< MAX; i++) {
        if (isPrime[i] == 0) {
            p.emplace_back(i);
            for (int j = 2; i * j< MAX; j++)
                isPrime[i * j]= 1;
        }
    }
}

void fill_list(int &max) {
    sieve();
    n[0]=1;
    for(auto &n1 : p) {
        for(int i=n1;i<=max;i++)
            n[i]+=n[i-n1];
    }
}
 
int main()  {
    long number_of_tests;
   
    scanf("%ld", &number_of_tests);
    std::vector<long> testv;
    int max = 0;
    while(number_of_tests--) {
        long test;
        std::cin >> test;
        if (test > max) max = test;
        testv.emplace_back(test);
    }
    fill_list(max); 
    for(auto &n1 : testv) {
       printf("%ld\n", n[n1]);
    }
}
