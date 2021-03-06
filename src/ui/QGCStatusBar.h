/*=====================================================================

QGroundControl Open Source Ground Control Station

(c) 2009 - 2013 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>

This file is part of the QGROUNDCONTROL project

    QGROUNDCONTROL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    QGROUNDCONTROL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with QGROUNDCONTROL. If not, see <http://www.gnu.org/licenses/>.

======================================================================*/

#ifndef QGCSTATUSBAR_H
#define QGCSTATUSBAR_H

#include <QStatusBar>
#include <QAction>
#include <QToolButton>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include "UASInterface.h"
#include "QGCMAVLinkLogPlayer.h"

class QGCStatusBar : public QStatusBar
{
    Q_OBJECT

public:
    explicit QGCStatusBar(QWidget* parent = 0);
    void addPerspectiveChangeAction(QAction* action);
    ~QGCStatusBar();

public slots:
    /** @brief Start / stop logging */
    void logging(bool checked);
    /** @brief Set log playing component */
    void setLogPlayer(QGCMAVLinkLogPlayer* player);
    virtual void paintEvent(QPaintEvent * event);

protected:
    void storeSettings();
    void loadSettings();

    QPushButton* toggleLoggingButton;
    QGCMAVLinkLogPlayer* player;
    bool changed;
    QString lastLogDirectory;
};

#endif // QGCSTATUSBAR_H
