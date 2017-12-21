#ifndef WINDOW_MGR_H_INCLUDED
#define WINDOW_MGR_H_INCLUDED

#include<vector>
#include<string>
using namespace std;

class Window_mgr
{
public:
    //
    using ScreenIndex = vector<Screen>::size_type;
    //���ָ����Ļ������
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen(24,80,' '};
};

void Window_mgr::clear(ScreenIndex i){
    //sָ��ָ����Ļ
    Screen &s = screens[i];
    //���ƶ���Ļ�������
    s.contents = string(s.height * s.width, ' ');
}

#endif // WINDOW_MGR_H_INCLUDED
