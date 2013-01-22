/**
 * Easy work - краткое описание на английском
 * Copyright (C) 2012 KeyGen <KeyGenQt@gmail.com>
 * https://github.com/KeyGen/Easy-work/wiki
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

#ifndef METRONOME_H
#define METRONOME_H

#include "Metronome_global.h"
#include <QDebug>

class MetronomeClass : public Metronome
{
    Q_OBJECT Q_INTERFACES(Metronome)

public:
    MetronomeClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Metronome"; }
    ~MetronomeClass(){}
};

#endif // METRONOME_H
