#include "iostream"
#include "vector"
#include <unordered_map>

using namespace std;

class Prototype{
public:
    virtual Prototype* clone() = 0;
};

class Rectangle: public Prototype
{
public:
    Rectangle* clone() override
    {
        return new Rectangle(*this);
    }
};

int main()
{
   

    return 0;
}