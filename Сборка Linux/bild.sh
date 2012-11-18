#! /bin/sh
sudo chmod 775 easy_work/usr/share/EasyWork/Style/anime.style
sudo chmod 775 easy_work/usr/share/EasyWork/Style/brown.style
sudo chmod 775 easy_work/usr/share/EasyWork/Style/green.style
sudo chmod 775 easy_work/usr/share/EasyWork/Style/magenta.style
sudo chmod 775 easy_work/usr/share/EasyWork/KeyboardLayout/be-BY.language
sudo chmod 775 easy_work/usr/share/EasyWork/KeyboardLayout/de-DE.language
sudo chmod 775 easy_work/usr/share/EasyWork/KeyboardLayout/en-US.language
sudo chmod 775 easy_work/usr/share/EasyWork/KeyboardLayout/it-IT.language
sudo chmod 775 easy_work/usr/share/EasyWork/KeyboardLayout/ka-GE.language
sudo chmod 775 easy_work/usr/share/EasyWork/KeyboardLayout/ru-RU.language
sudo chmod 775 easy_work/usr/share/EasyWork/KeyboardLayout/uk-UA.language
sudo chmod 775 easy_work/usr/share/applications/EasyWork.desktop
sudo chmod 775 easy_work/usr/share/pixmaps/easyworkgeneral.png
sudo chmod 775 easy_work/usr/share/EasyWork/Database
sudo chmod 775 easy_work/usr/share/EasyWork/KeyboardLayout
sudo chmod 775 easy_work/usr/share/EasyWork/Style
sudo chmod 775 easy_work/DEBIAN/postinst
sudo chmod 775 easy_work/DEBIAN/preinst


if [ -f easy_work/usr/share/EasyWork/Database/statisticForRegimeFile.mdb ]; then
  sudo rm easy_work/usr/share/EasyWork/Database/statisticForRegimeFile.mdb
fi

kate easy_work/DEBIAN/control
kate easy_work/DEBIAN/changelog

echo "Новая версия:"
read newVersion

fakeroot dpkg-deb --build easy_work

mv easy_work.deb Easy_Work_"$newVersion"_all.deb