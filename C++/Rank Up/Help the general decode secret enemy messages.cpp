// Task: General Patron is faced with a problem, his intelligence has intercepted
// some secret messages from the enemy but they are all encrypted. Those
// messages are crucial to getting the jump on the enemy and winning the war.
// Luckily intelligence also captured an encoding device as well. However even the
// smartest programmers weren't able to crack it though. So the general is asking you,
// his most odd but brilliant programmer.
// You can call the encoder like this.

// std::cout << Encoder::encode("Hello World!");

// Our cryptoanalysts kept poking at it and found some interesting patterns.

// std::cout << (Encoder::encode ("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")) << "\n" ;
// std::cout << (Encoder::encode ("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")) << "\n" ;
// std::cout << (Encoder::encode ("!@#$%^&*()_+-")) << "\n" ;
// std::string a, b, c;
// for (const auto& w : std::string("abcdefghijklmnopqrstuvwxyz")) {
//     a += Encoder::encode (std::string(  "") + w)[0];
//     b += Encoder::encode (std::string( "_") + w)[1];
//     c += Encoder::encode (std::string("__") + w)[2];
// }
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << c << std::endl;

// We think if you keep on this trail you should be able to crack the code! You are expected to fill in the
// std::string Decoder::decode(const std::string&)
// function. Good luck ! General Patron is counting on you!

#include <iostream>
#include <string>

const std::string encryptionSet = "abdhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA1OoD70MkvRuPqH";

struct Encoder
{
    static std::string encode(std::string const &strToEncrypt)
    {
        std::string encryptedStr(strToEncrypt);
        for (size_t i{}; i < strToEncrypt.size(); i++)
        {
            size_t posOfSymbolInSet{encryptionSet.find(strToEncrypt.at(i))},
                posOfEncryptedSymbol{posOfSymbolInSet + i + 1};

            if (posOfSymbolInSet != std::string::npos)
            {
                while (posOfEncryptedSymbol >= encryptionSet.size())
                    posOfEncryptedSymbol -= encryptionSet.size();
                encryptedStr.at(i) = encryptionSet.at(posOfEncryptedSymbol);
            }
        }
        return encryptedStr;
    }
};

struct Decoder
{
    static std::string decode(const std::string &encryptedStr)
    {
        std::string decryptedStr(encryptedStr);
        for (size_t i{}; i < encryptedStr.size(); i++)
        {
            size_t posOfSymbolInSet{encryptionSet.find(decryptedStr.at(i))},
                posOfDecryptedSymbol{posOfSymbolInSet - i - 1};

            if (posOfSymbolInSet != std::string::npos)
            {
                while (posOfDecryptedSymbol >= encryptionSet.size())
                    posOfDecryptedSymbol += encryptionSet.size();

                decryptedStr.at(i) = encryptionSet.at(posOfDecryptedSymbol);
            }
        }

        return decryptedStr;
    }
};

int main()
{
    std::cout << "Encrypting..." << std::endl;
    std::cout << Encoder::encode("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << std::endl;
    std::cout << Encoder::encode("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb") << std::endl;
    std::cout << Encoder::encode("!@#$%^&*()_+-") << std::endl;
    std::cout << Encoder::encode("hafegcg") << std::endl;
    std::cout << Encoder::encode("Hello World!") << std::endl
              << std::endl;

    std::cout << "Decrypting..." << std::endl;

    std::cout << Decoder::decode("bdhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA1OoD70MkvRuPqHabdhpF,82QsLir") << std::endl;
    std::cout << Decoder::decode("dhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA1OoD70MkvRuPqHabdhp") << std::endl;
    std::cout << Decoder::decode("!@#$%^&*()_+-") << std::endl;
    std::cout << Decoder::decode("pdVmw5y") << std::endl;
    std::cout << Decoder::decode("atC5kcOuKAr!") << std::endl;

    return EXIT_SUCCESS;
}
