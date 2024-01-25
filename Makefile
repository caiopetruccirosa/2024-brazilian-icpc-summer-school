all: build run

build:
	g++ $(FILE) -o .$(dirname $(FILE))/$(basename $(FILE))

run: build
	.$(dirname $(FILE))/$(basename $(FILE))