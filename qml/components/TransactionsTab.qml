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
/** @file TransactionsTab.qml
 * @author Ales Katona <almindor@gmail.com>
 * @date 2015
 *
 * Transactions tab
 */

import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.0

Tab {
    id: transactionsTab
    title: qsTr("Transactions")

    Column {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 15

        GridLayout {
            columns: 3
            width: parent.width

            Label {
                id: fromLabel
                text: qsTr("From: ")
            }

            ComboBox {
                id: fromField
                Layout.minimumWidth: 600
                Layout.columnSpan: 2
                model: accountModel
                textRole: "summary"
            }

            Label {
                id: toLabel
                text: qsTr("To: ")
            }

            TextField {
                id: toField
                Layout.minimumWidth: 350
            }

            Button {
                id: sendButon
                text: "Send"
            }
        }
    }

}
