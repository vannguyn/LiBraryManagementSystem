cmake_minimum_required(VERSION 3.10)

project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include folder
include_directories(include)

# User application
add_executable(user_app
    app/main_user.cpp
    src/services/LibraryService.cpp
    src/ui/UserUI.cpp
    src/repositories/BookRepository.cpp
    src/models/Book.cpp
    src/models/BorrowRecord.cpp
    src/models/User.cpp
)
