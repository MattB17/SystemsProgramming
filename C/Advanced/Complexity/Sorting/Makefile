OBJFILES = sort_measure.o sort.o

%.o: %.c sorts.h
	gcc -c $< -o $@

sort_measure.out: $(OBJFILES)
	gcc $(OBJFILES) -o sort_measure.out

.PHONY: clean
clean:
	rm sort_measure.out *.o
