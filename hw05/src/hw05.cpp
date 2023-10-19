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
            return 'a' <= c <= 'z' || 'A' <= c <= 'Z';
        };

        auto beginIt = str.begin();
        auto endIt = str.rbegin();
        bool flag = true;
        while(*beginIt <= *endIt)
        {
            while(!isChar(*beginIt)) beginIt++;
            while(!isChar(*endIt)) endIt--;

            if(toLower(*beginIt) != toLower(*endIt))
            {
                flag = false;
                break;
            }
            beginIt++;
            endIt--;
        }
        return flag;
    };

    VecOfStr output{};
    for(auto str: strings)
    {
        
        if(isAnagram(str))
        {
            std::cout << str <<'\n';
            output.push_back(str);
        }

    }

    return output;
}
