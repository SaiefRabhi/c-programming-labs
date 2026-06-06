# Aufgabe 4 – Fehlersuche (Debugging)

## Beschreibung

Diese Aufgabe bestand darin, Fehler in einem C-Programm zur Überprüfung von Kreditkartennummern (Luhn-Algorithmus) zu finden, zu analysieren und zu korrigieren.

---

## Fehleranalyse

### 1. Fehler

**Fehler:**

```c
if (i%2 = 0)
```

**Korrektur:**

```c
if (i % 2 == 0)
```

**Fehlertyp:** Syntaxfehler

**Interpretation:** Das Zuweisungszeichen (=) wurde anstelle des Vergleichsoperators (==) verwendet.

---

### 2. Fehler

**Fehler:**

```c
is_valid = (sum % 10) == 0
```

**Korrektur:**

```c
is_valid = (sum % 10) == 0;
```

**Fehlertyp:** Syntaxfehler

**Interpretation:** Das Semikolon am Ende der Anweisung fehlt.

---

### 3. Fehler

**Fehler:**

```c
if (!validate(argv[1])
```

**Korrektur:**

```c
if (!validate(argv[1]))
```

**Fehlertyp:** Syntaxfehler

**Interpretation:** Eine schließende Klammer fehlt.

---

### 4. Fehler

**Fehler:**

```c
void validate(int *digits)
```

**Korrektur:**

```c
int validate(char *digits)
```

**Fehlertyp:** Semantikfehler

**Interpretation:** Die Funktion muss einen Rückgabewert vom Typ int liefern und einen Zeichenkettenzeiger als Parameter erhalten.

---

### 5. Fehler

**Fehler:**

```c
for (i = 0; i < 16; i++)
    if (i % 2 == 0)
```

**Korrektur:**

```c
for (i = 15; i >= 0; i--)
    if (!(i % 2 == 0))
```

**Fehlertyp:** Logischer Fehler

**Interpretation:** Die Iteration muss von rechts nach links erfolgen, damit der Luhn-Algorithmus korrekt arbeitet.

---

### 6. Fehler

**Fehler:**

```c
return is_valid
```

**Korrektur:**

```c
return is_valid;
```

**Fehlertyp:** Syntaxfehler

**Interpretation:** Das Semikolon fehlt.

---

### 7. Fehler

**Fehler:**

```c
if (digit >= 9)
```

**Korrektur:**

```c
if (digit >= 10)
```

**Fehlertyp:** Logischer Fehler

**Interpretation:** Laut Algorithmus wird erst ab einem Wert von 10 die Zahl 9 subtrahiert.

---

### 8. Fehler

**Fehler:**

```c
int sum;
```

**Korrektur:**

```c
int sum = 0;
```

**Fehlertyp:** Logischer Fehler

**Interpretation:** Die Variable muss initialisiert werden, damit die Berechnung korrekt startet.

---

### 9. Fehler

**Fehler:**

```c
retrun(0);
```

**Korrektur:**

```c
return(0);
```

**Fehlertyp:** Lexikalischer Fehler

**Interpretation:** Tippfehler im Schlüsselwort return.

---

# Korrigierter Quelltext

```c
#include <stdio.h>
#include <string.h>

int validate(char *digits)
{
    int i;
    int sum = 0;
    int is_valid;

    for (i = 15; i >= 0; i--)
    {
        int digit = digits[i] - '0';

        if (!(i % 2 == 0))
        {
            sum += digit;
        }
        else
        {
            digit *= 2;

            if (digit >= 10)
                digit -= 9;

            sum += digit;
        }
    }

    is_valid = (sum % 10) == 0;
    return is_valid;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: csum <card number>\n");
        return 1;
    }

    if (strlen(argv[1]) != 16)
    {
        printf("Only 16-digit card numbers are supported\n");
        return 1;
    }

    if (!validate(argv[1]))
    {
        printf("Checksum error\n");
        return 2;
    }

    return 0;
}
```

---

# Zusatzaufgabe

## Gewicht des Buches

Das Buch „C Programmierung“ von Jürgen Wolf wiegt ungefähr **705 Gramm**.

## Implizite Datentypumwandlung

Jürgen Wolf erklärt, dass die implizite Datentypumwandlung automatisch durch den Compiler erfolgt und im Quelltext nicht sichtbar ist. Dabei können Informationen verloren gehen, beispielsweise Nachkommastellen bei der Umwandlung von Gleitkommazahlen in Ganzzahlen. In solchen Fällen empfiehlt sich die explizite Datentypumwandlung, bei der die Umwandlung bewusst vom Programmierer vorgenommen wird.
