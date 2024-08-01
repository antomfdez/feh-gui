qmake
cd build/Desktop-Release
sudo make install
FILE=/usr/bin/feh-gui
if [ ! -f "$FILE" ]; then
	sudo ln -s /opt/feh-gui/bin/feh-gui /usr/bin
fi
