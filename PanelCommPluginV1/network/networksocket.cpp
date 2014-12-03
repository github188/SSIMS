#include "networksocket.h"
#include <iostream>
#include "../SIMS_SERVER/logger/Logger.h"
using namespace QLogger;
using std::cout;
using std::endl;

NetworkSocket::NetworkSocket() : tcpSocket(new QTcpSocket())
{
    connect( tcpSocket, SIGNAL( connected() ), this, SIGNAL( connected() ) );
    connect( tcpSocket, SIGNAL( disconnected() ), this, SLOT( onDisconnected() ), Qt::QueuedConnection);
    connect( tcpSocket, SIGNAL( readyRead() ), this, SLOT( readData() ), Qt::QueuedConnection );
    buffer.clear();
}

bool NetworkSocket::setSocketDescriptor(qint32 socketdescriptor, QString &socketIP)
{
    if( !tcpSocket->setSocketDescriptor( socketdescriptor ) ) {
        //QLog_Error("Plugin", QString(Q_FUNC_INFO) + " " + tcpSocket->errorString());
        cout << "Set socket descriptor error: " << tcpSocket->errorString().toLocal8Bit().data() << endl;
        return false;
    }
    socketIP = tcpSocket->peerAddress().toString();
    return true;
}

NetworkSocket::~NetworkSocket()
{
    if( tcpSocket->state() == QTcpSocket::ConnectedState )
        tcpSocket->disconnectFromHost();
    tcpSocket->deleteLater();
}

void NetworkSocket::readData()
{
    forever {
        QDataStream in( tcpSocket );
        in.setVersion( QDataStream::Qt_5_0 );
        //! start of message <?xml
        QString mesStart = QStringLiteral("<?xml");
        //! end of message #
        QString mesEnd = QStringLiteral("#");
        //! read all available data to buffer
        buffer.append(tcpSocket->readAll());
        //! return if message length is too small
        if(buffer.length() < 7)
            return;
        //! check if the whole message come
        QString messageText = QString::fromUtf8(buffer);
        if(!messageText.contains(mesStart)) {
            buffer.clear();
            return;
        }
        if( messageText.contains(mesEnd)) {
            qint32 startIndex = messageText.indexOf(mesStart);
            qint32 endIndex = messageText.indexOf(mesEnd);
            QString xml = messageText.mid(startIndex,endIndex);
            emit newMessage(xml.toUtf8(), tcpSocket->peerAddress().toString());
            buffer.remove(0,messageText.mid(0,endIndex+1/*#*/).toUtf8().length());
            if(buffer.length() ==0)
                return;
        }
        else {
            return;//! wait for the whole message
        }
    }
}

void NetworkSocket::writeData(const QByteArray& data)
{
    QByteArray block;
    QDataStream out( &block, QIODevice::WriteOnly );
    out.setVersion( QDataStream::Qt_5_0 );
//    cout << " Sending xml message to site with ip:"
//         << tcpSocket->peerAddress().toString().toLocal8Bit().data() << endl;
    block.append( data );
    qint64 written = tcpSocket->write( block );
    //if(written != block.size())
        //cout << tr("written only %1 bytes of %2").arg(written).arg(block.size()).toLocal8Bit().data() << endl;
}

void NetworkSocket::onDisconnected()
{
    emit disconnected(tcpSocket->peerAddress().toString());
}
