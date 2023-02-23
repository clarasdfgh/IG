# IG 21/22 - Ejercicios Tema 1

###### Clara María Romero Lara, 3ºD

#### 1. En la página anterior se han citado cuatro ámbitos en los que la informática gráfica forma parte fundamental: el diseño industrial, el cine, la medicina y la arquitectura. Describa usted otras cuatro disciplinas profesionales o científicas que requieran de la participación inexcusable de los gráficos por ordenador para su correcto desempeño. 

1. Videojuegos de cualquier género requieren técnicas de informática gráfica, sean en 2 o 3 dimensiones
2. Simuladores de vuelo, de conducción... necesarios para formar pilotos de forma segura
3. Matemáticas, representación de datos y de topologías, incluso en 4 dimensiones
4. Geografía y geomorfología, los modelos 3d son una representación mucho más legible del terreno que un mapa tradicional

#### 2. Utilice no más de 50 palabras para describir en lenguaje natural con el máximo detalle el siguiente fotograma 

![image-20221014013002978](/home/clara/.config/Typora/typora-user-images/image-20221014013002978.png)

Para obtener este fotograma, se requiere una representación interna de los personajes, básicamente puntos y líneas. Cada una de las capas mostradas se basa en esa representación interna; pero con cada capa, la forma en que los puntos y líneas se generan, unen e interactúan se vuelve más compleja.

#### 3. Cuando ve una película de animación en el cine, ¿en qué se fija, en el guión o en los efectos más o menos realistas? ¿Recuerda el movimiento del pelo de “Sulley” en “Monstruos SA”? ¿Y el resbalar de la capa de “Encantador” sobre su caballo al llegar al castillo en “Shrek”? Si no lo recuerda, es buen momento para volver a verlo. 

Hace no mucho se estrenó la película Encanto, que presumía de contar con un elenco con todas las texturas de pelo registradas. La forma en la que cada personaje tiene un pelo que actúa de forma completamente distinta a la de los demás tiene mucho mérito, puede leer más sobre la evolución del pelo en peliculas de animación disney [aquí](https://www.insider.com/encanto-hair-animation-evolution-disney-3d-animated-movies-moana-tangled-2022-4). En esa misma película también se me hace destacable el uso de la arena, que fluía de forma muy realista, y de la luz. 

#### 4. Comparta con los amigos una sesión de cine: “La vida de Pi”. Documéntese y coménteles todos los elementos virtuales utilizados en la producción de la película.

Se decía que esta película era "*unfilmable*", imposible de grabar, por varios motivos. El guión, presupuesto y reparto eran algunos de ellos, pero lo que nos interesa son los efectos visuales: principalmente, el tigre (y otros animales) y el mar.

El mar constituye un pesonaje. El supervisor de efectos especiales recalca como una fotografía o vídeo real del mar agitado es impresionante, pero calmado y de día resulta plano y aburrido. Creándolo en 3D se podía dar vida, ver todos los movimientos y olas que mecían al protagonista. La mayor parte de la película fue grabada en unas piscinas de apenas 6 metros cuadrados, que fueron expandidas en postproducción al interminable mar que vemos . 

El tigre fue animado por el mismo estudio que creó al león Aslan en Las Crónicas de Narnia. Se usaron 4 tigres reales, como referencia, modelos de motion capture e incluso actores en algunas escenas. El hecho de utilizar imágenes reales de los animales en el largometraje fuerza que las escenas generadas por computador deban estar a la par y ser indistinguibles de las reales.

Puede leer más [aquí](https://www.mtv.com/news/xbozjq/life-of-pi-tiger-cgi-or-real) y [aquí](https://ew.com/article/2012/11/23/how-ang-lee-saved-life-of-pi/).

#### 5. Analice ambas definiciones (Carlson93 y Foley90) y comente las diferencias entre ambas. ¿Cuál le parece más acertada? 

La definición de Carlson es más completa, ya que incluye aspectos más allá de simplemente la síntesis. El modelado o creación del objeto son una parte importante, pero no podemos ignorar la manipulación de los objetos creados, o como se comportan bajo distintos parámetros.

#### 6. ¿Qué ventajas tiene el ordenador frente al humano u otros medios técnicos (p.ej. Cámaras) para la generación de imágenes? Lea http://es.gizmodo.com/no-son-fotos-el-75-del-catalogo-de-ikea-esta-generado-1628534358 (consultado 12/09/2022) 

- Generación en masa de imágenes realistas
- Personalización y corrección de cualquier mínimo detalle
- Ahorra costos en fotógrafos, muebles de display, modelos, almacenes, iluminación, trabajadores en las instalaciones... 

Por otro lado, es necesaria una enorme inversión inicial para digitalizar los objetos, así como personal con una formación más extensa y específica en el uso de los programas de modelado.

#### 7. Consulte en la bibliografía y comente la diferencia entre análisis y síntesis de imágenes. Sirva de ayuda la imagen que acompaña el principio del tema.

**Análisis**: tomando un objeto completo, estudiar cada una de las partes que lo conforman, para tener un mejor entendimiento de ello. Pasar del conjunto, a lo específico.

**Síntesis**: tomar muchas partes, e interconectarlas de forma coherente para formar un todo. Pasar de lo específico, al conjunto.

#### 8. Averigüe el origen de las curvas de Bèzier y D'Casteljau. ¿Es casualidad que ambos trabajaran en la industria automovilística? 

No, ambos buscaban una forma de modelar las curvas necesarias para diseñar un coche, las cuales son muy específicas para obtener una figura aerodinámica. 

Bézier trabajaba para Renault, y Casteljau trabajaba para Citroën. Aunque Casteljau llegó a la solución antes, no registró su trabajo y fue Bézier quién puso nombre a la curva. Se dice que, a modo de reconocimiento a Casteljau, se puso su nombre al algoritmo que calcula polinomios de las curvas de Bézier.

Puede leer más [aquí](https://medium.com/@wicar/b%C3%A9zier-curve-history-of-product-surfaces-1c4c8d08b98c).

#### 9. Documente al menos otros diez hitos de la Informática Gráfica a partir de 1970, al estilo de los indicados anteriormente.

1968- Primer display montado a la cabeza, creando la primera instancia de realidad virtual

1972- Tomografía computerizada TAC

1975- Modelado de la tetera de Utah

1977- Salida del Apple II, primer PC con gráficos a color incorporados

1982- Estreno Tron, primera película Disney con uso intensivo de gráficos 3d

1985- Cortometrajes enteramente en 3D de Pixar *Luxo Jr.* y *Tin Toy*

1985- Salida de la Nintendo Entertainment System, NES

1993- Salida de Doom, uno de los videojuegos más relevantes de la historia

1995- Estreno Toy Story, primer largometraje generado enteramente por ordenador

2009- Estreno Avatar, primer largometraje realista con performance capture y mundo realista completamente generado por ordenador

#### 10. Enumere las diferencias que hay entre modelar un edificio y digitalizarlo en 3D 

**Modelar**: partiendo de un lienzo en blanco y una serie de datos, crear una representación virtual del edificio que se corresponda con los parámetros dados. Construirlo desde 0 a partir de una representación lógica, como pueden ser sus medidas en metros.

**Digitalizar**: partiendo de un edificio existente, mediante tecnología rangetracing generar un objeto virtual que se corresponde con el real. A partir de un objeto existente, generar una representación lógica.

#### 11. En su opinión ¿es correcto, como hace Shirley, considerar la Realidad Virtual una disciplina independiente? 

En parte. Creo que es una disciplina que  pertenece al campo de la computación gráfica, ya que trata de la interacción entre el humano y el objeto virtual de forma más natural. Pero entiendo que se excluya, debido a que las dificultades que la diferencian del modelaje, animación... se basan en el modo de visualización de esta, en el realismo de su interacción... y no en que su representación lógica sea distinta a la de un modelo de no-VR.

#### 12. ¿Por qué cree he extraído de la lista original del libro [Shirley09] las disciplinas “procesamiento de imágenes” y “fotografía computacional”?

Porque ambas consisten en la modificación de imágenes (sean reales o generadas por ordenador), no en la creación de las mismas.

#### 13. ¿A qué aplicación de la IG de las anteriores pertenece cada una de las siguientes ilustraciones?

![image-20221014015659536](/home/clara/.config/Typora/typora-user-images/image-20221014015659536.png)

Videojuegos



![image-20221014015719803](/home/clara/.config/Typora/typora-user-images/image-20221014015719803.png)

Modelado y visualización en ingeniería y arquitectura



![image-20221014015726562](/home/clara/.config/Typora/typora-user-images/image-20221014015726562.png)

Videojuegos, arte digital, producción de animaciones y efectos especiales para cine y televisión



![image-20221014015739647](/home/clara/.config/Typora/typora-user-images/image-20221014015739647.png)

Visualización de datos



![image-20221014015746036](/home/clara/.config/Typora/typora-user-images/image-20221014015746036.png)

Visualización científica y médica

![image-20221014015801979](/home/clara/.config/Typora/typora-user-images/image-20221014015801979.png)

Simuladores y juegos serios para entrenamiento y aprendizaje, visualización científica y médica



![image-20221014015809770](/home/clara/.config/Typora/typora-user-images/image-20221014015809770.png)

Visualización de datos, visualización científica y médica



![image-20221014015834797](/home/clara/.config/Typora/typora-user-images/image-20221014015834797.png)

Visualización de datos, visualización científica y médica

![image-20221014015840458](/home/clara/.config/Typora/typora-user-images/image-20221014015840458.png)

Simuladores y juegos serios para entrenamiento y aprendizaje



![image-20221014015847624](/home/clara/.config/Typora/typora-user-images/image-20221014015847624.png)

Patrimonio Cultural

#### 14. Observe la escena que tiene ahora mismo en la sala donde se encuentra. Intente describir el proceso mediante el cual se forma la imagen en su retina. 

En la sala hay objetos formados por átomos, cada uno con distintas características a nivel molecular. Estas características determinan la forma en la que la luz pura rebota en los átomos, es decir, el color, brillo, transparencias...

La luz que rebota en estos objetos (es decir, la que no es absorbida) es captada por mis ojos gracias al hecho de que, por ejemplo, el aire no es chapapote. La luz recibida es procesada por mi cerebro que, junto al conocimiento contextual obtenido tras 22 años en la tierra, logra interpretar correctamente (casi siempre) como objetos y estructuras conocidas.

#### 15. ¿Conoce el mecanismo de funcionamiento de una cámara de fotos simple, denominado pinhole? Si no es así, búsquelo e intente establecer la analogía con el ejercicio anterior.

Una cámara *pinhole* consiste en una caja oscura con una pequeña apertura en un lateral. La luz entra en la apertura y proyecta una imagen invertida dentro de la cámara oscura.

La parte análoga es la forma en la que el ojo recibe la luz: la pupila es la apertura, y la luz se proyecta invertida dentro del globo ocular.

#### 16. Escriba la función de dibujado para pintar un pentágono regular con los vértices en verde, las líneas rojas y relleno azul. 

```c
void pentagono(float r){
    const float PI = 2*acos(0.0);
   	const float DEG_TO_RAD = PI/180;
    const float ang_pentagono = 360.0/5.0 * DEG_TO_RAD;

    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(0.0,0.0,1.0); 
    
    glBegin(GL_POLYGON);	
    for(int i=0; i<5; i++){
    	glVertex3f(r*cos(i*ang_pentagono), 0, r*sin(i*ang_pentagono));
    }
    glEnd();	
    
    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(1.0,0.0,.0); 
    
    glBegin(GL_LINE);	
    for(int i=0; i<5; i++){
    	glVertex3f(r*cos(i*ang_pentagono), 0, r*sin(i*ang_pentagono));
    }
    glEnd();	
    
    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(0.0,1.0,.0); 
    
    glBegin(GL_POINTS);	
    for(int i=0; i<5; i++){
    	glVertex3f(r*cos(i*ang_pentagono), 0, r*sin(i*ang_pentagono));
    }
    glEnd();	
}
```



#### 17. ¿Qué cara es la GL_FRONT de un polígono? ¿Es aleatorio?

La cara frontal, la normalmente visible. No, se determina que la cara frontal es la conformada por los vértices dados en sentido antihorario.

#### 18. Documente en sus apuntes cómo se codifican los colores en formato RGB entero y real. ¿Qué formato ofrece una mayor riqueza de colores? 

El formato RGB con enteros consiste en tres campos del 0 al 255 que determinan la cantidad de R, G, B. El formato real consta de los mismos campos y planteamiento, pero va del 0 al 1. El modo real puede almacenar mucho más que 255 grados de intensidad en cada campo porque, a nivel matemático, entre dos números hay infinitos decimales. Así que el real es superior.

#### 19. ¿Es correcto un color RGBA(423, 123, 121, 0)? 

No, dado que el formato RGBA de enteros sólo acepta números hasta el 255.

#### 20. ¿Es correcto un color RGBA(2.3, 0.123, 0.121, 1.0)? 

Técnicamente sí, pero el campo correspondiente al rojo tiene valor 2.3, cuando el límite es 1.0 - Compilará y se ejecutará correctamente, pero 2.3 satura a 1.0

#### 21. Escribe una nueva versión de FGE_CambioTamano para que el viewport sea siempre cuadrado, ocupando el cuadrado más grande posible dentro de la ventana, y centrado con respecto a esta. 

```c
void FGE_CambioTamano(int nuevoAncho, int nuevoAlto) { 
    if(nuevoAncho <= nuevoAlto)
        glViewport(0,0,nuevoAncho,nuevoAncho); 
    else
        glViewport(0,0, nuevoAlto, nuevoAlto); 
}
```



#### 22. La función glClear ¿limpia sólo el viewport o todo el framebuffer?

Todo el framebuffer.

#### 23. Escribe una función de dibujado que muestre el viewport cuadrado del ejercicio 25 en blanco y el resto de la ventana en gris.

```c
void FGE_CambioTamano(int nuevoAncho, int nuevoAlto) {
    if(nuevoAncho <= nuevoAlto)
        glViewport(0,0,nuevoAncho,nuevoAncho); 
    else
        glViewport(0,0, nuevoAlto, nuevoAlto); 
}
```

