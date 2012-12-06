#! /bin/sh

qmake
make
sudo make install

sudo chmod 777 /usr/share/EasyWork/Style
sudo chmod 777 /usr/share/EasyWork/Database

cd /usr/bin
./Easy_work