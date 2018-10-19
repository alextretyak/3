﻿import requests, re, os

times = [0]*24

for i in range(1, 101):                                                    # L(i) 1..100
    print('Processing page ' + str(i))                                     #    вывод(‘Processing page ’i)
    r = requests.get('http://habrahabr.ru/all/page'+str(i))                #    A r = http:get(‘habrahabr.ru/all/page’i) E N   #or#   A r = http:get(‘habrahabr.ru/all/page’i) # А р = ппгт:(‘habrahabr.ru/all/page’н)
    r.raise_for_status()                                                   #    r.throw_if_fail()                              #or#   [empty line]
    html = r.text                                                          #
    i = 0                                                                  #    A i = 0
    while True:                                                            #    L
        i = html.find('<span class="post__time">', i)                      #       i = html.find(‘<span class="post__time">’, i)
        if i == -1:                                                        #       I i == N
            break                                                          #          L.break
        i = html.find('</span>', i)
        time = html[:i][-5:]

        search_str = '<span class="post-stats__views-count">'
        start = html.find(search_str, i)
        i = html.find('</span>', start)
        r = re.match('(\d+(?:,\d+])?)(k?)', html[start+len(search_str):i]) # A r = re:match[‘(\d+(?:,\d+])?)(k?)’](html[start+search_str.len .< i])
        n = float(r.group(1).replace(',','.'))
        if r.group(2) == 'k':
            n *= 1000

        times[int(time[:2])] += n

f = open('temp_ram_file', 'w')                               # A f = File(‘ram:file’)
for i in range(len(times)):                                  # L(time) times
    f.write(str(times[i])+(' ' if i < len(times)-1 else '')) #    f.write(Str(time) + I L.next {‘ ’} E ‘’)
f.close()
os.system('type temp_ram_file | round_chart.exe')            # os:(‘ram:file >> round_chart.exe’)          # ос:(‘пам:файл >> round_chart.exe’)
os.remove('temp_ram_file')