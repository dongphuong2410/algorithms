TEST_DIR = test
SUBDIRS = test

all: main subdir

main: rc.c main.c
	$(CC) -o main rc.c main.c -g

subdir:
	@for dir in $(SUBDIRS);	\
		do $(MAKE) -C $$dir || exit 1;	\
	done

clean:
	rm main
	rm -f $(TEST_DIR)/test_read_matrix $(TEST_DIR)/test_main $(TEST_DIR)/test_group $(TEST_DIR)/test_remove $(TEST_DIR)/test_random
