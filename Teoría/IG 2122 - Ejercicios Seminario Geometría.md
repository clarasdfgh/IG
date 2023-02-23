# IG 21/22 - Ejercicios Seminario Geometría

###### Clara María Romero Lara, 3ºD

#### V. Dado el triángulo de la ilustración 5. Si a=5 y b=8, ¿Cuánto vale sin(A)? 

``` 
sin(A) = cateto opuesto / hipotenusa
	hipotenusa = sqrt(5² + 8²)
	cateto opuesto = 5
	
	sin(A) = 5 / sqrt(89) = 0.53 aprox.
```



#### VI. Si la cámara de OpenGL está mirando en el origen hacia el sentido negativo del eje Z, ¿Cuánto tengo que girarla en el eje Y, por el camino más corto, para que mire hacia un objeto situado en el punto...

- (4,0,-2)

```
atg(2/4) = 26.565º, y como es en sentido horario, -26.565º
```



- (-2,0,3)

```
acos(2/3) = 48.19º, le tenemos que sumar 90º para tener en cuenta el segundo cuadrante.

90º + 48.19º = 138.19º
```



- (1,0,0)

```
-90º
```



- (0.1,0,1)

```
atg(0.1/1) = 5.71º, le tenemos que sumar 180º para tener en cuenta los cuadrantes dos y tres. 185.71º

Como nos piden el camino más corto, 360º - 185.71º = 174.29º, que pasa a -174.29º por ser en sentido horario.
```



#### VII. Escribe el código en C que calcule las posiciones de las marcas horarias y de minutos de la esfera de reloj de la Ilustración 1. Queremos que como parámetro la función tenga el diámetro de la esfera. 

![image-20221019021610775](/home/clara/.config/Typora/typora-user-images/image-20221019021610775.png)

```c++
void reloj(float d){
    const float PI = 2*acos(0.0);
   	const float DEG_TO_RAD = PI/180;
    float r = d/2.0;
    float hora_ang = 360.0/12.0 * DEG_TO_RAD;
    float min_ang = 360.0/60.0 * DEG_TO_RAD;
    
    for(int i=0; i<12; i++){
    	horas[i] = glVertex3f(r*cos(i*hora_ang), 0, r*sin(i*hora_ang));
    }
    
    for(int i=0; i<60; i++){
    	minutos[i] = glVertex3f(r*cos(i*min_ang), 0, r*sin(i*min_ang));
    }
}
```



#### VIII. ¿ Es sin(-A) = -sin(A) ?

Sí, es una función impar



#### IX. Dados p≡(3, 5, 2) y q≡(1, 4, 9). Calcular:

- El vector R=p-q 

```
R = (3-1, 5-4, 2-9) = (2,1,-7)
```

- El vector S=q-p

```
s = (1-3, 4-5, 9-2) = (-2,-1,7)
```

- |R| 

```
|R| = sqrt(2² + 1² + (-7)²) = 7.35
```

- El vector normalizado 𝑅⃗

```
𝑅⃗ = (2/|R|, 1/|R|, -7/|R|) = (0.27,0.14,0.95)
```



#### X. Calcula el valor de k sabiendo que el módulo del vector vector V= (k, 3) es 5. 

```
|V| = 	sqrt(k² + 3²) = 5;
		k² + 3² = 5²;
		k² = 25 - 9;
		k = sqrt(16);
		k = 4
```



#### XI. Si vector V es un vector de componentes (3, 4), hallar un vector unitario de su misma dirección y sentido 

```
|V| = sqrt(3² + 4²) = 5

Vunit = (3/5, 4/5) = (0.6, 0.8)
```



#### XII. Calcular el vector W=U+V, si U=(3, −5), V=(1, −1)



#### XIII. Hallar k si el ángulo que forma U= (3, k) con V= (2, −1) vale: 

- 90º 



- 0º 



- -45º 



#### XIV. Dados los vectores U=(2, k) y V= (3, −2), calcula k para que los vectores U y V sean: 

- Perpendiculares 



- Paralelos 



- Formen un ángulo de 60º



#### XV. Hallar el ángulo que forman los vectores U=(1,1,-1) y V=(2,2,21).



#### XVI. Investigue, en incluya en sus apuntes, cómo calcular el área de un triángulo cualquiera haciendo uso del producto vectorial.