
/* C++ 基本位操作
在数据结构和算法设计中，经常会有一些枚举变量因为数量比较有限，如果直接使用C++语言基本类型 char, short,int 等会造成数据结构空间的浪费，为了充分利用内存空间，我们会采用bit字段设计和编程，比如有如下三个变量：
Direction //  取值只有0或者1
Offset // 取值只可能是 0，1,2,3 四个数字 
Instrument //取值范围为 0~1000000 的正整数

我们使用一个 4bytes 的 unsigned int 存储上述三个值：
其中 Direction 占用最低位的 1bit，
Offset 占用 Direction 旁边的 2bits，
剩余的 29bits 用来存储Instrument，
请根据该思路完善下面程序的三个 set API。

input
0
1
1
1

output
0
1
3
11

*/

/*
位运算的核心

    读取某个位：右移 + 掩码

    清除某个位：按位取反 + 按位与

    设置某个位：左移 + 按位或

按位存储多个值可以节省空间，并提高访问效率 
*/

#include <iostream>
#define DIRECTION_BITS_OFFSET 0x0
#define OFFSET_BITS_OFFSET 0x1
#define INSTRUMENT_BITS_OFFSET 0x3

#define DIRECTION_BITS_MASK 0x1 // 0b1, 一个bit
#define OFFSET_BITS_MASK 0x3 // 0b11, 两个bit
#define INSTRUMENT_BITS_MASK 0x1FFFFFFF // 29个bit

int get_Direction (int& value) {
    return (value >> DIRECTION_BITS_OFFSET) & DIRECTION_BITS_MASK;
}


int get_Offset (int& value) {
    return (value >> OFFSET_BITS_OFFSET) & OFFSET_BITS_MASK;
}

int get_Instrument (int& value) {
    return (value >> INSTRUMENT_BITS_OFFSET) & INSTRUMENT_BITS_MASK;
}
/* new_direction 为0或者 1 合法输入则设置 value 对应 bit 并返回0， 否则返回-1*/
int set_Direction (int& value, int new_direction) {
    if (new_direction == 0 || new_direction == 1)
    {
        value &= ~(DIRECTION_BITS_MASK << DIRECTION_BITS_OFFSET); // 清除原有bit
        value |= (new_direction << DIRECTION_BITS_OFFSET); // 设置新值
        return 0;
    }
    return -1;
}

/* new_offset 为 0-3 合法输入则设置 value 对应 bit 并返回 0，否则返回-1*/
int set_Offset(int& value, int new_offset) {
    if (new_offset >= 0 && new_offset <= 3)
    {
        value &= ~(OFFSET_BITS_MASK << OFFSET_BITS_OFFSET); // 清除原有bit
        value |= (new_offset << OFFSET_BITS_OFFSET); // 设置新值
    }
    return -1;
}

/* new Linstrument 为 0-1000000 合法输入则设置 value 对应 bit 并返回 0， 否则返回-1*/
int set_Instrument (int& value, int new_inst) {
    if (new_inst >= 0 && new_inst <= 1000000)
    {
        value &= ~(INSTRUMENT_BITS_MASK << INSTRUMENT_BITS_OFFSET); // 清除原有bit
        value |= (new_inst << INSTRUMENT_BITS_OFFSET); // 设置新值
    }
    return -1;
}
int main ()
{
    // int input_val, input_direction, input_offset, input_instrument; 
    int check_vall, check_val2, check_val3;
    int input_val = 11;
    int input_direction = 1; 
    int input_offset = 1; 
    int input_instrument = 1;
    // std::cin >>  input_val;
    // std::cin >>  input_direction; 
    // std:: cin >> input_offset; 
    // std:: cin >> input_instrument;
    check_vall = input_val;
    set_Direction (input_val, input_direction);
    check_val2 = input_val;
    set_Offset (input_val, input_offset);
    check_val3 = input_val;
    set_Instrument (input_val, input_instrument);

    std:: cout << check_vall << std::endl; 
    std:: cout << check_val2 << std:: endl; 
    std:: cout << check_val3 << std::endl; 
    std:: cout << input_val << std:: endl;

    return 0;
}