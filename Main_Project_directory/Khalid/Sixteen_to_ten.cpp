#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cstdint>

class Converter
{
private:
std::string TOF_hex;
std::vector<uint8_t> bytes;
std::istringstream iss;

public:
    Converter(std::string recieved) //надо будет сделать функцию, которая
                                    //будет читать данные как строку
                                    //и передавать в класс
    {
        TOF_hex = recieved;
    }

    std::string translator()
    {
        iss.str(TOF_hex);
    iss.clear();
    
    std::string hexByte;  // ← новая переменная для чтения
    std::string result;   // ← строка для результата
    
    while (iss >> hexByte)  // ← читаем во временную переменную
    {
        uint8_t byte = static_cast<uint8_t>(std::stoi(hexByte, nullptr, 16));
        bytes.push_back(byte);
        result += std::to_string(byte) + " ";  // добавляем в результат
    }
    
    return result;
    }

};

int main()
{
    std::string arr = "A1 B2 C3 D4 E5 F6 07 18 29 3A 4B 5C 6D 7E 8F 90";

    Converter A(arr);
    std::cout<<"Data recieved"<<std::endl;
    std::cout<<A.translator()<<std::endl;

}