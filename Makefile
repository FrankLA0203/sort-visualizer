LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all:
	@echo "** Building project"
	make clean
	g++ -c *.cpp
	g++ *.o -o "sort-visualizer" $(LIBS)

clean:
	@echo "** Cleaning project directory"
	rm -rf "sort-visualizer" *.o
