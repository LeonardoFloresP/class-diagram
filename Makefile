CXX = g++
CXXFLAGS = -std=c++11 -g
TARGET = school_admin
SOURCES = main.cpp Book.cpp Member.cpp Loan.cpp Library.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean

