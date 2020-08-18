# Cryptography RSA
Implementation of basic the RSA Encryption.

Encryption and Decryption in RSA exploits the Euler's generalization of Fermat's Little Theorem:

![equation](https://latex.codecogs.com/gif.latex?m%5E%7Bk%5Cphi%28n%29%7D%20%5Cequiv%201%20%28mod%5C%3Bn%29)

![equation](https://latex.codecogs.com/gif.latex?m%5E%7Bk%5Cphi%28n%29%20&plus;%201%7D%20%5Cequiv%20m%20%28mod%5C%3Bn%29)

Where totient function describes the number of values less than n which are relatively prime to n.

In RSA, n is always the product of two primes (p and q) therefore

![equation](https://latex.codecogs.com/gif.latex?%5Cphi%28n%29%20%3D%20%28p-1%29%28q-1%29)

The principle of RSA is to find two numbers (e and d), such that

![equation](https://latex.codecogs.com/gif.latex?ed%20%3D%20k%5Cphi%28n%29%20&plus;%201)

Or alternatively,

![equation](https://latex.codecogs.com/gif.latex?ed%20%3D%201%5C%3B%28mod%5C%3B%5Cphi%28n%29%29)

e must be a coprime of ![equation](https://latex.codecogs.com/gif.latex?%5Cphi%28n%29) and is chosen somewhat arbitrarily.

d is the modulo inverse of e under ![equation](https://latex.codecogs.com/gif.latex?%5Cphi%28n%29). (and vice versa)

(e, n) together forms the public key. To encrypt a message m:

![equation](https://latex.codecogs.com/gif.latex?c%20%3D%20m%5Ee%5C%3Bmod%5C%3Bn)

(d, n) together forms the private key. To decrypt a cipher c:

![equation](https://latex.codecogs.com/gif.latex?m%20%3D%20c%5Ed%5C%3Bmod%5C%3Bn)


## Setup
Create executable
```bash
g++ main.cpp -o main
```
Run executable
```bash
./main
```
