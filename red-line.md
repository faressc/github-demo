# Versionsverwaltung mit Git / Github

## Einführung

- Eine kurze Demonstration, wie Git und GitHub zur Versionskontrolle in Softwareprojekten mit mehreren Entwicklern verwendet werden.
- Es gibt ein Beispiel-Repository auf GitHub.
- Wir werden es Schritt für Schritt durchgehen und das Repository in einem neuen GitHub-Repository neu erstellen.
- Nehme an, dass alle schon mit Git gearbeitet haben

## Neues Repository erstellen

- Neues Repository auf GitHub erstellen: github-test

```bash
mkdir github-test
cd github-test
# Obere Befehle kopieren
code .
```

## Simples CMake-Projekt erstellen

- CMakeLists.txt erstellen
- cmake_minimum_required, project version from git tag und project configuration bis hin zu add_executable
- main.cpp und AddSubClass.h kopieren
- ggf. vscode neu starten für CMake-Tools
- kurz erklären main und addsubclass
- .gitignore kopieren

```bash
git status
git add .
git commit -m "Added source code"
git tag -a "v0.0.0"
cmake -B build
cmake --build build
./build/main
git push --follow-tags
```

Github repository Seite anschauen.

## First GitHub Action to build and run the project

- Nun möchten wir das dieses Projekt automatisch von GitHub runnern gebuildet und excecutet wird. Auf verschiedenen Betriebssysteme.

```bash
mkdir -p .github/workflows
mkdir -p .github/actions
```

- Setup, build and run action rein kopieren in actions
- build_run.yml rein kopieren in workflows

- Erst build_run.yml erklären
- Dann setup, build and run action erklären

```bash
git add .
git commit -m "Added GitHub Action"
git push
```

Job auf GitHub anschauen und erklären.

## Tests hinzufügen

- Wir möchten nun Tests hinzufügen. Weil um sicher zu gehen, dass das Programm auch das macht, was es soll, reicht es nicht nur es zu bauen und zu starten.
- Optionen WITH_TESTS in CMakeLists.txt hinzufügen
- if(WITH_TESTS) und add_executable(tests test.cpp test.h) hinzufügen
- test.h und test.cpp kopieren
- test.h dann test.cpp erklären

```bash
cmake -B build -DWITH_TESTS=ON
cmake --build build
./build/test
```

- Falschen Test hinzufügen - testen
- Wieder rausnehmen - testen

- test action rein kopieren in actions
- build_test.yml rein kopieren in workflows
- Erst build_test.yml erklären
- Dann test action erklären

```bash
git add .
git commit -m "Added tests"
git push
```

- Workflow test läuft nicht da kein pull request eröffnet wurde

```bash
git checkout -b feature
```

Readme.md bearbeiten

```bash
git add .
git commit -m "Added feature"
git push --set-upstream origin feature
```

- Pull request erstellen und checks anschauen
- Erläutern, dass trotzdem einfach gemerged werden kann

## Main branch schützen

- Settings -> Rules -> Rulesets -> New ruleset -> New branch ruleset:

- Ruleset Name: protect-main
- Enforcement status: Active
- Target branches:
    - Add target
    - Include by pattern: main
- Branch rules:
    - Restrict deletions: Enabled
    - Require a pull request before merging: Enabled
        - Required approvals: 0 but can be changed!
    - Require status checks to pass:
        - Add checks
        - test_result
- Block force pushes: Enabled

- Save changes

- Zeigen das beim pull request jetzt required checks sind

- Wieder zum main branch wechseln

```bash
git checkout main
```

- Änderungen machen am Readme.md

```bash
git add .
git commit -m "Added feature"
git push
```

- Great main branch is protected!
- Delete last commit

```bash
git reset --hard HEAD~1
git checkout feature
```

- Check hinzufügen der fehlschlägt in AddSubClass.h bei add() m_value += b + 1;

```bash
git add .
git commit -m "Break code"
git push
```

- Zeigen, dass wir nicht mergen können
- Das Problem beheben

```bash
git add .
git commit -m "Fixed code"
git push
```

- Pull request mergen
- Branch löschen

```bash
git checkout main
git pull
git branch -d feature
```

## Automatische Releases hinzufügen

- Issue erstellen: Automatic releases would be great
- Selbst zuweisen und label enhancement

- Neuen feature branch erstellen

```bash
git checkout -b feature-install
```

- Option WITH_INSTALL in CMakeLists.txt hinzufügen
- install(TARGETS main) am Ende der CMakeLists.txt hinzufügen

```bash
cmake -B build -DWITH_INSTALL=ON
cmake --build build
cmake --install build
```

- binaries zeigen
- install in actions kopieren
- on_tag.yml in workflows kopieren
- on_tag.yml erklären
- install action erklären

```bash
git add .
git commit -m "Added install step for artifacts"
git push --set-upstream origin feature-install
```

- Pull request erstellen mit Issue referenzieren #2
- Pull request mergen
- Branch löschen
- Zeigen, dass das issue geschlossen ist

```bash
git checkout main
git pull
git branch -d feature-install
```

- Github Actions erlauben releases zu erstellen
- Settings -> Actions -> General -> Workflow permissions -> Read and write permissions

- Release erstellen

```bash
git tag -a "v0.0.1"
git push --follow-tags
```

## Release executen

- Release downloaden und ausführen

```bash
x86_64
./Downloads/github-demo-0.0.1-Linux-x86_64/bin/main
```

## If there is time show badges

## Not covered in this demo

- Secrets
- Code signing on macOS
