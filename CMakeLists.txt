cmake_minimum_required(VERSION 3.10)

project(NodeImageEditor)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find Qt5 packages (Core, Gui, Widgets)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

# Include OpenCV
find_package(OpenCV REQUIRED)

# Set source and header files
set(SOURCES
    src/main.cpp
    src/MainWindow.cpp
)

set(HEADERS
    include/MainWindow.hpp
)

# Create the executable
add_executable(NodeImageEditor ${SOURCES} ${HEADERS})

# Link Qt5 libraries and OpenCV
target_link_libraries(NodeImageEditor Qt5::Core Qt5::Gui Qt5::Widgets ${OpenCV_LIBS})

# Set include directories
target_include_directories(NodeImageEditor PUBLIC ${OpenCV_INCLUDE_DIRS} include)


src/ImageInputNode.cpp
src/BaseNode.cpp
src/NodeConnection.cpp
src/NodeGraph.cpp
