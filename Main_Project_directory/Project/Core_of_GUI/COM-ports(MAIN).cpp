#include <QApplication>
#include <QDebug>

// === ЭТАП 1: Инициализация ===
#include "PortScanner.h"     // ✅ Сканер портов (нужен в начале)
#include "PortInfo.h"

// === ЭТАП 2: Активная работа ===
#include "SerialDriver.h"    // ✅ Устройство для чтения данных
#include "Converter.h"       // ✅ Ваш чистый C++ парсер

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // ========================================================================
    // ЭТАП 1: Сканирование портов (выполняется ОДИН РАЗ при старте)
    // ========================================================================
    
    PortScanner scanner;                          // Создаём сканер
    QList<PortInfo> ports = scanner.scanPorts();  // Сканируем систему
    
    if (ports.isEmpty()) {
        qDebug() << "COM-порты не найдены!";
        return 1;
    }
    
    // Выводим список пользователю (или заполняем ComboBox в GUI)
    qDebug() << "=== Доступные порты ===";
    for (const auto &port : ports) {
        qDebug() << port.portName << "-" << port.description;
    }
    
    // Пользователь выбирает порт (в реальном приложении — через интерфейс)
    QString selectedPort = ui->comboBoxPorts->currentText();  // Если храните просто имя
    
    // ========================================================================
    // ЭТАП 2: Подключение и работа с данными (выполняется ПОСЛЕ выбора)
    // ========================================================================
    
    SerialDevice* device = new SerialDevice();  // Создаём устройство
    Converter* converter = new Converter();     // Создаём ваш парсер
    
    // Настраиваем цепочку обработки данных
    QObject::connect(device, &SerialDevice::dataReceived, 
        [converter](const QByteArray &rawData) {
            
            // Конвертация типов: Qt → STL
            std::string hexString = rawData.toHex(' ').toUpper().toStdString();
            
            // Вызов ВАШЕГО парсера
            converter->setInput(hexString);
            std::string result = converter->translator();
            
            // Вывод результата
            qDebug() << "Parsed:" << QString::fromStdString(result);
            // Для GUI: ui->textEdit->append(QString::fromStdString(result));
        });
    
    // Подключаемся к выбранному порту
    device->connectToPort(selectedPort, 9600);
    
    qDebug() << "Подключено к" << selectedPort << ", ожидание данных...";

    return app.exec();  // Запускаем цикл событий
}

