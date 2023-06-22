all: clear clean compile run

compile: main.cpp Catalog.cpp MusicCatalog.cpp BookCatalog.cpp MovieCatalog.cpp

	@g++ -std=c++11 main.cpp Catalog.cpp MusicCatalog.cpp BookCatalog.cpp MovieCatalog.cpp -o test -lm
	
run:
	@./testmak
	
clean:
	@rm -f myprogram
	@rm -f a.out
		
clear:
	@clear
	
