cmake_minimum_required(VERSION 3.21)
project(pjc_nowe)

set(CMAKE_CXX_STANDARD 14)
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)

include_directories(.)

include_directories(/opt/homebrew/Cellar/mysql/8.0.29/include)
link_directories(/opt/homebrew/Cellar/mysql/8.0.29/lib)


set(FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR /opt/homebrew/Cellar/mysql-connector-c++/8.0.29)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include)
link_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib)

include(${wxWidgets_USE_FILE})



add_executable(pjc_nowe
        main.cpp
        main.h chooseDeck.cpp addDeck.cpp lesson.cpp edit.cpp start.cpp dataBase.cpp dataBase.h backendLogic.cpp backendLogic.h)


target_link_libraries(pjc_nowe ${wxWidgets_LIBRARIES})
target_link_libraries(pjc_nowe mysqlclient)
target_link_libraries(pjc_nowe mysqlcppconn8.2)
