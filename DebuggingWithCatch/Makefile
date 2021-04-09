test: test.x

%.o : %.cpp
	g++ -c $< -o $@

test.x: factorial.o catch-example.o
	g++ -g $^ -o $@

run_test: test.x
	./test.x

clean:
	rm -f *.x *.o *a.out
