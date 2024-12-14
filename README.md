# **RSA Cryptography Project**

This project was developed during the first semester of the Computer Science program at **Universidade Federal de Alagoas** as part of the **Discrete Mathematics** course. The goal was to explore and implement algorithms fundamental to cryptography, such as **fast modular exponentiation**, and to better understand the mathematical foundations of encryption.

## Description

The project implements a basic **RSA encryption system**, which includes:
- Generating public and private keys.
- **Modular exponentiation** for encryption and decryption.
- Saving the public and private keys to files.
- Encrypting and decrypting messages with RSA.

The algorithms used in this project, particularly **fast modular exponentiation** and the **Euclidean algorithm** for computing the greatest common divisor (GCD), are crucial for the performance and security of cryptographic systems like RSA.

## Technologies Used

- **C programming language**
- **Mathematical algorithms** (`modular exponentiation`, `GCD`, `modular inverse`)
- **File handling** for storing the keys and encrypted messages

## Design Choices

### Pure Implementation vs. GMP

In this project, we chose to implement the RSA encryption system from scratch without relying on external libraries like **GMP** (GNU Multiple Precision Arithmetic Library). The decision to avoid GMP was made for the sake of simplicity and to focus on understanding the underlying mathematical concepts behind cryptography and modular arithmetic.

This is a learning project, and as such, it does not handle very large numbers that would typically require high-performance libraries like GMP. The RSA implementation in this project is designed to work with smaller numbers, making it more accessible and easier to understand for educational purposes. While GMP would be necessary for handling much larger prime numbers (used in real-world cryptographic systems), this project is aimed at demonstrating the basic principles of encryption and decryption rather than implementing a fully optimized cryptographic system.

### Simple Use Case

This project is not intended for high-level security or large-scale cryptographic operations. It’s a simple demonstration of RSA encryption, suitable for educational purposes, where the numbers involved are small enough to fit comfortably within the default data types of the C programming language.
