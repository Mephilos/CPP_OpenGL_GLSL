//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/16/25.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;


int main()
{
    //writing
    if(true)
    {
        
        ofstream ofs("myFile.dat");
        if(!ofs)
        {
            cerr<< "파일을 열 수 없습니다." << endl;
            exit(true);
        }
        const size_t num_data = 10;
        ofs.write((char*)&num_data, sizeof(num_data));
        
        for(int i = 0; i < num_data; ++i)
            ofs.write((char*)&i, sizeof(i));
        
//        ofs<< "Line 1 " << endl;
//        ofs<< "Line 2 " << endl;
    }
    //reading
    if(true)
    {
        ifstream ifs("myFile.dat" , ios::binary);
        if(!ifs)
        {
            cerr<<"파일을 열 수 없습니다." <<endl;
            exit(1);
        }
//        while (ifs)
//        {
//            std::string str;
//            getline(ifs, str);
//            
//            cout<< str << endl;
//        }
        size_t num_data = 0;
        ifs.read((char*)&num_data, sizeof(num_data));
        
        for(size_t i = 0; i < num_data; ++i)
        {
            int num;
            ifs.read((char*)&num, sizeof(num));
            
            cout<< num << endl;
        }
    }
        
        
    return 0;
}
