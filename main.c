#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        unsigned long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

unsigned long long expModular(unsigned long long base, unsigned long long exponent, unsigned long long modulo) {
    unsigned long long result = 1;
    base = base % modulo;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulo;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulo;
    }
    return result;
}

int isPrime(unsigned long long num) {
    if (num < 2) return 0;
    if (num == 2 || num == 3) return 1;
    if (num % 2 == 0) return 0;
    for (unsigned long long i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

unsigned long long modInverse(unsigned long long a, unsigned long long m) {
    unsigned long long m0 = m, t, q;
    unsigned long long x0 = 0, x1 = 1;
    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;
    return x1;
}

void generateKey() {
    unsigned long long p, q, e, n, totient, d;

    do {
        printf("Enter the value of p (prime):\n");
        scanf("%llu", &p);
    } while (!isPrime(p));

    do {
        printf("Enter the value of q (prime):\n");
        scanf("%llu", &q);
    } while (!isPrime(q));

    n = p * q;
    totient = (p - 1) * (q - 1);

    do {
        printf("Enter the value of e (coprime with %llu):\n", totient);
        scanf("%llu", &e);
    } while (e >= totient || gcd(e, totient) != 1);

    d = modInverse(e, totient);

    FILE *publicKey = fopen("keys/public_key.txt", "w");
    fprintf(publicKey, "Public key (%llu, %llu)", e, n);
    fclose(publicKey);

    FILE *privateKey = fopen("keys/private_key.txt", "w");
    fprintf(privateKey, "Private key (%llu, %llu)", d, n);
    fclose(privateKey);

    printf("Public key stored in 'public_key.txt'.\n");
    printf("Private key stored in 'private_key.txt'.\n");
}

void encrypt() {
    getchar();
    unsigned long long e, n;

    printf("Enter your message to be encrypted:\n");
    char *message = NULL;
    size_t messageSize = 0;
    getline(&message, &messageSize, stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter the values of 'e' and 'n' (in the format 'e, n'):\n");
    scanf("%llu, %llu", &e, &n);

    FILE *encryptedMessage = fopen("messages/encrypted_message.txt", "w");
    for (size_t i = 0; i < strlen(message); i++) {
        unsigned long long encrypted = expModular((unsigned long long)message[i], e, n);
        fprintf(encryptedMessage, "%llu ", encrypted);
    }
    fclose(encryptedMessage);
    printf("Encrypted message saved in 'encrypted_message.txt'.\n");

    free(message);
}

void decrypt() {
    unsigned long long d, n;

    printf("Enter the values of 'd' and 'n' (in the format 'd, n'):\n");
    scanf("%llu, %llu", &d, &n);

    getchar();

    printf("Enter your encrypted message (numbers separated by spaces):\n");
    char *line = NULL;
    size_t lineSize = 0;
    getline(&line, &lineSize, stdin);

    char *token = strtok(line, " ");
    printf("Decrypted message:\n");
    while (token != NULL) {
        unsigned long long curr = strtoull(token, NULL, 10);
        unsigned long long decrypted = expModular(curr, d, n);
        printf("%c", (char)decrypted);
        token = strtok(NULL, " ");
    }
    printf("\n");

    free(line);
}

int main() {
    printf("What would you like to do?\n");
    printf("1- Generate public key.\n2- Encrypt a message.\n3- Decrypt a message.\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            generateKey();
            break;
        case 2:
            encrypt();
            break;
        case 3:
            decrypt();
            break;
        default:
            printf("Invalid option.\n");
    }
    return 0;
}
