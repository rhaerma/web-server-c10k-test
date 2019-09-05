build_low_level:
	g++ libevent/main.cpp -o libevent/main -levent

run_low_level:
	./libevent/main

run_high_level:
	python tornado/main.py