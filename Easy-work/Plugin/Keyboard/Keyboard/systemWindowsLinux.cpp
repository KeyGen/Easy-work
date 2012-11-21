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

#include "keyboard.h"
#include <QApplication>

#ifdef Q_OS_WIN32
    #include <windows.h>

    QString KeyboardClass::sistemsKeyboardLanguage(){

        HKL hkl;
        DWORD threadId;
        threadId = GetWindowThreadProcessId(NULL, NULL);
        hkl = GetKeyboardLayout(threadId);
        int codLayoutKeyboard = LOWORD(hkl);

        if(codLayoutKeyboard == ru_RU)
            return "ru-RU";
        if(codLayoutKeyboard == en_US)
            return "en-US";
        if(codLayoutKeyboard == ka_GE)
            return "ka-GE";
        if(codLayoutKeyboard == be_BY)
            return "be-BY";
        if(codLayoutKeyboard == uk_UA)
            return "uk-UA";
        if(codLayoutKeyboard == de_DE)
            return "de-DE";
        if(codLayoutKeyboard == it_IT)
            return "it-IT";

        return QApplication::keyboardInputLocale().bcp47Name();
    }

    bool KeyboardClass::statusCapsLock(){
        return GetKeyState(VK_CAPITAL);
    }

#else

#include </usr/include/X11/XKBlib.h>


    QString KeyboardClass::sistemsKeyboardLanguage(){
        return QApplication::keyboardInputLocale().bcp47Name();
    }

    bool KeyboardClass::statusCapsLock(){

        Display * d = XOpenDisplay((char*)0);
        bool caps_state = false;
        if (d) {
        unsigned n;

        XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
        caps_state = (n & 0x01) == 1;
        }

        return caps_state;
    }
#endif
