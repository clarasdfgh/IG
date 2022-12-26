# IG 21/22 - Ejercicios Transformaciones Geométricas

###### Clara María Romero Lara, 3ºD

#### 40. Calcule los nuevos valores de la posición en el espacio del punto [3,0,0] aplicándole las rotaciones del ejercicio anterior, por separado, y además tras las siguientes secuencias: 

- Rx[90] → Ry[-90] → Rz[200] 
- Rz[200] → Ry[-90] → Rx[90] 

##### Para estas secuencias, calcule tras cada rotación el valor temporal del punto y su posición final.



#### 41. Para comprobar la no conmutatividad de las transformaciones geométricas, calcule los nuevos valores de la posición en el espacio del punto p= [3,0,0] aplicándole las siguientes secuencias: 

- P’=(T3•T2•T1 )p 

- P’=(T1•T2•T3)p 

- P’=(T3•T1•T2 )p 

  Siendo

  - T1= Rx[90] 
  - T2= T[-9,4,3] 
  - T3= Rz[45] 

##### Para estas secuencias, calcule tras cada transformación de la composición el valor temporal del punto y su posición final. 



#### 42. Visite https://www.ugr.es/~demiras/cgex/ y realice las secuencias de transformaciones del ejercicio anterior.

#### 43. Visite la web https://www.ugr.es/~demiras/cgex/ y realice las secuencias de transformaciones del ejercicio 45 sobre el modelo, anotando el valor de la matriz resultado en cada momento, tras cada transformación de la secuencia. 



#### 44. Escribe funciones en C para manipulación de transformaciones y para aplica transformaciones a tuplas de 3 reales. 

- Componer( Transformacion *res, Transformacion *m1, Transformacion *m2 ) Compone dos matrices de transformación m1 y m2, y guarda el resultado en res 
- Aplicar( Real res[4], Transformacion *m, Real coo[4] ) Aplica la matriz de transformación m a la tupla de 4 reales coo, y almacena e resultado en res. 
- Rotacion( Transformacion *res, Real a, Real ex, Real ey, Real ez ) Crea una matriz de rotación de a grados entorno al eje definido por (ex, ey, ez) Escribe la matriz resultado en res. 
- Traslacion( Transformacion *res, Real dx, Real dy, Real dz ) Escribe en res la matriz de traslación asociada al vector de desplazamiento (dx, dy, dz). 
- Escalado( Transformacion *res, Real sx, Real sy, Real sz ) Escribe en res la matriz de escalado con factores de escala sx,sy y sz. Siendo typedef Real Transformacion\[4][4];



#### 45. Escribe una función en OpenGL, llamada gancho para dibujar con OpenGL la figura: Cada segmento recto tiene longitud unidad, y el extremo inferior está en el origen. 

![image-20221019020527699](/home/clara/.config/Typora/typora-user-images/image-20221019020527699.png)

#### 46. Usando exclusivamente la función gancho del problema anterior, construye otra función gancho_x4 para dibujar el polígono que aparece en la figura: Hay que tener en cuenta que la figura se puede obtener exclusivamente usando rotaciones de la original, pero en esas rotaciones el centro no es el origen.

![image-20221019020533450](/home/clara/.config/Typora/typora-user-images/image-20221019020533450.png)

#### 47. Documente en sus apuntes: ¿Cómo se hace una rotación con respecto a cualquier punto? 



#### 48. Escribe el pseudocódigo OpenGL otra función gancho_2p para dibujar la figura delejercicio 52, pero escalada y rotada de forma que sus extremos coincidan con dos puntos arbitrarios p0 = (x0, y0) y p1 = (x1, y1), que se pasan como parámetro a dicha función.