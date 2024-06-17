#include <iostream>
using namespace std;
class Car {
    char* model;
    int year;
    double price;
public:
    Car() : model(nullptr), year(0), price(0.0) {}

    Car(const char* mod) {
        model = new char[strlen(mod) + 1];
        strcpy(model, mod);
    }

    Car(const char* mod, int y, double pr) : Car(mod) {
        year = y;
        price = pr;
    }

    Car(const Car& obj) = delete;
    Car& operator=(const Car& obj) = delete;

    Car(Car&& b) {
        cout << "Constructor" << endl;
        model = b.model;
        year = b.year;
        price = b.price;
        b.model = 0;
    }

    Car& operator=(Car&& b) {
        cout << "Move" << endl;;
        if (this != &b) {
            delete[] model;
            model = b.model;
            year = b.year;
            price = b.price;
            b.model = 0;
        }
        return *this;
    }

    ~Car() {
        delete[] model;
    }

    const char* getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    double getPrice() const {
        return price;
    }

    void setModel(const char* mod) {
        delete[] model;
        model = new char[strlen(mod) + 1];
        strcpy(model, mod);
    }

    void setYear(int y) {
        year = y;
    }

    void setPrice(double pr) {
        price = pr;
    }

    void print(ostream& os) const {
        os << model << "\t" << year << "\t" << price << endl;
    }

    void read(istream& is) {
        char buff[100];
        cout << "Enter model -> ";
        is >> buff;
        setModel(buff);
        cout << "Enter year -> ";
        is >> year;
        cout << "Enter price -> ";
        is >> price;
    }
};

ostream& operator<<(ostream& os, const Car& obj) {
    obj.print(os);
    return os;
}

istream& operator>>(istream& is, Car& obj) {
    obj.read(is);
    return is;
}

Car By_value() {
    Car obj("By value\n");
    return obj;
}

void By_val2(Car obj) {
    cout << "test\n";
}

int main() {
    Car obj1("Porshe", 2022, 50000);
    cout << obj1 << endl;

    cin >> obj1;
    cout << obj1;

    Car a{ "Porshe" };

    Car b = move(a);

    return 0;
}