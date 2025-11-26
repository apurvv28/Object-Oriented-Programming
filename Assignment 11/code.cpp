#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPalindrome(int n) {
    int original = n, rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return original == rev;
}

int main() {
    vector<int> v;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        v.push_back(val);
    }

    int even = 0, odd = 0, prime = 0, palindrome = 0;

    for (int x : v) {
        if (x % 2 == 0) even++;
        else odd++;

        if (isPrime(x)) prime++;
        if (isPalindrome(x)) palindrome++;
    }

    cout << "\nEven Count       : " << even;
    cout << "\nOdd Count        : " << odd;
    cout << "\nPrime Count      : " << prime;
    cout << "\nPalindrome Count : " << palindrome << endl;

    return 0;
}
