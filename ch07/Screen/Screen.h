#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include<iostream>
#include<string>
using namespace std;

class Screen
{
    friend class Window_mgr;    //声明友元类
    //friend void Window_mgr::clear(ScreenIndex); //也可以只声明类中的成员函数为友元函数
public:
    using pos = string::size_type;  //类内定义类型别名，也可以用typedef
    Screen() = default; //因为类有了下面一个构造函数，所以需要声明一个默认构造函数
    Screen(pos ht, pos wd):height(ht), width(wd), contents(ht*wd, ' ') {}
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c) {}

    //获取光标位置字符，或指定位置字符
    char get() const {return contents[cursor];}     //隐式inline
    inline char get(pos r, pos c) const;  //显式inline

    //设定光标位置字符，或指定位置字符
    Screen& set(char);
    Screen& set(pos, pos, char);

    Screen& move(pos r, pos c);     //能在定义时设定为inline

    //显示函数，对象是否为const关系调用函数是否是const版本
    Screen& display(ostream &os) {do_display(os); return *this;}    //非常量版本
    const Screen& display(ostream &os) const {do_display(os); return *this;}    //常量版本
private:
    pos cursor = 0;     //光标位置
    pos height = 0, width = 0;
    string contents;    //显式内容

    //用于所有版本的display
    void do_display(ostream &os ) const {os << contents;}
};

char Screen::get(pos r, pos c) const {
    pos row = r*width;  //计算行的位置
    return contents[row+c]; //返回给定列的字符
}

inline Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos col, char c) {
    contents[r*width+col] = c;
    return *this;
}

inline Screen& Screen::move(pos r, pos c){      //类外定义时声明为inline
    pos row = r*width;  //计算行的位置
    cursor = row+c;     //在行内将光标移动到指定的列
    return *this;   //以左值的形式返回对象
}


#endif // SCREEN_H_INCLUDED
