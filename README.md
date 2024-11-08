# Build / Setup Prozess
Anweisungen ausgelagert in [BUILD_INSTRUCTIONS.md](BUILD_INSTRUCTIONS.md)

# Git Grundlagen / Workflow
Git Spickzettel: https://files.morr.cc/git-spickzettel.png

Guter Schnellstart mit Begriffen und Konzepten ist Kapitel 2 des _pro Git_ Buches: https://git-scm.com/book/de/v2/Git-Grundlagen-Ein-Git-Repository-anlegen

# Musterlösung integrieren (ohne die ganze History wegzuwerfen)
Angepasst von https://medium.com/@topspinj/how-to-git-rebase-into-a-forked-repo-c9f05e821c8a

Das Musterlösungs-Repository als remote mit Namen _upstream_ (oder ähnlich) hinzufügen:

`git remote add upstream gogs@git.cg.cs.tu-bs.de:CG1_WS2122/Base.git` 

Alle Branches von _upstream_ und deren Änderungen herunterladen

`git fetch upstream`

Die Änderungen hineinmergen und Konflikte so auflösen, dass die Musterlösung bevorzugt wird

`git merge -X theirs upstream/master`

bitte beachten: Dies löst nur _Konflikte_ so auf, dass die Änderungen der Musterlösung bevorzugt werden. Wenn ihr andere Dateien hinzugefügt habt, werden diese immer noch nach dem Merge vorhanden sein.
Ebenso verhält es sich, wenn ihr Interfaces von Funktionen geändert oder Änderungen vorgenommen habt, die nicht mit der _upstream_-Version in Konflikt stehen (z.B wenn ihr in Aufgabe 03 etwas an der Schnittpunktberechnung aus Aufgabe 01 ändert, das nicht in Aufgabe 03 angepasst wurde, wird die Änderung nach dem Merge immer noch da sein). 
Deswegen kann so ein Merge immer noch in nicht-kompilierbaren Code resultieren oder Bugs einführen.

Daher ist es _immer_ eine gute Idee, sich noch einmal einen Diff zwischen der aktuellen Version und der Musterlösung zu Gemüte zu führen:

`git diff master upstream/master`

hier kann man dann noch ggf. selbst Hand anlegen und die Änderungen dann wieder auf das eigene Repository schieben:

`git commit -am "Merge solution"`

`git push origin master`

evtl. muss noch `--force` angegeben werden