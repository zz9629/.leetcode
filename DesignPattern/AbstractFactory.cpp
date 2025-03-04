#include "iostream"
#include "vector"

using namespace std;

/*
input
3
modern
classical
modern

output
modern chair
modern sofa
classical chair
classical sofa
modern chair
modern sofa
*/

class AbstractChair
{
public:
    virtual void show() = 0;
};

class ModernChair : public AbstractChair
{
public:
    void show() override { cout << "modern chair" << endl; };
};

class ClassicalChair : public AbstractChair
{
public:
    void show() override { cout << "classical chair" << endl; };
};

class AbstractSofa
{
public:
    virtual void show() = 0;
};

class ModernSofa : public AbstractSofa
{
public:
    void show() override { cout << "modern sofa" << endl; };
};

class ClassicalSofa : public AbstractSofa
{
public:
    void show() override { cout << "classical sofa" << endl; };
};

class AbstractFactory
{
public:
    //virtual void produce() = 0;

    virtual AbstractChair* createChair() = 0;
    virtual AbstractSofa* createSofa() = 0;
};

class ModernFactory : public AbstractFactory
{ 
public:
    // void produce() override {
    //     AbstractChair* chair = new ModernChair();
    //     AbstractSofa* sofa = new ModernSofa();
    //     chair->show();
    //     sofa->show();
    // }
    AbstractChair* createChair() override
    {
        return new ModernChair();
    }

    AbstractSofa* createSofa() override
    {
        return new ModernSofa();
    }
};

class ClassicalFactory : public AbstractFactory
{ 
public:
    // void produce() override {
    //     AbstractChair* chair = new ClassicalChair();
    //     AbstractSofa* sofa = new ClassicalSofa();
    //     chair->show();
    //     sofa->show();
    // }
    AbstractChair* createChair() override
    {
        return new ClassicalChair();
    }

    AbstractSofa* createSofa() override
    {
        return new ClassicalSofa();
    }
};

// class System
// {
// public:
//     void produceModern()
//     {
//         auto factory = new ModernFactory();
//         factory->produce();
//     }
//     void produceClassical()
//     {
//         auto factory = new ClassicalFactory();
//         factory->produce();
//     }
// };

int main()
{
    int order;
    cin >> order;
    while (order--)
    {
        string style;
        cin >> style;

        AbstractFactory* factory = nullptr;
        if (style == "modern")
        {
            // system.produceModern();
            factory = new ModernFactory();
        }
        else 
        {
            // system.produceClassical();
            factory = new ClassicalFactory();
        }
        auto chair = factory->createChair();
        auto sofa = factory->createSofa();

        chair->show();
        sofa->show();

        delete chair;
        delete sofa;
        delete factory;
    }
    return 0;
}