#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;
//########################################################
//########################################################

//(1)插件基类：

 class BasePlugin
{
    public:
        virtual bool Run()=0;
};
//(2)映射关系--全局域函数
//这里采用函数，而不是直接在全局域定义静态变量是为了解决全局变量相互依赖的问题，
//（如全局对象A依赖于全局对象B，而B晚于A被构造出来）。
std::map<std::string,BasePlugin*>& GetPlugin()
{
    //局部静态对象，只有在使用到时才会被构造出来，由于是在全局对象构造中被调用到，所以不存在多线程问题，
    //因为这发生在main函数之前，其它线程还没有创建出来
    static std::map<std::string,BasePlugin*> mapPlugin;
    return mapPlugin;
}
//(3)注册类
//当构造该类的对象时，插入<name,BasePlugin*>到mapPlugin中，自动完成注册
//register.h
#define REGISTER_PLUGIN(name) \
    class name##Register \
    { \
        public:  \
            name##Register() \
            { \
                GetPlugin().insert(std::make_pair(#name, new (std::nothrow) name)); \
            } \
    }; \
    name##Register name##reg;   //调用构造函数
//(4)具体插件类
//1)myplugin.h
class MyPlugin: public BasePlugin{
    public:
    MyPlugin() {};
    ~MyPlugin(){};
    bool Run();
};
//2)myplugin.cpp(必须在cpp中调用上面定义的宏，原因待解)
//#include "register.h"
#include <map>

//<"MyPlugin", new MyPlugin>被插入到mapPlugin中


bool MyPlugin::Run()
{
   cout <<"run MyPlugin here\n";
   return 1;
}

//########################################################
//########################################################

REGISTER_PLUGIN(MyPlugin);

int main()
{
    GetPlugin()["MyPlugin"]->Run();
    return 1;
}