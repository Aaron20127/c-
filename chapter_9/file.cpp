#include <iostream>

extern const int finger = 1; //const 声明的外部变量必需使用extern才生效

namespace pers {
    void show_my_name(void)
    {
        std::cout << "liwei\n";
    }
}