#include <iostream>
using namespace std;

class Employer {
public:
    virtual void Print() const = 0;  
    virtual ~Employer() {}  
};

class President : public Employer {
private:
    const char* name;
public:
    President(const char* name) : name(name) {}
    void Print() const override {
        cout << "President: " << name << endl;
    }
};

class Manager : public Employer {
private:
    const char* department;
public:
    Manager(const char* department) : department(department) {}
    void Print() const override {
        cout << "Manager of department: " << department << endl;
    }
};

class Worker : public Employer {
private:
    const char* position;
public:
    Worker(const char* position) : position(position) {}
    void Print() const override {
        cout << "Worker with position: " << position << endl;
    }
};

int main() {
    Employer* employees[] = {
        new President("John Doe"),
        new Manager("Sales"),
        new Worker("Technician")
    };

    for (int i = 0; i < 3; ++i) {
        employees[i]->Print();
        delete employees[i];
    }

    return 0;
}
