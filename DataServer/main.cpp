#include <QtCore/QCoreApplication>
#include "DataServer.h"
#include <qdir.h>
#include "../FormulaPainter/InEdit.h"
#include <QtNetwork>
//#include <QSqlDatabase>

extern DataTask s_Task;
extern void MessageOutput( QtMsgType type, const QMessageLogContext &context, const QString &msg );
extern QFile s_LogFile;
//QSqlDatabase s_DB;

int main( int argc, char *argv[] )
  {
  QGuiApplication a(argc, argv);
//  s_DB.setDatabaseName( "production" );
//  s_DB.setUserName("root");
//  s_DB.setHostName( "localhost" );
//  s_DB.setPassword("Jozefa,Niedzw.");
//  if( !s_DB.open() ) a.exec();
//  return 0;
//  s_DB.close();
  if( QFileInfo( s_LogFile.fileName() ).size() > 500000 ) s_LogFile.resize( 0 );
  s_LogFile.open( QIODevice::Append );
//  qInstallMessageHandler( MessageOutput );
  qDebug() << "Start at: " << QDateTime::currentDateTime();
//  QGuiApplication a(argc, argv);
  DataServer Server;
  if( !Server.StartServer() ) return 1;
  QString ipAddress;
  QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
  // use the first non-localhost IPv4 address
  for (int i = 0; i < ipAddressesList.size(); ++i) {
      if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
          ipAddressesList.at(i).toIPv4Address()) {
          ipAddress = ipAddressesList.at(i).toString();
          break;
      }
  }
  // if we did not find one, use IPv4 localhost
  if (ipAddress.isEmpty())
      ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
  qDebug() << ipAddress << Server.serverPort();
  return a.exec();
  }
