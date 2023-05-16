all: clear clean compile run

compile: main.cpp Robot.cpp Humanic.cpp Optimusprime.cpp Bulldozer.cpp Robocop.cpp Roomba.cpp World.cpp

	@g++ -std=c++11 main.cpp Robot.cpp Humanic.cpp Optimusprime.cpp Bulldozer.cpp Robocop.cpp Roomba.cpp World.cpp -o test -lm
	
run:
	@./testmak
	
clean:
	@rm -f myprogram
	@rm -f a.out
		
clear:
	@clear
	
