test:
	@gcc -I../include -I../libs/include $(shell pkg-config --libs --cflags cmocka) matcher-test.c -o matcher-test && \
		./matcher-test 2>&1 | sed s/OK/$(shell printf "\033[32mOK\033[0m")/

clean:
	rm -rf matcher-test *.o
