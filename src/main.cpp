/*
    This file is part of etherwall.
    etherwall is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    etherwall is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with etherwall. If not, see <http://www.gnu.org/licenses/>.
*/
/** @file main.cpp
 * @author Ales Katona <almindor@gmail.com>
 * @date 2015
 *
 * Main entry point
 */

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "settings.h"
#include "accountmodel.h"
#include "transactionmodel.h"

using namespace Etherwall;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName("NetherBoyz");
    QCoreApplication::setOrganizationDomain("etherwall.com");
    QCoreApplication::setApplicationName("Etherwall");

    Settings settings;
    EtherIPC ipc;

    const QString ipcPath = settings.value("ipc/path", DefaultIPCPath).toString();

    if ( !settings.contains("ipc/path") ) {
        settings.setValue("ipc/path", ipcPath);
    }

    AccountModel accountModel(ipc);
    TransactionModel transactionModel(ipc);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("settings", &settings);
    engine.rootContext()->setContextProperty("ipc", &ipc);
    engine.rootContext()->setContextProperty("accountModel", &accountModel);
    engine.rootContext()->setContextProperty("transactionModel", &transactionModel);

    QObject::connect(&app, &QApplication::lastWindowClosed, &ipc, &EtherIPC::closeApp);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    ipc.start(ipcPath);

    return app.exec();
}