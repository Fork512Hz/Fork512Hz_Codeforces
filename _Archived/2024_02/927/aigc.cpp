#include <iostream>

int extendedGCD(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

bool findSolution(int a, int b, int c, int& x, int& y) {
    int gcd = extendedGCD(a, b, x, y);

    // Check if c is divisible by gcd(a, b)
    if (c % gcd != 0) {
        return false;
    }

    // Scale the solution to match the given equation ax + by = c
    x *= c / gcd;
    y *= c / gcd;

    // Adjust x to be minimal and positive
    int sign = (x < 0) ? -1 : 1;
    int steps = x / b;
    x -= steps * b * sign;

    // Ensure x is positive
    if (x <= 0) {
        x += b * sign;
    }

    return true;
}

int main() {
    int a, b, c;
    std::cout << "Enter values for a, b, and c: ";
    std::cin >> a >> b >> c;

    int x, y;

    if (findSolution(a, b, c, x, y)) {
        std::cout << "Solution: x = " << x << ", y = " << y << std::endl;
    } else {
        std::cout << "No solution exists for the given equation." << std::endl;
    }

    return 0;
}
