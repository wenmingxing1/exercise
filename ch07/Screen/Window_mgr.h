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
    //清空指定屏幕的内容
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen(24,80,' '};
};

void Window_mgr::clear(ScreenIndex i){
    //s指向指定屏幕
    Screen &s = screens[i];
    //将制定屏幕内容清空
    s.contents = string(s.height * s.width, ' ');
}

#endif // WINDOW_MGR_H_INCLUDED
