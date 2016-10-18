APPS=$(sort $(basename $(wildcard *.c)))

.PHONY: all clean

all: $(APPS)

%: %.c
	gcc $^ -o $@ -std=gnu99 -Wall -Wextra -Werror -pthread

clean:
	rm $(APPS) >/dev/null 2>&1 || true
