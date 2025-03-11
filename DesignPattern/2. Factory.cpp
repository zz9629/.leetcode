#include "iostream"
#include "string"
#include "vector"
using namespace std;

class Block
{
public:
    virtual void produce() const = 0;
};

class CircleBlock : public Block
{
public:
    void produce() const override { cout << "Circle Block" << endl; };
};

class SquareBlock : public Block
{
public:
    void produce() const override { cout << "Square Block" << endl; };
};

class BlockFactory
{
public:
    ~BlockFactory(){};
    virtual Block* createBlock() = 0;
};

class CircleBlockFactory : public BlockFactory
{
public:
    Block* createBlock() override {
        return new CircleBlock();
    };
};


class SquareBlockFactory : public BlockFactory
{
public:
    Block* createBlock() override {
        return new SquareBlock();
    };
};

class BlockFactorySystem {
private:
    vector<Block*> blocks;

public:
    // BlockFactorySystem(); //  !!!! 注意写{} 
    BlockFactorySystem(){};
    
    void produceBlocks(BlockFactory* factory, int quantity)
    {
        while (quantity--)
        {
            Block* product = factory->createBlock();
            blocks.push_back(product);
            product->produce();
        }
    }

    ~BlockFactorySystem(){
        for (Block* product: blocks)
        {
            delete product;
        }
    };
};

int main()
{
    // 创建积木工厂系统
    BlockFactorySystem factorySystem;
 
    // 读取生产次数
    int productionCount;
    std::cin >> productionCount;
 
    // 读取每次生产的积木类型和数量
    for (int i = 0; i < productionCount; i++) {
        std::string blockType;
        int quantity;
        std::cin >> blockType >> quantity;
 
        if (blockType == "Circle") {
            factorySystem.produceBlocks(new CircleBlockFactory(), quantity);
        } else if (blockType == "Square") {
            factorySystem.produceBlocks(new SquareBlockFactory(), quantity);
        }
    }
 
    return 0;
}