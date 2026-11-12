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
g++ -std=c++17 -Wall -Wextra -I../clases -I../primitivas main.cpp SistemaBicicletas.cpp ../primitivas/ABB.cpp ../primitivas/nodoArbol.cpp ../clases/bicicleta.cpp -o sistema_bicis
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

* **Módulo A - Gestión de Estaciones:**
* **Módulo B - Viajes y Colas de Espera:**
* **Módulo C - Registro de Bicicletas (ABB):** Almacenamiento de todas las bicicletas de la red en un Árbol Binario de Búsqueda ordenado por `bici_id`. Soporta inserción, búsqueda, listado ordenado (`inOrder`), conteo de bicicletas averiadas, cálculo de altura, eliminación de nodos (hoja, un hijo y dos hijos) y liberación completa de memoria (`postOrder`).
* **Módulo D - Redistribución con Backtracking:**

---

## Respuestas a las consignas de análisis

### Módulo A: Tabla de Hash
* **Función hash utilizada:** *[Completar]*
* **Cantidad de colisiones con los datos de prueba:** *[Completar]*
* **Factor de carga final:** *[Completar]*

### Módulo B: Complejidad y elección de estructuras
1. **Viajes desde una estación en un rango de fechas:**
   * *Complejidad:* *[Completar en notación Big O]*
   * *Justificación:* *[Completar]*
2. **Viajes y minutos pedaleados por DNI:**
   * *Complejidad:* *[Completar en notación Big O]*
   * *Justificación:* *[Completar]*
3. **Bicicletas con más de X kilómetros:**
   * *Complejidad:* O(n) (recorrido completo del ABB de n bicicletas).
   * *Justificación:* Como el árbol está indexado por `bici_id` y no por kilometraje, es necesario visitar todos los nodos del ABB para verificar qué bicicletas superan el umbral ingresado.
4. **Cola de espera por estación:**
   * *Complejidad:* O(1) para encolar y desencolar.
   * *Justificación:* Se eligió una cola (FIFO) porque respeta estrictamente el orden de llegada de los usuarios cuando no hay bicicletas disponibles, garantizando operaciones en tiempo constante en ambos extremos.
5. **Cola de prioridad (Min-Heap) para el taller:**
   * *Complejidad:* O(\log n) para insertar y O(\log n) para extraer la bicicleta más urgente.
   * *Justificación:* El Min-Heap permite mantener siempre en la raíz la bicicleta con mayor urgencia (prioridad 1, incluyendo las eléctricas) sin necesidad de reordenar toda la colección en cada inserción o extracción.

### Módulo C: Árbol Binario de Búsqueda (ABB)
* **¿Qué altura tendría el árbol si las bicicletas se cargaran ordenadas por ID? ¿Cómo afecta eso al costo de la búsqueda? (Ejemplo con 5 bicicletas):**
  * Si las bicicletas se insertan ordenadas de forma ascendente (por ejemplo, IDs `101, 102, 103, 104, 105`), cada nuevo nodo se inserta siempre como hijo derecho del anterior, degenerando el ABB en una **lista enlazada**.
  * Para n = 5 bicicletas, la altura del árbol sería h = n - 1 = 4 (tomando la altura de un árbol vacío como -1 y de un único nodo como 0).
  * **Impacto en la búsqueda:** En un ABB balanceado la búsqueda cuesta O(\log n), pero al quedar degenerado en lista, buscar el último elemento (`105`) o uno inexistente obliga a recorrer todos los nodos, degradando la complejidad temporal de la búsqueda al peor caso: **O(n)**.

### Módulo D: Redistribución con Backtracking
* **Complejidad temporal en el peor caso:** *[Completar]*
