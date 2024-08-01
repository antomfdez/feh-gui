QT.webenginecore_private.VERSION = 5.15.17
QT.webenginecore_private.name = QtWebEngineCore
QT.webenginecore_private.module =
QT.webenginecore_private.libs = $$QT_MODULE_LIB_BASE
QT.webenginecore_private.includes = $$QT_MODULE_INCLUDE_BASE/QtWebEngineCore/5.15.17 $$QT_MODULE_INCLUDE_BASE/QtWebEngineCore/5.15.17/QtWebEngineCore
QT.webenginecore_private.frameworks =
QT.webenginecore_private.depends = qml_private quick_private gui_private core_private webenginecore
QT.webenginecore_private.uses =
QT.webenginecore_private.module_config = v2 internal_module
QT.webenginecore_private.enabled_features = webengine-alsa webengine-printing-and-pdf webengine-kerberos webengine-ozone webengine-pepper-plugins webengine-poppler-cpp webengine-proprietary-codecs webengine-pulseaudio webengine-v8-snapshot-support webengine-webrtc webengine-webrtc-pipewire
QT.webenginecore_private.disabled_features = webengine-embedded-build
QMAKE_INCDIR_WEBENGINE_POPPLER_CPP = /usr/include/poppler/cpp /usr/include/poppler
QMAKE_DEFINES_WEBENGINE_PULSEAUDIO = _REENTRANT
QMAKE_INCDIR_WEBENGINE_PULSEAUDIO = /usr/include/glib-2.0 /usr/lib/glib-2.0/include /usr/include/sysprof-6
QMAKE_INCDIR_WEBENGINE_GIO = /usr/include/glib-2.0 /usr/lib/glib-2.0/include /usr/include/libmount /usr/include/blkid /usr/include/sysprof-6
QMAKE_LIBS_WEBENGINE_ALSA = -lasound
QMAKE_LIBS_WEBENGINE_POPPLER_CPP = -lpoppler-cpp
QMAKE_LIBS_WEBENGINE_PULSEAUDIO = -lpulse-mainloop-glib -lpulse -lglib-2.0
QMAKE_LIBS_WEBENGINE_GIO = -lgio-2.0 -lgobject-2.0 -lglib-2.0
