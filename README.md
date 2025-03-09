# Matrix-operations
Matrix operations
Problem B – Operacje na macierzach
Rozpatrujemy kwadratowe macierze o elementach będących pojedynczymi literami alfabetu
('a'
..
'z'
,
'A'
..
'Z'). Definiujemy następujący zestaw operacji (macierz wejściowa to A, a wyni-
kowa – B, obie o rozmiarach nn):
 T – transpozycja względem głównej przekątnej: Bj, i = Ai, j
 D – transpozycja względem drugiej przekątnej: Bn-j+1, n-i+1 = Ai, j
 H – odbicie poziome (względem osi pionowej): Bi, n-j+1 = Ai, j
 V – odbicie pionowe (względem osi poziomej): Bn-i+1, j = Ai, j
 A – obrót w prawo o 90°: Bj, n-i+1 = Ai, j
 B – obrót w prawo o 180°
 C – obrót w prawo o 270°
 X – obrót w lewo o 90°: Bn-j+1, i = Ai, j
 Y – obrót w lewo o 180°
 Z – obrót w lewo o 270°
dla i, j {1, 2,…, n}
Zadanie
Napisz program, który dla danej macierzy wyjściowej obliczy rezultat złożenia nie więcej niż
100 000 powyższych operacji.
Wejście
Standardowe wejście zawiera zestaw testów. Pierwszy wiersz wejścia zawiera jedną liczbę D
(0 < D < 20) określającą liczbę testów. Kolejne wiersze zawierają dane związane z testami. W
pierwszym wierszu każdego testu występuje zawsze jedna liczba n określająca rozmiary ma-
cierzy (liczba wierszy = liczba kolumn = n; 0 < n ≤ 300; wartości n w kolejnych testach mogą
być różne). Kolejne n wierszy zawiera po n liter (bez odstępów) będących elementami wejścio-
wej macierzy. Ostatni wiersz testu zawiera ciąg operacji do wykonania zapisany przy pomocy
ciągu znaków podanych przy ich definicjach powyżej. Ciąg ten jest zakończony znakiem ’&’
(bez apostrofów). Operacje powinny być wykonane w kolejności od lewej do prawej.
Wyjście
Każdemu testowi powinna odpowiadać w standardowym wyjściu macierz uzyskana w wyniku
wykonania ciągu zadanych operacji. Format wyprowadzonej macierzy powinien być taki sam,
jak w danych wejściowych, tzn. n wierszy po n znaków (bez spacji).
Przykład
Dla danych wejściowych:
2
3
abc
def
ghi
AT&
4
cGhJ
EEEE
aAaA
xYzY
HVX&
prawidłowy wynik to:
ghi
def
abc
xaEc
YAEG
zaEh
YAEJ
