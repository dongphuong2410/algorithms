all: test_read_matrix test_random test_group test_remove test_main

%: %.c ../rc.c
	$(CC) -o $@ $@.c ../rc.c -g
