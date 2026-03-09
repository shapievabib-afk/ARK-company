#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cstdint>
#include <limits>

class Converter {
private:
    std::string TOF_hex;

public:
    Converter(const std::string& recieved) : TOF_hex(recieved) {}

    std::string translator() {
        std::istringstream iss(TOF_hex);
        std::vector<uint32_t> bytes; 
        std::string hexByte;
        std::string result;
        
        while (iss >> hexByte) {
            try {
                size_t pos;
                int value = std::stoi(hexByte, &pos, 16);
                
                
                if (value > std::numeric_limits<uint32_t>::max()) {
                    return "Error: invalid byte '" + hexByte + "'";
                }
                
                bytes.push_back(static_cast<uint8_t>(value));
                if (!result.empty()) result += " ";
                result += std::to_string(value);
                
            } catch (...) {
                return "Error: parsing failed for '" + hexByte + "'";
            }
        }
        return result;
    }
};

int main() {
    std::string arr;
    std::getline(std::cin, arr);

    Converter A(arr);
    std::cout << "Data recieved" << std::endl;
    std::cout << A.translator() << std::endl;
}