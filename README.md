# README Lan Party

Acesta este un fișier README pentru codul care implementează un LanParty. Codul e scris în limbajul C și utilizează mai multe fișiere header pentru a implementa diferite structuri de date și funcții auxiliare.
##  Descriere cod

Codul constă în funcția main și utilizează fișierele header "arbori.h", "cozi_stive.h" și "liste.h". Iată o prezentare succintă a funcționalității codului:
1.  Manipularea fișierelor: Codul deschide trei fișiere (c.in, d.in și r.out) pentru citire și scriere de date.
2.  Citirea inputului: Codul citește valori întregi din fișierul c.in, le aduna, iar suma lor reprezinta cerintele pe care codul le abordeaza.
3.  Crearea și manipularea unei liste înlănțuite: Codul definește o structură numită Node ce contine informatii despre fiecare echipa. Se creează o listă înlănțuită utilizând structura Node. Se citește input din fișierul d.in și se adaugă echipe în lista înlănțuită. [Task 1]
4.  Calcularea scorurilor și eliminarea echipelor: Codul calculează scorurile pentru echipele din lista înlănțuită și elimină echipele pana ajung sa la cea mai mare putere a lui 2 [Task2]
5.  Operații pe coadă: Codul definește o structură numită Queue și realizeaza la fiecare element al cozii meciul intre 2 echipe.
6.  Runde de eliminare a echipelor: Codul efectuează o serie de runde de eliminare pentru echipe utilizând coada. Câștigătorii fiecărei runde sunt adăugați într-o stivă numită 'qualified', iar echipele eliminate sunt adăugate într-o stivă numită 'eliminated', urmand ca cei salvati in 'qualified' sa fie readaugati in coada pentru urmatoarea runda.Primlele 8 echipe sunt memorate intr-o noua lista inlantuita (top8)[Task 3]
7.  Operații pe arbore binar de căutare: Codul definește o structură numită NodArb cu ajutorul careia se va realiza un arbore BTS prin care se afiseaza clasamentul  clasamentul primelor 8 echipe in ordine descrescatoare [Task4]
8.  Sortare și operații pe arbore AVL: Codul sortează lista înlănțuită (top8) și creează un arbore AVL folosind lista sortată. Apoi, este afișat nivelul 2 al arborelui AVL in ordine descrescatoare [Task 5]

## Contact

For any inquiries or questions, please contact the author of this code.

Author: [Voicu Gabriel]
Email: [voicu.gabriel2601@gmail.com]
Github:[github.com/GabGVB]
# Checker
Checker-ul este o aplicație de testare automată a temelor. Este un produs open-source realizat de către și pentru studenții din Facultatea de Automatică și Calculatoare - UPB, și este menit atât să usureze munca asistenților de a corecta teme cât și sa ofere studenților o evaluare cât mai obiectivă.

## Rularea checker-ului
Pentru a verifica functionarea checker-ului va trebui sa descarcati tot depozitul de mai sus, dupa aceasta deschideti un terminal in folderul in care se afla depozitul descarcat si scrieti urmatoarea comanda:
```shell
./checker.sh
````
