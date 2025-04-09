#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Observer
{
public:
    virtual void update(int & number) = 0;
};

class Subject
{
public:
    virtual void addObserver(Observer * pObserver) = 0;

    virtual void deleteObserver(Observer * pObserver) = 0;
    
    virtual void notifyObservers() = 0;

    virtual ~Subject() = default;
};

class Clock : public Subject
{
public:
    void addObserver(Observer * pObserver) override
    {
        observers.push_back(pObserver);
    }

    void deleteObserver(Observer * pObserver) override
    {
        auto it = find(observers.begin(), observers.end(), pObserver);
        if (it != observers.end())
        {
            observers.erase(it);
        }
    }

    void notifyObservers() override
    {
        for (auto& item: observers)
        {
            item->update(number);
        }
    }

    void execute(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            number = i;
            notifyObservers();
        }
    }

    int getNumber()
    {
        return number;
    }

    ~Clock()
    {
        for (auto & item: observers)
        {
            delete item;
        }
    }

private:
    int number;
    vector<Observer* > observers;
};

class Student : public Observer
{
public:
    Student(string name) : name(name) {}

    void update(int & number) override {
        // auto clock = static_cast<Clock&>(subject);
        cout << name << " " << number << endl;
    }

private: 
    string name;
};

int main()
{
    Clock clock;
    // vector<Student*> students;
    int num;
    cin >> num;

    while (num--)
    {
        string name;
        cin >> name;
        auto pStudent = new Student(name); 
        // students.push_back(pStudent);
        clock.addObserver(pStudent);
    }

    int n;
    cin >> n;
    clock.execute(n);    

    return 0;
}


