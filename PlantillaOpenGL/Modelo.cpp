#include "stdafx.h"
#include "Modelo.h"

Modelo::Modelo() {

}

void Modelo::inicializarVertexArray(GLuint posicionID, GLuint colorID) {
	//Crear un vertex array
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	//Crear vertex buffer
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);

	//llenar el buffer
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(Vertice) * vertices.size(),
		vertices.data(), GL_STATIC_DRAW);

	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT,
		GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT,
		GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

}

void Modelo::dibujar(GLenum modoDibujo) {
	shader->enlazar();
	glBindVertexArray(vertexArrayID);
	glDrawArrays(modoDibujo, 0, vertices.size());
	glBindVertexArray(0);
	shader->desenlazar();

}