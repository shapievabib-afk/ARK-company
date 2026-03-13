#include <QApplication>
#include <QDebug>
#include "PortScanner.h"
#include "PortInfo.h"
#include "SerialDriver.h"
#include "Converter.h"       

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    PortScanner scanner;                          // Создаём сканер
    QList<PortInfo> ports = scanner.scanPorts();  // Сканируем систему
    
    if (ports.isEmpty()) {
        qDebug() << "COM-порты не найдены!";
        return 1;
    }
    
    qDebug() << "=== Доступные порты ===";
    for (const auto &port : ports) {
        qDebug() << port.portName << "-" << port.description;
    }
    

    QString selectedPort = ui->comboBoxPorts->currentText();
    
    SerialDevice* device = new SerialDevice();
    Converter* converter = new Converter();
    
    QObject::connect(device, &SerialDevice::dataReceived, 
        [converter](const QByteArray &rawData) {
            
            std::string hexString = rawData.toHex(' ').toUpper().toStdString();
            
            converter->setInput(hexString);
            std::string result = converter->translator();
            
            qDebug() << "Parsed:" << QString::fromStdString(result);
        });
        
    device->connectToPort(selectedPort, 9600);
    
    qDebug() << "Подключено к" << selectedPort << ", ожидание данных...";

    return app.exec();
}

