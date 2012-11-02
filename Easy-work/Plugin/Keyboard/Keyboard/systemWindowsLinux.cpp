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

#include "keyboard.h"
#include <QApplication>
//#include <windows.h>

QString KeyboardClass::sistemsKeyboardLanguage(){

// -----------Windows-----------
//    HKL hkl;
//    DWORD threadId;
//    threadId = GetWindowThreadProcessId(NULL, NULL);
//    hkl = GetKeyboardLayout(threadId);
//    int codLayoutKeyboard = LOWORD(hkl);

//    if(codLayoutKeyboard == 1049)
//        return "ru-RU";
//    if(codLayoutKeyboard == 1033)
//        return "en-US";
//    if(codLayoutKeyboard == 1079)
//        return "ka-GE";
//    if(codLayoutKeyboard == 1059)
//        return "be-BY";
//    if(codLayoutKeyboard == 1058)
//        return "uk-UA";
//    if(codLayoutKeyboard == 1031)
//        return "de-DE";
//    if(codLayoutKeyboard == 1040)
//        return "it-IT";

////    if(codLayoutKeyboard == 1036) // пока уберем
////        return "fr-FR";

    return QApplication::keyboardInputLocale().bcp47Name();
}
