#include <iostream>
#include <string>
#include <cryptopp/cryptlib.h>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/base64.h>
//debes tener instalado cripto ++ para que funcione
std::string EncryptPassword(const std::string& password, const std::string& encryptionKey)
{
    std::string encryptedPassword;

    try
    {
        CryptoPP::byte key[CryptoPP::AES::MAX_KEYLENGTH];
        CryptoPP::byte iv[CryptoPP::AES::BLOCKSIZE];

        memset(key, 0x00, CryptoPP::AES::MAX_KEYLENGTH);
        memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);

        CryptoPP::AES::Encryption aesEncryption((CryptoPP::byte*)encryptionKey.c_str(), CryptoPP::AES::DEFAULT_KEYLENGTH);
        CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);

        CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(encryptedPassword));
        stfEncryptor.Put(reinterpret_cast<const CryptoPP::byte*>(password.c_str()), password.length() + 1);
        stfEncryptor.MessageEnd();
    }
    catch (const CryptoPP::Exception& e)
    {
        std::cerr << "Error al encriptar la contraseña: " << e.what() << std::endl;
    }

    return encryptedPassword;
}

int main()
{
    std::string password = "mypassword123";
    std::string encryptionKey = "myencryptionkey";

    std::string encryptedPassword = EncryptPassword(password, encryptionKey);

    std::cout << "Contraseña original: " << password << std::endl;
    std::cout << "Contraseña encriptada: " << encryptedPassword << std::endl;

    return 0;
}
