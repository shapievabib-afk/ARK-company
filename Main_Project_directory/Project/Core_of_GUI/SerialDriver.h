#ifndef SERIALDEVICE_H
#define SERIALDEVICE_H

#include <QObject>
#include <QSerialPort>
#include <QByteArray>

class SerialDevice : public QObject {
    Q_OBJECT
public:
    explicit SerialDevice(QObject *parent = nullptr) 
        : QObject(parent), port(new QSerialPort(this)) {
        
        connect(port, &QSerialPort::readyRead, this, &SerialDevice::onDataReceived);
    }

    bool connectToPort(const QString &portName, qint32 baudRate = 9600) {
        port->setPortName(portName);
        port->setBaudRate(baudRate);
        port->setDataBits(QSerialPort::Data8);
        port->setParity(QSerialPort::NoParity);
        port->setStopBits(QSerialPort::OneStop);
        port->setFlowControl(QSerialPort::NoFlowControl);

        if (port->open(QIODevice::ReadWrite)) {
            emit connectionStatusChanged(true, "Подключено к " + portName);
            return true;
        } else {
            emit connectionStatusChanged(false, "Ошибка: " + port->errorString());
            return false;
        }
    }

    void disconnectFromPort() {
        if (port->isOpen()) {
            port->close();
            emit connectionStatusChanged(false, "Отключено");
        }
    }

    bool sendData(const QByteArray &data) {
        if (port->isOpen()) {
            return port->write(data) >= 0;
        }
        return false;
    }

    bool isConnected() const {
        return port->isOpen();
    }

signals:
    void dataReceived(const QByteArray &data);
    void connectionStatusChanged(bool connected, const QString &message);

private slots:
    void onDataReceived() {
        QByteArray data = port->readAll();
        if (!data.isEmpty()) {
            emit dataReceived(data);
        }
    }

private:
    QSerialPort *port;
};

#endif // SERIALDEVICE_H
