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
#include <cryptopp/mars.h>
using namespace std;
using namespace CryptoPP;

class mars_al
{
private:
    string f_in;
    string f_out;
    string f_IV;
    string psw;
    string salt = "ljsnkdjsbdfkjshdkfjsbdjghsdiughdsuhsiughkjvbkjzcbvksdifgsdgfadls";
public:
    mars_al() = delete;
    mars_al(const string& f_in, const string& f_out, const string& pass);
    mars_al(const string& f_in, const string& f_out, const string& pass, const string & iv);
    void EncryptMars (mars_al open);
    void DecryptMars (mars_al cipher);
};