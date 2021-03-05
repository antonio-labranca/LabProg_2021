all:
	g++ Lezione7_Valgrind/memcheck.cpp -o main_executable

debug_executable: Lezione7_Valgrind/cache.cpp
	g++ Lezione7_Valgrind/cache.cpp -g -o debug_executable

memcheck: debug_executable
	valgrind --track-origins=yes --leak-check=full ./debug_executable

clean:
	rm main_executable debug_executable
