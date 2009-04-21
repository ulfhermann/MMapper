/************************************************************************
**
** Authors:   Ulf Hermann <ulfonk_mennhar@gmx.de> (Alve),
**            Marek Krejza <krejza@gmail.com> (Caligor),
**            Nils Schimmelmann <nschimme@gmail.com> (Jahara)
**
** This file is part of the MMapper2 project.
** Maintained by Marek Krejza <krejza@gmail.com>
**
** Copyright: See COPYING file that comes with this distributione
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file COPYING included in the packaging of
** this file.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
** NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
** LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
** OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
** WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
*************************************************************************/

#ifndef FLAGSETTER
#define FLAGSETTER

#include <QMap>
#include <QByteArray>
#include "coordinate.h"
#include "component.h"
#include "roomrecipient.h"
#include "roomadmin.h"
#include "mapaction.h"

class RoomPropertySetterSlave : public RoomRecipient
{
private:
	AbstractAction * action;
public:
	RoomPropertySetterSlave(AbstractAction * in_action) : action(in_action) {}
	void receiveRoom(RoomAdmin *, const Room *);
	bool getResult() {return !action;}
};

class RoomPropertySetter : public Component
{
private:
	Q_OBJECT
	QMap<QByteArray, uint> propPositions;
	QMap<QByteArray, uint> fieldValues;

public:
	RoomPropertySetter();
	virtual Qt::ConnectionType requiredConnectionType(const QString &) {return Qt::DirectConnection;}
	
public slots:
	void parseProperty(const QByteArray &, const Coordinate &);
	
signals:
	void sendToUser(const QByteArray&);
	void lookingForRooms(RoomRecipient *,const Coordinate &);
};

#endif
