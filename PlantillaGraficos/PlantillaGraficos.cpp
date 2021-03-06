// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;


void dibujarQuads() {
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.8f, 0.0f);

	glVertex3f(1.0f, -0.5f, 0.0f);
	glVertex3f(-1.0f, -0.5f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);

	glColor3f(0.6f, 0.0f, 0.5f);

	glVertex3f(-0.3f, 0.1f, 0.0f);
	glVertex3f(0.7f, 0.1f, 0.0f);
	glVertex3f(0.7f, -0.7f, 0.0f);
	glVertex3f(-0.3f, -0.7f, 0.0f);

	glEnd();
}

void dibujarPoligono() {
	
}

void dibujarTrianguloContinuo() {
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.2f, 0.0f, 0.0f);

	glColor3f(0.0f, 0.7f, 1.0f);

	glVertex3f(0.1f, 0.5f, 0.0f);

	glEnd();
}

void dibujarLineaContinua() {
	glBegin(GL_LINE_STRIP);

	glColor3f(0.1f, 0.3f, 0.75f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.2f, 0.0f);
	glVertex3f(0.4f, 0.2f, 0.0f);
	glVertex3f(0.2f, 0.3f, 0.0f);

	glEnd();
}

void dibujarTriangulos() {
	//establecemos el tipo de primitiva
	glBegin(GL_TRIANGLES);
	//establecemos color
	glColor3f(1.0f, 0.0f, 0.5f); 
	//enviar vertices
	glVertex3f(0.0f, 0.7f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.7f, -0.7f, 0.0f);
	glColor3f(1.0f, 0.7f, 0.0f);
	glVertex3f(0.7f, -0.7f, 0.0f);

	glColor3f(0.4f, 0.6f, 1.0f);

	glVertex3f(0.4f, 0.4f, 0.0f);
	glVertex3f(-0.4f, 0.4f, 0.0f);
	glVertex3f(0.4f, -0.4f, 0.0f);
	glVertex3f(-0.4f, -0.4f, 0.0f);
	glVertex3f(-0.4f, 0.4f, 0.0f);
	glVertex3f(0.4f, -0.4f, 0.0f);
	//especificar que dejaremos de dibujar

	//glColor3f(0.6f, 0.7f, 0.8f);

	//glVertex3f(-0.4f, 0.1f, 0.0f);


	glEnd();
}

void dibujarLineas() {
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.6f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, 0.5f, 0.0f);

	glColor3f(0.0f, 0.3f, 0.6f);

	glVertex3f(0.3f, 0.0f, 0.0f);
	glVertex3f(0.6f, 0.5f, 0.0f);

	glEnd();
}

float posXTriangulo = 0.0f, posYTriangulo = 0.0f;
//declarar una ventana
GLFWwindow* window;
double tiempoAnterior;
double tiempoActual;
double velocidadTriangulo = 0.7;

void teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_RIGHT)
	{
		posXTriangulo += 0.009;
	}

	if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_LEFT)
	{
		posXTriangulo += -0.009;
	}

	if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_UP)
	{
		posYTriangulo += 0.009;
	}

	if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_DOWN)
	{
		posYTriangulo += -0.009;
	}

	tiempoAnterior = tiempoActual;
}

void actualizar()
{
	tiempoActual = glfwGetTime();
	double tiempoDiferencial = tiempoActual - tiempoAnterior;

	int estadoDerecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	int estadoArriba = glfwGetKey(window, GLFW_KEY_UP);
	int estadoAbajo = glfwGetKey(window, GLFW_KEY_DOWN);

	if (estadoDerecha == GLFW_PRESS)
	{
		posXTriangulo += 0.02 * tiempoDiferencial;
	}

	if (estadoIzquierda == GLFW_PRESS)
	{
		posXTriangulo -= 0.02 * tiempoDiferencial;
	}

	if (estadoArriba == GLFW_PRESS)
	{
		posYTriangulo += 0.02 * tiempoDiferencial;
	}

	if (estadoAbajo == GLFW_PRESS)
	{
		posYTriangulo -= 0.02 * tiempoDiferencial;
	}
}

void dibujar() {
	glPushMatrix();

	glTranslatef(posXTriangulo, posYTriangulo, 0.0f);

	glBegin(GL_TRIANGLES);

	glColor3f(0.2, 0.6, 0.1);
	glVertex3f(0.0f, 0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);

	glEnd();

	glPopMatrix();
}

int main()
{

	//Si no se pudo iniciar GLFW
	//Terminamos ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//iniciamos la ventana
	window = glfwCreateWindow(600, 600, "Ventana", NULL, NULL);

	//si no se pudo crear la ventana terminamos ejecucion
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//una vez estableciendo el contexto se activan las funciones modernas (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK)
	{
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	//establecemos que con cada evento de teclado se llama a la funcion teclado_callback
	///glfwSetKeyCallback(window, teclado_callback);

	//ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window))
	{
		//establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.67, 0.84, 1.0, 1);
		//Borrar!
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Actualizar valores y dibujar
		actualizar();
		dibujar();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	//despues del ciclo de dibujo eliminamos venta y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
