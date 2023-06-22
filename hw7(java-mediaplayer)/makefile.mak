all: clear compile run

clear:
	clear

compile:
	javac Dataset.java Audio.java Image.java non_playable.java 
	non_visual.java Observer.java playable.java Text.java Video.java visual.java 

run:
	java Dataset