#include "iostream"
using namespace std;

class Prototype
{
public:
    virtual Prototype* clone() const = 0;
    // virtual void printInfo() const = 0;
    ~Prototype(){}
};

class RectanglePrototype: public Prototype
{
public:
    RectanglePrototype(string color, int width, int height) : color(color), width(width), height(height)
    {
    }

    // 也可以RectanglePrototype*
    Prototype* clone() const override 
    {
        return new RectanglePrototype(*this);
        // return new RectanglePrototype(color, width, height);
        /*
        The copy constructor (RectanglePrototype(const RectanglePrototype& other)) automatically copies all attributes.
        [pro]This is more maintainable since e.g., adding more member variables do not require modifying the clone() method.
        [con]However, if your class has non-copyable resources (e.g., raw pointers, file handles), 
            then a deep copy implementation might be necessary. In such cases, you'd need a custom copy constructor or a manual deep copy inside clone().
        */
    }

    void printInfo() const
    {
        // Color: Red, Width: 10, Height: 5
        cout << "Color: " << color << ", Width: " << width << ", Height: " << height << endl;
    }

    string color;
    int width;
    int height;
};

int main()
{
    string color;
    int width, length;
    cin >> color >> width >> length;
    RectanglePrototype* original = new RectanglePrototype(color, width, length);
    
    int quantity;
    cin >> quantity;
    while (quantity--)
    {
        // static_cast<>()
        auto copy = static_cast<RectanglePrototype*>(original->clone());
        copy->printInfo();
        delete copy;
    }

    delete original;
    return 0;
}