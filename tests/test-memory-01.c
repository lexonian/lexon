/* memory management whitebox test - %MEM */ 

int main() {
	puts("Hello, mtrac!");

	char *c = malloc(2);
	free(c);

	mtrac_check();

	puts("done.");
}
