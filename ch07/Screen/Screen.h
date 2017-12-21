#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include<iostream>
#include<string>
using namespace std;

class Screen
{
    friend class Window_mgr;    //������Ԫ��
    //friend void Window_mgr::clear(ScreenIndex); //Ҳ����ֻ�������еĳ�Ա����Ϊ��Ԫ����
public:
    using pos = string::size_type;  //���ڶ������ͱ�����Ҳ������typedef
    Screen() = default; //��Ϊ����������һ�����캯����������Ҫ����һ��Ĭ�Ϲ��캯��
    Screen(pos ht, pos wd):height(ht), width(wd), contents(ht*wd, ' ') {}
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c) {}

    //��ȡ���λ���ַ�����ָ��λ���ַ�
    char get() const {return contents[cursor];}     //��ʽinline
    inline char get(pos r, pos c) const;  //��ʽinline

    //�趨���λ���ַ�����ָ��λ���ַ�
    Screen& set(char);
    Screen& set(pos, pos, char);

    Screen& move(pos r, pos c);     //���ڶ���ʱ�趨Ϊinline

    //��ʾ�����������Ƿ�Ϊconst��ϵ���ú����Ƿ���const�汾
    Screen& display(ostream &os) {do_display(os); return *this;}    //�ǳ����汾
    const Screen& display(ostream &os) const {do_display(os); return *this;}    //�����汾
private:
    pos cursor = 0;     //���λ��
    pos height = 0, width = 0;
    string contents;    //��ʽ����

    //�������а汾��display
    void do_display(ostream &os ) const {os << contents;}
};

char Screen::get(pos r, pos c) const {
    pos row = r*width;  //�����е�λ��
    return contents[row+c]; //���ظ����е��ַ�
}

inline Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos col, char c) {
    contents[r*width+col] = c;
    return *this;
}

inline Screen& Screen::move(pos r, pos c){      //���ⶨ��ʱ����Ϊinline
    pos row = r*width;  //�����е�λ��
    cursor = row+c;     //�����ڽ�����ƶ���ָ������
    return *this;   //����ֵ����ʽ���ض���
}


#endif // SCREEN_H_INCLUDED
