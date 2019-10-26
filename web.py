
import os,sys
import requests
from bs4 import BeautifulSoup

urllist = []
for i in range(1,21):#查找页数可更改，暂时设置为20页
    url = "https://www1.szu.edu.cn/mailbox/list.asp?page={page}&leader=%CE%CA%CC%E2%CD%B6%CB%DF&tag=7".format(page = i)
    urllist.append(url)
for url in urllist:            #循环获取信息
    headers={'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/77.0.3865.120 Safari/537.36'}
    r = requests.get(url, headers)
    r.encoding = 'GBK'    #输出中文
    soup = BeautifulSoup(r.text, "lxml")
    f = open("a.txt","a+",encoding="utf-8")
    for k in soup.find_all("a",class_="fontcolor3")[2:]:  #检查输出信息确定起点为2
        print (k.text)
        f.write(k.text)    #写入txt
        f.write('\n')
    f.close()
    