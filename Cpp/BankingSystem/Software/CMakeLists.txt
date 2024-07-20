cmake_minimum_required(VERSION 3.10)
project(BankingSystem)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Specify the path to MySQL Connector/C++ headers and libraries
set(MYSQL_CONNECTOR_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(MYSQL_CONNECTOR_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/lib")

# Specify the path to spdlog headers and library
set(SPDLOG_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/lib/spdlog/include")
set(SPDLOG_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/lib/spdlog/lib")

# Find and include ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Add include directories
include_directories(${MYSQL_CONNECTOR_INCLUDE_DIR})
include_directories(${SPDLOG_INCLUDE_DIR})

# Add the source files in the src directory
file(GLOB SOURCES "src/*.cpp")

# Create an executable
add_executable(BankingSystem ${SOURCES})

# Specify the output directory for the executable
set_target_properties(BankingSystem PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

# Link against MySQL Connector/C++, spdlog, and ncurses libraries
link_directories(${MYSQL_CONNECTOR_LIBRARY_DIR})
link_directories(${SPDLOG_LIBRARY_DIR})

# Find and link against spdlog library
find_library(SPDLOG_LIBRARIES NAMES spdlog PATHS ${SPDLOG_LIBRARY_DIR})

# Add the necessary libraries to link against
target_link_libraries(BankingSystem
    mysqlcppconn
    ${SPDLOG_LIBRARIES}
    ${CURSES_LIBRARIES}
)
