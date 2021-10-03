content_source = """
K06-10j	Filozofia	Wykład	Szanowny Panie Doktorze	Dr hab. Jan Wadowski	jan.wadowski@pwr.edu.pl		4,0	
K06-12c	Podstawy programowania	Wykład	Szanowna Pani Doktor	Dr inż. Hanna Stawska	hanna.stawska@pwr.edu.pl	Zajęcia były zreazliowane w inny sposób, ponieważ oprócz 30 godzin wykładu, zajęcia praktyczne były rozbite na 15 godzin ćwiczeń i 15 godzin laboratoriów zamiast 30 godzin laboratoriów w obecnym kursie.	5,0	
K06-16b	Technologie informacyjne	Zajęcia laboratoryjne	Szanowna Pani	Mgr inż. Joanna Marszałek	joanna.marszalek@pwr.edu.pl			
K06-15a	Miernictwo 1	Wykład	Szanowny Panie Doktorze	Dr hab. inż. Paweł Bieńkowski	pawel.bienkowski@pwr.edu.pl		4,0	
K06-11s	Podstawy programowania	Zajęcia laboratoryjne	Szanowny Panie Doktorze	Dr inż. Tomasz Janiczek	tomasz.janiczek@pwr.wroc.pl	Zajęcia były zreazliowane w inny sposób, ponieważ oprócz 30 godzin wykładu, zajęcia praktyczne były rozbite na 15 godzin ćwiczeń i 15 godzin laboratoriów zamiast 30 godzin laboratoriów w obecnym kursie.		
K05-26c	Algebra liniowa z geometrią...	Wykład	Szanowna Pani Doktor	Dr Joanna Jureczko	joanna.jureczko@pwr.edu.pl	Kurs poprzednio był realizowany w zakresie 30 godzin wykładu oraz 15 godzin ćwiczeń oraz posiadał 4 punkty ECTS. Odnoszę jednak wrażenie, że zakres materiału obejmował bardzo podobne zagadnienia.	4,5	Algebra z geometrią analityczną A
K06-13b	Własność intelek. i prawo aut.	Wykład	Szanowna Pani Doktor	Dr Renata Kopczyk	renata.kopczyk@pwr.edu.pl		4,5	
K06-17a	Technologie informacyjne	Wykład	Szanowny Panie Doktorze	Dr Marek Bazan	marek.bazan@pwr.edu.pl		4,5	
K05-25n	Algebra liniowa z geometrią...	Ćwiczenia	Szanowny Panie Doktorze	Dr Jerzy Cisło	jerzy.cislo@pwr.edu.pl	Kurs poprzednio był realizowany w zakresie 30 godzin wykładu oraz 15 godzin ćwiczeń oraz posiadał 4 punkty ECTS. Odnoszę jednak wrażenie, że zakres materiału obejmował bardzo podobne zagadnienia.		Algebra z geometrią analityczną A
K05-23m	Analiza matematyczna 1.2A	Ćwiczenia	Szanowny Panie Doktorze	Dr Jerzy Cisło	jerzy.cislo@pwr.edu.pl	Kurs poprzednio był realizowany w zakresie 30 godzin wykładu oraz 15 godzin ćwiczeń oraz posiadał 8 punkty ECTS. Odnoszę jednak wrażenie, że zakres materiału obejmował bardzo podobne zagadnienia.		Analiza matematyczna 1.2
K05-24c	Analiza matematyczna 1.2A	Wykład	Szanowny Panie Profesorze	Prof. dr hab. Mieczyslaw Wodecki	mieczyslaw.wodecki@pwr.edu.pl	Kurs poprzednio był realizowany w zakresie 30 godzin wykładu oraz 15 godzin ćwiczeń oraz posiadał 8 punkty ECTS. Odnoszę jednak wrażenie, że zakres materiału obejmował bardzo podobne zagadnienia.	3,0	Analiza matematyczna 1.2
K06-14b	Etyka inżynierska	Wykład	Szanowna Pani Doktor	Dr Teresa Marcinów	teresa.marcinow@pwr.edu.pl		4,5	
"""

for line in content_source.split("\n"):
    ret_str = ""
    line_columns = line.split('\t')
    # print(repr(line_columns))

    if len(line_columns)>=8:
        # import variables
        course_code_str = line_columns[0]
        subject_str = line_columns[1]
        form_of_the_course_str = line_columns[2]
        introduction_str = line_columns[3]
        teacher_str = line_columns[4]
        teacher_mail_str = line_columns[5]
        differences_str = line_columns[6]
        mark_str = line_columns[7]
        other_course_name_str = line_columns[8]

        if form_of_the_course_str == 'Wykład':
            ret_str += '\n\n'
            # Email adress
            ret_str += teacher_mail_str + '\n\n\n'

            # Topic of the email
            ret_str += course_code_str + " - Przepis oceny z kursu " + subject_str + ' - Kornel Stefańczyk\n\n\n'

            # Content below
            ret_str += introduction_str + ',\n\n'
            ret_str += "Proszę o przepisanie oceny z kursu " + subject_str + " o kodzie " + course_code_str + ", ponieważ jestem absolwentem kierunku Automatyka i Robotyka studiów inżynierskich na wydziale Elektroniki - dawne W4, które zacząłem w roku akademickim 2016/2017. "
            ret_str += "Podczas realizacji kierunku AiR odbyłem kurs "
            if other_course_name_str != "":
                ret_str += other_course_name_str
            else:
                ret_str += subject_str
            ret_str += " i uzyskałem z niego ocenę: " + mark_str + "."
            ret_str += '\n\n'

            if differences_str != "":
                ret_str += differences_str + '\n\n'


            ret_str += 'W załączniku znajduje się wygenerowany odpis suplementu dyplomu z systemu edukacja.cl\n\n'

            ret_str += 'Z wyrazami szacunku\n'
            ret_str += 'Kornel Stefańczyk\n'
            ret_str += 'Cyberbezpieczeństwo, 1 rok, 1 semestr, stacjonarnie\n'

            print(ret_str)



        print("-----------------------------")


