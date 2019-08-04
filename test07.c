#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#define REG(classname)                                          \
struct __TempClassName_##classname {                            \
    __TempClassName_##classname(){                              \
        RegisterManager::RegisterMap.insert(new classname());   \
    }                                                           \
};                                                              \
__TempClassName_##classname classname##_reg_obj


int main()
{
    REG(MyClass);
    
    return 1;
}