#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

struct People{

    string name;
    vector<string> photos;
};

int main()
{
    vector<People> peoples;
    ifstream ifs("./people.txt");
    ofstream ofs("./bad.txt", ofstream::app);
    if(ifs)
    {
        string line;
        while(getline(ifs,line))
        {
            string bad;
            istringstream iss(line);
            ostringstream oss(bad);
            if(iss)
            {
                string name,photo;
                People p;
                iss >> name;
                p.name = name;
                oss << name <<"  ";
                while(iss >> photo)
                {
                    p.photos.push_back(photo);
                    if(photo.size() == 3)
                    {
                        oss << photo << "  ";
                    }
                }
                oss << endl;
                ofs << oss.str();
                peoples.push_back(p);

            }
        }
    }

    for(const auto &p:peoples)
    {
        cout << p.name <<"  ";
        for(const auto &photo:p.photos)
        {
            cout << photo << "  ";
        }
        cout << endl;
    }

    return 0;
}

