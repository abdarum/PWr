# ANDROID_4
## Content
Application major function is to create Intents and pass arguments between them. 

Features:
* Open different Intent's
  * contactsIntent
  * messagesIntent
  * mapsIntent
  * customIntent
* Sharing data content with Intents's
  * Bundle
  * startActivityForResult(customIntent, 1);

## Screenshots
![](./Readme/view_1.png)
![](./Readme/view_2.png)
<!-- ![](./Readme/default) -->

## Resources
[Labolatory description[PL]](http://marek.piasecki.staff.iiar.pwr.wroc.pl/dydaktyka/pam-asi/laboratorium.html#ANDROID_4)

## Original assignment content



<table style="text-align: left; width: 600px;" border="1" cellpadding="10" cellspacing="0">

  <tbody>
    <tr style="font-family: Arial;">
      <td style="background-color: rgb(204, 204, 204);"><span style="font-weight: bold; color: rgb(0, 102, 0);">Laboratorium (A4)</span>&nbsp;
-&nbsp;
ANDROID -&nbsp; aplikacje złożone z wielu okien/aktywności<span style="font-weight: bold;"></span></td>
    </tr>
    <tr>
      <td>Oprogramuj złożoną wielo-okienkową aplikację, demonstrującą
wykorzystanie obiektów klasy <span style="font-family: Courier New,Courier,monospace;">Intent</span> oraz
metody <span style="font-family: Courier New,Courier,monospace;">startActivity(...)</span>
do uruchamiania własnych oraz wbudowanych aktywności systemu Android
(takich jak: Contacts, PhoneDialer, WebBrowser, GoogleMap). Klikanie
przycisków umieszczonych w głównym oknie/aktywności tego programu
powinno powodować:&nbsp; &nbsp; <br>
      <ol style="list-style-type: lower-alpha;">
        <li>Wyświetlenie listy kontaktów zapisanych w telefonie (a w
wersji zaawansowanej: wybór jednego z kontaktów).<br>
        </li>
        <li>Napisanie wiadomości SMS, której treść oraz odbiorca (numer
telefonu) będą wprowadzane za pomocą dwóch pól <span style="font-family: Courier New,Courier,monospace;">EditText</span>.</li>
        <li>Wyświetlenie mapy (GoogleMap) dla miejsca, którego
współrzędne geograficzne tzn. długość i szerokość geograficzna będą
wprowadzane w polach <span style="font-family: Courier New,Courier,monospace;">EditText</span>.<br>
        </li>
      </ol>
Przykładowe instrukcje takich wywołań <span style="font-weight: bold; font-family: Courier New;">startActivity</span>
można znależć w prezentacji <a href="http://grail.cba.csuohio.edu/~matos/notes/cis-493/lecture-notes/slides/Android-Chapter10-Intents.pdf">Android
Intents</a>
na
stronach nr: 10-26.<br>
      <ol start="4" style="list-style-type: lower-alpha;">
        <li>Ostatni przycisk powinien uruchamiać nową dodatkową
aktywność, w całości napisaną przez studenta, za pomocą metody <span style="font-family: Courier New,Courier,monospace;">startActivityForResult(...)</span>.<br>
Aktywność ta będzie otrzymywać
parametry z okna głównego (a po zakończeniu działania zwracać wynik) w
obiekcie klasy <span style="font-family: Courier New,Courier,monospace;">Bundle</span>.</li>
      </ol>
Wykorzystanie obiektów klasy <span style="font-family: Courier New,Courier,monospace;">Bundle</span> do
przekazywania argumentów jest
omówione w wyżej wymienionej prezentacji na stronach nr 44-48,
a przykładowa aplikacja realizująca funkcjonalność sumowania dwóch
otrzymanych liczb (Example 17), jest zaprezentowana na stronach od 49
do 60.&nbsp;&nbsp; <br>
      <hr style="width: 100%; height: 2px;"><span style="font-weight: bold;">Inne materiały pomocnicze:</span><br>Tutorial na temat Intencji oraz Aktywności w systemie Android (aut. Lars Vogel):<br>
&nbsp; -&nbsp; <a href="http://www.vogella.com/tutorials/AndroidIntent/article.html">Android
Intents - Tutorial<br>
      </a>Rozdziały z podręcznika online "<a href="http://www.techotopia.com/index.php/Android_Studio_Development_Essentials_-_Android_6_Edition">Android
Studio Development Essentials</a> (Techotopia)<br>
&nbsp; - 28 - <a href="http://www.techotopia.com/index.php/An_Overview_of_Android_6_Intents" title="An Overview of Android 6 Intents">An Overview of Android 6
Intents</a><br>
&nbsp; - 29 - <a href="http://www.techotopia.com/index.php/Android_6_Explicit_Intents_%E2%80%93_A_Worked_Example" title="Android 6 Explicit Intents – A Worked Example">Android 6
Explicit Intents</a><br>
&nbsp; - 30 - <a href="http://www.techotopia.com/index.php/Android_6_Implicit_Intents_%E2%80%93_A_Worked_Example" title="Android 6 Implicit Intents – A Worked Example">Android 6
Implicit Intents</a><br>
Zmiany w systemie nadawania uprawnień (od API Level 23 - Android 6.0)<br>
&nbsp; - <a href="http://developer.android.com/training/permissions/requesting.html">Requesting
Permissions at Run Time</a> <br>
      </td>
    </tr>
  </tbody>
</table>



