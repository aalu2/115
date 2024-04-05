#include <iostream>
#include <string>

class Package {
public:
    Package(const std::string& senderName, const std::string& senderAddress, const std::string& senderCity, const std::string& senderState, const std::string& senderZip,
            const std::string& recipientName, const std::string& recipientAddress, const std::string& recipientCity, const std::string& recipientState, const std::string& recipientZip,
            double weight, double costPerOunce)
            : senderName(senderName), senderAddress(senderAddress), senderCity(senderCity), senderState(senderState), senderZip(senderZip),
              recipientName(recipientName), recipientAddress(recipientAddress), recipientCity(recipientCity), recipientState(recipientState), recipientZip(recipientZip),
              weight(weight > 0 ? weight : 0), costPerOunce(costPerOunce > 0 ? costPerOunce : 0) {}

    virtual double calculateCost() const {
        return weight * costPerOunce;
    }

protected:
    std::string senderName;
    std::string senderAddress;
    std::string senderCity;
    std::string senderState;
    std::string senderZip;
    std::string recipientName;
    std::string recipientAddress;
    std::string recipientCity;
    std::string recipientState;
    std::string recipientZip;
    double weight;
    double costPerOunce;
};

class TwoDayPackage : public Package {
public:
    TwoDayPackage(const std::string& senderName, const std::string& senderAddress, const std::string& senderCity, const std::string& senderState, const std::string& senderZip,
                  const std::string& recipientName, const std::string& recipientAddress, const std::string& recipientCity, const std::string& recipientState, const std::string& recipientZip,
                  double weight, double costPerOunce, double flatFee)
            : Package(senderName, senderAddress, senderCity, senderState, senderZip, recipientName, recipientAddress, recipientCity, recipientState, recipientZip, weight, costPerOunce),
              flatFee(flatFee > 0 ? flatFee : 0) {}

    double calculateCost() const override {
        return Package::calculateCost() + flatFee;
    }

private:
    double flatFee;
};

class OvernightPackage : public Package {
public:
    OvernightPackage(const std::string& senderName, const std::string& senderAddress, const std::string& senderCity, const std::string& senderState, const std::string& senderZip,
                     const std::string& recipientName, const std::string& recipientAddress, const std::string& recipientCity, const std::string& recipientState, const std::string& recipientZip,
                     double weight, double costPerOunce, double additionalFeePerOunce)
            : Package(senderName, senderAddress, senderCity, senderState, senderZip, recipientName, recipientAddress, recipientCity, recipientState, recipientZip, weight, costPerOunce),
              additionalFeePerOunce(additionalFeePerOunce > 0 ? additionalFeePerOunce : 0) {}

    double calculateCost() const override {
        return weight * (costPerOunce + additionalFeePerOunce);
    }

private:
    double additionalFeePerOunce;
};

int main() {
    Package regularPackage("John Doe", "123 Main St", "Anytown", "CA", "12345", "Jane Smith", "456 Elm St", "Othertown", "NY", "67890", 16.0, 0.5);
    TwoDayPackage twoDayPackage("John Doe", "123 Main St", "Anytown", "CA", "12345", "Jane Smith", "456 Elm St", "Othertown", "NY", "67890", 16.0, 0.5, 10.0);
    OvernightPackage overnightPackage("John Doe", "123 Main St", "Anytown", "CA", "12345", "Jane Smith", "456 Elm St", "Othertown", "NY", "67890", 16.0, 0.5, 1.0);

    std::cout << "Regular Package Cost: $" << regularPackage.calculateCost() << std::endl;
    std::cout << "Two-Day Package Cost: $" << twoDayPackage.calculateCost() << std::endl;
    std::cout << "Overnight Package Cost: $" << overnightPackage.calculateCost() << std::endl;

    return 0;
}

