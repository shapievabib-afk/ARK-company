#ifndef PORTINFO_H
#define PORTINFO_H

#include <QString>
#include <QSerialPortInfo>

class PortInfo {
public:
    QString portName;       // Например: "COM3"
    QString description;    // Например: "USB Serial Device"
    QString manufacturer;   // Производитель
    QString serialNumber;   // Серийный номер устройства
    quint16 vendorId;       // VID
    quint16 productId;      // PID

    // Конструктор из нативного класса Qt
    explicit PortInfo(const QSerialPortInfo &info)
        : portName(info.portName())
        , description(info.description())
        , manufacturer(info.manufacturer())
        , serialNumber(info.serialNumber())
        , vendorId(info.vendorIdentifier())
        , productId(info.productIdentifier())
    {}

    // Проверка соответствия VID/PID
    bool isDevice(quint16 vid, quint16 pid) const {
        // 0 означает, что информация недоступна
        if (vendorId == 0 || productId == 0) return false;
        return (vendorId == vid && productId == pid);
    }
    
    // Проверка по описанию (если VID/PID недоступны)
    bool containsDescription(const QString &text) const {
        return description.contains(text, Qt::CaseInsensitive);
    }
};

#endif // PORTINFO_H