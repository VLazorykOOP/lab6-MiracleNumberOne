#include <iostream>
using namespace std;

// Base class without virtual inheritance
class Animal {
protected:
    int age;
public:
    Animal(int a = 0) : age(a) {}
    void display() {
        cout << "Age: " << age << endl;
    }
};

// Derived class without virtual inheritance
class Dog : public Animal {
private:
    string breed;
public:
    Dog(int a = 0, string b = "") : Animal(a), breed(b) {}
    void display() {
        cout << "Age: " << age << endl;
        cout << "Breed: " << breed << endl;
    }
};

// Base class with virtual inheritance
class VirtualAnimal {
protected:
    int weight;
public:
    VirtualAnimal(int w = 0) : weight(w) {}
    virtual void display() {
        cout << "Weight: " << weight << endl;
    }
};

// Derived class with virtual inheritance
class VirtualDog : virtual public VirtualAnimal {
private:
    string name;
public:
    VirtualDog(int w = 0, string n = "") : VirtualAnimal(w), name(n) {}
    void display() {
        cout << "Weight: " << weight << endl;
        cout << "Name: " << name << endl;
    }
};

int main() {
    Animal a(5);
    Dog d(3, "Labrador");
    VirtualAnimal va(10);
    VirtualDog vd(20, "Rex");

    cout << "Size of Animal object: " << sizeof(a) << endl;
    cout << "Size of Dog object: " << sizeof(d) << endl;
    cout << "Size of VirtualAnimal object: " << sizeof(va) << endl;
    cout << "Size of VirtualDog object: " << sizeof(vd) << endl;

    return 0;
}