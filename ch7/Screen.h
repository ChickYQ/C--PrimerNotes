#include<iostream>
#include<string>

class Screen{

public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos w, pos h):width(w),height(h),contents(w*h, ' '){}
    Screen(pos w, pos h, char c):width(w),height(h),contents(w*h, c){}

    char get(){return contents[cursor];}
    char get(pos r, pos c){return contents[r*width+c];}

    Screen &move(pos r, pos c){cursor = r * width + c; return *this;}
    Screen &set(char c){contents[cursor] = c; return *this;}
    Screen &set(pos r ,pos c, char ch){contents[r * width + c] = ch; return *this;}
    Screen &display(std::ostream &os){do_display(os); return *this;}
    const Screen &display(std::ostream &os) const {do_display(os);return *this;}


private:
    pos width = 0, height = 0;
    std::string contents;
    pos cursor = 0;
    void do_display(std::ostream &os) const {os << contents;}

};