# ANDROID_1
## Content
Application life cycle. 

Handled states:
* onCreate(Bundle savedInstanceState)
* onStart()
* onRestart()
* onPostResume()
* onStop()
* onPause()
* onDestroy()


## Resources
[Labolatory description[PL]](http://marek.piasecki.staff.iiar.pwr.wroc.pl/dydaktyka/pam-asi/laboratorium.html#ANDROID_1)

## Original assignment content


&nbsp;<span style="font-weight: bold;"><a name="ANDROID_1"></a></span>
<table style="text-align: left; width: 600px;" border="1" cellpadding="10" cellspacing="0">

  <tbody>
    <tr style="font-family: Arial;">
      <td style="background-color: rgb(204, 204, 204);"><span style="font-weight: bold; color: rgb(0, 102, 0);">Laboratorium (A1)</span>&nbsp;&nbsp;
-&nbsp; Analiza cyklu życia Aktywności w aplikacji Android.</td>
    </tr>
    <tr>
      <td><span style="font-family: Arial;"><span style="font-weight: bold;"></span></span>Pobierz z Internetu,
rozpakuj, zaimportuj i przetestuj w
środowisku Android Studio przykładową&nbsp; aplikację&nbsp;<a href="http://marek.piasecki.staff.iiar.pwr.wroc.pl/dydaktyka/pam/L02_AND/lifecycle.zip"><span style="font-weight: bold;">LifeCycle</span></a> demo z&nbsp; <a href="http://grail.cba.csuohio.edu/~matos/notes/cis-493/lecture-notes/code/_showFiles_zip.php">archiwum
V. Matosa</a>,<br>
      <span style="font-weight: bold;"> a następnie spróbuj wykonać
własną</span>
wersję takiej aplikacji, która będzie sygnalizować zmiany wewnętrznego
stanu Aktywności, poprzez wyświetlanie powiadomień za pomocą obiektów
klasy Toast:.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <span style="font-family: Courier New,Courier,monospace; color: rgb(0, 153, 0);">Toast.makeText(this,
"onCreate", 1).show();</span><br>
zaimplementuj w ten sposób działanie metod obsługujących wybrane
podstawowe wydarzenia:&nbsp; <span style="font-family: Courier New,Courier,monospace; color: rgb(0, 153, 0);">onCreate</span><span style="color: rgb(0, 153, 0);">, </span><span style="font-family: Courier New,Courier,monospace; color: rgb(0, 153, 0);">onStart</span><span style="color: rgb(0, 153, 0);">, </span><span style="font-family: Courier New,Courier,monospace; color: rgb(0, 153, 0);">onResume</span><span style="color: rgb(0, 153, 0);">, </span><span style="font-family: Courier New,Courier,monospace; color: rgb(0, 153, 0);">onSaveInstanceState</span><span style="color: rgb(0, 153, 0);">, </span><span style="font-family: Courier New,Courier,monospace; color: rgb(0, 153, 0);">onPause</span><span style="color: rgb(0, 153, 0);">, </span><span style="font-family: Courier New,Courier,monospace; color: rgb(0, 153, 0);">onStop</span><span style="color: rgb(0, 153, 0);">, </span><span style="font-family: Courier New,Courier,monospace; color: rgb(0, 153, 0);">onDestroy</span><span style="color: rgb(0, 153, 0);">, </span><span style="font-family: Courier New,Courier,monospace; color: rgb(0, 153, 0);">onRestart</span>.<br>
      <br>
      <span style="font-style: italic; color: rgb(153, 153, 153);">Podpowiedź:</span><br style="font-style: italic; color: rgb(153, 153, 153);">
      <div style="margin-left: 40px; font-style: italic; color: rgb(153, 153, 153);">To
zadanie będzie łatwiejsze gdy wykorzystasz opcję menu<br>
      </div>
      <div style="margin-left: 40px; font-style: italic; color: rgb(153, 153, 153);">&nbsp;&nbsp;&nbsp;
Code &gt; Override Methods…&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (skrót Ctrl+O)<br>
      </div>
      <div style="margin-left: 40px; font-style: italic; color: rgb(153, 153, 153);">dostępną
w środowisku Android Studio.<br>
      </div>
      <br>
Zaobserwuj i zanotuj sekwencje komunikatów Toast wyświetlanych po::<br>
      <ol style="list-style-type: lower-alpha;">
        <li>Kliknięciu programowego przycisku&nbsp;EXIT (w oknie aplikacji)</li>
        <li>Kliknięciu sprzętowego przycisku BACK (na telefonie)
        </li>
        <li>Kliknięciu sprzętowego przycisku HOME&nbsp;(na telefonie)</li>
        <li><span style="color: rgb(153, 153, 153);">Kliknięciu przycisku połączenia telefonicznego (CALL -
zielona słuchawka)</span><br><span style="color: rgb(153, 153, 153);">(uwaga: w starszych telefonach/emulatorach były dodatkowe przyciski Call / Hang-up)</span> </li>
        <li style="color: rgb(153, 153, 153);">Przytrzymaniu przycisku odłożenia słuchawki (HANG-UP
-&nbsp; czerwona słuchawka)</li>
        <li>Otrzymaniu tekstowej wiadomości SMS (z innego emulatora lub
telefonu)<br>
        </li>
        <li>Po otrzymaniu połączenia głosowego (z innego emulatora lub
telefonu).</li>
      </ol>
Za każdym razem wróć do tego samego podstawowego stanu "running",<br>
poprzez otwarcie okna z listą zainstalowanych aplikacji (launch pad),<br>
i przywrócenie/uruchomienie aplikacji, klikając na jej ikonie.<br>
      <br>
Zaobserwowane sekwencje komunikatów opisz i skomentuj, w formie
sprawozdania, w pliku o nazwie:&nbsp; <span style="font-family: Courier New,Courier,monospace; color: rgb(0, 153, 0);">Laboratorium_1.txt</span>&nbsp;
lub&nbsp; <span style="font-family: Courier New,Courier,monospace; color: rgb(0, 153, 0);">Laboratorium_1.pdf</span><br>
      <br>
Materiały/slajdy pomocnicze:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - <a href="http://grail.cba.csuohio.edu/~matos/notes/cis-493/lecture-notes/slides/Android-Chapter03-Life-Cycle.pdf">Android
Application's Life Cycle</a><br>
      <br>
      <span style="font-family: Arial; font-weight: bold;"></span></td>
    </tr>
  </tbody>
</table>



