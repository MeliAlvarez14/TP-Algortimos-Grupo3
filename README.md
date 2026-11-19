# Sistema de Bicicletas Públicas - UNAHUR (Grupo 3)

Trabajo Práctico de la materia **Algoritmos**. Implementación en C++ orientada a objetos utilizando memoria dinámica y estructuras de datos desarrolladas desde cero (sin contenedores de la STL para las estructuras principales).

---

## Compilación y ejecución

1. Abrir una terminal en la raíz del proyecto y entrar a la carpeta `sistema`:
```bash
cd sistema
```

2. Compilar el proyecto (sin warnings, bajo el estándar C++17):
```bash
g++ -std=c++17 -Wall -Wextra -I../clases -I../primitivas main.cpp SistemaBicicletas.cpp ../primitivas/ABB.cpp ../primitivas/NodoArbol.cpp ../clases/Bicicleta.cpp ../clases/Estacion.cpp ../primitivas/Cola.cpp ../clases/Viaje.cpp ../primitivas/NodoCola.cpp ../clases/TallerHeap.cpp -o sistema_bicis
```
*(Nota: cuando se vayan integrando los demás módulos agregar sus `.cpp` al comando de compilación).*

3. Ejecutar el menú interactivo por consola:
* **En Linux / Mac / Git Bash:**
  ```bash
  ./sistema_bicis
  ```
* **En Windows (PowerShell / CMD):**
  ```powershell
  ./sistema_bicis.exe
  ```

---

## Descripción de módulos

* **Módulo A - Gestión de Estaciones:** Administración de las estaciones de bicicletas y las conexiones (ciclovías) entre ellas. Soporta búsqueda por código de la estación, alta y baja de estaciones, listado de estaciones según dos criterios a elección del usuario (capacidad total de anclajes o cantidad de bicicletas disponibles), listado de estaciones con baja ocupación y ruta óptima entre dos estaciones.
* **Módulo B - Viajes y Colas de Espera:**
* **Módulo C - Registro de Bicicletas (ABB):** Almacenamiento de todas las bicicletas de la red en un Árbol Binario de Búsqueda ordenado por `bici_id`. Soporta inserción, búsqueda, listado ordenado (`inOrder`), conteo de bicicletas averiadas, cálculo de altura, eliminación de nodos (hoja, un hijo y dos hijos) y liberación completa de memoria (`postOrder`).
* **Módulo D - Redistribución con Backtracking:** Resolución del problema de reparto mediante backtracking. Dada la capacidad `C` de un camión y una lista de estaciones con sus bicicletas faltantes, determina e informa todas las combinaciones de estaciones cuyos faltantes suman exactamente `C`, utilizando podas por exceso de capacidad para optimizar la búsqueda.

---

## Respuestas a las consignas de análisis

### Módulo A: Tabla de Hash
* **Función hash utilizada:** Hash polinómico de cadenas (multiplicando los códigos ASCII por 128), combinada con la función módulo sobre una capacidad inicial prima (101).
* **Capacidad de la tabla:** 101 posiciones (*buckets*).
* **Cantidad de colisiones con los datos de prueba:** 0 colisiones.
* **Factor de carga final:**
  * Con datos de prueba reales (3 estaciones): 0.03
  * Proyección de diseño estimada (80 estaciones): 0.79

### Módulo B: Complejidad y elección de estructuras
1. **Viajes desde una estación en un rango de fechas:**
   * **Complejidad:** O(N), donde N es la cantidad total de viajes registrados en el sistema.
   * **Justificación:** Para almacenar el historial completo de viajes se eligió una lista enlazada simple (Nodo<Viaje>) implementada manualmente (no creamos una estructura generalizada en su propio archivo), permitiendo inserciones en O(1) al leer el archivo. Ya que la consulta requiere filtrar simultáneamente por estación de origen y un intervalo de fechas, es necesario recorrer secuencialmente todos los nodos de la lista para evaluar cada registro.
2. **Viajes y minutos pedaleados por DNI:**
   * **Complejidad:** O(N), donde N es la cantidad total de viajes registrados
   * **Justificación:** Se reutilizó la misma lista enlazada simple (Nodo<Viaje>). Como un mismo usuario puede haber realizado múltiples viajes en distintos momentos, recorrer la lista de principio a fin garantiza encontrar todas sus apariciones y acumular la duración en minutos de forma lineal.
3. **Bicicletas con más de X kilómetros:**
   * **Complejidad:** O(N) donde N es la cantidad total de bicicletas registradas en el árbol.
   * **Justificación:** Se utilizó el Árbol Binario de Búsqueda (ABB) existente donde ya residen todas las bicicletas de la red ordenadas por su identificador (bici_id). Debido a que el árbol está indexado por ID y no por kilometraje, un recorrido en profundidad (In-Order) visita cada nodo exactamente una vez en tiempo lineal respecto al tamaño del árbol para filtrar aquellas que superan el kilometraje ingresado.
4. **Cola de espera por estación:**
   * **Complejidad:** O(1) tanto para encolar un usuario en espera, como para asignarle una bicicleta al primero de la fila cuando se produce una devolución (desencolar).
   * **Justificación:** Se implementó una clase Cola dado que esta estructura (FIFO - First In, First Out) es la ideal para gestionar filas de espera, porque garantiza que el primer usuario en anotarse sea el primero en recibir una bicicleta al producirse una devolución, resolviendo ambas operaciones en tiempo constante estricto O(1).
5. **Cola de prioridad (Min-Heap) para el taller:**
   * **Complejidad:** O(log N) tanto para insertar como para extraer la bicicleta más urgente.
   * **Justificación:** Se implementó un Min-Heap sobre un arreglo dinámico porque permite mantener ordenados los elementos según su nivel de urgencia (1 máxima prioridad y las eléctricas tienen prioridad absoluta). Con el Heap se logra equilibrar el costo de inserción y extracción en tiempo logarítmico mediante los algoritmos de flotar.

### Módulo C: Árbol Binario de Búsqueda (ABB)
* **¿Qué altura tendría el árbol si las bicicletas se cargaran ordenadas por ID? ¿Cómo afecta eso al costo de la búsqueda? (Ejemplo con 5 bicicletas):**
  * Si las bicicletas se insertan ordenadas de forma ascendente (por ejemplo, IDs `101, 102, 103, 104, 105`), cada nuevo nodo se inserta siempre como hijo derecho del anterior, degenerando el ABB en una **lista enlazada**.
  * Para n = 5 bicicletas, la altura del árbol sería h = n - 1 = 4 (tomando la altura de un árbol vacío como -1 y de un único nodo como 0).
  * **Impacto en la búsqueda:** En un ABB balanceado la búsqueda cuesta O(\log n), pero al quedar degenerado en lista, buscar el último elemento (`105`) o uno inexistente obliga a recorrer todos los nodos, degradando la complejidad temporal de la búsqueda al peor caso: **O(n)**.

### Módulo D: Redistribución con Backtracking
* **Complejidad temporal en el peor caso:** `O(n · 2ⁿ)`, donde `n` es la cantidad de estaciones candidatas recibidas como entrada.
    * **Búsqueda (O(2ⁿ))** Para cada una de las `n` estaciones, el algoritmo toma una decisión binaria (incluir la estación en el recorrido del camión o descartarla). Esto genera un árbol binario de profundidad máxima `n`, el cual posee `2ⁿ` nodos hoja y 2<sup>n+1</sup> - 1 nodos en total. En el peor caso —por ejemplo, cuando la capacidad `C` es igual o mayor a la suma total de todos los faltantes—, las podas por exceso de capacidad (suma_actual + faltante <= C) no logran descartar ramas de forma temprana y se recorre el árbol completo.
    * **Solución (O(n))**: Cada vez que se alcanza una combinación válida (suma_actual == C), se recorre e imprime el arreglo auxiliar actual con las estaciones seleccionadas. Dado que un subconjunto puede contener como máximo `n` estaciones, esta operación tiene un costo lineal de `O(n)`.
    * **Conclusión**: Multiplicando la cantidad máxima de combinaciones posibles en las hojas (`2ⁿ`) por el costo de procesar e imprimir cada subconjunto válido (`O(n)`), la complejidad temporal resultante en el peor caso es `O(n · 2ⁿ)`.


## Integrantes👩‍💻👩‍💻👨‍💻
- Marquez Alina
- Alvarez Melina
- Gonzalez Cristian
