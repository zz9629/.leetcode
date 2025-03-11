#include<memory>
#include<mutex>
#include<iostream>
#include<string>
#include<map>
#include <unordered_map>
#include "vector"

using namespace std;
// class Singleton
// {
// public:
//     static Singleton& getInstance()
//     {
//         std::call_once(initFlag, [&](){
//             // pInstance = std::make_unique<Singleton>();
//             pInstance.reset(new Singleton()); //
//         });
//         return *pInstance;
//     }

//     void buy(string name, int num)
//     {
//         shoppingList.push_back({name, num});
//     }

//     void print()
//     {
//         for (auto& item: shoppingList)
//         {
//             cout << item.first << " " << item.second << endl;
//         }
//     }

//     ~Singleton(){
//         cout << "destrutor" << endl; 
//     };
//     // ~Singleton(){};

// private:
//     Singleton(){
//         cout << "construtor" << endl;
//     };
//     // Singleton(){ };

//     Singleton(const Singleton & ) = delete;
//     Singleton operator=(const Singleton & ) = delete;

//     static std::unique_ptr<Singleton> pInstance;
//     static std::once_flag initFlag;
//     vector<pair<string, int> > shoppingList;
// };
// std::unique_ptr<Singleton> Singleton::pInstance = nullptr;
// std::once_flag Singleton::initFlag;

class SingletonStatic
{
public:
    static SingletonStatic& getInstance()
    {
        static SingletonStatic instance;
        return instance;
    }
    void buy(string name, int num)
    {
        shoppingList.push_back({name, num});
    }

    void print()
    {
        for (auto& item: shoppingList)
        {
            cout << item.first << " " << item.second << endl;
        }
    }
    ~SingletonStatic(){};

private:
    SingletonStatic(){};
    vector<pair<string, int> > shoppingList;
};

int main()
{
    auto cart = SingletonStatic::getInstance();
    // auto & cart = Singleton::getInstance();
    // cart.buy("a", 1);
    // cart.buy("b", 1);
    // cart.buy("c", 1);
    
    string name;
    int num;
    while (cin >> name >> num)
    {
        cart.buy(name, num);
    }

    cart.print();

    return 0;
}