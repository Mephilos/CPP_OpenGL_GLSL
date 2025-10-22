#include <string>
#include <cstddef>
#include <iostream>
#include <locale>
#include <cstring>

int main()
{
    // c-style string example
    {
        char *strHello = new char[7];
        strncpy(strHello, "hello!", sizeof(char) * 6);
        strHello[sizeof(char) * 6] = '\0';
        std::cout << strHello << std::endl;
    }

    // basic_string<>, string, wstring
    {
        std::string string;
        std::wstring wstring;

        wchar_t wc;
    }
    {
        const std::wstring texts[] =
        {
            L"Ñá", // Spanish

            L"forêt intérêt", // French

            L"Gesäß" , // German

            L"取消波蘇日奇諾" , // Chinesse

            L"日本人のビット" , // Japanese

            L"немного русский" ,// Russian

            L"ένα κομμάτι της ελληνικής", // Greek

            L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ" , // Punjabi

            L"کمی از ایران ", // Persian

            L"కానీ ఈ ఏమి నరకం ఉంది?" , // Telugu

            L"Но какво, по дяволите, е това?" , // Bulgarian
        };
        std::locale::global(std::locale(""));
        std::wcout.imbue(std::locale());

        for(size_t i =0; i < 10 ; ++i)
            std::wcout << texts[i] << std::endl;
    }
}
