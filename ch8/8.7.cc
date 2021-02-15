#include<fstream>
#include<string>
#include<iostream>

int main()
{
    std::ofstream ofs("./123.txt",std::ofstream::app);  //app模式，不会清除文件内容，从末尾开始追加
    ofs << "123";
    return 0;
}