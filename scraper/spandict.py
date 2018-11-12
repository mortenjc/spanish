#!/usr/bin/python
# -*- coding: utf-8 -*-

import urllib2, re, unidecode, codecs, locale, sys
from bs4 import BeautifulSoup

sys.stdout = codecs.getwriter(locale.getpreferredencoding())(sys.stdout)

# Specific to spanishdict.com html
irreg = re.compile(u"<span class=\"conj-irregular\">(.*)</span>", re.UNICODE)

# Specific to spanishdict.com html
tenses = ["presentIndicative", "preteritIndicative", "imperfectIndicative",
          "conditionalIndicative", "futureIndicative" ]

def getSoup(url):
    quote_page = url
    page = urllib2.urlopen(quote_page.encode('ascii', 'ignore'))
    soup = BeautifulSoup(page, 'html.parser')
    return soup

def toUnicode(s):
    try:
        uverb = unicode(s, "utf-8")
    except:
        uverb = s
    return uverb

def getVerbList():
    verblist=[]
    soup = getSoup('https://www.spanishdict.com/guide/the-100-most-common-spanish-verbs')

    for entry in soup.find_all("span", {"class", "sdmd sdmd-text-accent-2"}):
        verblist.append(toUnicode(entry.contents[0]))
    verblist.sort()
    return verblist

# Specific to spanishdict.com conjugation html
def fixIrregular(parts):
    irrflag = False
    result = u''

    for part in parts:
        ps = toUnicode(part)
        irr = irreg.search(unicode(ps))
        if  irr == None:
            result += ps
        else:
            irrflag = irrflag or True
            result += toUnicode(irr.groups()[0])
    return [irrflag, result]


def getVerbConjugation(verblist):
    for verb in verblist:
        uverb = toUnicode(verb)
        soup = getSoup('http://www.spanishdict.com/conjugate/' + unidecode.unidecode(uverb))

        res_hdr = uverb
        inf = soup.find("div", {"class": "el"})
        res_eng = inf.contents[2].contents[0]
        res_reg = "regular"
        irregular = False
        res_conj = ""
        for tense in tenses:
            for i in range(6):
                conjug = soup.find(attrs={"data-person": str(i), "data-tense": tense})
                iflag, res = fixIrregular(conjug.contents)
                irregular = irregular or iflag
                res_conj += " " + res
            res_conj += "\n"
        if (irregular):
            res_reg = "irregular"
        print("# %s %s %s" % (res_hdr, res_reg, res_eng))
        print("%s" % (res_conj))
        sys.stdout.flush()

#getVerbConjugation('ser')
#getVerbConjugation('oír')
#getVerbConjugation('caer')
#getVerbConjugation('mantener')
#getVerbConjugation('escribir')
list = getVerbList()
getVerbConjugation(list)
