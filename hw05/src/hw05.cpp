#include <hw05.h>
#include <iostream>

VecOfStr hw05(const VecOfStr& strings)
{
    auto isAnagram = [](std::string str)
    {
        auto toLower = [](char c)
        {
            if('A' <= c && c <= 'Z')
            {
                return c + 32;
            }
            return c + 0;
        };

        auto isChar = [](char c)
        {
            return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
        };

        int64_t frontInd = 0;
        int64_t backInd = str.length() - 1;
        while(frontInd <= backInd)
        {
            while(!isChar(str[frontInd])) frontInd++;
            while(!isChar(str[backInd])) backInd--;
            

            if(toLower(str[frontInd]) != toLower(str[backInd]))
            {
                return false;
            }
            frontInd++;
            backInd--;
        }
        return true;
    };

    VecOfStr output{};
    for(auto str: strings)
    {
        
        if(isAnagram(str))
        {
            //std::cout << str <<'\n';
            output.push_back(str);
        }

    }

    return output;
}
