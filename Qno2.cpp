#include <iostream>
#include <string>

class Product {
public:
    Product(long code = 0, const std::string& name = "Unnamed Product") : code(code), name(name) {}

    long getCode() const { return code; }
    void setCode(long newCode) { code = newCode; }

    virtual void scanner() {
        std::cout << "Scanning product..." << std::endl;
    }

    virtual void printer() {
        std::cout << "Product Code: " << code << ", Product Name: " << name << std::endl;
    }

protected:
    long code;
    std::string name;
};

class PrepackedFood : public Product {
public:
    PrepackedFood(long code = 0, const std::string& name = "Unnamed Prepacked Food", double unitPrice = 0.0)
            : Product(code, name), unitPrice(unitPrice) {}

    void setUnitPrice(double price) { unitPrice = price; }
    double getUnitPrice() const { return unitPrice; }

    void scanner() override {
        std::cout << "Scanning prepacked food..." << std::endl;
    }

    void printer() override {
        std::cout << "Product Code: " << getCode() << ", Product Name: " << name << ", Unit Price: $" << unitPrice << std::endl;
    }

private:
    double unitPrice;
};

class FreshFood : public Product {
public:
    FreshFood(long code = 0, const std::string& name = "Unnamed Fresh Food", double weight = 0.0, double pricePerKilo = 0.0)
            : Product(code, name), weight(weight), pricePerKilo(pricePerKilo) {}

    void setWeight(double newWeight) { weight = newWeight; }
    double getWeight() const { return weight; }

    void setPricePerKilo(double price) { pricePerKilo = price; }
    double getPricePerKilo() const { return pricePerKilo; }

    void scanner() override {
        std::cout << "Scanning fresh food..." << std::endl;
    }

    void printer() override {
        std::cout << "Product Code: " << getCode() << ", Product Name: " << name << ", Weight: " << weight << " kg, Price per Kilo: $" << pricePerKilo << std::endl;
    }

private:
    double weight;
    double pricePerKilo;
};

int main() {
    Product product1(12345, "Generic Product 1");
    Product product2;
    product2.setCode(54321);
    product2.printer();

    PrepackedFood prepacked1(111, "Prepacked Product 1", 5.0);
    PrepackedFood prepacked2;
    prepacked2.setCode(222);
    prepacked2.setUnitPrice(2.5);
    prepacked2.printer();

    FreshFood fresh1(333, "Fresh Product 1", 2.0, 3.0);
    FreshFood fresh2;
    fresh2.setCode(444);
    fresh2.setWeight(1.5);
    fresh2.setPricePerKilo(4.0);
    fresh2.printer();

    return 0;
}
