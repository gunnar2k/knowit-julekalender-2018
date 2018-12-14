Kopi av oppgaveteksten fra https://julekalender.knowit.no/doors/cjpkscf3xsa370167i1ma50sg

# JULAMSEKVENS

Vi definerer en sekvens der hvert nummer i sekvensen er det minste mulige tallet som er summen av to distinkte tall som har forekommet tidligere i sekvensen på nøyaktig en måte. De to første tallene i sekvensen må være definert.

En sekvens kan for eksempel begynne på (1, 2), der N1 = 1, N2 = 2. Da sier vi at for hver n > 2, defineres Nn som det minste positive heltallet større enn Nn-1 som kan uttrykkes som den distinkte summen av to tall som har forekommet tidligere i sekvensen. Denne summen må være den eneste måten å komme til dette tallet på ved å velge distinkte tall fra tidligere i sekvensen. De ti første tallene i denne sekvensen er da:

1:
2:
3: (1+2)
4: (1+3)
6: (2+4)
8: (2+6)
11: (3+8)
13: (11+2)
16: (13+3)
18: (16+2)

De følgende tallene er ikke med i denne sekvensen fordi de ikke er distinkte summer:

5: (2+3, 4+1)
7: (4+3, 6+1)
9: (8+1, 6+3)
10: (2+8, 6+4)
12: (8+4, 11+1)
14: (11+3, 13+1)
15: (13+2, 4+11)
17: (11+6, 13+4)

Hva er summen av de hundre første primtallene i en slik sekvens som begynner med verdiene N1=1 og N2=3?
