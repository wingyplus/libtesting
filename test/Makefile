TESTS = matcher-test \
	second-test

all: clean $(TESTS)

$(TESTS):
	@gcc -I../include -I../libs/include $(shell pkg-config --libs --cflags cmocka) $@.c -o $@ && \
	echo $@ | ./colorize

clean:
	@rm -rf $(TESTS) *.o test-result.txt

.PHONY: $(TESTS)
