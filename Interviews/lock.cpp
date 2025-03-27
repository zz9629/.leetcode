#include <iostream>
#include <mutex>

/*
std::recursive_mutex 是 C++11 引入的一种 可重入的互斥锁（recursive mutex），允许 同一线程 在已持有锁的情况下 再次加锁，但必须 解锁相同次数。
*/

struct MyGuard {
    // std::recursive_mutex 允许同一线程多次锁定，所以 MyGuard 可以在 f2() 内部锁定 m，然后 f1() 再次锁定 m，不会造成死锁。
    std::recursive_mutex& l;  // 正确定义成员变量

    MyGuard(std::recursive_mutex& lock) : l(lock) {
        l.lock();
        std::cout << "lock" << std::endl;
    }

    ~MyGuard() {
        l.unlock();
        std::cout << "unlock" << std::endl;
    }
};

void f1(std::recursive_mutex& l) {
    MyGuard guard(l);  // 这里创建 MyGuard 实例
    std::cout << "f1 run" << std::endl;
} // 这里 f1 结束，局部变量 guard 作用域结束，触发析构

void f2(std::recursive_mutex& l) {
    MyGuard guard(l);
    f1(l);
    std::cout << "f2 run" << std::endl;
}

int main() {
    std::recursive_mutex m;
    f2(m);
    return 0;
}

/*
代码执行顺序

f2(m) 调用 MyGuard guard(l);

lock → 输出：lock

f1(l) 在 f2() 内部调用

lock → 输出：lock

f1 运行 → 输出：f1 run

MyGuard 析构 (f1() 返回) → 输出：unlock

f2 继续运行 → 输出：f2 run

MyGuard 析构 (f2() 返回) → 输出：unlock

最终输出：
lock
lock
f1 run
unlock
f2 run
unlock

*/