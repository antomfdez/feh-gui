QT.testlib.VERSION = 5.15.14
QT.testlib.name = QtTest
QT.testlib.module = Qt5Test
QT.testlib.libs = $$QT_MODULE_LIB_BASE
QT.testlib.includes = $$QT_MODULE_INCLUDE_BASE $$QT_MODULE_INCLUDE_BASE/QtTest
QT.testlib.frameworks =
QT.testlib.bins = $$QT_MODULE_BIN_BASE
QT.testlib.depends = core
QT.testlib.uses =
QT.testlib.module_config = v2 ltcg
QT.testlib.CONFIG = console testlib_defines
QT.testlib.DEFINES = QT_TESTLIB_LIB
QT.testlib.enabled_features = itemmodeltester valgrind
QT.testlib.disabled_features = testlib_selfcover
QT_CONFIG +=
QT_MODULES += testlib
