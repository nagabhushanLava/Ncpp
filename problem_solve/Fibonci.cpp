#include <iostream>
#include <chrono>
using namespace std;

long long fibonacci(long long n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    long long n;
    cout << "Enter the value of n: ";
    cin >> n;

    long long (*ptr)(long long) = &fibonacci;

    // Start timing
    auto start = chrono::high_resolution_clock::now();

    cout << "Fibonacci series: ";
    for (long long i = 0; i < n; ++i) {
        cout << ptr(i) << " ";
    }
    cout << endl;

    // End timing
    auto end = chrono::high_resolution_clock::now();

    // Calculate duration in seconds (fractional)
    chrono::duration<double> duration = end - start;
    cout << "Time taken: " << duration.count() << " seconds" << endl;

    return 0;
}
