#include "clnetsocket.h"
#include <iostream>
#include "logger/Logger.h"
using namespace QLogger;
using std::cout;
using std::endl;

ClientNetworkSocket::ClientNetworkSocket() : tcpSocket(new QTcpSocket()), blockSize(0)
{
    connect( tcpSocket, SIGNAL( connected() ), this, SIGNAL( connected() ) );
    connect( tcpSocket, SIGNAL( disconnected() ), this, SLOT( onDisconnected() ), Qt::QueuedConnection );
    connect( tcpSocket, SIGNAL( readyRead() ), this, SLOT( readData() ) );
}

bool ClientNetworkSocket::setSocketDescriptor(qint32 socketdescriptor, QString &socketIP)
{
    if( !tcpSocket->setSocketDescriptor( socketdescriptor ) ) {
        QLog_Error("Server", QString(Q_FUNC_INFO) + " " + tcpSocket->errorString());
        return false;
    }
    socketIP = tcpSocket->peerAddress().toString();
    return true;
}

ClientNetworkSocket::~ClientNetworkSocket()
{
    if( tcpSocket->state() == QTcpSocket::ConnectedState )
        tcpSocket->disconnectFromHost();
    delete tcpSocket;
}

void ClientNetworkSocket::readData()
{
    forever {
        QDataStream in(tcpSocket);
        in.setVersion(QDataStream::Qt_5_0);
        //! if this is the message start
        if(blockSize == 0) {
            //! if less than blocksize - return
            if(tcpSocket->bytesAvailable()<(qint64)sizeof(qint32))
                return;
            else {
                in>>blockSize;//! get the size of message
                cout << "new data block comes, size: " << blockSize << endl;
            }
        }
        //! if not the whole message come - return
        if(tcpSocket->bytesAvailable() < blockSize) {
            return;
        }
        else {
            QByteArray mes = tcpSocket->read(blockSize);
            emit newMessage(mes, tcpSocket->peerAddress().toString());
            blockSize = 0;
        }
    }
}

void ClientNetworkSocket::writeData(const QByteArray& data)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    out << (qint32)data.size();
    block.append(data);
    tcpSocket->write(block);
}

void ClientNetworkSocket::onDisconnected()
{
    emit disconnected(tcpSocket->peerAddress().toString());
}
