#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <windows.h>

#include <iostream>
#include <cctype>
#include <cstdio>
#include <windows.h>

bool isVowel(unsigned char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void processCharArray(char str[])
{
    int i = 0;
    std::cout << "Результат обработки строки как массива символов: ";

    while (str[i] != '\0')
    {
        if (str[i] == '.')
        {
            bool isVowelBefore = (i > 0) && isVowel(str[i - 1]);
            bool isConsonantAfter = (str[i + 1] != '\0') && isalpha(static_cast<unsigned char>(str[i + 1])) &&
                                    !isVowel(str[i + 1]);

            if (isVowelBefore && isConsonantAfter)
            {
                std::cout << "...";
            }
            else
            {
                std::cout << '.';
            }
        }
        else
        {
            std::cout << str[i];
        }
        i++;
    }
    std::cout << std::endl;
}

void processCString(char *str)
{
    std::cout << "Результат обработки Cи-строки: ";
    char previous = '\0';
    while (*str != '\0')
    {
        if (*str == '.')
        {
            bool isVowelBefore = (previous != '\0') && isVowel(previous);
            bool isConsonantAfter = (*(str + 1) != '\0') && isalpha(static_cast<unsigned char>(*(str + 1))) &&
                                    !isVowel(*(str + 1));

            if (isVowelBefore && isConsonantAfter)
            {
                std::cout << "...";
            }
            else
            {
                std::cout << '.';
            }
        }
        else
        {
            std::cout << *str;
        }
        previous = *str;
        ++str;
    }
    std::cout << std::endl;
}

void processFile()
{
    const char *inputFile = "input.txt";
    const char *outputFile = "output.txt";

    FILE *inFile;
    FILE *outFile;

    if (fopen_s(&inFile, inputFile, "r") != 0 || fopen_s(&outFile, outputFile, "w") != 0)
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        if (inFile)
            fclose(inFile);
        if (outFile)
            fclose(outFile);
        return;
    }

    char ch;
    char previous = '\0';

    std::cout << "Результат обработки файла: ";

    while ((ch = fgetc(inFile)) != EOF)
    {
        if (ch == '.')
        {
            bool isVowelBefore = (previous != '\0') && isVowel(previous);
            char next = fgetc(inFile);
            if (next != EOF)
            {
                bool isConsonantAfter = isalpha(static_cast<unsigned char>(next)) && !isVowel(next);

                if (isVowelBefore && isConsonantAfter)
                {
                    fputs("...", outFile);
                    std::cout << "...";
                }
                else
                {
                    fputc(ch, outFile);
                    std::cout << '.';
                }
                previous = next;

                if (next != '\0')
                {
                    ungetc(next, inFile);
                }
            }
        }
        else
        {
            fputc(ch, outFile);
            std::cout << ch;
            previous = ch;
        }
    }

    fclose(inFile);
    fclose(outFile);

    std::cout << std::endl
              << "Обработка файла завершена. Результат записан в " << outputFile << std::endl;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int choice;
    std::cout << "Выберите способ обработки строки:\n";
    std::cout << "1. Строка как массив символов\n";
    std::cout << "2. Строка как Cи-строка\n";
    std::cout << "3. Строка из файла\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1)
    {
        char str[256];
        std::cout << "Введите строку: ";
        std::cin.getline(str, 256);
        processCharArray(str);
    }
    else if (choice == 2)
    {
        char str[256];
        std::cout << "Введите строку: ";
        std::cin.getline(str, 256);
        processCString(str);
    }
    else if (choice == 3)
    {
        processFile();
    }
    else
    {
        std::cout << "Неверный выбор!" << std::endl;
    }

    return 0;
}
