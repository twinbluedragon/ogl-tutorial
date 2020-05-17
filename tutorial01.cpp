// 標準ヘッダをインクルードします。
#include <stdio.h>
#include <stdlib.h>

// GLEWをインクルードする。常にgl.hとglfw.hより先にインクルードしましょう。これはちょっとしたマジックです。
#include <GL/glew.h>

// GLFWをインクルードします。
#include <GLFW/glfw3.h>
GLFWwindow* window;

// GLMをインクルードします。
#include <glm/glm.hpp>
using namespace glm;

int main( void )
{
	// GLFWを初期化します。
	if( !glfwInit() )
	{
		fprintf( stderr, "GLFWの初期化に失敗しました。\n" );
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);	// 4x アンチエイリアス
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	// OpenGL3.3を使います。
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MacOS用：必ずしも必要ではありません。
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	// 古いOpenGLは使いません。

	// Windowを開き、OpenGLコンテキストを作ります
	GLFWwindow*	window;	// (ソースコードではこの変数はグローバルです。)
	window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "GLFWウィンドウのオープンに失敗しました。 もしIntelのGPUならば, 3.3に対応していません。チュートリアルのバージョン2.1を試してください。\n" );
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// GLEWを初期化する
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "GLEWの初期化に失敗しました。\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// 下でエスケープキーが押されるのを捉えるのを保証します。
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	do{
		// Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
		glClear( GL_COLOR_BUFFER_BIT );

		// 何も描きません。チュートリアル2で会いましょう！

		
		// バッファをスワップする。
		glfwSwapBuffers(window);
		glfwPollEvents();

	}// ESCキーが押されたかウィンドウが閉じたかをチェックする。
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

