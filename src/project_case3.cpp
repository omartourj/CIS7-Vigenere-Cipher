

#include <iostream>
#include <string>
using namespace std;

int main() {
    string plaintext, keyword;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter keyword: ";
    getline(cin, keyword);

    // Convert to uppercase
    for (int i = 0; i < plaintext.length(); i++) {
        plaintext[i] = toupper(plaintext[i]);
    }
    for (int i = 0; i < keyword.length(); i++) {
        keyword[i] = toupper(keyword[i]);
    }

    // Make the key the same length as plaintext
    string key = "";
    int j = 0;
    for (int i = 0; i < plaintext.length(); i++) {
        if (j == keyword.length()) {
            j = 0;
        }
        key += keyword[j];
        j++;
    }

    // Encrypt the message
    string encrypted = "";
    for (int i = 0; i < plaintext.length(); i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            int P = plaintext[i] - 'A';
            int K = key[i] - 'A';
            int C = (P + K) % 26;
            encrypted += char(C + 'A');
        } else {
            encrypted += plaintext[i];
        }
    }

    // Decrypt the message
    string decrypted = "";
    for (int i = 0; i < encrypted.length(); i++) {
        if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            int E = encrypted[i] - 'A';
            int K = key[i] - 'A';
            int P = (E - K + 26) % 26;
            decrypted += char(P + 'A');
        } else {
            decrypted += encrypted[i];
        }
    }

    cout << "\nGenerated Key: " << key << endl;
    cout << "Encrypted Text: " << encrypted << endl;
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}
