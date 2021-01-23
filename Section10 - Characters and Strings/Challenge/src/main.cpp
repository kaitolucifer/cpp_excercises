#include <iostream>
#include <string>

using namespace std;

int main()
{
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    string message {};
    cout << "Enter your secret message: ";
    getline(cin, message);
    cout << "Encrypting message..." << endl;
    for (size_t i {}; i < message.length(); ++i) {
        size_t position = alphabet.find(message.at(i));
        if (position != string::npos) {
            message.at(i) = key.at(position);
        }
    }
    cout << "Encrypted message: " << message << endl;
    cout << "Decrypting message..." << endl;
    for (size_t i {}; i < message.length(); ++i) {
        size_t position = key.find(message.at(i));
        if (position != string::npos) {
            message.at(i) = alphabet.at(position);
        }
    }
    cout << "Decrypted message: " << message << endl;
    return 0;
}