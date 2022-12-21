LIBS=-lsfml-graphics -lsfml-window -lsfml-system
CXX := g++
SFML_INCLUDE_PATH=/home/theo/Documents/2048/SFML/include/
SFML_LIB_PATH=/home/theo/Documents/2048/SFML
APP_NAME := 2048

main : main.cpp 
	$(CXX) -c main.cpp -I$(SFML_INCLUDE_PATH)

exec : main.o 
	$(CXX) main.o -o $(APP_NAME) -L$(SFML_LIB_PATH)/lib $(LIBS)

all: main exec
	echo "Done"

run: all
	./$(APP_NAME)

clean: 
	-rm *.o
	find . -type f -executable -exec rm '{}' \;
	-rm $(APP_NAME)
 