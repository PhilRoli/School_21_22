# 2122_4AHBG

## Installation

Download und Installation von gitforwindows (<https://git-for-windows.github.io/>)
Test im Terminal:

```txt
git
```

## Setup

```txt
git config --global user.name "<<<<Roman Schragl>>>>"
git config --global user.email "<<<<roman.schragl@htl-salzburg.ac.at>>>>"" 
```

## Arbeiten

**Aufsetzen:**

- Lokales Repo (Projekt-Verzeichnis) erzeugen und hineingehen:

  ````txt
  cd <<<<projektordner>>>>
  ````

- Remote Repo (von www.gitlab.com) klonen:

  ```txt
  git clone https://gitlab.com/fosy/2122_4ahbg.git ./
  ```

- Eigenen Zweig (Branch) lokal erzeugen und hineinwechseln:

  ```txt
  git branch <<<<SraR>>>>
  git checkout <<<<SraR>>>>
  ```

**Arbeiten:**

- Im Verzeichnis eingefügte oder veränderte Dateien für den Upload im lokalen Repo registrieren (entweder Dateien separat angeben oder .)

  ```txt
  git add <<<<.>>>>
  ```

- Registrierung finalisieren und kommentieren:

  ```txt
  git commit -m "<<<<English explaination>>>>"
  ```

- Upload:

  ```txt
  git push -u origin <<<<SraR>>>>
  ```
