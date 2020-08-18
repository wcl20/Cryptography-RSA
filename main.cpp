#include <iostream>
#include <math.h>

// Basic Euclidean Algorithm
// Returns the largest commond factor of a and b
int gcd(double a, double b)
{
    // Base case
    if (b == 0) return a;
    return gcd(b, fmod(a, b));
}

// Returns the value a^b (mod n)
double power(double a, double b, double n)
{
    double result = 1;

    a = fmod(a, n);
    if (a == 0) return 0;

    while (b > 0)
    {
        // If b is odd
        if (fmod(b, 2) == 1) result = fmod(result * a, n);

        // Now b is even
        b = floor(b / 2);
        a = fmod(a * a, n);
    }

    return result;
}

/*
 * Extended Euclidean Algorithm
 * Returns the largest common factor of a and b
 * and the coefficients of Bezout's identity x and y: ax + by = gcd(a, b)
 */
int extended_gcd(double a, double b, int *x, int *y)
{
    // Base Case
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int u, v;
    int gcd = extended_gcd(b, fmod(a, b), &u, &v);

    *x = v;
    *y = u - int(a / b) * v;

    return gcd;
}

/*
 * Returns the modolus multiplicative inverse of a under b.
 * The modulus inverse is a number x such that ax = 1 (mod b)
 *
 * Use exteded Euclidean algorithm to find x.
 * Exploit the fact that a and b are coprimes.
 *
 * ax + by = gcd(a, b)
 * ax + by = 1
 * ax + by = 1 (mod b)
 * ax = 1 (mod b)
 *
 * Since by (mod b) = 0.
 * Hence the x coefficient corresponds to the modulo inverse.
 */
double modulo_inverse(double a, double b)
{
    int x, y;
    int gcd = extended_gcd(a, b, &x, &y);
    if (gcd != 1) return 0;
    return fmod(fmod(x, b) + b, b);
}

int main()
{
    // Generate random prime numbers p and q
    double p = 11;
    double q = 13;

    std::cout << "Generate prime pairs ..." << std::endl;
    std::cout << "p: " << p << std::endl;
    std::cout << "q: " << q << std::endl;
    std::cout << std::endl;

    // Compute modulus n
    double n = p * q;
    std::cout << "Compute modulo ..." << std::endl;
    std::cout << "n: " << n << std::endl;
    std::cout << std::endl;

    // Compute Euler Totient phi(n)
    double r = (p - 1) * (q - 1);
    std::cout << "Compute Euler Totient ..." << std::endl;
    std::cout << "r: " << r << std::endl;
    std::cout << std::endl;

    // Find a number e that is coprime with r
    double e = 7;
    for (; gcd(e, r) != 1; e++);
    std::cout << "Compute public key e ..." << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "Check e and r are coprime ..." << std::endl;
    std::cout << "GCD(e, r) = " << gcd(e, r) << std::endl;
    std::cout << std::endl;

    // d is the modulus inverse of e and r
    double d = modulo_inverse(e, r);
    std::cout << "Compute private key d ..." << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "Checking ed = kr + 1 ..." << std::endl;
    std::cout << "ed % r = " << fmod(e * d, r) << std::endl;
    std::cout << std::endl;

    double message = 9;
    std::cout << "Message: " << message << std::endl;

    double encoded = power(message, e, n);//fmod(pow(message, e), n);
    std::cout << "Encoded: " << encoded << std::endl;

    double decoded = power(encoded, d, n);
    std::cout << "Decoded: " << decoded << std::endl;

    return 0;
}
