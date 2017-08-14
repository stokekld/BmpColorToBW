# Proyecto High Performance

Este es un proyecto que intenta demostrar las caracteristicas de OpenMP el cual es una interfaz (API) de programación multiproceso de memoria compartida. El proyecto es un comando que convierte una imagen en formato bmp a escala de grises y además la rota 180°.

* Para utilizar el comando lo primero que se debe de hacer es compilarlo:
    ```
    $ cd src/
    $ make
    ```
* El modo de uso del comando es el siguiente:
    ```
    $ ./bmpctbw /ruta/a/la/imagen
    ```
* El comando crea una nueva imagen con los cambios llamada _salida.bmp_.

Cuando se ejecuta el comando se puede ver la siguente salida:
```
Tamaño de imagen (bytes):       1499022
Ancho de imagen (px):           871
Alto de imagen (px):            573
Bits por px:                    24
Tiempo de ejecucion (s):        0.131183
```
Se puede observar la duración de la ejecución y algunas caracteristicas de la imagen. Para cambiar el número de hilos se puede correr el comando junto con la variable de entorno `OMP_NUM_THREADS` y el número de hilos deseados, por ejemplo:
```
OMP_NUM_THREADS=4 ./bmpctbw /tmp/New_Bitmap_Image_normal.bmp
```


