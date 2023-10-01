#include <hw03.h>
#include <cstring>
#include <iostream>

bool areCorrectStrs(char* str, const char* pattern);

void hw03(char* str, const char* pattern)
{
    if(areCorrectStrs(str, pattern)){
        int strLen = std::strlen(str);
        int patternLen = std::strlen(pattern);

        int c, i;
        c = i = 0;

        //std::cout << strLen << ' ' << patternLen << '\n';

        while(i < strLen)
        {
            //std::cout << str << ' ' << pattern <<"\n";

            if(*(str + i) == *(pattern + c))
            {
                if(c == patternLen - 1)
                {
                    if(i != strLen - 1)
                    {
                        std::memmove(str + i - c, str + i + 1, strLen - i - 1);
                    }
                    else
                    {
                        std::memmove(str + i - c, str + i, strLen - i);
                    }
                    
                    *(str + strLen - patternLen) = 0;

                    //std::cout << str << '\n';
                    
                    break;
                }
                else
                {
                    c++;
                }
            }
            else
            {
                if(c != 0) i--;
                c = 0;
            }
            i++;
        }
    }
}

bool areCorrectStrs(char* str, const char* pattern)
{
    return std::strlen(str) != 0 && std::strlen(pattern) != 0;
}