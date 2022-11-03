# School-42-minitalk
The purpose of this project is to create a small exchange program of data using UNIX signals.

Al arrancar el `server`, lo primero que obtenemos es el PID (_process id_). El PID ha de introducirse en el `client`, en otra ventana del terminal, seguido de una cadena de caracteres válida (sin espacios en blanco o entrecomillada, si se incluyen espacios en blanco). Al ejecutar el cliente con estos parámetros, la cadena de caracteres enviada aparecerá en el terminal donde se haya ejecutado el `server`.  

En este proyecto se han utilizado las señales `SIGUSR1` y `SIGUSR2`. Estas señales están reservadas para su uso por parte de programadores y no son utilizadas por el sistema operativo. En el proyecto se ha optado por interpretar que la señal `SIGUSR1`es el envío de un `0` y `SIGUSR2`, el envío de un bit (`1`).

El uso de una variable global por ejecutable está permitido en el proyecto, y esta se ha definido como `g_mutex` en `client.c`. Esta variable se ha empleado como una forma alternativa de sincronizar `client' con `server`.

To imput a hig quantity of character, use a site like [this one.](https://www.chiquitoipsum.com/)

## Bonus
To imput ramdomly generated unicode characters, use a site [like this.](https://perchance.org/emoji)
