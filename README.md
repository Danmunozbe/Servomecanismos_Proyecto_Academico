# Proyecto Academico servomecanismos 2024-1 (2?)

## Funcionamiento Encoder Optico
El Encoder optico tiene un total de 4 cables, 2 para VCC y GND; y los 2 para los sensores Opticos A y B. En uno de los motores deje colocado ya entradas hembra, el GND esta con el cable negro y el VCC (5 volts) con el rojo, los otros son para los sensores A y B los cuales requieren de resistencias "PULLUP" (las cuales se pueden activar con el arduino), no me acuerdo cual es cual pero tienen el cable verde. Para el otro Motor la distribucion es la misma.
En el codigo de [arduino encontrado en pruebas/EncoderOptico](arduino/Pruebas/EncoderOptico/EncoderOptico.ino) tiene un codigo muy basico para identificar cual es cual y si esta funcionando.
Un detalle importante es que intentando entnder como funciona dañe la helice de uno de los encoders. Ahi coloque otro pero no probe que funcionara (Me quede sin tiempo xd), en la carpeta de [modelados](modelados) está el modelo de inventor que use como base para reemplazarlo. No creo que sea necesario tener que imprimir la parte, cualquier cosas como un pedazo de carton deberia funcionar en caso de que el que ya está ahí no lo haga. Si esto sucede tal vez pintarlo de negro con un sharpie lo arregle.

Para el caso de control, recomiendo usar interrupciones, una por motor. La interrupcion se activa en uno de los sensores (A) y se evalua el estado de (B), dependiendo del valor de (B) le rueda giró en CC o en CCW. La relacion de los motores es de 1:80 por si algo, aunque no estoy tan seguro que sea igual con el soporte.

## Encoder magnetico
Deje 3 sensores magneticos que miden angulos, pero por alguna razon no quisieron funcionar. La referencia es el AS5600 por si los van a buscar.

## Cinematica Inversa
En el codigo de [matlab](academicProject.mlx) esta la cinematica inversa, para que parte del codigo funcione se requiere del ToolBox de robotica de petercorke. Este toolbox tambien se usa en robotica asi que seria bueno que lo vayan instalando, [aqui les dejo la instalacioc ](https://youtu.be/cl5Jbs1ZVJc?si=r-kWMLw480cAv4Nm), y [aqui el archivo por a descargar](https://petercorke.com/resources/downloads/#all_0-27-wpfd-rtb) 

> [!WARNING]  
> La version debe ser la 9.10 OJITO
### servoPoints
En resumen hay una conjunto de valores que definen la funcion en coordenadas polares 'Clover'
La funcion servoPoints toma la funcion, la escala y el angulo de rotacion (Despues de todo el proyecto pide escala y rotar asi que ahi estan). Luego lo que hace es hacer que el trebol este encerrado en un circulo de 15cm de diametro (esto por que la funcion original se sale de este valor y puede tener problemas en la cinematica inversa).

### getPoints
Luego se llama la funcion getPoints que tomas los valores, los escala, los rota y los vuelve a coordenasas cartesianas, y luego lo coloca en el centro de un cuadrado que tiene dimensiones del cuadrado esperado (es decir, los 15 centimetros junto con la escala.). Finalmente halla el punto mas cercano a 0,0 (que seria la esquina inferior izquierda) y se traza el camino desde ahi, hasta el trebol.
> Detalle: Deben modificar el codigo para que reciba cuantas veces se va a realizar el movimiento del trebol ya que ahi solo lo hace una vez.

Luego de esto coloque unas dimensiones y angulos inciales en lo que es "DH Parameters", no se preocupen mucho por eso, solo tengan en cuenta que "l1" y "l2" son las medidas de los eslabones y "offset" son los angulos iniciales del robot. Los que estan ahi funcionan pero son libres de modificarlos.

### ikine
Luego de esto se hallan los valores de los angulos para el cual se realiza camino del trebol. Este esta ahi por metodos numericos porque queria verificar que si esxistiera alguna configuracion para los angulos requeridos. En caso de que quieran hacerlo a "mano" [Este libro que se usa en robotica lo explica (pag-106)](https://www.researchgate.net/profile/Mohamed_Mourad_Lafifi/post/How_to_avoid_singular_configurations/attachment/59d6361b79197b807799389a/AS%3A386996594855942%401469278586939/download/Spong+-+Robot+modeling+and+Control.pdf) pero les dejo las ecuaciones e
$$
D=\frac{x^2+y^2-l_1^2-l_2^2}{2l_1l_2}=\cos{\theta_2}\\
\\
\theta_2=atan2(D,\sqrt{1-D^2})\\
\theta_1=atan2(x,y)-atan2(l1+l2\cos{\theta_2},l2\sin(\theta_2))
$$
> En el libro encuentran el atan2 de esta forma, sin embargo en Matlab el atan2 toma los parametros en orden distinto (es decir intercambian los parametros.)

## Otras cosas
En los archivos de arduino hay uno para probar el puente H (que es realmente sencillo de usar, recomiendo [este video](https://youtu.be/c0L4gNKwjRw?si=f5U9qAO5fSEXj6Z0))