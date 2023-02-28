//
// Created by Tran Giang on 2/5/23.
//
#include <iostream>
#include <vector>
#include <cmath>
#include "utils.cpp"

double square_root(double n){
    long double res = 1.0;
    double EPS = 1e-9;
    while(abs(res*res - n) > EPS){
        res = (res + n/res)/2;
    }
    return res;
}

void solve_square_root(){
    double n;
    std::cin >> n;
    double sr = square_root(n);
    std::cout << sr;
}

template<typename T>
std::vector<T> quadratic_func_roots(int a, int b, int c){
    double delta = b*b - 4*a*c;
    std::vector<T> res;
    if (delta < 0){
        res.push_back(-1);
        return res;
    }
    T root1 = (-b - std::sqrt(delta))/(2*a);
    T root2 = (-b + std::sqrt(delta))/(2*a);
    std::cout << root1 << " " << root2 << std::endl;
    res.push_back(std::floor(root1));
    res.push_back(std::floor(root2));
    std::sort(res.begin(), res.end(), [](int a, int b) -> bool {return a > b;});
    return res;
}

void solve_quadratic_func(){
    int a, b, c;
    std::cin >> a >> b >> c;

    std::vector<double> res = quadratic_func_roots<double>(a, b, c);
    print_1d_vector(res);
}

int digits_in_factorial(int N){
    /* log10 1 = 0
     * log10 10 = 1
     * log10 100 = 2
     * log10 1000 = 3
     *
     * find number digits of a number x is to calculate floor(log10 x) + 1
     *
     * factorial:
     * n! = 1*2*3*...*n
     * log10 n! = log10 1 + log10 2 + log10 3 + ... + log10 n
     */
    double num_digits = 0;
    for(int i = 2; i <= N; i++){
        num_digits += std::log10(i);
    }
    return std::floor(num_digits) + 1;
}

bool is_prime(int n){
    /* Upper bound of prime checks of number n is sqrt(n).
     * Proof: A number n can be represented as a pair (x,y).
     *  E.g: 30: (1, 30), (2, 15), (3, 10), (5, 6)
     * So x*y = n
     * if x <= y:
     *  x*x <= n^2
     *  x <= sqrt(n)
     */
    if(n <= 1){
        return false;
    }
    if(n == 2 || n == 3){
        return true;
    }
    if(n % 2 == 0 || n % 3 == 0){
        return false;
    }
    for(int i = 5; i <= sqrt(n); i+= 6){
        if(n % i == 0 || n % (i+2) == 0){
            return false;
        }
    }
    return true;
}

vector<int> prime_factors(int n){
    /* Prime number list P: 2, 3, 5, 7, 11, ...
     * p_i = 0
     * while (n > 0):
     *  while (n % p_i == 0):
     *      n = n / p_i
     *  i += 1
     */
    vector<int> primes;
    if(n <= 1){ return primes; }
    while(n % 2 == 0){
        primes.push_back(2);
        n = n/2;
    }
    while(n % 3 == 0){
        primes.push_back(3);
        n = n/3;
    }
    for(int i = 5; i <= sqrt(n); i += 6){
        while(n % i == 0){
            primes.push_back(i);
            n = n/i;
        }
        while(n % (i+2) == 0){
            primes.push_back(i+2);
            n = n/(i+2);
        }
    }
    if(n > 3){
        primes.push_back(n);
    }

    return primes;
}

int exactly_3divisors(int N){
    /* Given a positive integer value N. The task is to find how many numbers less than or equal to
     * N have numbers of divisors exactly equal to 3.
     * Input: 6 - Output: 1 - Explanation: The only number less than 6 with 3 divisors is 4.
     * ------------------
     * n = x*y
     * if x<=y: x*x <= n
     *        : x <= sqrt(n)
     * the maximum divisor could reach to n is x where x <= sqrt(n)
     * -------------------
     * 4: 2 2
     * 6: 2 3
     * 7: 7
     * 8: 2 2 2
     * 10: 2 5
     * 12: 2 2 3
     * 25: 5 5
     * 26: 2 13
     */
    int res = 0;
    for(int num = 2; num <= sqrt(N); num++){
        res += is_prime(num);
    }
    return res;
}

void solve_digits_in_factorial(){
    int N;
    std::cin >> N;
    int res = digits_in_factorial(N);
    std::cout << res;
}

int GCD(int a, int b){
    /* Greatest Common Divisor: finds multiplication of common prime factors.
     * E.g:
     *  30: 2x3x5
     *  15: 3x5
     *  => GCD(30, 15) = 3x5
     *  24: 2x2x2x3
     *  10: 2x5
     *  => GCD(24, 10) = 2
     *  --------------
     *  GCD(a, b) = a           if b = 0
     *            = GCD(b, a%b) if b > 0
    */
    return (b==0) ? a : GCD(b, a%b);
}