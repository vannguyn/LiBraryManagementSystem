CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

TARGET = user_app

SRC = \
app/main_user.cpp \
src/services/LibraryService.cpp \
src/ui/UserUI.cpp \
src/repositories/BookRepository.cpp \
src/models/Book.cpp \
src/models/BorrowRecord.cpp \
src/models/User.cpp

# target mặc định
all: $(TARGET)

# build
$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	./$(TARGET)

# clean
clean:
	rm -f $(TARGET).exe
