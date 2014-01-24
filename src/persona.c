struct persona{
	char *nombre;
	char *apellido;
};

void mostrarPersona(struct persona *p){
	printf("%s %s\n",p->nombre,p->apellido);
}
