#include <iostream>



sdfsdfsdfsdf
std::string firstLetterEachWord(std::string string);


int main()
{
    std::string str = "     alp kd5an     hehvdgdfgeheh deddvaran   jjjjj kk         1"; 
    std::cout << firstLetterEachWord(str); 

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


