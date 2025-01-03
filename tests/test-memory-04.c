/* memory management whitebox test - %MEM */

int main() {

	puts("Hello, mtrac!");

	char *c = malloc(2);

	mtrac_check();

	puts("done.");
}
