all: clean test
test:
	@gcc -I../include -I../libs/include $(shell pkg-config --libs --cflags cmocka) matcher-test.c -o matcher-test && \
	echo matcher-test >> test.list
	./runner

clean:
	rm -rf matcher-test *.o test.list
.PHONY: test
