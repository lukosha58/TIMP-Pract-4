#pragma once
#include <cryptopp/cryptlib.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/filters.h>
#include <cryptopp/osrng.h>
#include "cryptopp/modes.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cryptopp/gost.h>
using namespace std;
using namespace CryptoPP;

class gost_al
{
private:
    string f_in;
    string f_out;
    string f_IV;
    string psw;
    string salt = "ljsnkdjsbdfkjshdkfjsbdjghsdiughdsuhsiughkjvbkjzcbvksdifgsdgfadls";
public:
    gost_al() = delete;
    gost_al(const string& f_in, const string& f_out, const string& pass);
    gost_al(const string& f_in, const string& f_out, const string& pass, const string & iv);
    void EncryptGost (gost_al open);
    void DecryptGost (gost_al cipher);
};