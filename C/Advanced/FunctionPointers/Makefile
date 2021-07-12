OBJFILES = compare_sorts.o sorts.o

%.o: %.c sorts.h
	gcc -c $< -o $@

compare_sorts.out: $(OBJFILES)
	gcc $(OBJFILES) -o compare_sorts.out

.PHONY: clean
clean:
	rm compare_sorts.out *.o
