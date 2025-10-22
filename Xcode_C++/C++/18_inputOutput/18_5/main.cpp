//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/14/25.
//

#include <iostream>
#include <regex>

using namespace std;


int main()
{
    regex re("\\d");
    //regex re("[[:digit:]]{3}");
    //regex re("[A-Z]+");
    //regex re("[A-Z]{3}");
    //regex re("[0-9]{1})([-]?)([0-9]{1,4})");
    
    string str;
    
    while (true)
    {
        getline(cin, str);
        if(std::regex_match(str, re))
            std::cout<< "Match" << std::endl;
        else
            std::cout<<"No Match" << std::endl;
        
        {
            auto begin = std::sregex_iterator(str.begin(), str.end(), re);
            auto end = std::sregex_iterator();
            for(auto itr =begin; itr !=end; ++itr)
            {
                std::smatch match = * itr;
                std::cout << match.str() << " ";
            }
            std::cout << std::endl;
        }
        cout<< endl;
    }
}
