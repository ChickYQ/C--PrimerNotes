#include<fstream>
#include<iostream>
#include<string>
#include<vector>

void read_to_vector(const std::string& filename, std::vector<std::string> &v1)
{
    std::ifstream ifs(filename);
    if(ifs)
    {
        std::string buf;
        while(getline(ifs,buf))
        {
            v1.push_back(buf);
        }
    }
}

void read_word_to_vector(const std::string& filename, std::vector<std::string> &v1)
{
    std::ifstream ifs(filename);
    if(ifs)
    {
        std::string buf;
        while(ifs >> buf)
        {
            v1.push_back(buf);
        }
    }
}

int main()
{
    std::vector<std::string> v1,v2;
    std::string filename("./123.txt");
    read_to_vector(filename,v1);
    read_word_to_vector(filename,v2);

    for(auto &v : v1)
    {
        std::cout << v <<std::endl;
    }
    std::cout << std::endl << std::endl;
     for(auto &v : v2)
    {
        std::cout << v <<std::endl;
    }

}