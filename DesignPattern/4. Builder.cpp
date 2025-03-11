#include "iostream"
#include "vector"

using namespace std;

class Bike
{
public:
    void setFrame(string frame) { this->frame = frame; };
    void setTires(string tires) { this->tires = tires; };
    string info()
    {
        return frame + " " + tires;
    }
private:
    string frame;
    string tires;
};


class BikeBuilder
{
public:
    virtual void buildFrame() = 0;
    virtual void buildTires() = 0;
    virtual Bike getResult() { return bike; };
    
protected:
    Bike bike;
};

class MontainBikeBuilder : public BikeBuilder
{
public:
    void buildFrame() override
    {
        bike.setFrame("Aluminum Frame");
    };
    void buildTires() override 
    {
        bike.setTires("Knobby Tires");
    };
};

class RoadBikeBuilder : public BikeBuilder
{
public:
    void buildFrame() override
    {
        bike.setFrame("Carbon Frame");
    };
    void buildTires() override 
    {
        bike.setTires("Slim Tires");
    };
};


class BikeDirector
{
public:
    Bike contrsuct(BikeBuilder& builder)
    {
        builder.buildFrame();
        builder.buildTires();
        return builder.getResult();
    }
};

int main()
{
    int num;
    cin >> num;
    BikeDirector director;
    while (num--)
    {
        string type;
        cin >> type;
        BikeBuilder* builder;
        if (type == "mountain")
        {
            builder = new MontainBikeBuilder();
        }
        else if (type == "road")
        {
            builder = new RoadBikeBuilder();
        }
        Bike product = director.contrsuct(*builder);
        cout << product.info() << endl; 

        delete builder;
    }

    return 0;
}