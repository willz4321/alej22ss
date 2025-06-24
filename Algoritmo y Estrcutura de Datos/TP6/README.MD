Alternamos una carta para J1, otra para J2, hasta agotar el mazo:

para i desde 0 hasta n-1 hacer
    si i es par entonces
        Q1 ← ENFILA(Q1, mazo[i])
    sino
        Q2 ← ENFILA(Q2, mazo[i])

Simular rondas de juego
Mientras ambos tengan cartas, jugamos una ronda:

mientras (¬ESFILAVACIA(Q1) Y ¬ESFILAVACIA(Q2)) hacer
    // 4.1: Colección temporal de cartas en juego
    Fila mesa ← FILAVACIA()

    // 4.2: J1 y J2 dan vuelta una carta
    c1 ← FRENTE(Q1); Q1 ← DEFILA(Q1)
    c2 ← FRENTE(Q2); Q2 ← DEFILA(Q2)
    mesa ← ENFILA(mesa, c1)
    mesa ← ENFILA(mesa, c2)

    // 4.3: Resolver batalla o guerra
    si c1 ≠ c2 entonces
        // victoria directa
        si c1 > c2 entonces
            ganador ← Q1
        sino
            ganador ← Q2
    sino
        // ¡Guerra!  
        mientras (c1 == c2) Y (¬ESFILAVACIA(Q1) Y ¬ESFILAVACIA(Q2)) hacer
            // Cada jugador pone 1 carta “boca abajo”
            x1 ← FRENTE(Q1); Q1 ← DEFILA(Q1); mesa ← ENFILA(mesa, x1)
            x2 ← FRENTE(Q2); Q2 ← DEFILA(Q2); mesa ← ENFILA(mesa, x2)
            // Luego vuelven a “dar vuelta”
            c1 ← FRENTE(Q1); Q1 ← DEFILA(Q1); mesa ← ENFILA(mesa, c1)
            c2 ← FRENTE(Q2); Q2 ← DEFILA(Q2); mesa ← ENFILA(mesa, c2)
        fin mientras

        // Determinar ganador de la guerra (o porque alguien se quedó sin cartas)
        si c1 > c2 entonces
            ganador ← Q1
        sino
            ganador ← Q2
    fin si

    // 4.4: El ganador recoge todas las cartas de la mesa
    mientras ¬ESFILAVACIA(mesa) hacer
        carta ← FRENTE(mesa); mesa ← DEFILA(mesa)
        ganador ← ENFILA(ganador, carta)
    fin mientras

    // Actualizar Q1 o Q2 según quién sea ganador
    si ganador == Q1 entonces
        Q1 ← ganador
    sino
        Q2 ← ganador
    fin si
fin mientras

Devolver el ganador final
Al salir del bucle, uno de los dos tendrá la fila vacía:

si ESFILAVACIA(Q1) entonces
    retorna J2_name
sino
    retorna J1_name

