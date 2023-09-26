#include <hw02.h>

bool contains(std::string, char, int);

std::string hw02(std::string input_str){
    int size = input_str.length();
    for(int i = 0; i < size; i++)
    {
        if(!contains(input_str, input_str[i], i)){
            input_str.push_back(input_str[i]);
        }
    }
    input_str.erase(0, size);
    return input_str;
}

bool contains(std::string str, char ch, int size){
    bool flag = false;
    for(int i = 0; i < size; i++){
        if(str[i] == ch){
            flag = true;
            break;
        }
    }
    return flag;
 }