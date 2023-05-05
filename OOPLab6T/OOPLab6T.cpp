#include <iostream>
#include <string>
#include <cmath>
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



// Abstract class "Figure"
class Figure {
public:
    virtual double area() = 0; // Virtual area calculation function
};

// Derivative class "Rectangle"
class Rectangle : public Figure {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() {
        return width * height;
    }
};

// Derivative class "Circle"
class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() {
        return M_PI * radius * radius;
    }
};

// Derivative class "Right triangle"
class RightTriangle : public Figure {
private:
    double base;
    double height;
public:
    RightTriangle(double b, double h) : base(b), height(h) {}
    double area() {
        return base * height / 2.0;
    }
};

// Derivative class "Trapeze"
class Trapezoid : public Figure {
private:
    double base1;
    double base2;
    double height;
public:
    Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}
    double area() {
        return (base1 + base2) * height / 2.0;
    }
};



class Entity {
protected:
    std::string name;
public:
    Entity() {}
    Entity(const std::string& name) : name(name) {}
    virtual ~Entity() {}
    virtual void printInfo() const {
        std::cout << "Name: " << name << std::endl;
    }
};

class Student : public Entity {
protected:
    int id;
public:
    Student() {}
    Student(const std::string& name, int id) : Entity(name), id(id) {}
    void printInfo() const override {
        Entity::printInfo();
        std::cout << "ID: " << id << std::endl;
    }
};

class FamilyMember : public Entity {
protected:
    int age;
public:
    FamilyMember() {}
    FamilyMember(const std::string& name, int age) : Entity(name), age(age) {}
    void printInfo() const override {
        Entity::printInfo();
        std::cout << "Age: " << age << std::endl;
    }
};

class StudentFamilyMember : public Student, public FamilyMember {
public:
    StudentFamilyMember() {}
    StudentFamilyMember(const std::string& name, int id, int age)
        : Student(name, id), FamilyMember(name, age) {}
    void printInfo() const override {
        Student::printInfo();
        FamilyMember::printInfo();
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


    // Creation of objects of derived classes
    Rectangle r(5, 10);
    Circle c(4);
    RightTriangle t(3, 4);
    Trapezoid z(3, 6, 5);

    // Creating an array of pointers to the base class
    Figure* shapes[] = {&r, &c, &t, &z};

    // Derivation of the areas of each figure
    for (int i = 0; i < 4; i++) {
        cout << "Shape " << i + 1 << " area = " << shapes[i]->area() << endl;
    }


    Entity* entities[3];
    entities[0] = new Student("John Doe", 12345);
    entities[1] = new FamilyMember("Jane Doe", 40);
    entities[2] = new StudentFamilyMember("Alice Doe", 67890, 20);

    for (int i = 0; i < 3; i++) {
        entities[i]->printInfo();
        std::cout << std::endl;
    }

    for (int i = 0; i < 3; i++) {
        delete entities[i];
    }

    return 0;
}