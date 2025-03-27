Użytkowanie:

1. Umieść swój program w pliku szy.cpp

2. Skompiluj swoje rozwiązanie korzystając z:

./compile.sh 0  // kompiluje twoje rozwiązanie do pliku szy.e

lub

./compile.sh 1  // kompiluje twoje rozwiązanie do pliku szy.e
                z flagą DEBUG: program wykonywalny poza
                odpowiedzią będzie wypisywał przydatne zmienne diagnostyczne

3. Wykonaj swoje rozwiązanie na odpowiednim teście np.

./szy.e < in/szy0a.in

Takie uruchomienie powinno wypisać jeden z werdyktów:
ERROR ANSWER_ERROR_CODE kod_bledu
ERROR some_other_error (dalej opis błędu)
ANSWER L

Sprawdzarka oczekuje testów w formacie:
Q
X_1 Y_1 N_1 S_1
X_2 Y_2 N_2 S_2
...
...
...
X_Q Y_Q N_Q S_Q
