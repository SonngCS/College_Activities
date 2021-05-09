Algoritmo "prototipo-atividadepratica"
// Disciplina   : [Algoritmos I]
// Professor   : Ciro Cirne Trindade
// Autor(a)    : Vitor Cordeiro Paes Prieto
// Data atual  : 08/05/2021
Var
   i, n, m, maior1, maior2, indice1, indice2: inteiro
   vet: vetor[0..19] de inteiro
   porcentn1, porcentn2, soma1, soma2: real

Inicio
   soma2 <- 0
   maior2 <- 0
   indice1 <- 1
   indice2 <- 1
   leia(n, m)
   leia(vet[0])
   soma1 <- vet[0]
   maior1 <- vet[0]
   para i de 1 ate ((m*2)-1) faca
      leia(vet[i])
      se i <= m-1 entao
      //meses da primeira dose (0 ate m-1)
         soma1 <- soma1 + vet[i]
         se vet[i] > maior1 entao
            maior1 <- vet[i]
            indice1 <- i+1
         fimse
      senao
      // meses da segunda dose (de m ate (m*2)-1)
         soma2 <- soma2 + vet[i]
         se vet[i] > maior2 entao
            maior2 <- vet[i]
            indice2 <- (i - m)+1
         fimse
      fimse
   fimpara

   porcentn1 <- (soma1*100)/n
   porcentn2 <- (soma2*100)/n

   escreval(porcentn1:2:1)
   escreval(porcentn2:2:1)
   escreval(indice1)
   escreval(indice2)

Fimalgoritmo