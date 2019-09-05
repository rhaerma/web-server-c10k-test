low_level:
	mkdir -p bin
	g++ src/low_level.cpp -o bin/low_level -levent

run_low_level:
	./bin/low_level

run_high_level:
	python src/high_level.py