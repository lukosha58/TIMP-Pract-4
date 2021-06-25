#include "mars.h"
mars_al::mars_al(const string& f_in, const string& f_out, const string& pass)
{
    this->f_in = f_in;
    this->f_out = f_out;
    this->psw = pass;
}
mars_al::mars_al(const string& f_in, const string& f_out, const string& pass, const string & iv)
{
    this->f_in = f_in;
    this->f_out = f_out;
    this->psw = pass;
    this->f_IV = iv;
}
void mars_al::EncryptMars (mars_al open)
{
    SecByteBlock key(MARS::DEFAULT_KEYLENGTH);
    PKCS12_PBKDF<SHA384> pbkdf;
    pbkdf.DeriveKey(key.data(), key.size(), 0, (byte*)open.psw.data(), open.psw.size(), (byte*)salt.data(), salt.size(), 1024, 0.0f);


    AutoSeededRandomPool prng;
    byte iv[MARS::BLOCKSIZE];
    prng.GenerateBlock(iv, sizeof(iv));


    ofstream v_IV(string(open.f_out + ".iv").c_str(), ios::out | ios::binary);
    v_IV.write((char*)iv, MARS::BLOCKSIZE);
    v_IV.close();
    cout << "Файл c вектором инициализации создан.\nЕго расположение: " << open.f_out << ".iv" << endl;


    CBC_Mode<MARS>::Encryption encr;
    encr.SetKeyWithIV(key, key.size(), iv);
    FileSource fs(open.f_in.c_str(), true, new StreamTransformationFilter(encr, new FileSink(open.f_out.c_str())));
    cout << "Было проведено шифрование.\nРезультат в файле, его расположение следущее:\n" << open.f_out << endl;
}

void mars_al::DecryptMars (mars_al cipher)
{
    SecByteBlock key(MARS::DEFAULT_KEYLENGTH);
    PKCS12_PBKDF<SHA384> pbkdf;
    pbkdf.DeriveKey(key.data(), key.size(), 0, (byte*)cipher.psw.data(), cipher.psw.size(), (byte*)salt.data(), salt.size(), 1024, 0.0f);

    byte iv[MARS::BLOCKSIZE];

    ifstream IV(cipher.f_IV.c_str(), ios::in | ios::binary);
    IV.read((char*)(&iv), MARS::BLOCKSIZE);

    CBC_Mode<MARS>::Decryption decr;
    decr.SetKeyWithIV(key, key.size(), iv);
    FileSource fs(cipher.f_in.c_str(), true, new StreamTransformationFilter(decr, new FileSink(cipher.f_out.c_str())));
    cout << "Проведено шифрование.\nРезультат в файле. Его расположение:\n" << cipher.f_out << endl;
}