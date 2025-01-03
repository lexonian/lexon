/* memory management whitebox test - %MEM */

int main() {

	puts("Hello, mtrac!");

	mtrac_verbose = true;
	mtrac_blank_pointers = true;

	char *c1 = strdup(";-)");
	char *c2 = strdup(";-)");
	char *c3 = strdup(";-)");
	free(c1);	
	free(c2);	
	free(c3);	

	mtrac_check();


	c1 = strdup(";-)");
	c2 = strdup(";-)");
	c3 = strdup(";-)");
	free(c2);	
	free(c1);	
	free(c3);	

	mtrac_check();


	c1 = strdup(";-)");
	c2 = strdup(";-)");
	c3 = strdup(";-)");
	free(c3);	
	free(c1);	
	free(c2);	

	mtrac_check();


	c1 = strdup(";-)");
	c2 = strdup(";-)");
	c3 = strdup(";-)");
	free(c3);	
	free(c2);	
	free(c1);	

	mtrac_check();


	c1 = strdup(";-)");
	c2 = strdup(";-)");
	c3 = strdup(";-)");
	free(c1);	
	free(c3);	
	free(c2);	

	mtrac_check();


	c1 = strdup(";-)");
	c2 = strdup(";-)");
	c3 = strdup(";-)");
	free(c2);	
	free(c1);	
	free(c3);	

	mtrac_check();


	c2 = strdup(";-)");
	c1 = strdup(";-)");
	c3 = strdup(";-)");
	free(c3);	
	free(c1);	
	free(c2);	

	mtrac_check();


	c3 = strdup(";-)");
	c1 = strdup(";-)");
	c2 = strdup(";-)");
	free(c3);	
	free(c2);	
	free(c1);	

	mtrac_check();


	c1 = strdup(";-)");
	c3 = strdup(";-)");
	c2 = strdup(";-)");
	free(c1);	
	free(c3);	
	free(c2);	

	mtrac_check();


	puts("done.");
}
