# Enigma_ConsoleApp
Simple Enigma crypto console emulator.

<h3>1. Введение</h3>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Энигма  –  самая популярная шифровальная машина. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Она известна тем, что использовалась немцами во время второй мировой. Сегодня шифровальные машины уже в прошлом, операции шифрования и расшифрования выполняются на процессорах. Однако сами процессоры появились именно благодаря шифровальным машинам, потому что первым программируемым компьютером считается Колосс Марк 2, построенный в 1943 году для дешифровки другой немецкой шифровальной машины – «Lorenz SZ». 

<h3>2. Устройство Энигмы. Алгоритм шифрования</h3>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;При нажатии на клавишу Энигмы ток не только зажигает лампочку с зашифрованной буквой, но и изменяет положение шестеренок, чтобы нажатие на следующую клавишу кодировалось по-другому, таким образом одна и та же буква будет кодироваться разными символами в зависимости от положений роторов. При этом буквы образуют пары, то есть кодируются друг другом, это позволяет расшифровывать сообщения Энигмы точно таким же образом как и зашифровывать, надо просто вводить текст и смотреть на лампочки. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Роторов в Энигмах установлено от трех до четырех штук в зависимости от её предназначения и года выпуска, при этом Энигмы могли комплектоваться дополнительными сменными роторами для увеличения количества возможных комбинаций настроек.

<p align="center">
  <img src="pictures/rotors.jpg" width="500" />
</p>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Значение приходит в один контакт ротора и выходит из другого, соединения перепутаны. Сами роторы также можно менять местами. Грубо говоря за один проход по трем шестерёнкам буква изменяется три раза, а потом еще три так как сигнал пойдет через роторы в обратном направлении. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Механизм шестеренок работает как часы. Когда первая шестеренка сделает один круг, вторая шестеренка сдвинется на одно деление. Когда вторая шестеренка сделает один круг, третья сдвинется на одно деление. По аналогии с секундами, минутами и часами соответственно. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;У военной версии Энигмы был дополнительный уровень защиты – коммутатор. Он позволяет менять провода между роторами и лампочками местами, это увеличивает количество возможных комбинаций и соответственно затрудняет подбор ключах.

<h3>3. Пример использования Энигмы</h3>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Давайте попробуем зашифровать букву «A» с первым ротором передвинутым на одно положение назад. Все буквы взяты наугад, просто для примера. Для упрощения понимания представим, что ротор один, потому что суть от этого не поменяется, остальные роторы нужны для увеличения количества возможных комбинаций, чтобы было сложнее взломать шифр. Мы можем представить хоть 100 роторов, но смысла в этом нет. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Сигнал от нажатия клавиши «А» придет в то место в первом роторе, в котором раньше была буква «B». Допустим, что в первом роторе контакт буквы «B» с одного конца соединен с контактом буквы «K» с другого конца. Но ток на этом контакте означал бы букву «K» если бы мы ввели букву «B» при роторе в нулевом положении, в положении 1 он придет не на контакт буквы «K», а на тот контакт, который стоит позади изначального положения буквы «K». 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;После прохождения через все роторы в одном направлении электрический ток сталкивается с рефлектором. Рефлектор представляет из себя 13 проводов, которые соединяют все 26 контактов попарно. Пусть в рефлекторе соединены буквы «E» и «Q», и ток ток из буквы «K», смещенной на одно деление назад первым ротором, попадает именно на букву «E» и выходит из контакта обозначающем «Q». 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;В нулевом положении контакт «Q» бы соединялся с буквой «F» с обратной стороны первого ротора, но в положении ротора -1 он будет соединяться с буквой «O», а после прохода через первый ротор в обратном направлении станет буквой «H» и на машине загорится соответствующая лампочка. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Таким образом, при смещении ротора на одно положение назад, буква «A» зашифруется как «H», а буква «H», проходя тот же путь в обратном направлении, станет буквой «A».

<h3>4. Взлом Энигмы</h3>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Как я уже писал, из-за устройства Энигмы буквы образуют пары и не могут шифроваться сами собой. Это и было ключевой уязвимостью системы, которой Британцы успешно воспользовались. Они брали популярные слова и искали место в тексте, в котором каждая буква из этого слова не соответствует букве в тексте. Желательно взять достаточно длинное слово, чтобы снизить вероятность ошибки. Как пример, каждый день утром немцы отправляли прогноз погоды в котором было слово «Wetterbericht», которое переводится как прогноз погоды. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Для расшифровки использовалась машина «Bombe». Поляки тоже называли свою машину для расшифрования немецких текстов «Bombe», однако, кроме названия, ничего общего эти два устройства не имели. Британская «Bombe» перебирала все возможные варианты настроек, в которых зашифрованные буквы будут расшифровываться как «Wetterbericht», вернее она исключала неправильные варианты, пока не оставался один верный.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Машина работает по весьма хитроумному методу, позволяющему пренебречь настройками коммутационной панели в процессе поиска ключевой комбинации, что сводит пространство ключей Энигмы всего к 105456 комбинациям и делает весь шифр фатально уязвимым.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Метод эксплуатирует наличие в паре открытый-закрытый текст так называемых «циклов». Чтобы объяснить понятие «цикл», рассмотрим следующее открытое сообщение «WETTERVORHERSAGEBISKAYA» и соответствующий ему зашифрованный текст «RWIVTYRESXBFOGKUHQBAISE». 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Обратите внимание на подстановки, реализуемые энигмой в 14, 15 и 20 позициях. На 14 шаге буква A шифруется в G, а она шифруется в K на 15 шаге, затем буква K зашифровывается в A на 20 шаге, закольцовывая тем самым цепочку A-G-K-A. Такие закольцованные цепочки называются циклами. Наличие циклов позволяет разделить задачу взлома Энигмы на две простые составные части: 1) поиск стартового положения роторов и 2) поиск соединений коммутационной панели при известных установках роторов. 

Опустив коммутационную панель выразим внутреннее преобразование Энигмы через Pi:    
&nbsp;&nbsp;&nbsp;&nbsp;Pi = R-1TR    
Теперь шифрование можно записать как:    
&nbsp;&nbsp;&nbsp;&nbsp;Ei = S-1PiS   
Используя формулу перепишем подстановки из примера в 14, 15 и 20 позициях.    
&nbsp;&nbsp;&nbsp;&nbsp;S-1P14S(A) = G или что одно и тоже P14S(A) = S(G).    
&nbsp;&nbsp;&nbsp;&nbsp;P15S(G) = S(K)    
&nbsp;&nbsp;&nbsp;&nbsp;P20S(K) = S(A)    
Заменив в последнем выражении S(K) получим:   
&nbsp;&nbsp;&nbsp;&nbsp;P20P15P14S(A) = S(A), где S(A) — буква, соединенная с A на коммутационной панели.   

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Теперь атака сводится к тривиальному перебору всех возможных установок ротора. Для каждой комбинации роторов необходимо проверить выполнение равенства. Если равенство выполняется для буквы S, это означает что найдена правильная конфигурация роторов и что буква A соединена на коммутационной панели с буквой S. Поиск остальных пар сводится к по буквенной расшифровке зашифрованного текста и сопоставлению результата с известным открытым текстом.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Следует отметить, что с вероятностью 1/26 равенство может выполняться и при неправильной установке роторов, поэтому для повышения надежности алгоритма желательно использовать несколько «циклов».

<h3>5. Обзор программы-эмулятора</h3>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Я написал два варианта программы-эмулятора Энигмы. Первый – простой, с одним ротором и без проверки ввода, второй – посложнее, с тремя роторами и проверкой ввода. Первый сделал для упрощения понимания людьми, не разбирающимися в программировании, но интересующимися темой. С той же целью сделано три массива со значениями роторов вместо одного. Оба варианта программы эмулируют Энигму без коммутационной панели, возможно сделаю версию с ней в будущем.

Алгоритм работы версии программы с тремя роторами:    
&nbsp;&nbsp;&nbsp;&nbsp;а) получение начальных положений роторов от пользователя и проверка введенных данных на удовлетворению условию 0<input<27 функцией «rotorPosInput()»,   
&nbsp;&nbsp;&nbsp;&nbsp;б) получение символа или нескольких символов от пользователя для шифрования и перевод в верхний регистр в случае ввода в нижнем т.к. у Энигмы не было разделения на регистры,   
&nbsp;&nbsp;&nbsp;&nbsp;в) эмуляция прохождения электрического сигнала по роторам и рефлектору функциями «rotor1()», «rotor2()», «rotor3()», «reflector()». Замена буквы введенной пользователем на другую букву проводится три раза в одном направлении и три раза в другом, после прохождения через рефлектор,    
&nbsp;&nbsp;&nbsp;&nbsp;г) расчёт новых позиций роторов и смена их положений,   
&nbsp;&nbsp;&nbsp;&nbsp;д) вывод результата, одной буквы или нескольких,    
&nbsp;&nbsp;&nbsp;&nbsp;е) возврат к пункту 2.    

<h3>6. Работа с программой</h3>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;После запуска программа предлагает пользователю ввести положения роторов.

<p align="center">
  <img src="pictures/program1.jpg" width="500" />
</p>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Далее она ждет ввода буквы. Для примера введём «A», «B», «C» и «D».

<p align="center">
  <img src="pictures/program2.jpg" width="500" />
</p>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Результатом шифрования стали буквы «T», «M», «V» и «K». Для расшифровки текста запускаем программу, вводим те же начальные позиции роторов и зашифрованный текст, получаем расшифрованный текст.

<p align="center">
  <img src="pictures/program3.jpg" width="500" />
</p>
