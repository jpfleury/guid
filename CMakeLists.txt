cmake_minimum_required(VERSION 3.16)
project(Guid VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets DBus)

execute_process(
	COMMAND git describe --tags --always --dirty
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	OUTPUT_VARIABLE GIT_APP_VERSION
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_compile_definitions(APP_VERSION="${GIT_APP_VERSION}")

set(SOURCES
	Guid.cpp
	qrcodegen/qrcodegen.cpp
	guid.qrc
)
set(HEADERS
	Guid.h
	GuidHelpData.hpp
	qrcodegen/qrcodegen.hpp
)

add_executable(guid ${SOURCES} ${HEADERS})

target_include_directories(guid PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/qrcodegen
)

target_link_libraries(guid Qt5::Core Qt5::Gui Qt5::Widgets Qt5::DBus)
