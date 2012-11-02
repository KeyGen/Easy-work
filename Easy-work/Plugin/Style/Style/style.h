/**
 * Easy work - writed by KeyGen 2012
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#ifndef STYLE_H
#define STYLE_H

#include "Style_global.h"

#include <QDebug>

class StyleClass : public Style
{
    Q_OBJECT Q_INTERFACES(Style)

public:
    StyleClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Style"; }
    virtual QString getStyleSheet() { return readFile(); }

    virtual ~StyleClass();

private:
    QString readFile(QString path = ":/standart.style");

signals:
    void getStyle(QString);
};

#endif // STYLE_H
