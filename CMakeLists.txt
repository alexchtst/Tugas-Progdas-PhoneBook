cmake_minimum_required(VERSION 3.10)
project(MyWxApp)

set(CMAKE_CXX_STANDARD 17)

set(wxWidgets_ROOT_DIR "C:/wxWidgets-3.2.8")
set(wxWidgets_LIB_DIR "C:/wxWidgets-3.2.8/lib/gcc_lib")
set(wxWidgets_CONFIGURATION mswud)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(MyWxApp
    main.cpp
    CRUD_PANEL.cpp
    LOAD_PANEL.cpp
)

target_link_libraries(MyWxApp ${wxWidgets_LIBRARIES})
