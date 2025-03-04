
#include "iostream"
#include "memory"
#include "mutex"

using namespace std;

// Lazy Singleton（懒汉）版本：
class LazySingleton
{
public:
    LazySingleton(const LazySingleton&) = delete;               // 禁止拷贝构造
    LazySingleton& operator=(const LazySingleton&) = delete;    // 禁止赋值

    static LazySingleton* getInstance()
    {
        if (pInstance == nullptr) 
        {
            pInstance = new LazySingleton();
        }
        return pInstance;
    }

    void print()
    {
        cout << "hello" << endl;
    }

private:
    LazySingleton(){};
    static LazySingleton* pInstance;
};
//定义并初始化 Singleton 类的 静态成员变量 pInstance，其作用是确保 单例对象的唯一性。
LazySingleton* LazySingleton::pInstance = nullptr;

/*
// 使用智能指针避免内存泄漏问题
class LazySingletonUnique
{
public:
    static LazySingletonUnique * getInstance()
    {
        if (!pInstance)
        {
            pInstance = std::unique_ptr<LazySingletonUnique>(new LazySingletonUnique());
            // pInstance = std::make_unique<LazySingletonUnique>(); // 更加安全        
        }

        return pInstance.get();
    }

    void print() { cout << "hello, unique!" << endl;}

    LazySingletonUnique(){cout << "unique constructor !" << endl;};
    ~LazySingletonUnique(){cout << "unique destructor !" << endl;};

private:
    static unique_ptr<LazySingletonUnique> pInstance;   // 私有静态成员
};
// 在类内声明，但不需要手动在类外初始化
std::unique_ptr<LazySingletonUnique> LazySingletonUnique::pInstance = nullptr;

// 使用锁确保线程安全
#include <mutex>
class SingletonMutex
{
public:
    static SingletonMutex* getInstance()
    {
        if (pInstance == nullptr)  // 第一次检查（避免不必要加锁）
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (pInstance == nullptr)  // 第二次检查（确保线程安全）
            {
                pInstance = new SingletonMutex();
            }
        }
        return pInstance;
    }

private:
    SingletonMutex() {}
    static SingletonMutex* pInstance;
    static std::mutex mtx;
};

SingletonMutex* SingletonMutex::pInstance = nullptr;
std::mutex SingletonMutex::mtx;
*/

// 使用static确保线程安全
class SingletonStatic
{
public:
    static SingletonStatic& getInstance()
    {
        static SingletonStatic instance;
        return instance;
    }
    void print() { cout << "hello, static!" << endl;}

private:
    SingletonStatic(){};
};

// unique_ptr + std::call_once
class SingletonBest
{
public:
    // 获取单例实例（线程安全）
    static SingletonBest* getInstance()
    {
        std::call_once(initFlag, []() {
            pInstance = std::make_unique<SingletonBest>();
        });
        return pInstance.get();
    }
    void print()
    {
        std::cout << "Hello, Thread-Safe Singleton!" << std::endl;
    }
    ~SingletonBest() { std::cout << "Singleton Destructor" << std::endl; }
    SingletonBest() { std::cout << "Singleton Constructor" << std::endl; }

private:
    SingletonBest(const SingletonBest&) = delete;
    SingletonBest& operator=(const SingletonBest&) = delete;

    // 使用智能指针管理实例
    static std::unique_ptr<SingletonBest> pInstance;
    static std::once_flag initFlag; // 保证初始化只执行一次
};
// 初始化静态成员 **Static members must be defined outside the class**
std::unique_ptr<SingletonBest> SingletonBest::pInstance = nullptr;
std::once_flag SingletonBest::initFlag;

int main()
{
    LazySingleton* pInstance = LazySingleton::getInstance();
    pInstance->print();
    delete pInstance;

    // auto test = LazySingletonUnique::getInstance();
    // test->print();
    
    auto staticSingleton = SingletonStatic::getInstance();
    staticSingleton.print();

    auto best = SingletonBest::getInstance();
    best->print();

    return 0;
}