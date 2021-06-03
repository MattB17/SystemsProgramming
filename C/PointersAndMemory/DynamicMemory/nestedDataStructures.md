int **pointers = malloc(sizeof(int*) * 2);
pointers[0] = malloc(sizeof(int));
pointers[1] = malloc(sizeof(int) * 3);

pointers[0][0] = 55;
pointers[1][2] = 300;

free(pointers[0]);
free(pointers[1]);
free(pointers);
