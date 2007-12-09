; Svensk standardmall f�r rapporter fr�n Turquoise SuperStat
; � 2002-2007 Peter Karlsson
;
; Rader som inleds med semikolon (som denna) kommer att ignoreras. F�r att
; skriva en rad med inledande semikolon i den f�rdiga rapporten inleder
; du raden med tv� semikolon (;;). Tomma rader i mallen skapar tomma rader
; i utdata.
;
; Ett avslutande omv�nt snedstreck (\) betyder att raden inte kommer att
; avslutas med en radbrytning. F�r att skriva ett avslutande omv�nt
; snedstreck avslutar du raden med tv� omv�nda snedstreck (\\).
;
; Variabler l�ggs in p� formen @nyckelord@. F�r att l�gga in ett ensamt @
; skriver du tv� snabel-a:n (@@).
;
; Filen l�ses sekventiellt.
;
; Alla rader som inleds med variabeln @place@ skapar en topplista, d�r radens
; m�nster repeteras. Variablerna som beror p� platsen i topplistan f�r sina
; v�rden av @place@-variabeln.
;
; F�rst kommer st�d f�r �vers�ttning. Denna sektion genererar ingen utdata,
; ist�llet anv�nds dess inneh�ll f�r att konfigurera utdatamotorn.
[Localization]
; Namn p� veckodagar
Mon=M�ndag
Tue=Tisdag
Wed=Onsdag
Thu=Torsdag
Fri=Fredag
Sat=L�rdag
Sun=S�ndag
; Sedan kommer huvudet
[Common]
Turquoise SuperStat @version@ * Statistik f�r meddelandearea
======================================================

@copyright@

;
; Vad som skall g�ras om meddelandearean �r tom. Rapportmotorn avslutar
; efter [IfEmpty]-sektionen eller den f�rsta icke-[Common]-sektionen.
[IfEmpty]
Meddelandearean �r tom.
;
; Om den inte �r tom forts�tter vi.
; @ifareas@ g�r att raden endast tas med om mer �n en meddelandearea eller
; diskussionsgrupp l�stes in.
[IfNews]
Rapporten t�cker @written@ messages \
@ifareas@i @totalareas@ grupper, \
[IfNotNews]
Rapporten t�cker @written@ messages \
@ifareas@i @totalareas@ m�ten, \
; @ifreceived@ g�r att raden endast tas med om det finns information om
; mottagningsdatum.
[Common]
som \
@ifreceived@togs emot av detta system mellan @earliestreceived@ och @lastreceived@ och \
skrevs mellan @earliestwritten@ och @lastwritten@.

[Quoters]
-----------------------------------------------------------------------------
Citatsvartlista (bland personer som skrivit minst tre meddelanden)

Plats Namn                                                       Texter Kvot
; Tal inom hakparenteser anger f�ltbredd.
@place[5]@ @name[58]@@written[5]@ @ratio[7]@

@bytestotal@ byte skrevs totalt (endast meddelandekroppar), av vilka \
@bytesquoted@, eller @ratio@, var citat.

[Writers]
-----------------------------------------------------------------------------
Skribenttopplista

Plats Namn                                               Texter  Byte  Citat
@place[5]@ @name[50]@@written[5]@ @byteswritten[8]@ @ratio[7]@

[IfNotNews]
@totalpeople@ personer identifierades totalt (s�ndare och mottagare).

[IfNews]
@totalpeople@ personer identifierades totalt.

[Original]
-----------------------------------------------------------------------------
Topplista �ver originalinneh�ll per meddelande (bland personer som skrivit \
minst tre meddelanden)

Plats Namn                                        Orig. / Text = PrTxt Citat
@place[5]@ @name[43]@@bytesoriginal[6]@ /@written[5]@ = @permessage[5]@ @ratio[7]@

[TopNets]
-----------------------------------------------------------------------------
Topplista �ver n�t

Plats   Zon:N�t   Texter      Byte
; Variablen @fidonet@ �r speciell. Bredden anger bredden f�r b�de zon och
; n�t, s� den totala bredden av @fidonet[5] �r 11.
@place[5]@ @fidonet[5]@ @written[8]@ @byteswritten[8]@

Meddelanden fr�n @totalnets@ olika n�t hittades.

[TopDomains]
-----------------------------------------------------------------------------
Topplista �ver toppdom�ner

Plats Dom�n  Texter      Byte
@place[5]@ @topdomain[7]@@written[8]@ @byteswritten[8]@

Meddelanden fr�n @totaldomains@ olika toppdom�ner hittades.

[Received]
-----------------------------------------------------------------------------
Topplista �ver mottagare

Plats Namn                                Mott. S�nt  Kvot
@place[5]@ @name[35]@@received[5]@ @written[5]@ @receiveratio[6]@

[Subjects]
-----------------------------------------------------------------------------
Topplista �ver �renderader

Plats �rende                                                     Texter Byte
@place[5]@ @subject[57]@@written[6]@ @byteswritten[7]@

@totalsubjects@ olika �renderader hittades.

[Programs]
-----------------------------------------------------------------------------
Topplista �ver program

Plats Program                              Texter
@place[5]@ @program[35]@@written[6]@

@totalprograms@ olika program hittades (utan h�nsyn till version).

[Week]
; @place@ inneh�ller dagetikett
-----------------------------------------------------------------------------
Texter per veckodag

Dag        Texter
@place[9]@@written[6]@ @bar[60]@

[Day]
; @place@ inneh�ller timetikett
-----------------------------------------------------------------------------
Texter per timme

Timme      Texter
@place[9]@@written[6]@ @bar[60]@

[Common]
-----------------------------------------------------------------------------
