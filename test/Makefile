test:
	@gcc -L../libs/lib -I../include -I../libs/include matcher-test.c -lcmocka -o matcher-test && \
		./matcher-test 2>&1 | sed s/OK/$(shell printf "\033[32mOK\033[0m")/

clean:
	rm -rf matcher-test *.o
