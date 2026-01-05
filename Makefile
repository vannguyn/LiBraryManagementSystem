CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

TARGET = admin_app

SRC = \
app/main_admin.cpp \
src/services/LibraryService.cpp \
src/ui/UserUI.cpp \
src/repositories/BookRepository.cpp \
src/models/Book.cpp \
src/models/BorrowRecord.cpp \
src/models/User.cpp \
src/repositories/BorrowRepository.cpp \
src/repositories/UserRepository.cpp \
src/ui/AdminUI.cpp

# target mặc định
all: $(TARGET)

# build
$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	./$(TARGET)

# clean
clean:
	rm -f $(TARGET).exe
