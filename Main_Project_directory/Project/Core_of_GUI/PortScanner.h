#ifndef PORTSCANNER_H
#define PORTSCANNER_H

#include <QObject>
#include <QList>
#include <QSerialPortInfo>
#include "PortInfo.h"

class PortScanner : public QObject {
    Q_OBJECT
public:
    explicit PortScanner(QObject *parent = nullptr) : QObject(parent) {}

    // Сканирование системы и возврат списка портов
    QList<PortInfo> scanPorts() {
        QList<PortInfo> ports;
        const auto infos = QSerialPortInfo::availablePorts();
        
        for (const QSerialPortInfo &info : infos) {
            // Фильтруем пустые порты (иногда бывают "мусорные" записи в реестре)
            if (!info.portName().isEmpty()) {
                ports.append(PortInfo(info));
            }
        }
        return ports;
    }

    // Автопоиск устройства по VID/PID
    QString findPortByHardwareId(const QList<PortInfo> &ports, quint16 vid, quint16 pid) {
        for (const auto &port : ports) {
            if (port.isDevice(vid, pid)) {
                return port.portName;
            }
        }
        return QString();
    }
    
    // Автопоиск по строке в описании
    QString findPortByDescription(const QList<PortInfo> &ports, const QString &text) {
        for (const auto &port : ports) {
            if (port.containsDescription(text)) {
                return port.portName;
            }
        }
        return QString();
    }
};

#endif // PORTSCANNER_H