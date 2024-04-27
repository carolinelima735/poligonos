#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

	typedef struct {
   	 	float X;
    	float Y;
} Ponto;

	float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    	return fabs((A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y)) / 2.0);
}

	float AreaPoligono(Ponto *vertices, int numVertices) {
    float areaTotal = 0.0;
		int i;
		for(i = 1; i < numVertices - 1; i++) {
        areaTotal += AreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }
    return areaTotal;
}

	int main() {
		setlocale(LC_ALL,"portuguese");
    	FILE *file;
    	file = fopen("poligonos.txt", "r");
    	if (file == NULL) {
        	printf("Arquivo n�o encontrado/ n�o existe.");
        	return 1;
    }

    int numVertices;
    fscanf(file, "%d", &numVertices);

    Ponto *vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));
    if (vertices == NULL) {
        printf("Erro.");
        return 1;
    }

   int i;
	for (i = 0; i < numVertices; i++) {
        fscanf(file, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    fclose(file);

    float area = AreaPoligono(vertices, numVertices);
    printf("A �rea do pol�gono � %.2f\n", area);

    free(vertices);
    return 0;
}

