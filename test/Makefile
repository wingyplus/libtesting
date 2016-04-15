TEST = matcher-test \
       second-test

all: clean $(TEST) run
.PHONY: all

$(TEST):
	@gcc -I../include -I../libs/include $(shell pkg-config --libs --cflags cmocka) $@.c -o $@ && \
	echo $@ >> test-result.txt

run:
	./run

clean:
	rm -rf $(TEST) *.o test-result.txt
.PHONY: test
