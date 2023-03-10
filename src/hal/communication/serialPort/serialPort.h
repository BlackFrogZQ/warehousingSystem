#pragma once
#include "src/system/sigleClass.h"
#include "src/system/basic.h"
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>

class CSerialPort : public QObject
{
    Q_OBJECT

public:
    CSerialPort(QObject* p = nullptr);
    ~CSerialPort();

public slots:
    bool slotOpenPort(const QString &p_portName);
    void slotReceiveInfo();

signals:
    void sendReadSignal(const int &p_readType);

private:
    QSerialPort* m_serialPort;
};