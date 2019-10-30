#include <iostream>






std::string firstLetterEachWord(std::string string);


int main()
{
    std::string str = "     alp kaan     devran   jjjjj kkkk         1"; 
    std::cout << firstLetterEachWord(str); 
    return 0;


}



std::string firstLetterEachWord(std::string string)
{
    std::string result = "";
    bool v = true;


    for (int i = 0; i<string.length(); i++) {


        if (string[i] == ' ')
            v = true;
        
        else if (string[i] != ' ' && v == true){
            result.push_back(string[i]);
            v = false;
        }
        
    }


    return result;
}


