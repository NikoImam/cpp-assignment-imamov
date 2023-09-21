#include <hw02.h>

bool contains(std::string, char);

std::string hw02(std::string input_str){
    std::string output_str{};

    for(int i = 0; i < input_str.length(); i++)
    {
        if(!contains(output_str, input_str[i])){
            output_str.push_back(input_str[i]);
        }
    }
    return output_str;
}

bool contains(std::string str, char ch){
    bool flag = false;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ch){
            flag = true;
            break;
        }
    }
    return flag;
 }