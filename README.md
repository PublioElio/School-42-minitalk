<div id="header" align="center">
  <img src="https://media.giphy.com/media/RNZIqvlB7cAyCdh9Gu/giphy.gif" width="200"/>
</div>

<h1 align="center">School 42 minitalk</h1>

This repository contains all files for the __minitalk__ project from School 42 Málaga cursus. The purpose of this project is to create a small data exchange program using UNIX signals. For more details about this task, [you can read the subject](https://github.com/PublioElio/School-42-minitalk).

<h2 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#index">Index</a>
	<span> · </span>
	<a href="#requirements">Requirements</a>
	<span> · </span>
	<a href="#instructions">Instructions</a>
	<span> · </span>
	<a href="#testing">Testing</a>
</h2>

## About
In this project it is necessary to create a `client` and a `server`. The `client` will send a string of characters to the `server`, using only UNIX signals. The `server` will then print the received string to another terminal. Additionally, as part of the **bonus** of the task, the `server` will confirm the reception of data to the `client`.

Al arrancar el `server`, lo primero que obtenemos es el PID (_process id_). El PID ha de introducirse en el `client`, en otra ventana del terminal, seguido de una cadena de caracteres válida (sin espacios en blanco o entrecomillada, si se incluyen espacios en blanco). Al ejecutar el cliente con estos parámetros, la cadena de caracteres enviada aparecerá en el terminal donde se haya ejecutado el `server`.  

En este proyecto se han utilizado las señales `SIGUSR1` y `SIGUSR2`. Estas señales están reservadas para su uso por parte de programadores y no son utilizadas por el sistema operativo. En el proyecto se ha optado por interpretar que la señal `SIGUSR1`es el envío de un `0` y `SIGUSR2`, el envío de un bit (`1`).

El uso de una variable global por ejecutable está permitido en el proyecto, y esta se ha definido como `g_mutex` en `client.c`. Esta variable se ha empleado como una forma alternativa de sincronizar `client' con `server`.

To imput a hig quantity of character, use a site like [this one.](https://www.chiquitoipsum.com/)

## Bonus
To imput ramdomly generated unicode characters, use a site [like this.](https://perchance.org/emoji)
