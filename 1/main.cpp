#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using namespace CryptoPP;
int main ()
{
    SHA512 hash;
    cout <<"Name: " << hash.AlgorithmName() << endl;
    cout << "Diget size:" << hash.DigestSize() << endl;
    cout << "Block size:" << hash.BlockSize() << endl;
    fstream file;
    string path = "/home/user/Desktop/crypto.txt";
    string line_message, content;
    file.open(path);
    while(true) {
        getline(file,line_message);
        if (file.fail())
            break;
        content += line_message;
    }
    cout << "content: " << content << endl;
    vector<byte> digest (hash.DigestSize());
    hash.Update((const byte*)(content.data()),content.size());
    hash.Final(digest.data());
    cout << "Digest: ";
   StringSource(digest.data(),digest.size(),true, new  HexEncoder(new  FileSink(cout))); // выводим хэш в формате "hex"
    cout << endl;
    return 0;
}